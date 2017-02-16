#include "SceneBase.h"
#include "Enemy.h"

unsigned Enemy::enemyCount = 0;

Enemy::Enemy()
{



}
Enemy::Enemy(Enemy ::enemyType typ)

{
	_Type = typ;
	switch (_Type)
	{
	case  spider:
	{
		_MovementSpeed = 10;
		_Damage = 10;
		_Hp = 10;
		_Range = 100;
		_State = spider_patrol;
	}
	}

	/*scale = 10;*/
	enemyCount++;
}

//void Enemy::interact()
//{
//	// distance between character and  enemy
//	Vector3 distance = (position_ - _scene->camera.position);
//	Vector3 unitDistance = distance.Normalized();
//
//	float moveX = unitDistance.x * _MovementSpeed * _scene->_dt;
//	float moveZ = unitDistance.z * _MovementSpeed * _scene->_dt;
//
//	// Rotate the enemy towards the player
//	rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));
//
//	// Move the Enemy
//	position_.x -= moveX;
//	position_.z -= moveZ;
//
//	if ((position_ - _scene->camera.getPosition()).Length() <= _interactDistance)
//	{
//		
//	}
//	else
//	{
//	
//	}
//  
//}


void Enemy::setDamage(float dam)
{
	_Damage = dam;
}

float   Enemy::getDamage()
{
	return _Damage;
}

void  Enemy::setMovementSpeed(float speed)
{
	_MovementSpeed = speed;
}

float  Enemy::getMovementSpeed()
{
	return _MovementSpeed;
}

void  Enemy::setHp(int health)
{
	_Hp = health;
}

int  Enemy::getHp()
{
	return _Hp;
}

float Enemy::getRange()
{
	return _Range;
}

void Enemy::setRange(float r)
{
	_Range = r;
}