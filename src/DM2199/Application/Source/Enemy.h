#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include "Vector3.h"
#include "WaypointManager.h"

using std::vector;

class Enemy
{
public:
	enum enemyType
	{
		spider = 0,
		robot1,
		robot2,
		robot3,
		robot4,
	};

	enum enemyState
	{
		spider_patrol,
		spider_chase
	};
	Enemy();
	Enemy(enemyType);
	virtual ~Enemy(){ enemyCount--; };

	void update();
	static unsigned enemyCount;

	//void setEnemyType(enemyType value);
	//enemyType getEnemyType();

	//Setters and Getters for movement speed
	void setMovementSpeed(float);
	float getMovementSpeed();

	//Setters and Getters for damage
	void setDamage(float);
	float getDamage();

	//Setter and Getters for hp
	void setHp(int);
	int  getHp();

	const float _interactDistance = 40.0f;

	void setRange(float);
	float getRange();

	Vector3 _Position;
	float   _Rotation;

	enemyState _State;
	enemyType _Type;

	void addWaypoint(Vector3);
	void movetoWaypoint(double dt);
	WaypointManager* WPManager;
	Waypoint* currWaypoint;
private:
    float _MovementSpeed;// Movement speed
	float _Damage;
	float _Hp;
	
	
	float _Range;
	
};





#endif