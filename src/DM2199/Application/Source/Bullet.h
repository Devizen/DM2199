#ifndef BULLET_H
#define BULLET_H


#include "Object.h"


class Tutorial;
class Level1;
class Level2;
class Level3;
class Level4;
class Boss;

class Bullet : public Object
{
public:
	Bullet(Tutorial* scene, Vector3 pos, float rotateYaw, float rotatePitch);
	Bullet(Tutorial* scene, Vector3 pos);

    Bullet(Level1* scene, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level1* scene, Vector3 pos);

    Bullet(Level2* scene, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level2* scene, Vector3 pos);

    Bullet(Level3* scene, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level3* scene, Vector3 pos);

    Bullet(Level4* scene, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level4* scene, Vector3 pos);

    Bullet(Boss* scene, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Boss* scene, Vector3 pos);
	~Bullet();

	virtual void interact();

private:
	Vector3 _defaultPosition;
	float _defaultYaw;
	float _defaultPitch;

	const float _maxDistance = 1000.f;
	const float bulletSpeed = 600.0f;

	bool mingxiue26rox = false;
	


};


#endif