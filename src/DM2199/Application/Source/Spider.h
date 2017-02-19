#pragma once 

#include "Enemy.h"

class Spider: public Enemy
{
public:
	enum spiderState
	{
		patrolling,
		chasing,
	};


	Spider();
	Spider(float , float ,int, float);
	~Spider();

	//Setters and Getters for movement speed
	void setMovementSpeed(float);
	float getMovementSpeed();

	//Setters and Getters for damage
	void setDamage(float);
	float getDamage();

	//Setter and Getters for hp
	void setHp(int);
	int  getHp();

	void setSpiderState(spiderState);
	spiderState getSpiderState();

	void update();

	bool inRange = false;

private:
	spiderState _State;
	float _MovementSpeed;// Movement speed
	float _Damage;
	float _Hp;
	Vector3 _Point;
	float _Range;

};


