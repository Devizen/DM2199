#include "FactoryObject.h"
#include <algorithm>

FactoryObject::FactoryObject()
{
}
FactoryObject::~FactoryObject()
{
	for (auto &i : Container)
		delete i;

}

void FactoryObject::createFactoryObject(Object* obj)
{
	Container.push_back(obj);
}

void FactoryObject::destroyFactoryObject(Object* obj)
{
	// remove all elements with the value obj
	validateIterator(Container.erase(std::remove(Container.begin(), Container.end(), obj),
		Container.end()));


	delete obj; // de-allocate memory
}


void FactoryObject::processInteraction()
{
	objIterator = Container.begin();

	//Run the iterator to process the interaction
	for (objIterator; objIterator != Container.end();)
	{
		(*objIterator)->interact();

		if (!_iteratorUpdated) // vector.erase() is not called
		{
			++objIterator;
		}
		else
		{
			// skip increment since vector.erase() already returned the value of the next valid iterator
			_iteratorUpdated = false;
		}
	}

}


void FactoryObject::validateIterator(std::vector<Object*>::iterator it)
{
	objIterator = it;
	_iteratorUpdated = true;

}

void FactoryObject::renderFactoryObject()
{

	for (std::vector<Object*>::iterator it = Container.begin(); it != Container.end(); ++it)
	{
		(*it)->objectRender();

	}
}

