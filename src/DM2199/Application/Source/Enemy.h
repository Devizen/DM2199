#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"


class Enemy : public Object
{
public:
	Enemy(SceneBase * scene, Vector3 pos);
    Enemy();
	~Enemy(){ enemyCount--; };

    bool damageDealt(float posX, float posZ);

	virtual void interact();
	static unsigned enemyCount;

	const float _interactDistance = 100.0f;

private:
	const float _MovementSpeed = 20.5f; // Movement speed
};





#endif