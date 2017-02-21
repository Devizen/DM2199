#include "Bullet.h"
#include "Levels\Tutorial.h"


Bullet::Bullet(Tutorial* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

	type = Tutorial::GEO_LIGHTBALL3;
	_defaultYaw = _scene->camera.getYaw();
	_defaultPitch = _scene->camera.getPitch();
	_defaultPosition = pos;
	scale = 5;
	rotateY = -rotateYaw;
	rotateZ = rotatePitch;

}

Bullet::~Bullet()
{
}

void Bullet::interact(){


	position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);
	position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * _scene->_dt);
	position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);



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

