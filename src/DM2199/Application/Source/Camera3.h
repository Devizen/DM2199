#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Camera3 : public Camera
{
    friend class SceneEditor;
	friend class Tutorial;
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Camera3();
	~Camera3();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	virtual void Reset();
	void preventXZOver();
    void resetDirectionPressed();
    void collisionCheck();

    //Jump
	bool jump = false;
    bool directionJump = false;
    bool fall = false;
    bool upPressed = false, downPressed = false, leftPressed = false, rightPressed = false;
    bool jumpStucked = false;

    //Camera View
    bool firstPerson = true;
    bool thirdPerson = false;
	
	float armRotate = 0.f;
    float mapSize = 4850.f;
    float jumpHeight = 25.f;


    //Messages Freeze Movement
    bool messageFreeze = false;


    //Collision Detection
    //Total Amount of Objects
    static unsigned const amountOfObjects = 5;

    //Previous position
    Vector3 prevPosCol = { 0.0f, 0.0f, 0.0f };

    Vector3 objectsMin[amountOfObjects];
    Vector3 objectsMax[amountOfObjects];

    //Sword
    bool swordCombined = false;

    //Lumber
    bool lumberCollected = false;

    //Portal
    bool portalUnlocked = false;
    bool enteredPortal = false;
    bool end = false;

    enum objects;

	float getPitch() { return pitch; };
	float getYaw() { return yaw; };
	Vector3 getPosition() { return position; };

	void ResetCursorVariables();

	int health = 500;
	int poisonTime = 0;
	bool poison = false;
	bool poisonText = false;

    int maxhealth = health;
private:
	//----------Mouse Variables -----------

	// Current angle of camera rotation
	float yaw;
	float pitch;
	// Mouse direction moved, possible values: -1, 0, 1
	double mouseMovedX;
	double mouseMovedY;

	// Distance the Cursor moved from the current and last frame. Used to determine mouse sensitivity
	float mouseMovedDistanceX;
	float mouseMovedDistanceY;

	// Updates the direction in which the cursor has moved
	void updateCursor();

	bool isMouseEnabled = true;

	// Maximum & Minimum height that the User can look
	float _MinYawAngle = -50.0f;
	float _MaxYawAngle = 50.0f;

	// Cursor's previous position
	double lastX = 0;
	double lastY = 0;

    //Collision Enabling and Disabling for Level Editor
    static void collisionSwitch(bool collisionInput, string levelInput);

    //Check if Pause Menu was called
    static void pauseCheck(bool input);

	
};

#endif