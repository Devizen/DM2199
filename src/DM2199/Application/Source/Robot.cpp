#include "Robot.h"
#include "MyMath.h"

static double copyDT = 0.f;
static Camera3 copyPos;

Robot::Robot(float speed, float damage, float hp, float range, int typeRobot)
	:Enemy(speed, damage, hp, range)
{
	enemytype = 2;
	robotType = typeRobot;

	_State = Robot::robotState::patrolling;

}




void Robot::update()
{
	if (_Hp <= 0)
	{
		_State = death;
	}

	switch (_State)
	{
	case patrolling:
	{
		movetoWaypoint(copyDT); //  move from one waypoint to another ,return to current waypoint
		//  after character goes out of range
		/*cout << "Position: " << _Position << endl;*/

		if ((_Position - copyPos.getPosition()).Length() < getRange())
		{
			_State = Robot::robotState::chasing;
		}
	}
	break;
	case chasing:
	{
		//distance between character and  enemy
		Vector3 distance = (_Position - copyPos.position);
        Vector3 unitDistance = distance.Normalized(); 
     /*   try
        {*/
		//unitDistance = distance.Normalized();
        //}
        //catch (DivideByZero what)
        //{
        //    /*cout << what.what() << endl;*/
        //}

		float moveX = unitDistance.x * getMovementSpeed()* copyDT;
		float moveZ = unitDistance.z * getMovementSpeed()* copyDT;

		// Rotate the enemy towards the player
		_Rotation = -Math::RadianToDegree(atan2(distance.z, distance.x));

		// Move the Enemy
		_Position.x -= moveX;
		_Position.z -= moveZ;

		if ((_Position - copyPos.getPosition()).Length() > getRange())
		{
			_State = Robot::robotState::patrolling;
		}
		else if (_Hp <= 25)
		{
			_State = Robot::robotState::escaping;
		}
	}
	break;
	case death:
	{
		
	}
	break;
	case escaping:
	{
		//distance between character and  enemy
		Vector3 distance = (_Position - copyPos.getPosition());
		Vector3 unitDistance = distance.Normalized();

		float moveX = unitDistance.x * getMovementSpeed()*copyDT;
		float moveZ = unitDistance.z * getMovementSpeed()*copyDT;

		// Rotate the enemy towards the player
		/*_Rotation = Math::RadianToDegree(atan2(distance.z, distance.x));
*/
		// Move the Enemy
		if ((_Position - copyPos.getPosition()).Length() < getRange())
		{
			_Position.x += moveX;
			_Position.z += moveZ;
		}
		else
		{
			_State = Robot::robotState::patrolling;
		}

	
	}
	break;
	}

}


void Robot::dtFromScene(double dt)
{
	copyDT = dt;
}

void Robot::positionFromCamera(Camera3 pos)
{
	copyPos = pos;
}


Robot::~Robot()
{

}

void Robot::setDamage(float dam)
{
	_Damage = dam;
}

float  Robot::getDamage()
{
	return _Damage;
}

void Robot::setMovementSpeed(float spee)
{
	_MovementSpeed = spee;
}

float Robot::getMovementSpeed()
{
	return _MovementSpeed;
}

void Robot::setHp(float hea)
{
	_Hp = hea;
}

float Robot::getHp()
{
	return _Hp;
}

void Robot::setRange(float ran)
{
	_Range = ran;
}

float Robot::getRange()
{
	return _Range;
}


void  Robot::setState(int value)
{
	_State = static_cast<robotState> (value);
}

int Robot::getState()
{
	return _State;
}

void Robot::addWaypoint(Vector3 WPposition)
{
	WPManager->addWaypoint(WPposition);

	if (WPManager->WaypointList.size() == 1)
	{
		vector<Waypoint*>::iterator it = WPManager->WaypointList.begin();
		currWaypoint = (*it);
	}
}
void Robot::movetoWaypoint(double dt)
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