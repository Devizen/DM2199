#include "Object.h"
#include "Levels/Tutorial.h"


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


	/*if (isFlicker == true)
	 	_scene->RenderMeshOnScreen(_scene->meshList[meshscreenType], 40, 30, 80, 60);*/
	
}

//Hello