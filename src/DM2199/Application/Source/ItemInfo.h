#pragma once
#include <string>

using namespace::std;

class ItemInfo
{
public:
	ItemInfo();
	~ItemInfo();
	ItemInfo(string type, int damage, float range, float reloadspeed,
			 float attackspeed);

	int getdamage();
	string gettype();

	float getrange();
	float getreloadspeed();
	float getattackspeed();
private:
	int damage;
	string type;
	
	float range;
	float reloadspeed;
	float attackspeed;
};