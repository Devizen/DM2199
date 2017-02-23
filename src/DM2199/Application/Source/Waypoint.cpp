#include "Waypoint.h"

Waypoint::Waypoint()
	:_position(0,0,0) //vector3
	, nextWaypoint(NULL)
{}

Waypoint::~Waypoint(){}

Waypoint::Waypoint(Vector3 _position)
{
	this->_position = _position;
	nextWaypoint = NULL;
}

Vector3 Waypoint::getPosition()
{
	return _position;
}

Waypoint* Waypoint::getNextWaypoint()
{
	return nextWaypoint;
}

void Waypoint::setNextWaypoint(Waypoint* next)
{
	nextWaypoint = next;
}