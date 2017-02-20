#pragma once

#include <vector>
#include "Vector3.h"

class Waypoint
{
public:
	Waypoint();
	~Waypoint();

	Waypoint(Vector3);

	Vector3 getPosition();
	Waypoint* getNextWaypoint();

	void setNextWaypoint(Waypoint*);
private:
	Waypoint* nextWaypoint;

	Vector3 _position;
};