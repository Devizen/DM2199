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
	};


	Spider(float, float, float, float,SceneBase * scene);
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

	void setRange(float);
	float getRange();


	virtual void setState(int);
	virtual int getState();

	void update();

	bool inRange = false;
	
private:
	spiderState _State;
	SceneBase * _scene;

};


