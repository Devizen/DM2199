#include "Inventory.h"

Inventory::Inventory():
inventorydefined(0),
listposition(0),
activeItem(NULL),
secondaryItem(NULL),
display1(NULL),
display2(NULL),
pointer(0)
{
}

Inventory::~Inventory()
{
}

int Inventory::getdefined()
{
	return inventorydefined;
}

void Inventory::setdefined(int a)
{
	inventorydefined = a;
}

void Inventory::setActiveItem(ItemInfo* activeItem)
{
	this->activeItem = activeItem;
}

ItemInfo* Inventory::getActiveItem()
{
	return activeItem;
}

void Inventory::addItem(ItemInfo* newItem)
{
	itemList.push_back(newItem);
	if (getDisplay1() == NULL)
	{
		display1 = newItem;
	}
	else if (getDisplay1() != NULL)
	{
		if (getDisplay2() == NULL)
		{
			display2 = newItem;
		}
		else
		{
			display1 = display2;
			display2 = newItem;

			listposition++;
		}
	}

	if (getActiveItem() == NULL)
	{
		activeItem = newItem;
	}
	else if (getActiveItem() != NULL && getSecondaryItem() == NULL)
	{
		secondaryItem = newItem;
	}
}

ItemInfo* Inventory::getDisplay1()
{
	return display1;
}
ItemInfo* Inventory::getDisplay2()
{
	return display2;
}
void Inventory::CycleDisplay(bool direction)
{
	if (direction) //go up
	{
		if (pointer)
		{
			pointer = false;
		}
		else
		{
			if (listposition > 0)
			{
				int counter = 0;
				listposition -= 1;
				//call function 
				vector<ItemInfo*>::iterator it = itemList.begin();
				while (counter < listposition)
				{
					it++;
					counter++;
				}
				display2 = display1;
				display1 = (*it);
			}
		}
	}
	else //go down
	{
		if (!pointer)
		{
			pointer = true;
		}
		else
		{
			if (listposition + 2 < itemList.size())
			{
				int counter = 0;
				listposition += 1;
				//call function
				vector<ItemInfo*>::iterator it = itemList.begin();
				while (counter <= listposition)
				{
					it++;
					counter++;
				}
				display1 = display2;
				display2 = (*it);
			}
		}
	}
}

void Inventory::equipItem(bool active)
{
	if (active) // equip active item
	{
		if (!pointer && getSecondaryItem() != display1)
			setActiveItem(display1);
		else if (getSecondaryItem() != display2)
			setActiveItem(display2);
	}
	else  // equip secondary item
	{
		if (!pointer && getActiveItem() != display1)
			setSecondaryItem(display1);
		else if (getActiveItem() != display2)
			setSecondaryItem(display2);
	}
}

void Inventory::setSecondaryItem(ItemInfo* secondary)
{
	secondaryItem = secondary;
}

ItemInfo* Inventory::getSecondaryItem()
{
	return secondaryItem;
}