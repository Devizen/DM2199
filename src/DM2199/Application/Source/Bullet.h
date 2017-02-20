#ifndef BULLET_H
#define BULLET_H


#include "Object.h"


class SceneBase;

class Bullet : public Object
{
public:
	Bullet(SceneBase* scene, Vector3 pos, float rotateYaw,float rotatePitch);
	~Bullet();

	virtual void interact();

private:
	Vector3 _defaultPosition;
	float _defaultYaw;
	float _defaultPitch;
	const float _maxDistance = 40;
	const float bulletSpeed = 150.0f;
	


};


#endif