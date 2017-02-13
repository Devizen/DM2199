#include "Bullet.h"
#include "SceneBase.h"


Bullet::Bullet(SceneBase* scene, Vector3 pos) : Object(scene, pos)
{

	type = SceneBase::GEO_LIGHTBALL3;
	_defaultYaw = _scene->camera.getYaw();
	_defaultPitch = _scene->camera.getPitch();
	_defaultPosition = pos;


}

Bullet::~Bullet()
{
}

void Bullet::interact(){


	position_.x += (float)(50 * cos(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);
	position_.y += (float)(50 * tan(Math::DegreeToRadian(_defaultPitch)) * _scene->_dt);
	position_.z += (float)(50 * sin(Math::DegreeToRadian(_defaultYaw))* _scene->_dt);

	rotateY = _scene->camera.getPitch();

	//Delete bullet once it reachs max distance
	if ((_defaultPosition - position_).Length() >= _maxDistance) {
		_scene->objFactory.destroyFactoryObject(this);
		return;
	}

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


	for (std::vector<Object*>::iterator it = _scene->objFactory.Container.begin(); it != _scene->objFactory.Container.end(); ++it)
	{

		if ((*it)->objectType.size() > 0 ){

			if  (((*it)->position_ - position_).Length() < 40)
			_scene->objFactory.destroyFactoryObject(*it);

		}

	}

}

