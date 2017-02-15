#include "SceneBase.h"
#include "Enemy.h"

unsigned Enemy::enemyCount = 0;


Enemy::Enemy(SceneBase * scene, Vector3 pos) : Object(scene, pos)
{
	objectType = { SceneBase::GEO_ENEMYHEAD, SceneBase::GEO_ENEMYLEFTARM,
		SceneBase::GEO_ENEMYRIGHTARM, SceneBase::GEO_ENEMYLEFTLEG,
	SceneBase::GEO_ENEMYRIGHTLEG,SceneBase::GEO_ENEMYTORSO };
		


	scale = 10;
	enemyCount++;
}

void Enemy::interact()
{
	// distance between character and  enemy
	Vector3 distance = (position_ - _scene->camera.position);
	Vector3 unitDistance = distance.Normalized();

	float moveX = unitDistance.x * _MovementSpeed * _scene->_dt;
	float moveZ = unitDistance.z * _MovementSpeed * _scene->_dt;

	// Rotate the enemy towards the player
	rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

	// Move the Enemy
	position_.x -= moveX;
	position_.z -= moveZ;

	if ((position_ - _scene->camera.getPosition()).Length() <= _interactDistance)
	{
		meshscreenType = SceneBase::GEO_FLICKER;
		isFlicker = true;
	}
  
}