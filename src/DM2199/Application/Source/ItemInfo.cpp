#include "ItemInfo.h"

ItemInfo::ItemInfo() :
type("fist"),
damage(10),
range(10),
reloadspeed(0),
attackspeed(5)
{
}

ItemInfo::~ItemInfo()
{
}

ItemInfo::ItemInfo(string type, int damage, float range, float reloadspeed,
	float attackspeed)
{
	this->type = type;
	this->damage = damage;
	this->range = range;
	this->reloadspeed = reloadspeed;
	this->attackspeed = attackspeed;
}

string ItemInfo::gettype()
{
	return type;
}