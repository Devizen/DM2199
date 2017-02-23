#ifndef OBJECT_H
#define OBJECT_H

#include "Vector3.h"
#include "Camera3.h"
#include <vector>

class Tutorial;
class Level1;
class Level2;
class Level3;
class Level4;
class Boss;

class Object
{
public:
	Object(Tutorial* scene, Vector3 pos) : _scene(scene), position_(pos){};
    Object(Level1* scene, Vector3 pos) : level1(scene), position_(pos){};
    Object(Level2* scene, Vector3 pos) : level2(scene), position_(pos){};
    Object(Level3* scene, Vector3 pos) : level3(scene), position_(pos){};
    Object(Level4* scene, Vector3 pos) : level4(scene), position_(pos){};
    Object(Boss* scene, Vector3 pos) : boss(scene), position_(pos){};
	Object(Vector3 pos) : position_(pos){};
	virtual ~Object(){};

	virtual void interact() = 0; // update
	virtual void objectRender();

	/*Camera3 camera;*/

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

protected:
	Tutorial * _scene;
    Level1 * level1;
    Level2 * level2;
    Level3 * level3;
    Level4 * level4;
    Boss * boss;
};
#endif