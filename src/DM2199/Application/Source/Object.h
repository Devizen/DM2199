#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3.h"
#include "Camera3.h"
#include <vector>

class SceneBase;

class Object
{
public:
	Object(SceneBase* scene, Vector3 pos) : _scene(scene), position_(pos){};
	virtual ~Object(){};

	virtual void interact() = 0; // update
	virtual void objectRender();

	Camera3 camera;

	Vector3 position_;
	float scale = 1;
	float rotateX = 0;
	float rotateY = 0;
	float rotateZ = 0;

	float sizeX = 1;
	float sizeY = 1;
	float translateX = 0;
	float translateY = 0;

	unsigned type = 0;


	std::vector <unsigned> objectType;  // to handle multiple obj parts
protected:
	SceneBase * _scene;
};
#endif