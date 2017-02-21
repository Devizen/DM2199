#pragma once 

#include "Enemy.h"
#include "SceneBase.h"

class Robot : public Enemy
{
	friend class SceneBase;
public:
	enum robotState
	{
		patrolling,
		chasing,
		death,
		shooting,
	};

	Robot();
	Robot(float, float, float, float, int typeRobot );
	~Robot();

	virtual void addWaypoint(Vector3);
	virtual void movetoWaypoint(double dt);

	//Setters and Getters for movement speed
	void setMovementSpeed(float);
	float getMovementSpeed();

	//Setters and Getters for damage
	void setDamage(float);
	float getDamage();

	//Setter and Getters for hp
	void setHp(float);
	float  getHp();

	void setRange(float);
	float getRange();

	virtual void setState(int);
	virtual int getState();

	virtual void update();

	bool shoot = false;

	bool inRange = false;
	
	//Get DT
	static void dtFromScene(double dt);
	static void positionFromCamera(Camera3 pos);

private:
	robotState _State;
	

};