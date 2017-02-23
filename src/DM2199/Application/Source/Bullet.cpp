#include "Bullet.h"
#include "Levels\Tutorial.h"
#include "Levels/Level1.h"
#include "Levels/Level2.h"
#include "Levels/Level3.h"
#include "Levels/Level4.h"
#include "Levels/Boss.h"
#include "SceneEditor.h"

static unsigned scene = 0;

void Bullet::sceneBullet(unsigned input)
{
    scene = input;
}

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
    _defaultYaw = level1->camera.getYaw();
    _defaultPitch = level1->camera.getPitch();
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
    _defaultYaw = level2->camera.getYaw();
    _defaultPitch = level2->camera.getPitch();
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
    _defaultYaw = level3->camera.getYaw();
    _defaultPitch = level3->camera.getPitch();
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
    _defaultYaw = level4->camera.getYaw();
    _defaultPitch = level4->camera.getPitch();
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
    _defaultYaw = boss->camera.getYaw();
    _defaultPitch = boss->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(Boss* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = SceneEditor::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}

Bullet::Bullet(SceneEditor* scene, Vector3 pos, float rotateYaw, float rotatePitch) : Object(scene, pos)
{

    type = SceneEditor::GEO_LIGHTBALL3;
    _defaultYaw = level1->camera.getYaw();
    _defaultPitch = level1->camera.getPitch();
    _defaultPosition = pos;
    scale = 5;
    rotateY = -rotateYaw;
    rotateZ = rotatePitch;

    mingxiue26rox = false;
}
Bullet::Bullet(SceneEditor* scene, Vector3 pos) :Object(scene, pos)
{
    _defaultPosition = pos;
    type = SceneEditor::GEO_LIGHTBALL2;
    scale = 5;

    mingxiue26rox = true;
}


Bullet::~Bullet()
{
}

void Bullet::interact(){


    if (scene == 0)
    {
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

		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = _scene->enemyStorage.begin(); itEnemy != _scene->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					_scene->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = _scene->enemyStorage.begin(); itEnemy != _scene->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					_scene->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }

    if (scene == 1)
    {
        if (mingxiue26rox == false)
        {
            position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* level1->_dt);
            position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * level1->_dt);
            position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* level1->_dt);

        }

        if (mingxiue26rox == true)
        {
            Vector3 distance = (_defaultPosition - level1->camera.getPosition());
            Vector3 unitDistance = distance.Normalized();
            float moveX = unitDistance.x * bulletSpeed* level1->_dt;
            float moveZ = unitDistance.z * bulletSpeed* level1->_dt;

            // Rotate the enemy towards the player
            rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

            // Move the Enemy
            position_.x -= moveX;
            position_.z -= moveZ;
        }

		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = level1->enemyStorage.begin(); itEnemy != level1->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					level1->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = level1->enemyStorage.begin(); itEnemy !=  level1->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					level1->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }

    if (scene == 2)
    {
        if (mingxiue26rox == false)
        {
            position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* level2->_dt);
            position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * level2->_dt);
            position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* level2->_dt);

        }

        if (mingxiue26rox == true)
        {
            Vector3 distance = (_defaultPosition - level2->camera.getPosition());
            Vector3 unitDistance = distance.Normalized();
            float moveX = unitDistance.x * bulletSpeed* level2->_dt;
            float moveZ = unitDistance.z * bulletSpeed* level2->_dt;

            // Rotate the enemy towards the player
            rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

            // Move the Enemy
            position_.x -= moveX;
            position_.z -= moveZ;
        }



		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = level2->enemyStorage.begin(); itEnemy != level2->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					level2->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = level2->enemyStorage.begin(); itEnemy != level2->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					level2->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }

    if (scene == 3)
    {
        if (mingxiue26rox == false)
        {
            position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* level3->_dt);
            position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * level3->_dt);
            position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* level3->_dt);

        }

        if (mingxiue26rox == true)
        {
            Vector3 distance = (_defaultPosition - level3->camera.getPosition());
            Vector3 unitDistance = distance.Normalized();
            float moveX = unitDistance.x * bulletSpeed* level3->_dt;
            float moveZ = unitDistance.z * bulletSpeed* level3->_dt;

            // Rotate the enemy towards the player
            rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

            // Move the Enemy
            position_.x -= moveX;
            position_.z -= moveZ;
        }


		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = level3->enemyStorage.begin(); itEnemy != level3->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					level3->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = level3->enemyStorage.begin(); itEnemy != level3->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					level3->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }

    if (scene == 4)
    {
        if (mingxiue26rox == false)
        {
            position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* level4->_dt);
            position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * level4->_dt);
            position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* level4->_dt);

        }

        if (mingxiue26rox == true)
        {
            Vector3 distance = (_defaultPosition - level4->camera.getPosition());
            Vector3 unitDistance = distance.Normalized();
            float moveX = unitDistance.x * bulletSpeed* level4->_dt;
            float moveZ = unitDistance.z * bulletSpeed* level4->_dt;

            // Rotate the enemy towards the player
            rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

            // Move the Enemy
            position_.x -= moveX;
            position_.z -= moveZ;
        }


		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = level4->enemyStorage.begin(); itEnemy != level4->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					level4->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = level4->enemyStorage.begin(); itEnemy != level4->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					level4->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }

    if (scene == 5)
    {
        if (mingxiue26rox == false)
        {
            position_.x += (float)(bulletSpeed * cos(Math::DegreeToRadian(_defaultYaw))* boss->_dt);
            position_.y += (float)(bulletSpeed * tan(Math::DegreeToRadian(_defaultPitch)) * boss->_dt);
            position_.z += (float)(bulletSpeed* sin(Math::DegreeToRadian(_defaultYaw))* boss->_dt);

        }

        if (mingxiue26rox == true)
        {
            Vector3 distance = (_defaultPosition - boss->camera.getPosition());
            Vector3 unitDistance = distance.Normalized();
            float moveX = unitDistance.x * bulletSpeed* boss->_dt;
            float moveZ = unitDistance.z * bulletSpeed* boss->_dt;

            // Rotate the enemy towards the player
            rotateY = -Math::RadianToDegree(atan2(distance.z, distance.x));

            // Move the Enemy
            position_.x -= moveX;
            position_.z -= moveZ;
        }
    

		if (mingxiue26rox == false)
		{
			for (vector<Enemy*>::iterator itEnemy = boss->enemyStorage.begin(); itEnemy != boss->enemyStorage.end(); itEnemy++)
			{
				if ((position_ - (*itEnemy)->_Position).Length() < 10 || (_defaultPosition - position_).Length() >= _maxDistance)
				{
					boss->objFactory.destroyFactoryObject(this);
					return;
				}

			}
		}

		//Delete bullet when enemy's bullet travels too far
		if (mingxiue26rox == true)
		{
			for (vector<Enemy*>::iterator itEnemy = boss->enemyStorage.begin(); itEnemy != boss->enemyStorage.end(); itEnemy++)
			{
				if ((_defaultPosition - position_).Length() >= 50)
				{
					boss->objFactory.destroyFactoryObject(this);
					return;
				}
			}
		}
    }


}

