#ifndef BULLET_H
#define BULLET_H


#include "Object.h"


class Tutorial;
class Level1;
class Level2;
class Level3;
class Level4;
class Boss;
class SceneEditor;

class Bullet : public Object
{
public:
	Bullet(Tutorial* scene, Vector3 pos, float rotateYaw, float rotatePitch);
	Bullet(Tutorial* scene, Vector3 pos);

    Bullet(Level1* sceneLevel1, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level1* sceneLevel1, Vector3 pos);

    Bullet(Level2* sceneLevel2, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level2* sceneLevel2, Vector3 pos);

    Bullet(Level3* sceneLevel3, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level3* sceneLevel3, Vector3 pos);

    Bullet(Level4* sceneLevel4, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Level4* sceneLevel4, Vector3 pos);
                        
    Bullet(Boss* sceneBoss, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(Boss* sceneBoss, Vector3 pos);

    Bullet(SceneEditor* sceneBoss, Vector3 pos, float rotateYaw, float rotatePitch);
    Bullet(SceneEditor* sceneBoss, Vector3 pos);

	~Bullet();

	virtual void interact();

    static void sceneBullet(unsigned input);

private:
	Vector3 _defaultPosition;
	float _defaultYaw;
	float _defaultPitch;

	const float _maxDistance = 1000.f;
	const float bulletSpeed = 600.0f;

	bool mingxiue26rox = false;
	


};


#endif