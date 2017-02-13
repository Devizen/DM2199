#ifndef FACTORYOBJECT_H
#define FACTORYOBJECT_H
#include "Bullet.h"
#include "Application.h"
#include <vector>

class FactoryObject
{
public:
	FactoryObject();
	~FactoryObject();
	void createFactoryObject(Object*);
	void destroyFactoryObject(Object *);
	void renderFactoryObject();
	void processInteraction();

	std::vector<Object*> Container;

	// Updates the current iterator, used when a element is deleted from the vector
	void validateIterator(std::vector<Object*>::iterator it);

private:
	std::vector<Object*>::iterator objIterator;
	bool _iteratorUpdated = false;
};

#endif 