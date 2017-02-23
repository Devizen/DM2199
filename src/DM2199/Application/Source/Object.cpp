#include "Object.h"
#include "Levels/Tutorial.h"
#include "Levels/Level1.h"
#include "Levels/Level2.h"
#include "Levels/Level3.h"
#include "Levels/Level4.h"
#include "Levels/Boss.h"

void Object::objectRender()
{
	 //To render ONE obj part
		_scene->modelStack.PushMatrix();
		_scene->modelStack.Translate(position_.x, position_.y, position_.z);
		_scene->modelStack.Rotate(rotateX, 1, 0, 0);
		_scene->modelStack.Rotate(rotateZ, 0, 0, 1);
		_scene->modelStack.Rotate(rotateY, 0, 1, 0);
		_scene->modelStack.Scale(scale, scale, scale);
		_scene->RenderMesh(_scene->meshList[type], true);
		_scene->modelStack.PopMatrix();

       // level1->modelStack.PushMatrix();
       // level1->modelStack.Translate(position_.x, position_.y, position_.z);
       // level1->modelStack.Rotate(rotateX, 1, 0, 0);
       // level1->modelStack.Rotate(rotateZ, 0, 0, 1);
       // level1->modelStack.Rotate(rotateY, 0, 1, 0);
       // level1->modelStack.Scale(scale, scale, scale);
       // level1->RenderMesh(level1->meshList[type], true);
       // level1->modelStack.PopMatrix();

       // level2->modelStack.PushMatrix();
       // level2->modelStack.Translate(position_.x, position_.y, position_.z);
       // level2->modelStack.Rotate(rotateX, 1, 0, 0);
       // level2->modelStack.Rotate(rotateZ, 0, 0, 1);
       // level2->modelStack.Rotate(rotateY, 0, 1, 0);
       // level2->modelStack.Scale(scale, scale, scale);
       // level2->RenderMesh(level2->meshList[type], true);
       // level2->modelStack.PopMatrix();

       // level3->modelStack.PushMatrix();
       // level3->modelStack.Translate(position_.x, position_.y, position_.z);
       // level3->modelStack.Rotate(rotateX, 1, 0, 0);
       // level3->modelStack.Rotate(rotateZ, 0, 0, 1);
       // level3->modelStack.Rotate(rotateY, 0, 1, 0);
       // level3->modelStack.Scale(scale, scale, scale);
       // level3->RenderMesh(level3->meshList[type], true);
       // level3->modelStack.PopMatrix();

       // level4->modelStack.PushMatrix();
       // level4->modelStack.Translate(position_.x, position_.y, position_.z);
       // level4->modelStack.Rotate(rotateX, 1, 0, 0);
       // level4->modelStack.Rotate(rotateZ, 0, 0, 1);
       // level4->modelStack.Rotate(rotateY, 0, 1, 0);
       // level4->modelStack.Scale(scale, scale, scale);
       // level4->RenderMesh(level4->meshList[type], true);
       // level4->modelStack.PopMatrix();

       //boss->modelStack.PushMatrix();
       //boss->modelStack.Translate(position_.x, position_.y, position_.z);
       //boss->modelStack.Rotate(rotateX, 1, 0, 0);
       //boss->modelStack.Rotate(rotateZ, 0, 0, 1);
       //boss->modelStack.Rotate(rotateY, 0, 1, 0);
       //boss->modelStack.Scale(scale, scale, scale);
       //boss->RenderMesh(boss->meshList[type], true);
       //boss->modelStack.PopMatrix();

	/*if (isFlicker == true)
	 	_scene->RenderMeshOnScreen(_scene->meshList[meshscreenType], 40, 30, 80, 60);*/
	
}

//Hello