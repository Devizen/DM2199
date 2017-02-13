#include "SceneLight.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "Application.h"
#include "MeshBuilder.h"

#include "shader.hpp"
#include "Utility.h"

#include <iostream>

using std::cout;
using std::cin;

SceneLight::SceneLight()
{
}

SceneLight::~SceneLight()
{
}

void SceneLight::Init()
{
	// Set background color to dark blue
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// Init VBO here

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//Load vertex and fragment shaders
	m_programID = LoadShaders("Shader//Shading.vertexshader", "Shader//Shading.fragmentshader");

	//Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");

	// Use our shader
	glUseProgram(m_programID);

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1, 1, 1);
	//meshList[GEO_SUN] = MeshBuilder::GenerateSphere("sun", Color(1, 1, 0), 20, 20, 1);
	//meshList[GEO_MOON] = MeshBuilder::GenerateSphere("moon", Color(0.8, 0.8, 0.8), 20, 20, 1);

	//meshList[GEO_MERCURY] = MeshBuilder::GenerateSphere("mercury", Color(1, 0.6, 0.2), 20, 20, 1);
	//meshList[GEO_VENUS] = MeshBuilder::GenerateSphere("venus", Color(1, 0.8, 0.4), 20, 20, 1);
	//meshList[GEO_EARTH] = MeshBuilder::GenerateSphere("earth", Color(0.2, 0.2, 0.8), 20, 20, 1);
	//meshList[GEO_MARS] = MeshBuilder::GenerateSphere("mars", Color(0.6, 0.4, 0.2), 20, 20, 1);
	//meshList[GEO_JUPITER] = MeshBuilder::GenerateSphere("jupiter", Color(0.4, 0.4, 0.4), 20, 20, 1);
	//meshList[GEO_SATURN] = MeshBuilder::GenerateSphere("saturn", Color(0.4, 0.4, 0.2), 20, 20, 1);
	//meshList[GEO_URANUS] = MeshBuilder::GenerateSphere("uranus", Color(0.4, 0.4, 0.6), 20, 20, 1);
	//meshList[GEO_NEPTUNE] = MeshBuilder::GenerateSphere("neptune", Color(0.2, 0.4, 0.8), 20, 20, 1);
	//meshList[GEO_SATURNRING] = MeshBuilder::GenerateRing("saturnring", Color(0.4, 0.4, 0.2), 20, 3, 2);
	//meshList[GEO_CYLINDER] = MeshBuilder::GenerateCylinder("cylinder", Color(0, 1, 1), 24, 1, 10);

	meshList[GEO_SPHERE] = MeshBuilder::GenerateSphere("one", Color(0, 0, 1), 20, 20, 5);
	meshList[GEO_SPHERE]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_SPHERE]->material.kDiffuse.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_SPHERE]->material.kSpecular.Set(0.1f, 0.1f, 0.1f);

	meshList[GEO_SUN] = MeshBuilder::GenerateSphere("two", Color(0, 1, 0), 20, 20, 5);
	meshList[GEO_SUN]->material.kDiffuse.Set(0.6f, 0.6f, 0.6f);
	meshList[GEO_SUN]->material.kSpecular.Set(0.3f, 0.3f, 0.3f);

	meshList[GEO_MOON] = MeshBuilder::GenerateSphere("three", Color(0, 1, 1), 20, 20, 5);
	meshList[GEO_MOON]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_MOON]->material.kDiffuse.Set(0.3f, 0.3f, 0.3f);
	meshList[GEO_MOON]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_EARTH] = MeshBuilder::GenerateSphere("four", Color(1, 0, 0), 20, 20, 5);
	meshList[GEO_EARTH]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_EARTH]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_EARTH]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_JUPITER] = MeshBuilder::GenerateSphere("five", Color(1, 0, 1), 20, 20, 5);
	meshList[GEO_JUPITER]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_JUPITER]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_JUPITER]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_MARS] = MeshBuilder::GenerateSphere("six", Color(1, 1, 1), 20, 20, 5);
	meshList[GEO_MARS]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_MARS]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_MARS]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_MERCURY] = MeshBuilder::GenerateSphere("seven", Color(0.9, 0.6, 0.9), 20, 20, 5);
	meshList[GEO_MERCURY]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_MERCURY]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_MERCURY]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_VENUS] = MeshBuilder::GenerateSphere("eight", Color(0.9, 0.6, 0.3), 20, 20, 5);
	meshList[GEO_VENUS]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_VENUS]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_VENUS]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_SATURN] = MeshBuilder::GenerateSphere("nine", Color(0, 0.4, 0.8), 20, 20, 5);
	meshList[GEO_SATURN]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_SATURN]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_SATURN]->material.kSpecular.Set(1.f, 1.f, 1.f);

	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 20, 20, 1);

	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad", Color(0.1, 0.1, 0.1), 40,40);
	meshList[GEO_QUAD]->material.kAmbient.Set(1.f, 0.f, 1.f);
	meshList[GEO_QUAD]->material.kDiffuse.Set(0.f, 1.f, 1.f);
	meshList[GEO_QUAD]->material.kSpecular.Set(1.f, 1.f, 1.f);

	rotateAngle = 1.0f;
	translateX = 0.0f;
	translateX2 = -40.0f;
	translateY = 28.0f;
	translateY2 = 29.0f;
	translateY3 = 30.0f;
	scaleAll = 1.0f;
	camera.Init(Vector3(40, 30, 30), Vector3(0, 0, 0), Vector3(0, 1, 0));
	//Prevent Jerk
	//camera.Init(Vector3(0, 0, 80), Vector3(0, 0, 0), Vector3(0, 1, 0));

	//Projection
	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 1000.f);
	projectionStack.LoadMatrix(projection);

	light[0].position.Set(0, 20, 0);
	light[0].color.Set(1, 1, 1);
	light[0].power = 1;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);

}

void SceneLight::Update(double dt)
{
	static const float LSPEED = 10.f;
	srand(time(NULL));
	unsigned int randspeed = rand() % 100 + 1;
	unsigned int randspeed2 = rand() % 100 + 1;
	unsigned int randspeed3 = rand() % 100 + 1;

	int randx = rand() % 40 - 40;
	int randx2 = rand() % 40 - 40;
	int randx3 = rand() % 40 - 40;

	//Static is first time called and will not be called again.
	static float translateDirection = 1;
	static float translateDown = 1;

	if (Application::IsKeyPressed('1'))
	{
		glEnable(GL_CULL_FACE);
	}

	if (Application::IsKeyPressed('2'))
	{
		glDisable(GL_CULL_FACE);
	}

	if (Application::IsKeyPressed('3'))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	}

	if (Application::IsKeyPressed('4'))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode
	}

	if (Application::IsKeyPressed('5'))
	{
		lightswitch = true;
	}

	if (Application::IsKeyPressed('6'))
	{
		lightswitch = false;
	}


	if (Application::IsKeyPressed(VK_SPACE))
	{
		rotateAngle += (float)(500 / translateDirection * dt);
	}

	rotateAngle += (float)(40 * translateDirection * dt);
	if (rotateAngle > 360)
	{
		//translateDirection = -1;
		rotateAngle = -360;

	}
	else if (rotateAngle <= -360)
	{
		translateDirection = 1;
	}

	camera.Update(dt);


	if (Application::IsKeyPressed('I'))
		light[0].position.z -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('K'))
		light[0].position.z += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('J'))
		light[0].position.x -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('L'))
		light[0].position.x += (float)(LSPEED * dt);
	if (Application::IsKeyPressed('O'))
		light[0].position.y -= (float)(LSPEED * dt);
	if (Application::IsKeyPressed('P'))
		light[0].position.y += (float)(LSPEED * dt);
}

void SceneLight::Render()
{
	srand(time(NULL));
	unsigned int change = rand() % 3;
	unsigned int change2 = rand() % 3;
	unsigned int change3 = rand() % 3;

	unsigned int randscale = rand() % 10 + 1;
	unsigned int randscale2 = rand() % 10 + 1;
	unsigned int randscale3 = rand() % 10 + 1;

	//Clear color & depth buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Mtx44 MVP;

	viewStack.LoadIdentity(); //No need camera for now, set it at World's origin
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();

	//Passing light position to shader
	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);

	//Generate Axes
	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top(); //Remember, matrix multiplication is the other way around
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	meshList[GEO_AXES]->Render();




	modelStack.PushMatrix(); //Sphere
	modelStack.Translate(0.f, 5.f, 0.f);


	RenderMesh(meshList[GEO_SPHERE], lightswitch);
	modelStack.PopMatrix(); //End Sphere

	modelStack.PushMatrix(); //Sphere 2
	modelStack.Translate(10.f, 5.f, 0.f);
	

	RenderMesh(meshList[GEO_SUN], lightswitch);
	modelStack.PopMatrix(); //End Sphere 2

	modelStack.PushMatrix(); //Sphere 3
	modelStack.Translate(-10.f, 5.f, 0.f);
	

	RenderMesh(meshList[GEO_MOON], lightswitch);
	modelStack.PopMatrix(); //End Sphere 3

	modelStack.PushMatrix(); //Sphere 4
	modelStack.Translate(0.f, 5.f, -10.f);
	

	RenderMesh(meshList[GEO_EARTH], lightswitch);
	modelStack.PopMatrix(); //End Sphere 4

	modelStack.PushMatrix(); //Sphere 5
	modelStack.Translate(0.f, 5.f, 10.f);
	

	RenderMesh(meshList[GEO_JUPITER], lightswitch);
	modelStack.PopMatrix(); //End Sphere 5

	modelStack.PushMatrix(); //Sphere 6
	modelStack.Translate(10.f, 5.f, 10.f);
	

	RenderMesh(meshList[GEO_MARS], lightswitch);
	modelStack.PopMatrix(); //End Sphere 6

	modelStack.PushMatrix(); //Sphere 7
	modelStack.Translate(10.f, 5.f, -10.f);


	RenderMesh(meshList[GEO_MERCURY], lightswitch);
	modelStack.PopMatrix(); //End Sphere 7

	modelStack.PushMatrix(); //Sphere 8
	modelStack.Translate(-10.f, 5.f, 10.f);
	
	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	RenderMesh(meshList[GEO_VENUS], lightswitch);
	modelStack.PopMatrix(); //End Sphere 8

	modelStack.PushMatrix(); //Sphere 9
	modelStack.Translate(-10.f, 5.f, -10.f);

	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	RenderMesh(meshList[GEO_SATURN], lightswitch);
	modelStack.PopMatrix(); //End Sphere 9

	modelStack.PushMatrix();
	modelStack.Translate(light[0].position.x, light[0].position.y, light[0].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix(); //Quad
	modelStack.Translate(0.f, 0.f, 0.f);
	modelStack.Scale(50.f, 1, 50.f);

	glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	RenderMesh(meshList[GEO_QUAD], lightswitch);
	modelStack.PopMatrix(); //End Quad

}

void SceneLight::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	modelView = viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
	if (enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}
	mesh->Render();
}


void SceneLight::Exit()
{
	// Cleanup VBO here
	glDeleteVertexArrays(1, &m_vertexArrayID);

	glDeleteProgram(m_programID);
}
