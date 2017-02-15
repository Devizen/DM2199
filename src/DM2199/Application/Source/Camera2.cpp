#include "Camera2.h"
#include "Application.h"
#include "Mtx44.h"
#include <iostream>

using namespace std;

/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera2::Camera2()
{
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera2::~Camera2()
{
}

/******************************************************************************/
/*!
\brief
Initialize Camera2

\param pos - position of Camera2
\param target - where the Camera2 is looking at
\param up - up vector of Camera2
*/
/******************************************************************************/
void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = pos;
	this->target = target;

	//Can update this code to prevent jerk.
	this->up = up;
}

/******************************************************************************/
/*!
\brief
Reset the Camera2 settings
*/
/******************************************************************************/
void Camera2::Reset()
{
}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera2 will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera2::Update(double dt)
{
    Mtx44 rotationMatrix;
    Vector3 view = target - position;
    Vector3 right = view.Cross(up);

    //rotateAngle += (float)(50 * dt);
    //rotationMatrix.SetToIdentity;


    if (Application::IsKeyPressed('W'))
    {
        if (position.y <= 75)
        {
            rotationMatrix.SetToRotation(-1, right.x, right.y, right.z);
            position = rotationMatrix * position;
        }
    }

    if (Application::IsKeyPressed('S'))
    {
        if (position.y >= -75)
        {
            rotationMatrix.SetToRotation(1, right.x, right.y, right.z);
            position = rotationMatrix * position;
        }
    }

    if (Application::IsKeyPressed('A'))
    {
        rotationMatrix.SetToRotation(-2, up.x, up.y, up.z);
        position = rotationMatrix * position;
    }

    if (Application::IsKeyPressed('D'))
    {
        rotationMatrix.SetToRotation(2, up.x, up.y, up.z);
        position = rotationMatrix * position;
    }

    if (Application::IsKeyPressed('E'))
    {
        cout << "Position X: " << position.x << endl;
        cout << "Position Y: " << position.y << endl;
        cout << "Position Z: " << position.z << endl;

        if (position.x >= 0.f && position.x <= 128.f &&
            position.y >= 0.f && position.y <= 128.f &&
            position.z >= 0.f && position.z <= 128.f)
        {
            position += view * (float)dt;
        }

        if (position.x > 128.f)
        {
            position.x -= 1.f;
        }

        if (position.x < 0.f)
        {
            position.x += 1.f;
        }

        if (position.y > 128.f)
        {
            position.y -= 1.f;
        }

        if (position.y < 0.f)
        {
            position.y += 1.f;
        }

        if (position.z > 128.f)
        {
            position.z -= 1.f;
        }

        if (position.z < 0.f)
        {
            position.z += 1.f;
        }
    }

    if (Application::IsKeyPressed('Q'))
    {
        cout << "Position X: " << position.x << endl;
        cout << "Position Y: " << position.y << endl;
        cout << "Position Z: " << position.z << endl;

        if (position.x >= 0.f && position.x <= 128.f &&
            position.y >= 0.f && position.y <= 128.f &&
            position.z >= 0.f && position.z <= 128.f)
        {
            position -= view * (float)dt;
        }

        if (position.x > 128.f)
        {
            position.x -= 1.f;
        }

        if (position.x < 0.f)
        {
            position.x += 1.f;
        }

        if (position.y > 128.f)
        {
            position.y -= 1.f;
        }

        if (position.y < 0.f)
        {
            position.y += 1.f;
        }

        if (position.z > 128.f)
        {
            position.z -= 1.f;
        }

        if (position.z < 0.f)
        {
            position.z += 1.f;
        }
    }


	//if (Application::IsKeyPressed('W'))
	//{
	//	//Vector3 view = (target - position).Normalized(); //Return a normalized.
	//	Vector3 view = target - position; //Return a normalized.
	//	view.Normalize();
	//	Vector3 right = view.Cross(up);
	//	right.Normalize();
	//	up = right.Cross(view);
	//	//up.Normalize(); No need because 90/270 degree
	//	float pitch = -40.f * dt;
	//	Mtx44 rotation;
	//	rotation.SetToRotation(pitch, right.x, right.y, right.z);
	//	position = rotation * position;
	//}

	//if (Application::IsKeyPressed('S'))
	//{
	//	Vector3 view = target - position; //Return a normalized.
	//	view.Normalize();
	//	Vector3 right = view.Cross(up);
	//	right.Normalize();
	//	up = right.Cross(view);
	//	float pitch = 40.f * dt;
	//	Mtx44 rotation;
	//	rotation.SetToRotation(pitch, right.x, right.y, right.z);
	//	position = rotation * position;
	//}

	//if (Application::IsKeyPressed('A'))
	//{
	//	float yaw = -40.f * dt;
	//	Mtx44 rotation;
	//	rotation.SetToRotation(yaw, 0, 1, 0);
	//	position = rotation * position;
	//	position.x -= 40.f * dt;
	//}

	//if (Application::IsKeyPressed('D'))
	//{
	//	float yaw = 40.f * dt;
	//	Mtx44 rotation;
	//	rotation.SetToRotation(yaw, 0, 1, 0);
	//	position.x += 40.f * dt;
	//}

	//if (Application::IsKeyPressed('N'))
	//{
	//	Vector3 view = target - position;
	//	view.Normalize();
	//	position += view * 40.f * dt;
	//}

	//if (Application::IsKeyPressed('N'))
	//{
	//	Vector3 view = target - position;
	//	view.Normalize();
	//	position -= view * 40.f * dt;
	//}
}