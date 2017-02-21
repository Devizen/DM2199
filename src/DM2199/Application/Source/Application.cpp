
#include "Application.h"

//Include GLEW
#include <GL/glew.h>

//Include GLFW
#include <GLFW/glfw3.h>

//Include the standard C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


#include "SceneBase.h"
#include "SceneSplash.h"
#include "SceneMainMenu.h"
#include "SceneLoading.h"
#include "SceneEditor.h"
#include "Levels/Tutorial.h"
#include "Enemy.h"

GLFWwindow* m_window;
const unsigned char FPS = 60; // FPS of this game
const unsigned int frameTime = 1000 / FPS; // time for each frame

static int sceneNumber;
static int sceneToChange;
static unsigned loadTime;

//Define an error callback
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    _fgetchar();
}

//Define the key input callback
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

bool Application::IsKeyPressed(unsigned short key)
{
    return ((GetAsyncKeyState(key) & 0x8001) != 0);
}

Application::Application()
{
 
}

Application::~Application()
{
}


//Resize callback
void resize_callback(GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h); //Update OpenGL the new window size
}

void Application::Init()
{
    sceneNumber = 0;
    //Set the error callback
    glfwSetErrorCallback(error_callback);

    //Initialize GLFW
    if (!glfwInit())
    {
        exit(EXIT_FAILURE);
    }

    //Set the GLFW window creation hints - these are optional
    glfwWindowHint(GLFW_SAMPLES, 4); //Request 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //Request a specific OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //Request a specific OpenGL version
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 


    //Create a window and create its OpenGL context
    m_window = glfwCreateWindow(800, 600, "Computer Graphics", NULL, NULL);

    //If the window couldn't be created
    if (!m_window)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //Register callback; Create after window
    glfwSetWindowSizeCallback(m_window, resize_callback);

    //This function makes the context of the specified window current on the calling thread. 
    glfwMakeContextCurrent(m_window);

    //Sets the key callback
    //glfwSetKeyCallback(m_window, key_callback);

    glewExperimental = true; // Needed for core profile
    //Initialize GLEW
    GLenum err = glewInit();

    //If GLEW hasn't initialized
    if (err != GLEW_OK)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        //return -1;
    }
}

void Application::ChangeScene(int sceneNo)
{
    sceneNumber = sceneNo;
}

void Application::Run()
{
    //Main Loop
    Scene *sceneSplash = new SceneSplash();
    Scene *sceneMainMenu = new SceneMainMenu();
    Scene *sceneLoading = new SceneLoading();
    Scene *sceneTutorial = new SceneBase();
    Scene *sceneEditor = new SceneEditor();
	//Scene *sceneBase = new SceneBase();
    Scene *scene = sceneSplash;
    Scene *sceneLoadingAtBack;
    scene->Init();

    m_timer.startTimer();    // Start timer to calculate how long it takes to render this frame
    while (!glfwWindowShouldClose(m_window) && !IsKeyPressed(VK_ESCAPE))
    {
        if (sceneNumber == 1 && scene != sceneMainMenu)
        {
            scene->Exit();
            scene = sceneMainMenu;
            sceneLoading->Init();
            scene->Init();
        }

        if (sceneNumber == 2 && scene != sceneLoading)
        {
            scene->Exit();
            scene = sceneLoading;
            scene->Init();
        }

        if (scene == sceneLoading)
        {
            if (sceneNumber == 3 && scene != sceneTutorial)
            {
                sceneLoadingAtBack = sceneTutorial;
                sceneLoadingAtBack->Init();
                scene->Exit();
                scene = sceneLoadingAtBack;
            }

            if (sceneNumber == 4 && scene != sceneEditor)
            {
                sceneLoadingAtBack = sceneEditor;
                sceneLoadingAtBack->Init();
                scene->Exit();
                scene = sceneLoadingAtBack;
            }
        }
	
		scene->Update(m_timer.getElapsedTime());
	     
        scene->Render();
        //Swap buffers
        glfwSwapBuffers(m_window);
        //Get and organize events, like keyboard and mouse input, window resizing, etc...
        glfwPollEvents();
        m_timer.waitUntil(frameTime);       // Frame rate limiter. Limits each frame to a specified time in ms.   

    } //Check if the ESC key had been pressed or if the window had been closed
    scene->Exit();
    delete scene;


}

void Application::Exit()
{
    //Close OpenGL window and terminate GLFW
    glfwDestroyWindow(m_window);
    //Finalize and clean up GLFW
    glfwTerminate();
}
