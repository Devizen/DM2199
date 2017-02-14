#include "SceneSplash.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "Application.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
#include "LoadOBJ.h"

#include "shader.hpp"
#include "Utility.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>


using std::cout;
using std::cin;

SceneSplash::SceneSplash()
{
}

SceneSplash::~SceneSplash()
{
}

void SceneSplash::Init()
{
    // Set background color to black 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Enable blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Init VBO here

    // Generate a default VAO for now
    glGenVertexArrays(1, &m_vertexArrayID);
    glBindVertexArray(m_vertexArrayID);

    //Load vertex and fragment shaders
    m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");

    //Get a handle for our "MVP" uniform
    m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
    m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
    m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
    m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
    m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
    m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
    m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");

    m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
    m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
    m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
    m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
    m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
    m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
    m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
    m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
    m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
    m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
    m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");

    m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
    m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
    m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
    m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
    m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
    m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
    m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
    m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
    m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
    m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
    m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");

    m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
    m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
    m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
    m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
    m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
    m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
    m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
    m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
    m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
    m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
    m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");

    m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");

    m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

    // Get a handle for our "colorTexture" uniform
    m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
    m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");

    // Get a handle for our "textColor" uniform
    m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
    m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");


    // Use our shader
    glUseProgram(m_programID);

    for (int i = 0; i < NUM_GEOMETRY; ++i)
    {
        meshList[i] = NULL;
    }

    //Splash Screen
    meshList[GEO_SPLASH] = MeshBuilder::GenerateOBJ("splash", "OBJ//menu.obj");
    meshList[GEO_SPLASH]->textureID = LoadTGA("Image//splash.tga");

    //Prevent Jerk
    camera.Init(Vector3(0, 0, 1), Vector3(0, 0, 0), Vector3(0, 1, 0));

    //Projection
    Mtx44 projection;
    projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 4000.f);
    projectionStack.LoadMatrix(projection);


    light[0].type = Light::LIGHT_DIRECTIONAL;
    light[0].position.Set(0, 1000, 0);
    light[0].color.Set(1, 1, 1);
    light[0].power = 1;
    light[0].kC = 1.f;
    light[0].kL = 0.01f;
    light[0].kQ = 0.001f;
    light[0].cosCutoff = cos(Math::DegreeToRadian(45));
    light[0].cosInner = cos(Math::DegreeToRadian(30));
    light[0].exponent = 30.f;
    light[0].spotDirection.Set(0.f, 1.f, 0.f);

    light[1].type = Light::LIGHT_POINT;
    light[1].position.Set(0.f, 1000.f, 0.f);
    light[1].color.Set(1.f, 0.f, 0.f);
    light[1].power = 10;
    light[1].kC = 1.f;
    light[1].kL = 0.01f;
    light[1].kQ = 0.001f;
    light[1].cosCutoff = cos(Math::DegreeToRadian(45));
    light[1].cosInner = cos(Math::DegreeToRadian(30));
    light[1].exponent = 3.f;
    light[1].spotDirection.Set(0.f, 1.f, 0.f);

    light[2].type = Light::LIGHT_SPOT;
    light[2].position.Set(0.f, 0.f, 50.f);
    light[2].color.Set(1.f, 1.f, 0.f);
    light[2].power = 0;
    light[2].kC = 1.f;
    light[2].kL = 0.01f;
    light[2].kQ = 0.001f;
    light[2].cosCutoff = cos(Math::DegreeToRadian(45));
    light[2].cosInner = cos(Math::DegreeToRadian(30));
    light[2].exponent = 3.f;
    light[2].spotDirection.Set(0.f, 1.f, 0.f);

    // Make sure you pass uniform parameters after glUseProgram()
    glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
    glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
    glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
    glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
    glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
    glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
    glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
    glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);

    glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
    glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
    glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
    glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
    glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
    glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
    glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
    glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);

    glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
    glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
    glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
    glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
    glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
    glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
    glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
    glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
    glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);

    // Make sure you pass uniform parameters after glUseProgram()
    glUniform1i(m_parameters[U_NUMLIGHTS], 3);


}

void SceneSplash::Update(double dt)
{
    //Time Out for Splash Screen
    static float timeOut = 0.f;

    srand((unsigned)time(NULL));

    timeOut += (float)dt;

    cout << timeOut << endl;
    if (timeOut > 2.f)
    {
        Application::ChangeScene(1);
    }
    if (Application::IsKeyPressed('7'))
    {
        light[0].type = Light::LIGHT_POINT;
        glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
        light[1].type = Light::LIGHT_POINT;
        glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
        //to do: switch light type to POINT and pass the information to shader
    }
    if (Application::IsKeyPressed('8'))
    {
        light[0].type = Light::LIGHT_DIRECTIONAL;
        glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
        light[1].type = Light::LIGHT_DIRECTIONAL;
        glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
        //to do: switch light type to DIRECTIONAL and pass the information to shader
    }
    if (Application::IsKeyPressed('9'))
    {
        light[0].type = Light::LIGHT_SPOT;
        glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
        light[1].type = Light::LIGHT_SPOT;
        glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
        //to do: switch light type to SPOT and pass the information to shader
    }

    camera.Update(dt);

}

void SceneSplash::Render()
{
    srand((unsigned)time(NULL));

    //Clear color & depth buffer every frame
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Mtx44 MVP;

    viewStack.LoadIdentity(); //No need camera for now, set it at World's origin
    viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
    modelStack.LoadIdentity();

    //Passing light position to shader
    Position lightPosition_cameraspace = viewStack.Top() * light[0].position;

    //Light 1
    if (light[0].type == Light::LIGHT_DIRECTIONAL)
    {
        Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
        Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
    }
    else if (light[0].type == Light::LIGHT_SPOT)
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
        Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
        glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
    }
    else
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
        glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
    }

    //Light 2
    if (light[1].type == Light::LIGHT_DIRECTIONAL)
    {
        Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
        Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
        glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
    }
    else if (light[1].type == Light::LIGHT_SPOT)
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
        glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
        Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
        glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
    }
    else
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
        glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
    }

    //Light 2
    if (light[2].type == Light::LIGHT_DIRECTIONAL)
    {
        Vector3 lightDir(light[2].position.x, light[2].position.y, light[2].position.z);
        Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
        glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
    }
    else if (light[2].type == Light::LIGHT_SPOT)
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
        glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
        Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
        glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
    }
    else
    {
        Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
        glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
    }

    RenderMeshOnScreen(meshList[GEO_SPLASH], 40, 30, 100, 100);

}


void SceneSplash::RenderMesh(Mesh *mesh, bool enableLight)
{
    Mtx44 MVP, modelView, modelView_inverse_transpose;

    MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
    glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
    modelView = viewStack.Top() * modelStack.Top();
    glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
    if (enableLight)
    {
        glUniform1i(m_parameters[U_LIGHTENABLED], 1);
        modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
        glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

        //load material
        glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
        glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
        glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
        glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
    }
    else
    {
        glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    }

    if (mesh->textureID > 0)
    {
        glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, mesh->textureID);
        glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    }
    else
    {
        glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
    }


    mesh->Render(); //this line should only be called once
    if (mesh->textureID > 0)
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void SceneSplash::RenderText(Mesh* mesh, std::string text, Color color)
{
    if (!mesh || mesh->textureID <= 0) //Proper error check
    {
        return;
    }

    glDisable(GL_DEPTH_TEST);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
    glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
    glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->textureID);
    glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    for (unsigned i = 0; i < text.length(); ++i)
    {
        Mtx44 characterSpacing;
        characterSpacing.SetToTranslation(i * 1.0f, 0.f, 0); //1.0f is the spacing of each character, you may change this value
        Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
        glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

        mesh->Render((unsigned)text[i] * 6, 6);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
    glEnable(GL_DEPTH_TEST);
}

void SceneSplash::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
    if (!mesh || mesh->textureID <= 0) //Proper error check
    {
        return;
    }

    glDisable(GL_DEPTH_TEST);

    Mtx44 ortho;
    ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
    projectionStack.PushMatrix();
    projectionStack.LoadMatrix(ortho);
    viewStack.PushMatrix();
    viewStack.LoadIdentity(); //No need camera for ortho mode
    modelStack.PushMatrix();
    modelStack.LoadIdentity(); //Reset modelStack
    modelStack.Scale(size, size, size);
    modelStack.Translate(x, y, 0);

    glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
    glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
    glUniform1i(m_parameters[U_LIGHTENABLED], 0);
    glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, mesh->textureID);
    glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
    for (unsigned i = 0; i < text.length(); ++i)
    {
        Mtx44 characterSpacing;
        characterSpacing.SetToTranslation(i * 0.5f + 0.5f, 0.5f, 0); //0.5f beside i is the spacing of each character, you may change this value
        Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
        glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

        mesh->Render((unsigned)text[i] * 6, 6);
    }
    glBindTexture(GL_TEXTURE_2D, 0);
    glUniform1i(m_parameters[U_TEXT_ENABLED], 0);

    //Add these code just before glEnable(GL_DEPTH_TEST);
    projectionStack.PopMatrix();
    viewStack.PopMatrix();
    modelStack.PopMatrix();


    glEnable(GL_DEPTH_TEST);
}

void SceneSplash::RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey)
{
    glDisable(GL_DEPTH_TEST);
    Mtx44 ortho;
    ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
    projectionStack.PushMatrix();
    projectionStack.LoadMatrix(ortho);
    viewStack.PushMatrix();
    viewStack.LoadIdentity(); //No need camera for ortho mode

    modelStack.PushMatrix();
    modelStack.LoadIdentity();
    modelStack.Translate((float)x, (float)y, 0.f);
    modelStack.Scale((float)sizex, (float)sizey, 1.f);
    //to do: scale and translate accordingly
    RenderMesh(mesh, false); //UI should not have light
    projectionStack.PopMatrix();
    viewStack.PopMatrix();
    modelStack.PopMatrix();
    glEnable(GL_DEPTH_TEST);
}


void SceneSplash::Exit()
{
    // Cleanup VBO here
    for (int i = 0; i < NUM_GEOMETRY; ++i)
    {
        if (meshList[i] != NULL)
        {
            delete meshList[i];
        }
    }
    glDeleteVertexArrays(1, &m_vertexArrayID);

    glDeleteProgram(m_programID);
}
