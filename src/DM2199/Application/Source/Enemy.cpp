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
		_MovementSpeed = 70;
		_Damage = 10;
		_Hp = 10;
		_Range = 100;
		_State = spider_patrol;
	}
	}

	/*scale = 10;*/
	enemyCount++;

	WPManager = new WaypointManager();
}

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

void Enemy::addWaypoint(Vector3 WPposition)
{
	WPManager->addWaypoint(WPposition);

	if (WPManager->WaypointList.size() == 1)
	{
		vector<Waypoint*>::iterator it = WPManager->WaypointList.begin();
		currWaypoint = (*it);
	}
}
void Enemy::movetoWaypoint(double dt)
{
	if (currWaypoint != NULL)
	{
		if ((_Position - currWaypoint->getPosition()).Length() > 16)
		{
			Vector3 distance = (_Position - currWaypoint->getPosition());
			Vector3 unitDistance = distance.Normalized();

			float moveX = unitDistance.x * _MovementSpeed * dt;
			float moveZ = unitDistance.z * _MovementSpeed * dt;

			// Rotate the enemy towards the player
			//(*it)->_Rotation = -Math::RadianToDegree(atan2(distance.z, distance.x));

			// Move the Enemy
			_Position.x -= moveX;
			_Position.z -= moveZ;
		}
		else
		{
			if (currWaypoint->getNextWaypoint() == NULL)
			{
				vector<Waypoint*>::iterator it = WPManager->WaypointList.begin();
				currWaypoint = (*it);
			}
			else
			{
				currWaypoint = currWaypoint->getNextWaypoint();
			}
		}
	}
<<<<<<< HEAD
  
}

bool Enemy::damageDealt(float posX, float posZ)
{
    if ((this->position_.x - 15 < posX && 
        this->position_.x + 15 > posX) &&
        (this->position_.z - 15 < posZ &&
        this->position_.z + 15 > posZ))
    {
        return true;
    }
    else
    {
        return false;
    }
=======
>>>>>>> origin/master
}