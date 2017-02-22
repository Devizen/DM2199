#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include <GLFW\glfw3.h>
#include "SceneEditor.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using std::ifstream;
using std::cout;
using std::endl;
using std::stof;

static bool collision;
static string level = "";
static bool pauseInput;

Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}
void cbMouseEvent(GLFWwindow* window, int button, int action, int mods) {

	// Toggle cursor on right click
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) 
    {
        if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL) 
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide cursor
        }
        else 
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL); // Show Cursor
            // Reset the cursor to middle
            int w, h;
            glfwGetWindowSize(window, &w, &h);
            glfwSetCursorPos(window, (double)w / 2, (double)h / 2);
        }
	}

}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();

	// Mouse Variables
	mouseMovedX = 0;
	mouseMovedY = 0;

	yaw = 0.0f;
	pitch = 0.0f;
	glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide cursor
	glfwSetMouseButtonCallback(glfwGetCurrentContext(), cbMouseEvent);
    
    //Collision for Level Editor set to False as default.
    collision = false;
}

void Camera3::updateCursor() 
{

	double currentX = 0;
	double currentY = 0;

	glfwGetCursorPos(glfwGetCurrentContext(), &currentX, &currentY);

	if (currentX != lastX) {
		mouseMovedX = (currentX > lastX) ? 1 : -1; // 1 for left, -1 for right
		mouseMovedDistanceX = std::abs((float)(currentX - lastX)); // distance the cursor moved and return a positive value of it
	}
	else {
		mouseMovedX = 0;
	}

	if (currentY != lastY) {
		mouseMovedY = (currentY < lastY) ? 1 : -1; // 1 for up, -1 for down
		mouseMovedDistanceY = std::abs((float)(currentY - lastY)); // distance the cursor moved and return a positive value of it
	}
	else {
		mouseMovedY = 0;
	}

	lastX = currentX;
	lastY = currentY;

}

void Camera3::ResetCursorVariables() {
	mouseMovedX = 0;
	mouseMovedY = 0;
	mouseMovedDistanceX = 0;
	mouseMovedDistanceY = 0;
	glfwGetCursorPos(glfwGetCurrentContext(), &lastX, &lastY);
}

void Camera3::Update(double dt)
{
    if (pauseInput == false)
    {

        // Cursor is shown, stop rotating the camera
        if (isMouseEnabled && glfwGetInputMode(glfwGetCurrentContext(), GLFW_CURSOR) == GLFW_CURSOR_DISABLED && !Application::IsKeyPressed(MK_RBUTTON))
        {
            updateCursor();
        }
        else
        {
            ResetCursorVariables();
        }

        static const float CAMERA_SPEED = 100.f;
        float run = 1.f;

        Mtx44 rotation;
        Vector3 view = (target - position).Normalized();
        Vector3 right = view.Cross(up);
        Vector3 upp = view.Cross(right);

        float rotationSpeed = 2.5f * (float)dt;

        //Keyboard Controls
        if (Application::IsKeyPressed(VK_NUMPAD5) || Application::IsKeyPressed(VK_LSHIFT))
        {
            run = 3.f;
        }

        //Directions
        if (Application::IsKeyPressed('W') && directionJump == false)
        {
            preventXZOver();
            if (Application::IsKeyPressed(VK_SPACE))
            {
                directionJump = true;
            }
            collisionCheck();
            position += view * (float)(CAMERA_SPEED * run * dt);
            position.y = 0.f;
            target = position + view;

            resetDirectionPressed();
            upPressed = true;
        }

        if (Application::IsKeyPressed('S') && directionJump == false)
        {
            preventXZOver();
            if (Application::IsKeyPressed(VK_SPACE))
            {
                directionJump = true;
            }
            collisionCheck();
            position -= view * (float)(CAMERA_SPEED * run * dt);
            position.y = 0.f;
            target = position + view;

            resetDirectionPressed();
            downPressed = true;
        }

        if (Application::IsKeyPressed('A') && directionJump == false)
        {
            preventXZOver();
            if (Application::IsKeyPressed(VK_SPACE))
            {
                directionJump = true;
            }

            collisionCheck();
            position = position - right * (float)(CAMERA_SPEED * run * dt);
            target = position + view;

            resetDirectionPressed();
            leftPressed = true;
        }

        if (Application::IsKeyPressed('D') && directionJump == false)
        {
            preventXZOver();
            if (Application::IsKeyPressed(VK_SPACE))
            {
                directionJump = true;
            }

            collisionCheck();
            position = position + right * (float)(CAMERA_SPEED * run * dt);
            target = position + view;

            resetDirectionPressed();
            rightPressed = true;

        }

        //Viewing Angle
        if (Application::IsKeyPressed(VK_NUMPAD4))
        {
            yaw -= (CAMERA_SPEED * (float)dt * run);
        }

        if (Application::IsKeyPressed(VK_NUMPAD6))
        {
            yaw += (CAMERA_SPEED * (float)dt * run);
        }

        if (Application::IsKeyPressed(VK_NUMPAD8))
        {
            //Bound check for viewing up.
            if (view.y < 0.7f)
            {
                pitch += (CAMERA_SPEED * (float)dt * run);
            }
        }

        if (Application::IsKeyPressed(VK_NUMPAD2))
        {
            //Bound check for viewing down.
            if (view.y > -0.7f)
            {
                pitch -= (CAMERA_SPEED * (float)dt * run);
            }
        }

        //Jump
        if (Application::IsKeyPressed(VK_SPACE) && jump == false && fall == false)
        {
            jump = true;
            directionJump = false;
        }

        //Non-movement jump
        if (jump == true && directionJump == false)
        {
            position.y += 1.f * (float)(CAMERA_SPEED * run * dt);
            target = position + view;
            if (position.y > jumpHeight)
            {
                jump = false;
                fall = true;
            }
        }

        if (fall == true && directionJump == false)
        {
            position.y -= 1.f * (float)(CAMERA_SPEED * run * dt);
            target = position + view;
            if (position.y <= 0.f)
            {
                fall = false;
            }
        }

        //Directional jump
        //Up
        if (jump == true && directionJump == true && upPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y += 1.f * (float)(CAMERA_SPEED * run * dt);
                position += view * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }
            if (position.y > jumpHeight || jumpStucked == true)
            {
                jump = false;
                fall = true;
            }
        }

        //Up Fall
        if (fall == true && directionJump == true && upPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y -= 1.f * (float)(CAMERA_SPEED * run * dt);
                position += view * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (jumpStucked == true && position.y > 0)
            {
                collisionCheck();
                position.y--;
                target = position + view;
            }

            if (position.y <= 0.f)
            {
                fall = false;
                directionJump = false;
                upPressed = false;
            }
        }

        //Down
        if (jump == true && directionJump == true && downPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y += 1.f * (float)(CAMERA_SPEED * run * dt);
                position -= view * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (position.y > jumpHeight || jumpStucked == true)
            {
                jump = false;
                fall = true;
            }
        }

        //Down Fall
        if (fall == true && directionJump == true && downPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y -= 1.f * (float)(CAMERA_SPEED * run * dt);
                position -= view * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (jumpStucked == true && position.y > 0)
            {
                collisionCheck();
                position.y--;
                target = position + view;
            }

            if (position.y <= 0.f)
            {
                fall = false;
                directionJump = false;
                downPressed = false;
            }
        }

        //Left
        if (jump == true && directionJump == true && leftPressed == true)
        {
            preventXZOver();
            collisionCheck();


            if (jumpStucked == false)
            {
                position.y += 1.f * (float)(CAMERA_SPEED * run * dt);
                position = position - right * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (position.y > jumpHeight || jumpStucked == true)
            {
                jump = false;
                fall = true;
            }
        }

        //Left Fall
        if (fall == true && directionJump == true && leftPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y -= 1.f * (float)(CAMERA_SPEED * run * dt);
                position = position - right * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (jumpStucked == true && position.y > 0)
            {
                collisionCheck();
                position.y--;
                target = position + view;
            }

            if (position.y <= 0.f)
            {
                fall = false;
                directionJump = false;
                leftPressed = false;
            }
        }

        //Right
        if (jump == true && directionJump == true && rightPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y += 1.f * (float)(CAMERA_SPEED * run * dt);
                position = position + right * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (position.y > jumpHeight || jumpStucked == true)
            {
                jump = false;
                fall = true;
            }
        }

        //Right Fall
        if (fall == true && directionJump == true && rightPressed == true)
        {
            preventXZOver();
            collisionCheck();

            if (jumpStucked == false)
            {
                position.y -= 1.f * (float)(CAMERA_SPEED * run * dt);
                position = position + right * (float)(CAMERA_SPEED * run * dt);
                target = position + view;
            }

            if (jumpStucked == true && position.y > 0)
            {
                collisionCheck();
                position.y--;
                target = position + view;
            }

            if (position.y <= 0.f)
            {
                fall = false;
                directionJump = false;
                rightPressed = false;
            }
        }

        if (Application::IsKeyPressed('R'))
        {
            Reset();
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////
        // Rotate Camera with mouse-axis
        if (mouseMovedX < 0) { // Left
            yaw -= rotationSpeed * mouseMovedDistanceX;
        }

        if (mouseMovedX > 0) { // Right
            yaw += rotationSpeed  * mouseMovedDistanceX;
        }

        if (mouseMovedY > 0) { // Up
            pitch += rotationSpeed  * mouseMovedDistanceY;
        }

        if (mouseMovedY < 0) { // Down
            pitch -= rotationSpeed * mouseMovedDistanceY;
        }


        pitch = Math::Clamp(pitch, _MinYawAngle, _MaxYawAngle); // clamp the up/down rotation of the camera to these angles

        target.x = cos(Math::DegreeToRadian(pitch)) * cos(Math::DegreeToRadian(yaw)) + position.x;
        target.y = sin(Math::DegreeToRadian(pitch)) + position.y;
        target.z = cos(Math::DegreeToRadian(pitch)) * sin(Math::DegreeToRadian(yaw)) + position.z;

    }
  /*  else
    {
        if (Application::IsKeyPressed(VK_NUMPAD4))
        {
            float yaw = (float)(CAMERA_SPEED * dt* run);
            rotation.SetToRotation(yaw, 0, 1, 0);
            view = rotation * view;
            target = position + view;
        }

        if (Application::IsKeyPressed(VK_NUMPAD6))
        {
            float yaw = (float)(-CAMERA_SPEED * dt* run);
            rotation.SetToRotation(yaw, 0, 1, 0);
            view = rotation * view;
            target = position + view;
        }

        if (Application::IsKeyPressed(VK_NUMPAD8))
        {
            if (view.y < 0.9f)
            {
                float yaw = (float)(CAMERA_SPEED * dt* run);
                rotation.SetToRotation(yaw, right.x, right.y, right.z);
                view = rotation * view;
                target = position + view;
            }
        }

        if (Application::IsKeyPressed(VK_NUMPAD2))
        {
            if (view.y > -0.9f)
            {
                float yaw = (float)(-CAMERA_SPEED * dt* run);
                rotation.SetToRotation(yaw, right.x, right.y, right.z);
                view = rotation * view;
                target = position + view;
            }
        }*/

  /*  }*/

	//Poison
	if (poison)
	{
		health--;
		poisonTime++;
	}
	if (poisonTime > 0 && poisonTime < 150)
		poisonText = true;
	else
		poisonText = false;
}

void Camera3::pauseCheck(bool input)
{
    pauseInput = input;
}

void Camera3::preventXZOver()
{
	if (position.x < -mapSize)
	{
		position.x = -mapSize;
	}
	if (position.x > mapSize)
	{
		position.x = mapSize;
	}
	if (position.z < -mapSize)
	{
		position.z = -mapSize;
	}
	if (position.z > mapSize)
	{
		position.z = mapSize;
	}
}

void Camera3::collisionSwitch(bool collisionInput, string levelInput)
{
    collision = collisionInput;
    level = levelInput;
}

void Camera3::collisionCheck()
{
    if (collision == true)
    {
        //Storing of object name
        vector<string>objectName;
        //Storing of object x coordinates
        vector<string>objectPosX;
        //Storing of object z coordinates
        vector<string>objectPosZ;
        
        //linePos will be capped at 3, when it is 3, it reverts back to 1. Saves 3 lines as a set to text file for an object.
        static int linePos = 1;

        string line = "";
        ifstream myfile(level);

        //Load the respective text file to save all the objects information into the vectors above.
        while (myfile.peek() != EOF)
        {
            //Read line by line
            getline(myfile, line);

            //Read 3 lines as a set.
            //Store coordinates respectively.
            if (linePos == 1)
            {
                string pos, posX, posZ;
                bool x = false;
                pos = line;

                for (unsigned i = 0; i < pos.size(); i++)
                {
                    if (pos[i] != ',' && x == false)
                    {
                        posX += pos[i];
                    }
                    if (pos[i] == ',')
                    {
                        x = true;
                        objectPosX.push_back(posX);
                        continue;
                    }
                    if (x == true)
                    {
                        posZ += pos[i];
                    }
                }
                objectPosZ.push_back(posZ);
                posX = "";
                posZ = "";
            }
            //Skip line 2 as texture is not needed to check for collision.
            if (linePos == 2)
            {

            }
            //Store object name to check for object specific collision.
            if (linePos == 3)
            {
                objectName.push_back(line);
            }

            //Keep going to next line.
            if (linePos < 3)
            {
                linePos++;
            }
            //Revert line back to 1 so that it reads as 3 lines per set.
            else
            {
                linePos = 1;
            }

        }

        //Float for storing coordinates to check for collision.
        float x, z;
        //Variable to bind all three loops together.
        int generateObjects = 0;
        //For breaking loop when player collided with object.
        bool collided = false;
        //For skipping to the next for loop so that all 3 loops are binded together.
        bool preventReoccurence = false;
        //To check and enable collision according to objects.
		const string mountain = "OBJ//mountain.obj";
		const string lamp = "OBJ//lamp.obj";
		const string lantern = "OBJ//lantern.obj";
		const string tombstone = "OBJ//tombstone.obj";
		const string tree = "OBJ//tree.obj";
		const string statue1 = "OBJ//statue1.obj";
		const string statue2 = "OBJ//statue2.obj";

        for (vector<string>::reverse_iterator objectrItName = objectName.rbegin(); objectrItName != objectName.rend() && collided == false; objectrItName++)
        {
            for (vector<string>::reverse_iterator objectrItX = objectPosX.rbegin() + generateObjects; objectrItX != objectPosX.rend() && preventReoccurence == false; objectrItX++)
            {
                //Proceed to next loop.
                preventReoccurence = true;
                for (vector<string>::reverse_iterator objectrItZ = objectPosZ.rbegin() + generateObjects; objectrItZ != objectPosZ.rend(); objectrItZ++)
                {
                    //Covert x and z to float for checking.
                    x = stof(objectrItX->data());
                    z = stof(objectrItZ->data());
                    if (objectrItName->data() == mountain)
                    {
                        if ((position.x >= x - 70 && position.x <= x + 70) &&
                            (position.z >= z - 70 && position.z <= z + 70))
                        { 
                            //Set position to previous position if camera touches the object boundary.
                            position = prevPosCol;
                            jumpStucked = true;
                            //Enable collided to break out of the entire loop.
                            collided = true;
                            break;
                        }
                    }

					else if (objectrItName->data() == lamp)
					{
						if ((position.x >= x - 10 && position.x <= x + 10) &&
							(position.z >= z - 10 && position.z <= z + 10))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}

					else if (objectrItName->data() == lantern)
					{
						if ((position.x >= x - 10 && position.x <= x + 10) &&
							(position.z >= z - 10 && position.z <= z + 10))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}

					else if (objectrItName->data() == tombstone)
					{
						if ((position.x >= x - 30 && position.x <= x + 30) &&
							(position.z >= z - 20 && position.z <= z + 20))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}

					else if (objectrItName->data() == tree)
					{
						if ((position.x >= x - 70 && position.x <= x + 70) &&
							(position.z >= z - 70 && position.z <= z + 70))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}

					else if (objectrItName->data() == statue1)
					{
						if ((position.x >= x - 25 && position.x <= x + 25) &&
							(position.z >= z - 10 && position.z <= z + 10))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}

					else if (objectrItName->data() == statue2)
					{
						if ((position.x >= x - 40 && position.x <= x + 40) &&
							(position.z >= z - 25 && position.z <= z + 25))
						{
							//Set position to previous position if camera touches the object boundary.
							position = prevPosCol;
							jumpStucked = true;
							//Enable collided to break out of the entire loop.
							collided = true;
							break;
						}
					}
                    //Reset boolean so that the next iteration of for loop can be accessed.
                    preventReoccurence = false;
                    //Increase variable by 1 so that the loops will stay binded.
                    generateObjects++;
                    break;
                }
            }
        }
        //Set previous position to current position if there is no collision.
        prevPosCol = position;
        jumpStucked = false;
    }
}

void Camera3::resetDirectionPressed()
{
    upPressed = false;
    downPressed = false;
    leftPressed = false;
    rightPressed = false;
}

void Camera3::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
    collision = false;
    directionJump = false;
}