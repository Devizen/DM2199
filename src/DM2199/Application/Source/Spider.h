#pragma once 

#include "Enemy.h"
#include "SceneBase.h"

class Spider: public Enemy
{
public:
	enum spiderState
	{
		patrolling,
		chasing,
		death,
		attack,
	};


	Spider(float, float, float, float);
	~Spider();

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

	//Jumping
	bool jump = false;
	bool fall = false;
	float jumpHeight = 20;

	//Poison
	bool poisoned = false;

	void setRange(float);
	float getRange();


	virtual void setState(int);
	virtual int getState();

	void update();

	bool inRange = false;

	//Get DT
	static void dtFromScene(double dt);
	static void positionFromCamera(Camera3 pos);
	
private:
	spiderState _State;
	Tutorial * _scene;

};


