#pragma once

#include "Waypoint.h"

#include <vector>
#include "Vector3.h"

using namespace::std;

class WaypointManager
{
public:
	WaypointManager();
	~WaypointManager();

	void addWaypoint(Vector3);
	void WaypointUpdate();

	vector<Waypoint*> WaypointList;
};