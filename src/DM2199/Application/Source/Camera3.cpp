#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"
#include <GLFW\glfw3.h>

Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}
void cbMouseEvent(GLFWwindow* window, int button, int action, int mods) {

	// Toggle cursor on right click
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE) {
		if (glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide cursor
		}
		else {
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

    //Objects Location
    objectsLocation();


	// Mouse Variables
	mouseMovedX = 0;
	mouseMovedY = 0;

	yaw = 0.0f;
	pitch = 0.0f;
	glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_DISABLED); // Hide cursor
	glfwSetMouseButtonCallback(glfwGetCurrentContext(), cbMouseEvent);
    
}

void Camera3::updateCursor() {

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
    if (Application::IsKeyPressed(VK_NUMPAD5))
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


    else
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
        }

    }
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

void Camera3::collisionCheck()
{
    if ((position.x >= objectsMin[0].x && position.x <= objectsMax[0].x) &&
        (position.y >= objectsMin[0].y && position.y <= objectsMax[0].y) &&
        (position.z >= objectsMin[0].z && position.z <= objectsMax[0].z)) 
    {
        position = PrevPos;
        jumpStucked = true;
    }
    else if ((position.x >= objectsMin[1].x && position.x <= objectsMax[1].x) &&
            (position.y >= objectsMin[1].y && position.y <= objectsMax[1].y) &&
            (position.z >= objectsMin[1].z && position.z <= objectsMax[1].z))
    {
        position = PrevPos;
        jumpStucked = true;
    }

    else if ((position.x >= objectsMin[2].x && position.x <= objectsMax[2].x) &&
        (position.y >= objectsMin[2].y && position.y <= objectsMax[2].y) &&
        (position.z >= objectsMin[2].z && position.z <= objectsMax[2].z))
    {
        position = PrevPos;
        jumpStucked = true;
    }

    else if ((position.x >= objectsMin[3].x && position.x <= objectsMax[3].x) &&
        (position.y >= objectsMin[3].y && position.y <= objectsMax[3].y) &&
        (position.z >= objectsMin[3].z && position.z <= objectsMax[3].z))
    {
        position = PrevPos;
        jumpStucked = true;
    }

    else if ((position.x >= objectsMin[4].x && position.x <= objectsMax[4].x) &&
        (position.y >= objectsMin[4].y && position.y <= objectsMax[4].y) &&
        (position.z >= objectsMin[4].z && position.z <= objectsMax[4].z))
    {
        position = PrevPos;
        jumpStucked = true;
    }

    else
    {
        PrevPos = position;
        jumpStucked = false;
    }
    
}

void Camera3::objectsLocation()
{
    //Mountains
    objectsMin[0].x = -95.f;
    objectsMax[0].x = 50.f;
    objectsMin[0].y = 0.f;
    objectsMax[0].y = 30.f;
    objectsMin[0].z = 210.f;
    objectsMax[0].z = 370.f;


    objectsMin[1].x = -90.f;
    objectsMax[1].x = 80.f;
    objectsMin[1].y = 0.f;
    objectsMax[1].y = 30.f;
    objectsMin[1].z = -330.f;
    objectsMax[1].z = -170.f;

    objectsMin[2].x = 230.f;
    objectsMax[2].x = 400.f;
    objectsMin[2].y = 0.f;
    objectsMax[2].y = 30.f;
    objectsMin[2].z = 125.f;
    objectsMax[2].z = 275.f;

    objectsMin[3].x = 115.f;
    objectsMax[3].x = 275.f;
    objectsMin[3].y = 0.f;
    objectsMax[3].y = 30.f;
    objectsMin[3].z = -140.f;
    objectsMax[3].z = 0.f;

    objectsMin[4].x = -285.f;
    objectsMax[4].x = -110.f;
    objectsMin[4].y = 0.f;
    objectsMax[4].y = 30.f;
    objectsMin[4].z = -170.f;
    objectsMax[4].z = -20.f;

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