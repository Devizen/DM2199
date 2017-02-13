#ifndef ENEMY_H
#define ENEMY_H

#include "Object.h"


class Enemy : public Object
{
public:
	Enemy(SceneBase * scene, Vector3 pos);
	~Enemy(){ enemyCount--; };

	virtual void interact();
	static unsigned enemyCount;

private:
	const float _MovementSpeed = 20.5f; // Movement speed
};





#endif