#ifndef BULLET_H
#define BULLET_H


#include "Object.h"

class SceneBase;

class Bullet : public Object
{
public:
	Bullet(SceneBase* scene, Vector3 pos);
	~Bullet();

	virtual void interact();

private:
	Vector3 _defaultPosition;
	float _defaultYaw;
	const float _maxDistance = 40;

};


#endif