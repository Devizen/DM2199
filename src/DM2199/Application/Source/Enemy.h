#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include "Vector3.h"
#include "WaypointManager.h"
#include "Camera3.h"

using std::vector;

class Enemy    // Abstract class
{
public:
	Enemy(float, float, float, float);
	virtual ~Enemy(){ enemyCount--; };
  
	virtual void update()=0;
	static unsigned enemyCount;

	const float _interactDistance = 40.0f;

	virtual void addWaypoint(Vector3) = 0;
	virtual void movetoWaypoint(double dt) = 0;
	WaypointManager* WPManager;
	Waypoint* currWaypoint;



	virtual void setState(int) =0;
	virtual int getState() =0;

	Camera3 camera;


	///-----------Variables--------- (will be passed down to derived class)
    float _MovementSpeed;
	float _Damage;
	float _Hp;
	float _Range;
	Vector3 _Position;
	float   _Rotation;

	unsigned enemytype = 0;  // <------  used to identify which TYPE of enemy it is
	unsigned robotType = 0;  // <------ used to identify which TYPE of robot it is

	float healthBarSpider = 10.f;
	float healthBarRobot1 = 20.f;
};





#endif