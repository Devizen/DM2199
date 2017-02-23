#pragma once
#include "ItemInfo.h"
#include <iostream>
#include <vector>

using namespace::std;

class Inventory
{
public:
	Inventory();
	~Inventory();

	int getdefined();
	void setdefined(int a);
	
	void setActiveItem(ItemInfo*);
	ItemInfo* getActiveItem();

	void setSecondaryItem(ItemInfo*);
	ItemInfo* getSecondaryItem();

	ItemInfo* getDisplay1();
	ItemInfo* getDisplay2();

	void addItem(ItemInfo*);
	void CycleDisplay(bool direction);
	
	void equipItem(bool active);

	vector<ItemInfo*> itemList;
	bool pointer;
	int listposition;
    bool sidepointer;

private:
	
	ItemInfo* display1;
	ItemInfo* display2;

	ItemInfo* activeItem;
	ItemInfo* secondaryItem;

	int inventorydefined;
};