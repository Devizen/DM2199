#include "Bullet.h"
#include "Levels\Tutorial.h"
#include "Levels/Level1.h"
#include "Levels/Level2.h"
#include "Levels/Level3.h"
#include "Levels/Level4.h"
#include "Levels/Boss.h"


Bullet::Bullet(Tutorial* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

	type = Tutorial::GEO_LIGHTBALL3;
	_defaultYaw = _scene->camera.getYaw();
	_defaultPitch = _scene->camera.getPitch();
	_defaultPosition = pos;
	scale = 5;
	rotateY = -rotateYaw;
	rotateZ = rotatePitch;

	mingxiue26rox = false;
}
Bullet::Bullet(Tutorial* scene ,Vector3 pos) :Object(scene, pos)
{
	_defaultPosition = pos;
	type = Tutorial::GEO_LIGHTBALL2;
	scale = 5;

	mingxiue26rox = true;
}

Bullet::Bullet(Level1* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = Level1::GEO_LIGHTBALL3;
    _defaultYaw = _scene->camera.getYaw();
    _defaultPitch = _scene->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Level1* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = Level1::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::Bullet(Level2* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = Level2::GEO_LIGHTBALL3;
    _defaultYaw = _scene->camera.getYaw();
    _defaultPitch = _scene->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Level2* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = Level2::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::Bullet(Level3* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = Level3::GEO_LIGHTBALL3;
    _defaultYaw = _scene->camera.getYaw();
    _defaultPitch = _scene->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Level3* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = Level3::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::Bullet(Level4* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = Level4::GEO_LIGHTBALL3;
    _defaultYaw = _scene->camera.getYaw();
    _defaultPitch = _scene->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Level4* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = Level4::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::Bullet(Boss* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = Boss::GEO_LIGHTBALL3;
    _defaultYaw = _scene->camera.getYaw();
    _defaultPitch = _scene->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Boss* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = Boss::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::~Bullet()
{
}

void Bullet::interact(){


	if (mingxiue26rox == false)
	{
		position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);
		position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * _scene->_dt);
		position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);

	}

	if (mingxiue26rox == true)
	{
		Vector3 distance = (_defaultPosition - _scene->camera.getPosition());
		Vector3 unitDistance = distance.Normalized();
		float moveX = unitDistance.x * bulletSpeed* _scene->_dt;
		float moveZ = unitDistance.z * bulletSpeed* _scene->_dt;

		// Rotate the enemy towards the player
		rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

		// Move the Enemy
		position_.x -= moveX;
		position_.z -= moveZ;
	}
	//Delete bullet once it reachs max distance
	//if ((_defaultPosition - position_).Length() >= _maxDistance) {
	//	_scene->objFactory.destroyFactoryObject(this);
	//	return;
	//}

	
	
	for (vector<Enemy*>::iterator itEnemy = _scene->enemyStorage.begin(); itEnemy != _scene->enemyStorage.end(); itEnemy++)
	{
		if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
		{
			_scene->objFactory.destroyFactoryObject(this);
			return;
		}
		
	}
	//	

	//for (std::vector<Object*>::iterator it = _scene->objFactory.Container.begin(); it != _scene->objFactory.Container.end(); ++it)
	//{

	//	if ((*it)->type == SceneBase::GEO_ROCK && ((*it)->position_ - position_).Length() < 5){
	//		(*it)->scale -= 0.2f* _scene->_dt;

	//		if ((*it)->scale <= 0.2f) {
	//			_scene->objFactory.destroyFactoryObject(*it);
	//		}
	//	}  // *it points to all the object , use objectType size to  identify that it is enemy
	//	else if ((*it)->objectType.size() > 0 && (*it)->objectType[1] == SceneBase::GEO_ENEMYTORSO)
	//	{
	//		if (((*it)->position_ - position_).Length() < 5)
	//		{
	//			_scene->objFactory.destroyFactoryObject(*it);
	//		}
	//	}
	//}



}

