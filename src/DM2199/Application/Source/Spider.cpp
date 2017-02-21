#include "Spider.h"



static double copyDT = 0.f;
static Camera3 copyPos;

Spider::Spider(float speed, float damage, float hp, float range)
	:Enemy(speed, damage, hp, range)
{
	enemytype = 1;
	_State = Spider::spiderState::patrolling;

}


void Spider::dtFromScene(double dt)
{
	copyDT = dt;
}

void Spider::positionFromCamera(Camera3 pos)
{
	copyPos = pos;
}

void Spider::update()
{
	switch (_State)
	{
	case patrolling:
	{

		movetoWaypoint(copyDT); //  move from one waypoint to another ,return to current waypoint
		//  after character goes out of range


//<<<<<<< 6931c871721755c46b9251c0acede3809e30716d
		jump = false;
		fall = false;

//<<<<<<< a8973e63e76c62b26e6400ab8c5478b5597fe6d8
//		if ((_Position - _scene->camera.getPosition()).Length() < getRange())
//=======
		if ((_Position - _spiderScene->camera.getPosition()).Length() < getRange())
//>>>>>>> 5763ed7c9efd901a1fd7526044c1c177504c2698
//=======
		if ((_Position - copyPos.getPosition()).Length() < getRange())
//>>>>>>> 48b8361c306e892cf119d9de053f2e6d8ebdbe3e

		movetoWaypoint(_spiderScene->_dt); //  move from one waypoint to another ,return to current waypoint

		movetoWaypoint(copyDT); //  move from one waypoint to another ,return to current waypoint

		//  after character goes out of range
		


		if ((_Position - _spiderScene->camera.getPosition()).Length() < getRange())


		//if ((_Position - copyPos.getPosition()).Length() < getRange())

		{
			_State = Spider::spiderState::chasing;
		}
	}
	break;
	case chasing:
	{
		//distance between character and  enemy

//<<<<<<< ab62977ce1a25f1f6550dd79e35774ee2fcefc9e
		Vector3 distance = (_Position - copyPos.position);
		Vector3 unitDistance = distance.Normalized();
		float moveX = unitDistance.x * getMovementSpeed()* copyDT;
		float moveZ = unitDistance.z * getMovementSpeed()* copyDT;
//=======
		Vector3 distance = (_Position - _spiderScene->camera.position);
		Vector3 unitDistance = distance.Normalized();

		float moveX = unitDistance.x * getMovementSpeed()*_spiderScene->_dt;
		float moveZ = unitDistance.z * getMovementSpeed()*_spiderScene->_dt;

		float moveDistanceX = distance.x *getMovementSpeed()*_spiderScene->_dt;
		float moveDistanceZ = distance.z * getMovementSpeed()*_spiderScene->_dt;
//>>>>>>> 5763ed7c9efd901a1fd7526044c1c177504c2698

		//Vector3 distance = (_Position - copyPos.position);
		//Vector3 unitDistance = distance.Normalized();
		//float moveX = unitDistance.x * getMovementSpeed()* copyDT;
		//float moveZ = unitDistance.z * getMovementSpeed()* copyDT;


		// Rotate the enemy towards the player
		_Rotation = -Math::RadianToDegree(atan2(distance.z, distance.x));

		// Move the Enemy
		_Position.x -= moveX;
		_Position.z -= moveZ;


//<<<<<<< 6931c871721755c46b9251c0acede3809e30716d
/*<<<<<<< a8973e63e76c62b26e6400ab8c5478b5597fe6d8
		if ((_Position - _scene->camera.getPosition()).Length() > getRange())
=======*/
		

		if ((_Position - _spiderScene->camera.getPosition()).Length() > getRange())
//<<<<<<< ab62977ce1a25f1f6550dd79e35774ee2fcefc9e
//>>>>>>> 5763ed7c9efd901a1fd7526044c1c177504c2698
//=======
		if ((_Position - copyPos.getPosition()).Length() > getRange())
//>>>>>>> 48b8361c306e892cf119d9de053f2e6d8ebdbe3e
//=======
//>>>>>>> 5763ed7c9efd901a1fd7526044c1c177504c2698

		{
			_State = Spider::spiderState::patrolling;
		}

		else if ((_Position - _scene->camera.getPosition()).Length() > (getRange() - 15))
		{
			_State = Spider::spiderState::attack;
		}

	}
	break;
	case death:
	{
		
	}
	break;
	case attack:
	{
		//distance between character and  enemy
		Vector3 distance = (_Position - _scene->camera.position);
		Vector3 unitDistance = distance.Normalized();

		float moveX = unitDistance.x * getMovementSpeed()*_scene->_dt;
		float moveZ = unitDistance.z * getMovementSpeed()*_scene->_dt;

		if ((_Position - _scene->camera.getPosition()).Length() > (getRange() - 15))
			jump = true;

		if (jump == true)
		{
			_Position.y += 1.f * (float)(getMovementSpeed()*_scene->_dt);
		}

		if (_Position.y > jumpHeight)
		{
			jump = false;
			fall = true;
		}

		if (fall == true)
		{
			_Position.y -= 1.f * (float)(getMovementSpeed()*_scene->_dt);
		}

		if (_Position.y < 0)
		{
			_Position.y = 0;
		}

		// Rotate the enemy towards the player
		_Rotation = -Math::RadianToDegree(atan2(distance.z, distance.x));

		// Move the Enemy
		_Position.x -= moveX;
		_Position.z -= moveZ;	

		if ((_Position - _scene->camera.getPosition()).Length() > getRange())
		{
			_State = Spider::spiderState::patrolling;
		}
	}
	break;
	}
}





Spider::~Spider()
{

}

void Spider::setDamage(float dam)
{
	_Damage = dam;
}

float  Spider::getDamage()
{
	return _Damage;
}

void Spider::setMovementSpeed(float spee)
{
	_MovementSpeed = spee;
}

float Spider::getMovementSpeed()
{
	return _MovementSpeed;
}

void Spider::setHp(float hea)
{
	_Hp = hea;
}

float Spider::getHp()
{
	return _Hp;
}

void Spider::setRange(float ran)
{
	_Range = ran;
}

float Spider::getRange()
{
	return _Range;
}


void  Spider::setState(int value)
{
	_State = static_cast<spiderState> (value);
}

int Spider::getState()
{
	return _State;
}

void Spider::addWaypoint(Vector3 WPposition)
{
	WPManager->addWaypoint(WPposition);

	if (WPManager->WaypointList.size() == 1)
	{
		vector<Waypoint*>::iterator it = WPManager->WaypointList.begin();
		currWaypoint = (*it);
	}
}
void Spider::movetoWaypoint(double dt)
{
	if (currWaypoint != NULL)
	{
		if ((_Position - currWaypoint->getPosition()).Length() > 16)
		{
			Vector3 distance = (_Position - currWaypoint->getPosition());
			Vector3 unitDistance = distance.Normalized();

			float moveX = unitDistance.x * _MovementSpeed * dt;
			float moveZ = unitDistance.z * _MovementSpeed * dt;

			//// Rotate the enemy towards the player
			_Rotation = -Math::RadianToDegree(atan2(distance.z, distance.x));

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
}