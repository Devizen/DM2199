#include "SceneBase.h"
#include "Enemy.h"

unsigned Enemy::enemyCount = 0;

Enemy::Enemy(float speed, float damage, float hp, float range)
    :_MovementSpeed(speed), _Damage(damage), _Hp(hp), _Range(range)

{
	enemyCount++;
	WPManager = new WaypointManager();
}


