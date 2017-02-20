#include "WaypointManager.h"

WaypointManager::WaypointManager(){}

WaypointManager::~WaypointManager(){}

void WaypointManager::addWaypoint(Vector3 newPosition)
{
	if (WaypointList.size() < 1)
	{
		Waypoint* addThis = new Waypoint(newPosition);
		WaypointList.push_back(addThis);
	}
	else
	{
		Waypoint* addThis = new Waypoint(newPosition);
		vector<Waypoint*>::iterator it = WaypointList.begin();
		for (it; it != WaypointList.end(); it++)
		{
			if ((*it)->getNextWaypoint() == NULL)
			{
				(*it)->setNextWaypoint(addThis);
			}
		}
		WaypointList.push_back(addThis);
	}
}

void WaypointManager::WaypointUpdate()
{

}