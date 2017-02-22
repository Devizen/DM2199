//#include "SceneBase.h"
//#include "GL\glew.h"
//#include "Mtx44.h"
//#include "Application.h"
//#include "MeshBuilder.h"
//#include "LoadTGA.h"
//#include "LoadOBJ.h"
//
//#include "shader.hpp"
//#include "Utility.h"
//
//#include <iostream>
//#include <iomanip>
//#include <stdlib.h>
//
//#include "ItemInfo.h"
//#include "Inventory.h"
//
//
//using std::cout;
//using std::cin;
//
//SceneBase::SceneBase()
//{
//}
//
//SceneBase::~SceneBase()
//{
//}
//
//Inventory* global_inventory = 0;
//void SceneBase::Init()
//{
//	// Set background color to black 
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	// Enable depth test
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//
//	// Enable blending
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	// Init VBO here
//
//	// Generate a default VAO for now
//	glGenVertexArrays(1, &m_vertexArrayID);
//	glBindVertexArray(m_vertexArrayID);
//
//	//Load vertex and fragment shaders
//	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
//
//	//Get a handle for our "MVP" uniform
//	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
//	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
//	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
//	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
//	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
//	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
//	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
//
//	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
//	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
//	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
//	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
//	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
//	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
//	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
//	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
//	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
//	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
//	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
//
//	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
//	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
//	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
//	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
//	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
//	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
//	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
//	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
//	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
//	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
//	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
//
//	m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
//	m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
//	m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
//	m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
//	m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
//	m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
//	m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
//	m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
//	m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
//	m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
//	m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");
//
//	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
//
//	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
//
//	// Get a handle for our "colorTexture" uniform
//	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
//	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
//
//	// Get a handle for our "textColor" uniform
//	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
//	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
//
//
//	// Use our shader
//	glUseProgram(m_programID);
//
//	for (int i = 0; i < NUM_GEOMETRY; ++i)
//	{
//		meshList[i] = NULL;
//	}
//
//	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1, 1, 1);
//
//	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 20, 20, 1);
//	meshList[GEO_LIGHTBALL2] = MeshBuilder::GenerateSphere("lightball_2", Color(0.5f, 0.f, 0.f), 20, 20, 1);
//	meshList[GEO_LIGHTBALL3] = MeshBuilder::GenerateSphere("lightball_3", Color(1.f, 1.f, 0.f), 20, 20, 1);
//
//	meshList[GEO_GROUND] = MeshBuilder::GenerateQuad("grass", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_GROUND]->textureID = LoadTGA("Image//MetalFloor.tga");
//
//	//Skybox Day
//	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");
//
//	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");
//
//	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");
//
//	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");
//
//	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");
//
//	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");
//
//	//Skybox Night
//	meshList[GEO_FRONTn] = MeshBuilder::GenerateQuad("frontn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_FRONTn]->textureID = LoadTGA("Image//frontn.tga");
//
//	meshList[GEO_BACKn] = MeshBuilder::GenerateQuad("backn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BACKn]->textureID = LoadTGA("Image//backn.tga");
//
//	meshList[GEO_TOPn] = MeshBuilder::GenerateQuad("topn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_TOPn]->textureID = LoadTGA("Image//topn.tga");
//
//	meshList[GEO_BOTTOMn] = MeshBuilder::GenerateQuad("bottomn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BOTTOMn]->textureID = LoadTGA("Image//bottomn.tga");
//
//	meshList[GEO_LEFTn] = MeshBuilder::GenerateQuad("leftn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_LEFTn]->textureID = LoadTGA("Image//leftn.tga");
//
//	meshList[GEO_RIGHTn] = MeshBuilder::GenerateQuad("rightn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_RIGHTn]->textureID = LoadTGA("Image//rightn.tga");
//
//	//Text
//	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
//	meshList[GEO_TEXT]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_X] = MeshBuilder::GenerateText("x", 16, 16);
//	meshList[GEO_X]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_Y] = MeshBuilder::GenerateText("y", 16, 16);
//	meshList[GEO_Y]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_Z] = MeshBuilder::GenerateText("z", 16, 16);
//	meshList[GEO_Z]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_FPS] = MeshBuilder::GenerateText("FPS", 16, 16);
//	meshList[GEO_FPS]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_COUNTDOWN] = MeshBuilder::GenerateText("Time", 16, 16);
//	meshList[GEO_COUNTDOWN]->textureID = LoadTGA("Image//comic.tga");
//
//	//Environment
//	meshList[GEO_MOUNTAIN] = MeshBuilder::GenerateOBJ("mountain", "OBJ//mountain.obj");
//	meshList[GEO_MOUNTAIN]->textureID = LoadTGA("Image//objects.tga");
//
//	meshList[GEO_MOUNTAIN_2] = MeshBuilder::GenerateOBJ("mountain_2", "OBJ//mountain.obj");
//	meshList[GEO_MOUNTAIN_2]->textureID = LoadTGA("Image//objects.tga");
//
//	meshList[GEO_MESSAGES] = MeshBuilder::GenerateText("messages", 16, 16);
//	meshList[GEO_MESSAGES]->textureID = LoadTGA("Image//comic.tga");
//
//	//Sprites
//	meshList[GEO_HANDL1] = MeshBuilder::GenerateOBJ("handL1", "OBJ//quad.obj");
//	meshList[GEO_HANDL1]->textureID = LoadTGA("Image//Sprites//HandL1.tga");
//	meshList[GEO_HANDR1] = MeshBuilder::GenerateOBJ("handR1", "OBJ//quad.obj");
//	meshList[GEO_HANDR1]->textureID = LoadTGA("Image//Sprites//HandR1.tga");
//	meshList[GEO_HANDL2] = MeshBuilder::GenerateOBJ("handL2", "OBJ//quad.obj");
//	meshList[GEO_HANDL2]->textureID = LoadTGA("Image//Sprites//HandL2.tga");
//	meshList[GEO_HANDR2] = MeshBuilder::GenerateOBJ("handR2", "OBJ//quad.obj");
//	meshList[GEO_HANDR2]->textureID = LoadTGA("Image//Sprites//HandR2.tga");
//	meshList[GEO_HANDI] = MeshBuilder::GenerateOBJ("handI", "OBJ//quad.obj");
//	meshList[GEO_HANDI]->textureID = LoadTGA("Image//Sprites//HandI.tga");
//	meshList[GEO_GUN1] = MeshBuilder::GenerateOBJ("gun1", "OBJ//quad.obj");
//	meshList[GEO_GUN1]->textureID = LoadTGA("Image//Sprites//Gun1.tga");
//	meshList[GEO_GUN2] = MeshBuilder::GenerateOBJ("gun2", "OBJ//quad.obj");
//	meshList[GEO_GUN2]->textureID = LoadTGA("Image//Sprites//Gun2.tga");
//	meshList[GEO_GUN3] = MeshBuilder::GenerateOBJ("gun3", "OBJ//quad.obj");
//	meshList[GEO_GUN3]->textureID = LoadTGA("Image//Sprites//Gun3.tga");
//	meshList[GEO_GUNI] = MeshBuilder::GenerateOBJ("gunI", "OBJ//quad.obj");
//	meshList[GEO_GUNI]->textureID = LoadTGA("Image//Sprites//GunI.tga");
//	meshList[GEO_SWORD1] = MeshBuilder::GenerateOBJ("sword1", "OBJ//quad.obj");
//	meshList[GEO_SWORD1]->textureID = LoadTGA("Image//Sprites//Sword1.tga");
//	meshList[GEO_SWORD2] = MeshBuilder::GenerateOBJ("sword2", "OBJ//quad.obj");
//	meshList[GEO_SWORD2]->textureID = LoadTGA("Image//Sprites//Sword2.tga");
//	meshList[GEO_SWORD3] = MeshBuilder::GenerateOBJ("sword3", "OBJ//quad.obj");
//	meshList[GEO_SWORD3]->textureID = LoadTGA("Image//Sprites//Sword3.tga");
//	meshList[GEO_SWORDI] = MeshBuilder::GenerateOBJ("swordI", "OBJ//quad.obj");
//	meshList[GEO_SWORDI]->textureID = LoadTGA("Image//Sprites//SwordI.tga");
//	meshList[GEO_TORCH] = MeshBuilder::GenerateOBJ("torch", "OBJ//quad.obj");
//	meshList[GEO_TORCH]->textureID = LoadTGA("Image//Sprites//Torch.tga");
//	meshList[GEO_TORCHI] = MeshBuilder::GenerateOBJ("torchI", "OBJ//quad.obj");
//	meshList[GEO_TORCHI]->textureID = LoadTGA("Image//Sprites//TorchI.tga");
//	meshList[GEO_HEALTHPOTION] = MeshBuilder::GenerateOBJ("healthPotion", "OBJ//quad.obj");
//	meshList[GEO_HEALTHPOTION]->textureID = LoadTGA("Image//Sprites//HealthPotion.tga");
//	meshList[GEO_ANTIDOTE] = MeshBuilder::GenerateOBJ("antidote", "OBJ//quad.obj");
//	meshList[GEO_ANTIDOTE]->textureID = LoadTGA("Image//Sprites//Antidote.tga");
//
//	meshList[GEO_GUN_ICON] = MeshBuilder::GenerateOBJ("antidote", "OBJ//Wall.obj");
//	meshList[GEO_GUN_ICON]->textureID = LoadTGA("Image//Sprites//GunIcon.tga");
//
//	//Item
//	meshList[GEO_INVENTORY] = MeshBuilder::GenerateOBJ("Inventory", "OBJ//inventory.obj");
//	meshList[GEO_INVENTORY]->textureID = LoadTGA("Image//inventory.tga");
//
//	meshList[GEO_MINI_PLAYER] = MeshBuilder::GenerateOBJ("mini_player", "OBJ//inventory.obj");
//	meshList[GEO_MINI_PLAYER]->textureID = LoadTGA("Image//mini_player.tga");
//
//	meshList[GEO_MINI_GROUND] = MeshBuilder::GenerateOBJ("mini_ground", "OBJ//inventory.obj");
//	meshList[GEO_MINI_GROUND]->textureID = LoadTGA("Image//grass.tga");
//
//	meshList[GEO_MINI_ENEMY] = MeshBuilder::GenerateOBJ("mini_enemy", "OBJ//inventory.obj");
//	meshList[GEO_MINI_ENEMY]->textureID = LoadTGA("Image//mini_enemy.tga");
//
//	meshList[GEO_GAME_HUD] = MeshBuilder::GenerateOBJ("game_hud", "OBJ//inventory.obj");
//	meshList[GEO_GAME_HUD]->textureID = LoadTGA("Image//game_hud.tga");
//
//	meshList[GEO_HP] = MeshBuilder::GenerateOBJ("game_hp", "OBJ//inventory.obj");
//	meshList[GEO_HP]->textureID = LoadTGA("Image//hp_bar.tga");
//
//	meshList[GEO_EN] = MeshBuilder::GenerateOBJ("game_en", "OBJ//inventory.obj");
//	meshList[GEO_EN]->textureID = LoadTGA("Image//en_bar.tga");
//
//	//Enemy 1
//	meshList[GEO_ENEMYHEAD] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyHead.obj");
//	meshList[GEO_ENEMYHEAD]->textureID = LoadTGA("Image//Enemy//EnemyHead.tga");
//
//	meshList[GEO_ENEMYRIGHTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYLEFTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYLEFTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYRIGHTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYTORSO] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyTorso.obj");
//	meshList[GEO_ENEMYTORSO]->textureID = LoadTGA("Image//Enemy//EnemyTorso.tga");
//
//	//Enemy 2
//	meshList[GEO_ENEMYRIGHTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYTORSO2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2Torso.obj");
//	meshList[GEO_ENEMYTORSO2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//
//	//Enemy 3
//	meshList[GEO_ENEMYRIGHTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYTORSO3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3Torso.obj");
//	meshList[GEO_ENEMYTORSO3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//
//	//Enemy 4
//	meshList[GEO_ENEMYRIGHTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RighLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYTORSO4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4Torso.obj");
//	meshList[GEO_ENEMYTORSO4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//
//	//Flicker
//	meshList[GEO_FLICKER] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//quad.obj");
//	meshList[GEO_FLICKER]->textureID = LoadTGA("Image//blood//bloodflicker.tga");
//
//
//	meshList[GEO_SPIDERBODY] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderBody.obj");
//	meshList[GEO_SPIDERBODY]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERL1] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderL1.obj");
//	meshList[GEO_SPIDERL1]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERL2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderL2.obj");
//	meshList[GEO_SPIDERL2]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERL3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderL3.obj");
//	meshList[GEO_SPIDERL3]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERR1] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderR1.obj");
//	meshList[GEO_SPIDERR1]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERR2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderR2.obj");
//	meshList[GEO_SPIDERR2]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//	meshList[GEO_SPIDERR3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//SpiderR3.obj");
//	meshList[GEO_SPIDERR3]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//
//
//	meshList[GEO_LAMP] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Lamp.obj");
//	meshList[GEO_LAMP]->textureID = LoadTGA("Image//Lamp.tga");
//
//	meshList[GEO_ENEMYHEALTHBAR] = MeshBuilder::GenerateQuad("enemyHealthBar", Color(1.0f, 0.0f, 0.0f), 1, 1);
//
//	meshList[GEO_ARROW] = MeshBuilder::GenerateOBJ("Arrow", "OBJ//inventory.obj");
//	meshList[GEO_ARROW]->textureID = LoadTGA("Image//Arrow.tga");
//
//	meshList[GEO_ACTIVE_SELECT] = MeshBuilder::GenerateOBJ("active_select", "OBJ//inventory.obj");
//	meshList[GEO_ACTIVE_SELECT]->textureID = LoadTGA("Image//active_select.tga");
//
//	meshList[GEO_SECONDARY_SELECT] = MeshBuilder::GenerateOBJ("secondary_select", "OBJ//inventory.obj");
//	meshList[GEO_SECONDARY_SELECT]->textureID = LoadTGA("Image//secondary_select.tga");
//
//	meshList[GEO_TIME] = MeshBuilder::GenerateOBJ("time_bar", "OBJ//inventory.obj");
//	meshList[GEO_TIME]->textureID = LoadTGA("Image//time_bar.tga");
//
//	//Prevent Jerk
//	camera.Init(Vector3(0, 0, 484), Vector3(0, 0, 0), Vector3(0, 1, 0));
//
//	//Projection
//	Mtx44 projection;
//	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 4000.f);
//	projectionStack.LoadMatrix(projection);
//
//	//Spot light
//	light[0].type = Light::LIGHT_SPOT;
//	light[0].position.Set(0, 10, 0);// this is overidden at the update
//	light[0].color.Set(1, 1, 1);
//	light[0].power = 0;
//	light[0].kC = 1.f;
//	light[0].kL = 0.01f;
//	light[0].kQ = 0.001f;
//	light[0].cosCutoff = cos(Math::DegreeToRadian(25)); // higher angle = more area covered with light
//	light[0].cosInner = cos(Math::DegreeToRadian(15)); // use to toggle inner light , lower angle  = light more concentrated
//	light[0].exponent = 3.f;
//	light[0].spotDirection.Set(0.f, 1.f, 0.f); // this is overidden at the update
//
//	light[1].type = Light::LIGHT_POINT;
//	light[1].position.Set(0.f, 1000.f, 0.f);
//	light[1].color.Set(1.f, 0.f, 0.f);
//	light[1].power = 10;
//	light[1].kC = 1.f;
//	light[1].kL = 0.01f;
//	light[1].kQ = 0.001f;
//	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
//	light[1].cosInner = cos(Math::DegreeToRadian(30));
//	light[1].exponent = 3.f;
//	light[1].spotDirection.Set(0.f, 1.f, 0.f);
//
//	light[2].type = Light::LIGHT_SPOT;
//	light[2].position.Set(0.f, 0.f, 50.f);
//	light[2].color.Set(1.f, 1.f, 0.f);
//	light[2].power = 0;
//	light[2].kC = 1.f;
//	light[2].kL = 0.01f;
//	light[2].kQ = 0.001f;
//	light[2].cosCutoff = cos(Math::DegreeToRadian(45));
//	light[2].cosInner = cos(Math::DegreeToRadian(30));
//	light[2].exponent = 3.f;
//	light[2].spotDirection.Set(0.f, 1.f, 0.f);
//
//	// Make sure you pass uniform parameters after glUseProgram()
//	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
//	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
//	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
//	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
//	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
//	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);
//
//	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
//	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
//	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
//	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
//	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
//	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
//	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);
//
//	glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
//	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
//	glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
//	glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
//	glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
//	glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
//	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
//	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);
//
//	// Make sure you pass uniform parameters after glUseProgram()
//	glUniform1i(m_parameters[U_NUMLIGHTS], 3);
//
//
//	// Param 1 - name of sound ---- Param 2 -distance sound able to travel --- Param 3 - volume of sound (0 to 1)
//	soundStorage.push_back(new Sound("gunshot.mp3", 1000, 1));
//	soundStorage.push_back(new Sound("splatter.mp3", 1000, 1));
//	soundStorage.push_back(new Sound("run.mp3", 1000, 0.5));
//	soundStorage.push_back(new Sound("backgroundmusic.mp3"));
//	soundStorage.push_back(new Sound("jump.mp3", 1000, 0.5));
//	soundStorage.push_back(new Sound("footstep.mp3", 1000, 1));
//
//	/* vec3df somePosition = { 0, 0,0};
//	 soundStorage[1]->play3DSound(true, false, false, somePosition);*/
//
//	/*soundStorage[3]->play2DSound(true, false, false); */
//
//	/*objFactory.createFactoryObject(new Enemy(this, Vector3(Math::RandFloatMinMax(-50, 50), 0, Math::RandFloatMinMax(-50, 50))) );*/
//
//	//----------------Inventory--------------
//	inventoryOpen = false;
//
//	//initialise singleton of inventory class
//
//	if (global_inventory == 0)
//	{
//		global_inventory = new Inventory();
//		global_inventory->setdefined(1);
//	}
//	//type , damage , range , reload speed , attack speed
//	ItemInfo* gun = new ItemInfo("gun", 20, 20, 10, 15);
//	global_inventory->addItem(gun);
//
//	ItemInfo* torch = new ItemInfo("torch", 0, 50, 0, 10);
//	global_inventory->addItem(torch);
//	// adding items to inventory
//	ItemInfo* fist = new ItemInfo();
//	global_inventory->addItem(fist);
//
//	//delay between keypresses while in menu
//	startTime = 0.0f;
//	cooldown = 15.0f;
//
//	//speed ,damage ,hp, range ,this
//	Enemy * newEnemy = new Spider(70.f, 5.f, 50.f, 100.f);
//	newEnemy->addWaypoint(Vector3(200, 0, 200));
//	newEnemy->addWaypoint(Vector3(200, 0, -200));
//	newEnemy->addWaypoint(Vector3(-200, 0, -200));
//	newEnemy->addWaypoint(Vector3(-200, 0, 200));
//	enemyStorage.push_back(newEnemy);
//
//	// speed , damage ,hp , range , this , int(used to identify which type of robot)
//	Enemy * newEnemy2 = new Robot(70.f, 5.f, 100.f, 100.f, 1);
//	newEnemy2->addWaypoint(Vector3(300, 0, -100));
//	newEnemy2->addWaypoint(Vector3(400, 0, -400));
//	newEnemy2->addWaypoint(Vector3(-400, 0, -400));
//	newEnemy2->addWaypoint(Vector3(-400, 0, 400));
//	enemyStorage.push_back(newEnemy2);
//
//	Enemy * newEnemy3 = new Spider(70.f, 5.f, 50.f, 100.f);
//	newEnemy3->addWaypoint(Vector3(-400, 0, 200));
//	newEnemy3->addWaypoint(Vector3(300, 0, -300));
//	newEnemy3->addWaypoint(Vector3(-2300, 0, -300));
//	newEnemy3->addWaypoint(Vector3(-2300, 0, 200));
//	enemyStorage.push_back(newEnemy3);
//
//	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		(*it)->_Position = (*it)->currWaypoint->getPosition();
//	}
//}
//
//void SceneBase::Update(double dt)
//{
//	vec3df camPos = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
//	Vector3 view = camera.target - camera.position;
//	vec3df dir = { view.x, view.y, view.z };
//	vec3df up = { camera.up.x, camera.up.y, camera.up.z };
//	vec3df zero = { 0, 0, 0 };
//
//	for (unsigned i = 0; i < soundStorage.size(); ++i)
//	{
//		soundStorage[i]->getSoundEngine()->setListenerPosition(camPos, dir.normalize(), zero, up.normalize());
//		soundStorage[i]->getSoundEngine()->update();
//	}
//
//	Robot::dtFromScene(dt);
//	Robot::positionFromCamera(camera);
//
//	Spider::dtFromScene(dt);
//	Spider::positionFromCamera(camera);
//
//	//Bullet::dtFromScene(dt);
//	//Bullet::positionFromCamera(camera);
//
//	_dt = (float)dt;
//	_elapsedTime += _dt;
//
//	static float rotateLimit = 1;
//	rotateArm += (float)(50 * rotateLimit * dt);
//    if (rotateArm > 10)
//    {
//        rotateArm = 10.f;
//        rotateLimit = -1;
//    }
//    if (rotateArm < -10)
//    {
//        rotateArm = -10.f;
//        rotateLimit = 1;
//    }
//
//	static bool canPress = true;
//
//	if (!Application::IsKeyPressed('Q'))
//		canPress = true;
//
//	// Light on
//	if (canPress && Application::IsKeyPressed('Q')) {
//		light[0].power = (light[0].power > 0) ? 0.0f : 3.0f; // Toggle Power between 0 and 2
//		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//		canPress = false;
//	}
//	if (light[0].power > 0)
//	{
//		float ys = 10.f;
//		energy -= ys * _dt;
//	}
//	if (torchDead == true)
//	{
//		light[0].power = 0;
//		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//	}
//	if (energy < 0)
//	{
//		energy = 0;
//	}
//	// Flashlight position and direction
//	light[0].position.Set(camera.position.x, camera.position.y, camera.position.z);
//	light[0].spotDirection = camera.position - camera.target;  // move direction of light along view vector
//
//	//Process  obj movement
//	objFactory.processInteraction();
//
//	static const float LSPEED = 10.f;
//	srand((unsigned)time(NULL));
//
//	static float rotateWorld = 1;
//
//	float run = 1.f;
//
//	if (Application::IsKeyPressed(MK_LBUTTON))
//	{
//		if (_elapsedTime >= nextBulletTime)
//		{
//			objFactory.createFactoryObject(new Bullet(this, camera.getPosition(), camera.getYaw(), camera.getPitch()));
//			nextBulletTime = _elapsedTime + coolDown;
//			soundStorage[0]->play3DSound(false, false, false, camPos);
//			bulletTouch = false;
//			swing = true;
//		}
//	}
//	if (swing == true)
//	{
//		swingTime++;
//	}
//
//	if (Application::IsKeyPressed('I'))
//	{
//		if (inventoryOpen && startTime >= cooldown)
//		{
//			inventoryOpen = false;
//			startTime = 0;
//		}
//		else if (startTime >= cooldown)
//		{
//			inventoryOpen = true;
//			startTime = 0;
//		}
//	}
//
//	vec3df footPos = { camera.getPosition().x, camera.getPosition().y - 20, camera.getPosition().z };
//	//FootStep Sound
//	if (Application::IsKeyPressed('W') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('A') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('S') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('D') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//
//	if (Application::IsKeyPressed(VK_SPACE) && (_elapsedTime >= nextJump))
//	{
//		nextJump = _elapsedTime + coolDown;
//		soundStorage[4]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed(VK_SHIFT) && (_elapsedTime >= nextRun))
//	{
//		nextRun = _elapsedTime + coolDown;
//		soundStorage[2]->play3DSound(false, false, true, footPos);
//	}
//
//	//Skybox Rotation
//	rotateSkybox += (float)(1 * rotateWorld * dt);
//
//	//Skybox
//	if (rotateSkybox > 360)
//	{
//		rotateSkybox = 0;
//	}
//
//	if (Application::IsKeyPressed(VK_NUMPAD5))
//	{
//		run = 3.f;
//	}
//
//	//Reset
//	if (Application::IsKeyPressed('R'))
//	{
//		resetAll();
//	}
//
//	if (Application::IsKeyPressed('7'))
//	{
//		light[0].type = Light::LIGHT_POINT;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_POINT;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to POINT and pass the information to shader
//	}
//	if (Application::IsKeyPressed('8'))
//	{
//		light[0].type = Light::LIGHT_DIRECTIONAL;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_DIRECTIONAL;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to DIRECTIONAL and pass the information to shader
//	}
//	if (Application::IsKeyPressed('9'))
//	{
//		light[0].type = Light::LIGHT_SPOT;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_SPOT;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to SPOT and pass the information to shader
//	}
//
//	camera.Update(dt);
//
//	//FPS Counter
//	FPS = 1 / (float)dt;
//
//	startTime++;
//
//	enemyUpdate(dt);
//
//	timeleft--;
//}
//
//void SceneBase::enemyUpdate(double dt)
//{
//	//-------This function is called in SceneBase::Update(double dt) to process Enemy interactions-----------------
//
//	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		(*it)->update();
//
//		for (vector<Object*>::iterator factoryIt = factoryIt = objFactory.Container.begin(); factoryIt != objFactory.Container.end(); factoryIt++)
//		{
//			if ((*factoryIt)->type == SceneBase::GEO_LIGHTBALL3)   //BULLET INTERACTION WITH ENEMY
//			{
//				if (((*factoryIt)->position_ - (*it)->_Position).Length() < 20 && bulletTouch == false)
//				{
//					if ((*it)->enemytype == 1)
//					{
//						(*it)->_Hp -= 10;
//						(*it)->healthBarSpider -= 2.f;
//						damaged = true;
//						bulletTouch = true;
//
//						if ((*it)->_Hp == 0)
//						{
//							(*it)->setState(2);  //  death is at enum 2
//						}
//					}
//					if ((*it)->enemytype == 2)
//					{
//						(*it)->_Hp -= 10;
//						(*it)->healthBarRobot1 -= 2.f;
//						damaged = true;
//						bulletTouch = true;
//
//						if ((*it)->_Hp == 0)
//						{
//							(*it)->setState(2);  //  death is at enum 2
//						}
//					}
//				}
//			}
//		}
//	}
//}
//void SceneBase::Render()
//{
//	srand((unsigned)time(NULL));
//
//	//Clear color & depth buffer every frame
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//	Mtx44 MVP;
//
//	viewStack.LoadIdentity(); //No need camera for now, set it at World's origin
//	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
//	modelStack.LoadIdentity();
//
//	//Passing light position to shader
//	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//
//	//Light 1
//	if (light[0].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[0].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//	//Light 2
//	if (light[1].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[1].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//	//Light 2
//	if (light[2].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[2].position.x, light[2].position.y, light[2].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[2].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//
//	//Generate Axes
//	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top(); //Remember, matrix multiplication is the other way around
//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//	RenderMesh(meshList[GEO_AXES], false);
//
//	modelStack.PushMatrix();
//	modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
//	RenderSkybox();
//	modelStack.PopMatrix();
//
//	//Environment
//	renderMountains();
//	renderGround();
//	renderPosition();
//
//	renderText();
//
//	objFactory.renderFactoryObject();
//
//	renderEnemy();
//
//	renderSprites();
//
//	renderHUD();
//}
//
//void SceneBase::renderEnemy()
//{
//	for (vector<Enemy *> ::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		if (((*it)->_Position - camera.getPosition()).Length() < 10)
//		{
//			RenderMeshOnScreen(meshList[GEO_FLICKER], 40, 30, 80, 60);
//			vec3df bloodStartingLocation = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
//			if (_elapsedTime >= nextSplatter)
//				soundStorage[1]->play3DSound(false, false, false, bloodStartingLocation);
//			nextSplatter = _elapsedTime + coolDown;
//
//			camera.health--;
//
//			if ((*it)->enemytype == 1)
//			{
//				if (Math::RandIntMinMax(0, 100) < 10)
//				{
//					camera.poison = true;
//				}
//			}
//		}
//
//		switch ((*it)->enemytype)
//		{
//
//		case   1:    // ----------------Spider ----------------------------
//		{
//			if ((*it)->getState() != Spider::spiderState::death)
//			{
//				//Spider
//				modelStack.PushMatrix();
//				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//				modelStack.PushMatrix();
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERBODY], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(-rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERL1], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERR1], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERL2], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(-rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERR2], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(-rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERL3], true);
//				modelStack.PopMatrix();
//				modelStack.PushMatrix();
//				modelStack.Translate(0, 0, -1);
//				modelStack.Rotate(rotateArm, 0, 1, 0);
//				modelStack.Translate(0, 0, 1);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDERR3], true);
//				modelStack.PopMatrix();
//				modelStack.PopMatrix();
//
//				//Health Bar
//				modelStack.PushMatrix();
//				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 1.3f, (*it)->_Position.z);
//				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//				modelStack.Rotate(90, 0, 0, 1);
//				if ((*it)->healthBarSpider>0)
//					modelStack.Scale(1, 1, (*it)->healthBarSpider);
//				else
//					modelStack.Scale(1, 1, 1);
//				RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
//				modelStack.PopMatrix();
//
//			}
//		}
//		break;
//		case 2:  // ---------------Robot1 ----------------------
//		{
//			if ((*it)->getState() != Robot::robotState::death)
//			{
//				if ((*it)->robotType == 1)
//				{
//					//Robot
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO], true);
//					RenderMesh(meshList[GEO_ENEMYHEAD], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//
//					//Health Bar
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 1.3f, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.Rotate(90, 0, 0, 1);
//					if ((*it)->healthBarRobot1>0)
//						modelStack.Scale(1, 1, (*it)->healthBarRobot1);
//					else
//						modelStack.Scale(1, 1, 1);
//					RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
//					modelStack.PopMatrix();
//				}
//
//				if ((*it)->robotType == 2)
//				{
//					//Robot 2
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 5, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -5, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 5, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -5, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG2], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//
//				if ((*it)->robotType == 3)
//				{
//					//Robot 3
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 1, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -1, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 1, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -1, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG3], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//				if ((*it)->robotType == 4)
//				{
//					//Robot 4
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG4], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//			}
//		}
//		break;
//		}
//	}
//}
//
//void SceneBase::renderHUD()
//{
//	if (inventoryOpen)
//	{
//		if (startTime >= cooldown)
//		{
//			if (Application::IsKeyPressed(VK_DOWN)) // scroll down item list
//			{
//				global_inventory->CycleDisplay(0);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed(VK_UP)) // scroll up item list
//			{
//				global_inventory->CycleDisplay(1);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed('J')) // equip primary
//			{
//				global_inventory->equipItem(1);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed('K')) // equip secondary
//			{
//				global_inventory->equipItem(0);
//				startTime = 0;
//			}
//		}
//		RenderMeshOnScreen(meshList[GEO_INVENTORY], 40, 27, 80, 65);
//		renderInventory();
//		renderStats();
//	}
//	else
//	{
//		//in game hud
//		RenderMeshOnScreen(meshList[GEO_GAME_HUD], 40, 32, 80, 65);
//
//		if (health > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_HP], 5 + 11.3 * camera.health / 1000, 6.1, 105 * camera.health / 1000, 9);
//		}
//		if (energy > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_EN], 5 + 11.3* energy / 10000, 2.3, 105 * energy / 10000, 9);
//		}
//		if (energy == 0)
//		{
//			torchDead = true;
//		}
//		if (timeleft > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_TIME], 58.6 + 11.3* timeleft / 60000, 14.5, 105 * timeleft / 60000, 11);
//		}
//		renderRemainingTime();
//		//minimap
//		RenderMeshOnScreen(meshList[GEO_MINI_GROUND], 10, 50, 15, 15);
//		RenderMeshOnScreen(meshList[GEO_MINI_PLAYER], 10.5 + ((camera.getPosition().x / 1000) * 14), 50 + ((camera.getPosition().z / 1000)* 14.4), 6, 6);
//		for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//		{
//			if ((*it)->getState() != Robot::robotState::death || (*it)->getState() != Spider::spiderState::death)
//				RenderMeshOnScreen(meshList[GEO_MINI_ENEMY], 10.5 + (((*it)->_Position.x / 1000) * 14), 50 + (((*it)->_Position.z / 1000) * 14.4), 10, 10);
//		}
//	}
//}
//
//void SceneBase::renderInventory()
//{
//	if (!global_inventory->pointer)
//	{
//		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 20, 27 , 30);
//	}
//	else
//	{
//		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 10, 27 , 30);
//	}
//
//	ItemInfo* activeItem = global_inventory->getActiveItem();
//	if (activeItem->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 15, 35, 130, 130);
//	}
//	else if (activeItem->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 15, 34, 50, 50);
//	}
//	else if (activeItem->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 15, 35, 150, 150);
//	}
//	ItemInfo* secondaryItem = global_inventory->getSecondaryItem();
//	if (secondaryItem->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 33, 35, 130, 130);
//	}
//	else if (secondaryItem->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 32.5, 35, 50, 50);
//	}
//	else if (secondaryItem->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 33, 35, 150, 150);
//	}
//
//	ItemInfo* ItemDisplay1 = global_inventory->getDisplay1();
//	if (ItemDisplay1->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 12, 23, 60, 60);
//	}
//	else if (ItemDisplay1->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 10, 40, 5, 5);
//	}
//	else if (ItemDisplay1->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 23, 70, 70);
//	}
//	if (ItemDisplay1 == activeItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 23.2, 6, 7.2);
//	}
//	else if (ItemDisplay1 == secondaryItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 23.2, 6, 7.2);
//	}
//	ItemInfo* ItemDisplay2 = global_inventory->getDisplay2();
//	if (ItemDisplay2->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 10, 10, 50, 50);
//	}
//	else if (ItemDisplay2->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 12, 13, 25 , 25);
//	}
//	else if (ItemDisplay2->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 13, 70, 70);
//	}
//	if (ItemDisplay2 == activeItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 13.7, 6, 7.2);
//	}
//	else if (ItemDisplay2 == secondaryItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 13.7, 6, 7.2);
//	}
//	
//	//Potions
//	RenderMeshOnScreen(meshList[GEO_HEALTHPOTION], 29, 23.5, 100, 100);
//	renderPotionCount();
//	RenderMeshOnScreen(meshList[GEO_ANTIDOTE], 29, 14, 100, 100);
//	renderAntidoteCount();
//}
//
//void SceneBase::renderMountains()
//{
//
//	float mountainsCoordX[4];
//	float mountainsCoordZ[4];
//
//	mountainsCoordX[0] = -200.f;
//	mountainsCoordZ[0] = -100.f;
//
//	mountainsCoordX[1] = 200.f;
//	mountainsCoordZ[1] = -70.f;
//
//	mountainsCoordX[2] = 320;
//	mountainsCoordZ[2] = 200.f;
//
//	mountainsCoordX[3] = -20.f;
//	mountainsCoordZ[3] = 300.f;
//
//	mountainsCoordX[4] = 0.f;
//	mountainsCoordZ[4] = -250.f;
//
//	for (unsigned i = 0; i < 5; i++)
//	{
//		modelStack.PushMatrix();
//		modelStack.Translate(mountainsCoordX[i], -30.f, mountainsCoordZ[i]);
//		modelStack.Scale(100.f, 50.f, 100.f);
//		RenderMesh(meshList[GEO_MOUNTAIN], true);
//		modelStack.PopMatrix();
//	}
//}
//
//
//void SceneBase::RenderSkybox()
//{
//	//Day
//	if (cycle == false)
//	{
//		modelStack.PushMatrix();
//		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, 998.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_FRONT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, -998.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BACK], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_TOP], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, -998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BOTTOM], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(998.f, 0.f, 0.f);
//		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_LEFT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(-998.f, 0.f, 0.f);
//		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_RIGHT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PopMatrix();
//	}
//
//	//Night
//	if (cycle == true)
//	{
//		modelStack.PushMatrix();
//		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, 998.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_FRONTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, -998.f);
//		//modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BACKn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_TOPn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, -998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BOTTOMn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(998.f, 0.f, 0.f);
//		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_LEFTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(-998.f, 0.f, 0.f);
//		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_RIGHTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PopMatrix();
//	}
//}
//
//
//void SceneBase::renderGround()
//{
//	modelStack.PushMatrix();
//	modelStack.Translate(0.f, -30.f, 0.f);
//	modelStack.Scale(1000.f, 1000.f, 1000.f);
//	RenderMesh(meshList[GEO_GROUND], true);
//	modelStack.PopMatrix();
//
//	modelStack.PushMatrix();
//	modelStack.PopMatrix();
//}
//
//void SceneBase::renderSprites()
//{
//	//Gun
//	//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100, 0, 0, 0, 1);
//	//if (swing == false)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN1], 65, 9, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime < 15)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN2], 65, 12, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 15 && swingTime < 30)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN3], 65, 11, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 30)
//	//{
//	//	swing = false;
//	//	swingTime = 0;
//	//}
//
//	//Cannon
//	//if (swing == false)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON1], 50, 11, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime < 20)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON2], 50, 13, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 20 && swingTime < 40)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON3], 50, 12, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 40)
//	//{
//	//	swing = false;
//	//	swingTime = 0;
//	//}
//
//	if (global_inventory->getActiveItem()->gettype() == "fist" || global_inventory->getSecondaryItem()->gettype() == "fist")
//	{
//		if (swing == false)
//		{
//			//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100);
//			RenderMeshOnScreen(meshList[GEO_HANDR1], 65, 5, 100, 100);
//		}
//		//Punching hands
//		if (swing == true)
//		{
//			//RenderMeshOnScreen(meshList[GEO_HANDL2], 15, 10, 100, 100);
//			RenderMeshOnScreen(meshList[GEO_HANDR2], 65, 10, 100, 100);
//			if (swingTime > 40)
//			{
//				swing = false;
//				swingTime = 0;
//			}
//		}
//	}
//	else if (global_inventory->getActiveItem()->gettype() == "gun" || global_inventory->getSecondaryItem()->gettype() == "gun")
//	{
//		if (swing == false)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN1], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime < 15)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN2], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime > 15 && swingTime < 30)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN3], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime > 30)
//		{
//			swing = false;
//			swingTime = 0;
//		}
//	}
//	else if (global_inventory->getActiveItem()->gettype() == "torch" || global_inventory->getSecondaryItem()->gettype() == "torch")
//		RenderMeshOnScreen(meshList[GEO_TORCH], 25, 5, 150, 150);
//}
//
//
//void SceneBase::renderPosition()
//{
//	std::string sX = "X: " + std::to_string((int)camera.position.x),
//		sY = "Y: " + std::to_string((int)camera.position.y),
//		sZ = "Z: " + std::to_string((int)camera.position.z);
//
//	modelStack.PushMatrix();
//	//No transform needed
//	RenderTextOnScreen(meshList[GEO_X], sX, Color(0, 1, 0), 3, 23, 19);
//	RenderTextOnScreen(meshList[GEO_Y], sY, Color(0, 1, 0), 3, 23, 18);
//	RenderTextOnScreen(meshList[GEO_Z], sZ, Color(0, 1, 0), 3, 23, 17);
//
//	modelStack.PopMatrix();
//}
//
//
//void SceneBase::renderText()
//{
//	std::string sFPS = "FPS: " + std::to_string(FPS);
//	sFPS.resize(9);
//	RenderTextOnScreen(meshList[GEO_FPS], sFPS, Color(1, 1, 0), 2, 0, 29);
//}
//
//void SceneBase::renderRemainingTime()
//{
//
//	std::string rTime = "";
//	int tempTime = timeleft;
//	int seconds = 0;
//	int minutes = 0;
//	while (tempTime >= 60)
//	{
//		tempTime -= 60;
//		seconds += 1;
//	}
//	while (seconds > 60)
//	{
//		seconds -= 60;
//		minutes += 1;
//	}
//	if (seconds > 9)
//	{
//		rTime = std::to_string(minutes) + ":" + std::to_string(seconds);
//	}
//	else
//	{
//		rTime = std::to_string(minutes) + ":0" + std::to_string(seconds);
//	}
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], rTime, Color(1, 0 ,0), 2, 30, 7);
//}
//
//void SceneBase::renderPotionCount()
//{
//	std::string count = "";
//	count = std::to_string(potionCount);
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 10);
//}
//
//void SceneBase::renderAntidoteCount()
//{
//	std::string count = "";
//	count = std::to_string(antidoteCount);
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 5);
//}
//
//void SceneBase::renderStats()
//{
//	/*ItemInfo* active = global_inventory->getActiveItem();
//	string itemName = active->gettype();
//	RenderTextOnScreen(meshList[GEO_FPS], itemName, Color(0,0,0), 2, 25, 20);*/
//}
//
//void SceneBase::RenderMesh(Mesh *mesh, bool enableLight)
//{
//	Mtx44 MVP, modelView, modelView_inverse_transpose;
//
//	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//	modelView = viewStack.Top() * modelStack.Top();
//	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
//	if (enableLight)
//	{
//		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
//		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
//		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);
//
//		//load material
//		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
//		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
//		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
//		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
//	}
//	else
//	{
//		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	}
//
//	if (mesh->textureID > 0)
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	}
//	else
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
//	}
//
//
//	mesh->Render(); //this line should only be called once
//	if (mesh->textureID > 0)
//	{
//		glBindTexture(GL_TEXTURE_2D, 0);
//	}
//}
//
//void SceneBase::RenderText(Mesh* mesh, std::string text, Color color)
//{
//	if (!mesh || mesh->textureID <= 0) //Proper error check
//	{
//		return;
//	}
//
//	glDisable(GL_DEPTH_TEST);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
//	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
//	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	for (unsigned i = 0; i < text.length(); ++i)
//	{
//		Mtx44 characterSpacing;
//		characterSpacing.SetToTranslation(i * 1.0f, 0.f, 0); //1.0f is the spacing of each character, you may change this value
//		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
//		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//
//		mesh->Render((unsigned)text[i] * 6, 6);
//	}
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
//{
//	if (!mesh || mesh->textureID <= 0) //Proper error check
//	{
//		return;
//	}
//
//	glDisable(GL_DEPTH_TEST);
//
//	Mtx44 ortho;
//	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
//	projectionStack.PushMatrix();
//	projectionStack.LoadMatrix(ortho);
//	viewStack.PushMatrix();
//	viewStack.LoadIdentity(); //No need camera for ortho mode
//	modelStack.PushMatrix();
//	modelStack.LoadIdentity(); //Reset modelStack
//	modelStack.Scale(size, size, size);
//	modelStack.Translate(x, y, 0);
//
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
//	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
//	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	for (unsigned i = 0; i < text.length(); ++i)
//	{
//		Mtx44 characterSpacing;
//		characterSpacing.SetToTranslation(i * 0.5f + 0.5f, 0.5f, 0); //0.5f beside i is the spacing of each character, you may change this value
//		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
//		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//
//		mesh->Render((unsigned)text[i] * 6, 6);
//	}
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
//
//	//Add these code just before glEnable(GL_DEPTH_TEST);
//	projectionStack.PopMatrix();
//	viewStack.PopMatrix();
//	modelStack.PopMatrix();
//
//
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey)
//{
//	glDisable(GL_DEPTH_TEST);
//	Mtx44 ortho;
//	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
//	projectionStack.PushMatrix();
//	projectionStack.LoadMatrix(ortho);
//	viewStack.PushMatrix();
//	viewStack.LoadIdentity(); //No need camera for ortho mode
//
//	modelStack.PushMatrix();
//	modelStack.LoadIdentity();
//	modelStack.Translate((float)x, (float)y, 0);
//	modelStack.Scale((float)sizex, (float)sizey, 1);
//	//to do: scale and translate accordingly
//	RenderMesh(mesh, false); //UI should not have light
//	projectionStack.PopMatrix();
//	viewStack.PopMatrix();
//	modelStack.PopMatrix();
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::resetAll()
//{
//	camera.position.Set(0.f, 0.f, 484.f);
//}
//
//void SceneBase::Exit()
//{
//	// Cleanup VBO here
//	for (int i = 0; i < NUM_GEOMETRY; ++i)
//	{
//		if (meshList[i] != NULL)
//		{
//			delete meshList[i];
//		}
//	}
//	glDeleteVertexArrays(1, &m_vertexArrayID);
//
//	glDeleteProgram(m_programID);
//}
//
////#include "SceneBase.h"
////#include "GL\glew.h"
////#include "Mtx44.h"
////#include "Application.h"
////#include "MeshBuilder.h"
////#include "LoadTGA.h"
////#include "LoadOBJ.h"
////
////#include "shader.hpp"
////#include "Utility.h"
////
////#include <iostream>
////#include <iomanip>
////#include <stdlib.h>
////
////#include "ItemInfo.h"
////#include "Inventory.h"
////
////
////using std::cout;
////using std::cin;
////
////SceneBase::SceneBase()
////{
////}
////
////SceneBase::~SceneBase()
////{
////}
////
////Inventory* global_inventory = 0;
////void SceneBase::Init()
////{
////	// Set background color to black 
////	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
////
////	// Enable depth test
////	glEnable(GL_DEPTH_TEST);
////	glEnable(GL_CULL_FACE);
////
////	// Enable blending
////	glEnable(GL_BLEND);
////	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
////
////	// Init VBO here
////
////	// Generate a default VAO for now
////	glGenVertexArrays(1, &m_vertexArrayID);
////	glBindVertexArray(m_vertexArrayID);
////
////	//Load vertex and fragment shaders
////	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
////
////	//Get a handle for our "MVP" uniform
////	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
////	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
////	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
////	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
////	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
////	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
////	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
////
////	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
////	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
////	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
////	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
////	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
////	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
////	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
////	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
////	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
////	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
////	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
////
////	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
////	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
////	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
////	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
////	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
////	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
////	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
////	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
////	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
////	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
////	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
////
////	m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
////	m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
////	m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
////	m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
////	m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
////	m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
////	m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
////	m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
////	m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
////	m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
////	m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");
////
////	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
////
////	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
////
////	// Get a handle for our "colorTexture" uniform
////	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
////	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
////
////	// Get a handle for our "textColor" uniform
////	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
////	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
////
////
////	// Use our shader
////	glUseProgram(m_programID);
////
////	for (int i = 0; i < NUM_GEOMETRY; ++i)
////	{
////		meshList[i] = NULL;
////	}
////
////	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1, 1, 1);
////
////	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 20, 20, 1);
////	meshList[GEO_LIGHTBALL2] = MeshBuilder::GenerateSphere("lightball_2", Color(0.5f, 0.f, 0.f), 20, 20, 1);
////	meshList[GEO_LIGHTBALL3] = MeshBuilder::GenerateSphere("lightball_3", Color(1.f, 1.f, 0.f), 20, 20, 1);
////
////	meshList[GEO_GROUND] = MeshBuilder::GenerateQuad("grass", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_GROUND]->textureID = LoadTGA("Image//grass.tga");
////
////	//Skybox Day
////	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");
////
////	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");
////
////	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");
////
////	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");
////
////	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");
////
////	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");
////
////	//Skybox Night
////	meshList[GEO_FRONTn] = MeshBuilder::GenerateQuad("frontn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_FRONTn]->textureID = LoadTGA("Image//frontn.tga");
////
////	meshList[GEO_BACKn] = MeshBuilder::GenerateQuad("backn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_BACKn]->textureID = LoadTGA("Image//backn.tga");
////
////	meshList[GEO_TOPn] = MeshBuilder::GenerateQuad("topn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_TOPn]->textureID = LoadTGA("Image//topn.tga");
////
////	meshList[GEO_BOTTOMn] = MeshBuilder::GenerateQuad("bottomn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_BOTTOMn]->textureID = LoadTGA("Image//bottomn.tga");
////
////	meshList[GEO_LEFTn] = MeshBuilder::GenerateQuad("leftn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_LEFTn]->textureID = LoadTGA("Image//leftn.tga");
////
////	meshList[GEO_RIGHTn] = MeshBuilder::GenerateQuad("rightn", Color(1, 1, 1), 1.f, 1.f);
////	meshList[GEO_RIGHTn]->textureID = LoadTGA("Image//rightn.tga");
////
////	//Text
////	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
////	meshList[GEO_TEXT]->textureID = LoadTGA("Image//comic.tga");
////
////	meshList[GEO_X] = MeshBuilder::GenerateText("x", 16, 16);
////	meshList[GEO_X]->textureID = LoadTGA("Image//comic.tga");
////
////	meshList[GEO_Y] = MeshBuilder::GenerateText("y", 16, 16);
////	meshList[GEO_Y]->textureID = LoadTGA("Image//comic.tga");
////
////	meshList[GEO_Z] = MeshBuilder::GenerateText("z", 16, 16);
////	meshList[GEO_Z]->textureID = LoadTGA("Image//comic.tga");
////
////	meshList[GEO_FPS] = MeshBuilder::GenerateText("FPS", 16, 16);
////	meshList[GEO_FPS]->textureID = LoadTGA("Image//comic.tga");
////
////	meshList[GEO_COUNTDOWN] = MeshBuilder::GenerateText("Time", 16, 16);
////	meshList[GEO_COUNTDOWN]->textureID = LoadTGA("Image//comic.tga");
////
////	//Environment
////	meshList[GEO_MOUNTAIN] = MeshBuilder::GenerateOBJ("mountain", "OBJ//mountain.obj");
////	meshList[GEO_MOUNTAIN]->textureID = LoadTGA("Image//objects.tga");
////
////	meshList[GEO_MOUNTAIN_2] = MeshBuilder::GenerateOBJ("mountain_2", "OBJ//mountain.obj");
////	meshList[GEO_MOUNTAIN_2]->textureID = LoadTGA("Image//objects.tga");
////
////	meshList[GEO_MESSAGES] = MeshBuilder::GenerateText("messages", 16, 16);
////	meshList[GEO_MESSAGES]->textureID = LoadTGA("Image//comic.tga");
////
////	//Sprites
////	meshList[GEO_HANDL1] = MeshBuilder::GenerateOBJ("handL1", "OBJ//quad.obj");
////	meshList[GEO_HANDL1]->textureID = LoadTGA("Image//Sprites//HandL1.tga");
////	meshList[GEO_HANDR1] = MeshBuilder::GenerateOBJ("handR1", "OBJ//quad.obj");
////	meshList[GEO_HANDR1]->textureID = LoadTGA("Image//Sprites//HandR1.tga");
////	meshList[GEO_HANDL2] = MeshBuilder::GenerateOBJ("handL2", "OBJ//quad.obj");
////	meshList[GEO_HANDL2]->textureID = LoadTGA("Image//Sprites//HandL2.tga");
////	meshList[GEO_HANDR2] = MeshBuilder::GenerateOBJ("handR2", "OBJ//quad.obj");
////	meshList[GEO_HANDR2]->textureID = LoadTGA("Image//Sprites//HandR2.tga");
////	meshList[GEO_HANDI] = MeshBuilder::GenerateOBJ("handI", "OBJ//quad.obj");
////	meshList[GEO_HANDI]->textureID = LoadTGA("Image//Sprites//HandI.tga");
////	meshList[GEO_GUN1] = MeshBuilder::GenerateOBJ("gun1", "OBJ//quad.obj");
////	meshList[GEO_GUN1]->textureID = LoadTGA("Image//Sprites//Gun1.tga");
////	meshList[GEO_GUN2] = MeshBuilder::GenerateOBJ("gun2", "OBJ//quad.obj");
////	meshList[GEO_GUN2]->textureID = LoadTGA("Image//Sprites//Gun2.tga");
////	meshList[GEO_GUN3] = MeshBuilder::GenerateOBJ("gun3", "OBJ//quad.obj");
////	meshList[GEO_GUN3]->textureID = LoadTGA("Image//Sprites//Gun3.tga");
////	meshList[GEO_GUNI] = MeshBuilder::GenerateOBJ("gunI", "OBJ//quad.obj");
////	meshList[GEO_GUNI]->textureID = LoadTGA("Image//Sprites//GunI.tga");
////	meshList[GEO_SWORD1] = MeshBuilder::GenerateOBJ("sword1", "OBJ//quad.obj");
////	meshList[GEO_SWORD1]->textureID = LoadTGA("Image//Sprites//Sword1.tga");
////	meshList[GEO_SWORD2] = MeshBuilder::GenerateOBJ("sword2", "OBJ//quad.obj");
////	meshList[GEO_SWORD2]->textureID = LoadTGA("Image//Sprites//Sword2.tga");
////	meshList[GEO_SWORD3] = MeshBuilder::GenerateOBJ("sword3", "OBJ//quad.obj");
////	meshList[GEO_SWORD3]->textureID = LoadTGA("Image//Sprites//Sword3.tga");
////	meshList[GEO_SWORDI] = MeshBuilder::GenerateOBJ("swordI", "OBJ//quad.obj");
////	meshList[GEO_SWORDI]->textureID = LoadTGA("Image//Sprites//SwordI.tga");
////	meshList[GEO_TORCH] = MeshBuilder::GenerateOBJ("torch", "OBJ//quad.obj");
////	meshList[GEO_TORCH]->textureID = LoadTGA("Image//Sprites//Torch.tga");
////	meshList[GEO_TORCHI] = MeshBuilder::GenerateOBJ("torchI", "OBJ//quad.obj");
////	meshList[GEO_TORCHI]->textureID = LoadTGA("Image//Sprites//TorchI.tga");
////	meshList[GEO_HEALTHPOTION] = MeshBuilder::GenerateOBJ("healthPotion", "OBJ//quad.obj");
////	meshList[GEO_HEALTHPOTION]->textureID = LoadTGA("Image//Sprites//HealthPotion.tga");
////	meshList[GEO_ANTIDOTE] = MeshBuilder::GenerateOBJ("antidote", "OBJ//quad.obj");
////	meshList[GEO_ANTIDOTE]->textureID = LoadTGA("Image//Sprites//Antidote.tga");
////
////	meshList[GEO_GUN_ICON] = MeshBuilder::GenerateOBJ("antidote", "OBJ//Wall.obj");
////	meshList[GEO_GUN_ICON]->textureID = LoadTGA("Image//Sprites//GunIcon.tga");
////
////	//Item
////	meshList[GEO_INVENTORY] = MeshBuilder::GenerateOBJ("Inventory", "OBJ//inventory.obj");
////	meshList[GEO_INVENTORY]->textureID = LoadTGA("Image//inventory.tga");
////
////	meshList[GEO_MINI_PLAYER] = MeshBuilder::GenerateOBJ("mini_player", "OBJ//inventory.obj");
////	meshList[GEO_MINI_PLAYER]->textureID = LoadTGA("Image//mini_player.tga");
////
////	meshList[GEO_MINI_GROUND] = MeshBuilder::GenerateOBJ("mini_ground", "OBJ//inventory.obj");
////	meshList[GEO_MINI_GROUND]->textureID = LoadTGA("Image//grass.tga");
////
////	meshList[GEO_MINI_ENEMY] = MeshBuilder::GenerateOBJ("mini_enemy", "OBJ//inventory.obj");
////	meshList[GEO_MINI_ENEMY]->textureID = LoadTGA("Image//mini_enemy.tga");
////
////	meshList[GEO_GAME_HUD] = MeshBuilder::GenerateOBJ("game_hud", "OBJ//inventory.obj");
////	meshList[GEO_GAME_HUD]->textureID = LoadTGA("Image//game_hud.tga");
////
////	meshList[GEO_HP] = MeshBuilder::GenerateOBJ("game_hp", "OBJ//inventory.obj");
////	meshList[GEO_HP]->textureID = LoadTGA("Image//hp_bar.tga");
////
////	meshList[GEO_EN] = MeshBuilder::GenerateOBJ("game_en", "OBJ//inventory.obj");
////	meshList[GEO_EN]->textureID = LoadTGA("Image//en_bar.tga");
////
////	//Enemy 
////	meshList[GEO_ENEMYHEAD] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyHead.obj");
////	meshList[GEO_ENEMYHEAD]->textureID = LoadTGA("Image//Enemy//EnemyHead.tga");
////
////	meshList[GEO_ENEMYRIGHTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightArm.obj");
////	meshList[GEO_ENEMYRIGHTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
////
////	meshList[GEO_ENEMYLEFTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftArm.obj");
////	meshList[GEO_ENEMYLEFTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
////
////	meshList[GEO_ENEMYLEFTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftLeg.obj");
////	meshList[GEO_ENEMYLEFTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
////
////	meshList[GEO_ENEMYRIGHTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightLeg.obj");
////	meshList[GEO_ENEMYRIGHTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
////
////	meshList[GEO_ENEMYTORSO] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyTorso.obj");
////	meshList[GEO_ENEMYTORSO]->textureID = LoadTGA("Image//Enemy//EnemyTorso.tga");
////
////	//Enemy 2
////	meshList[GEO_ENEMYRIGHTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightArm.obj");
////	meshList[GEO_ENEMYRIGHTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
////	meshList[GEO_ENEMYLEFTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftArm.obj");
////	meshList[GEO_ENEMYLEFTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
////	meshList[GEO_ENEMYLEFTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftLeg.obj");
////	meshList[GEO_ENEMYLEFTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
////	meshList[GEO_ENEMYRIGHTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightLeg.obj");
////	meshList[GEO_ENEMYRIGHTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
////	meshList[GEO_ENEMYTORSO2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2Torso.obj");
////	meshList[GEO_ENEMYTORSO2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
////
////	//Enemy 3
////	meshList[GEO_ENEMYRIGHTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightArm.obj");
////	meshList[GEO_ENEMYRIGHTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
////	meshList[GEO_ENEMYLEFTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftArm.obj");
////	meshList[GEO_ENEMYLEFTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
////	meshList[GEO_ENEMYLEFTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftLeg.obj");
////	meshList[GEO_ENEMYLEFTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
////	meshList[GEO_ENEMYRIGHTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightLeg.obj");
////	meshList[GEO_ENEMYRIGHTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
////	meshList[GEO_ENEMYTORSO3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3Torso.obj");
////	meshList[GEO_ENEMYTORSO3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
////
////	//Enemy 4
////	meshList[GEO_ENEMYRIGHTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RightArm.obj");
////	meshList[GEO_ENEMYRIGHTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
////	meshList[GEO_ENEMYLEFTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftArm.obj");
////	meshList[GEO_ENEMYLEFTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
////	meshList[GEO_ENEMYLEFTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftLeg.obj");
////	meshList[GEO_ENEMYLEFTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
////	meshList[GEO_ENEMYRIGHTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RighLeg.obj");
////	meshList[GEO_ENEMYRIGHTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
////	meshList[GEO_ENEMYTORSO4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4Torso.obj");
////	meshList[GEO_ENEMYTORSO4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
////
////	//Flicker
////	meshList[GEO_FLICKER] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//quad.obj");
////	meshList[GEO_FLICKER]->textureID = LoadTGA("Image//blood//bloodflicker.tga");
////
////
////	meshList[GEO_SPIDER] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Spider.obj");
////	meshList[GEO_SPIDER]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
////
////	meshList[GEO_ENEMYHEALTHBAR] = MeshBuilder::GenerateQuad("enemyHealthBar", Color(1.0f, 0.0f, 0.0f), 1, 1);
////
////	meshList[GEO_ARROW] = MeshBuilder::GenerateOBJ("Arrow", "OBJ//inventory.obj");
////	meshList[GEO_ARROW]->textureID = LoadTGA("Image//Arrow.tga");
////
////	meshList[GEO_ACTIVE_SELECT] = MeshBuilder::GenerateOBJ("active_select", "OBJ//inventory.obj");
////	meshList[GEO_ACTIVE_SELECT]->textureID = LoadTGA("Image//active_select.tga");
////
////	meshList[GEO_SECONDARY_SELECT] = MeshBuilder::GenerateOBJ("secondary_select", "OBJ//inventory.obj");
////	meshList[GEO_SECONDARY_SELECT]->textureID = LoadTGA("Image//secondary_select.tga");
////
////	meshList[GEO_TIME] = MeshBuilder::GenerateOBJ("time_bar", "OBJ//inventory.obj");
////	meshList[GEO_TIME]->textureID = LoadTGA("Image//time_bar.tga");
////
////	//Prevent Jerk
////	camera.Init(Vector3(0, 0, 484), Vector3(0, 0, 0), Vector3(0, 1, 0));
////
////	//Projection
////	Mtx44 projection;
////	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 4000.f);
////	projectionStack.LoadMatrix(projection);
////
////	//Spot light
////	light[0].type = Light::LIGHT_SPOT;
////	light[0].position.Set(0, 10, 0);// this is overidden at the update
////	light[0].color.Set(1, 1, 1);
////	light[0].power = 0;
////	light[0].kC = 1.f;
////	light[0].kL = 0.01f;
////	light[0].kQ = 0.001f;
////	light[0].cosCutoff = cos(Math::DegreeToRadian(25)); // higher angle = more area covered with light
////	light[0].cosInner = cos(Math::DegreeToRadian(15)); // use to toggle inner light , lower angle  = light more concentrated
////	light[0].exponent = 3.f;
////	light[0].spotDirection.Set(0.f, 1.f, 0.f); // this is overidden at the update
////
////	light[1].type = Light::LIGHT_POINT;
////	light[1].position.Set(0.f, 1000.f, 0.f);
////	light[1].color.Set(1.f, 0.f, 0.f);
////	light[1].power = 10;
////	light[1].kC = 1.f;
////	light[1].kL = 0.01f;
////	light[1].kQ = 0.001f;
////	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
////	light[1].cosInner = cos(Math::DegreeToRadian(30));
////	light[1].exponent = 3.f;
////	light[1].spotDirection.Set(0.f, 1.f, 0.f);
////
////	light[2].type = Light::LIGHT_SPOT;
////	light[2].position.Set(0.f, 0.f, 50.f);
////	light[2].color.Set(1.f, 1.f, 0.f);
////	light[2].power = 0;
////	light[2].kC = 1.f;
////	light[2].kL = 0.01f;
////	light[2].kQ = 0.001f;
////	light[2].cosCutoff = cos(Math::DegreeToRadian(45));
////	light[2].cosInner = cos(Math::DegreeToRadian(30));
////	light[2].exponent = 3.f;
////	light[2].spotDirection.Set(0.f, 1.f, 0.f);
////
////	// Make sure you pass uniform parameters after glUseProgram()
////	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
////	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
////	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
////	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
////	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
////	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
////	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
////	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
////	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);
////
////	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
////	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
////	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
////	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
////	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
////	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
////	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
////	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
////	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);
////
////	glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
////	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
////	glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
////	glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
////	glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
////	glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
////	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
////	glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
////	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);
////
////	// Make sure you pass uniform parameters after glUseProgram()
////	glUniform1i(m_parameters[U_NUMLIGHTS], 3);
////
////
////	// Param 1 - name of sound ---- Param 2 -distance sound able to travel --- Param 3 - volume of sound (0 to 1)
////	soundStorage.push_back(new Sound("gunshot.mp3", 1000, 1));
////	soundStorage.push_back(new Sound("splatter.mp3", 1000, 1));
////	soundStorage.push_back(new Sound("run.mp3", 1000, 0.5));
////	soundStorage.push_back(new Sound("backgroundmusic.mp3"));
////	soundStorage.push_back(new Sound("jump.mp3", 1000, 0.5));
////	soundStorage.push_back(new Sound("footstep.mp3", 1000, 1));
////
////	/* vec3df somePosition = { 0, 0,0};
////	 soundStorage[1]->play3DSound(true, false, false, somePosition);*/
////
////	/*soundStorage[3]->play2DSound(true, false, false); */
////
////	/*objFactory.createFactoryObject(new Enemy(this, Vector3(Math::RandFloatMinMax(-50, 50), 0, Math::RandFloatMinMax(-50, 50))) );*/
////
////	//----------------Inventory--------------
////	inventoryOpen = false;
////
////	//initialise singleton of inventory class
////
////	if (global_inventory == 0)
////	{
////		global_inventory = new Inventory();
////		global_inventory->setdefined(1);
////	}
////	//type , damage , range , reload speed , attack speed
////	ItemInfo* gun = new ItemInfo("gun", 20, 20, 10, 15);
////	global_inventory->addItem(gun);
////
////	ItemInfo* torch = new ItemInfo("torch", 0, 50, 0, 10);
////	global_inventory->addItem(torch);
////	// adding items to inventory
////	ItemInfo* fist = new ItemInfo();
////	global_inventory->addItem(fist);
////
////	//delay between keypresses while in menu
////	startTime = 0.0f;
////	cooldown = 15.0f;
////
////	//speed ,damage ,hp, range ,this
////	Enemy * newEnemy = new Spider(70.f, 5.f, 50.f, 100.f);
////	newEnemy->addWaypoint(Vector3(200, 0, 200));
////	newEnemy->addWaypoint(Vector3(200, 0, -200));
////	newEnemy->addWaypoint(Vector3(-200, 0, -200));
////	newEnemy->addWaypoint(Vector3(-200, 0, 200));
////	enemyStorage.push_back(newEnemy);
////
////	// speed , damage ,hp , range , this , int(used to identify which type of robot)
////	Enemy * newEnemy2 = new Robot(70.f, 5.f, 100.f, 100.f, 1);
////	newEnemy2->addWaypoint(Vector3(300, 0, -100));
////	newEnemy2->addWaypoint(Vector3(400, 0, -400));
////	newEnemy2->addWaypoint(Vector3(-400, 0, -400));
////	newEnemy2->addWaypoint(Vector3(-400, 0, 400));
////	enemyStorage.push_back(newEnemy2);
////
////	Enemy * newEnemy3 = new Spider(70.f, 5.f, 50.f, 100.f);
////	newEnemy3->addWaypoint(Vector3(-400, 0, 200));
////	newEnemy3->addWaypoint(Vector3(300, 0, -300));
////	newEnemy3->addWaypoint(Vector3(-2300, 0, -300));
////	newEnemy3->addWaypoint(Vector3(-2300, 0, 200));
////	enemyStorage.push_back(newEnemy3);
////
////	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
////	{
////		(*it)->_Position = (*it)->currWaypoint->getPosition();
////	}
////}
////
////void SceneBase::Update(double dt)
////{
////	vec3df camPos = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
////	Vector3 view = camera.target - camera.position;
////	vec3df dir = { view.x, view.y, view.z };
////	vec3df up = { camera.up.x, camera.up.y, camera.up.z };
////	vec3df zero = { 0, 0, 0 };
////
////	for (unsigned i = 0; i < soundStorage.size(); ++i)
////	{
////		soundStorage[i]->getSoundEngine()->setListenerPosition(camPos, dir.normalize(), zero, up.normalize());
////		soundStorage[i]->getSoundEngine()->update();
////	}
////
////	Robot::dtFromScene(dt);
////	Robot::positionFromCamera(camera);
////
////	Spider::dtFromScene(dt);
////	Spider::positionFromCamera(camera);
////
////	//Bullet::dtFromScene(dt);
////	//Bullet::positionFromCamera(camera);
////
////	_dt = (float)dt;
////	_elapsedTime += _dt;
////
////	static float rotateLimit = 1;
////	rotateArm += (float)(50 * rotateLimit * dt);
////    if (rotateArm > 10)
////    {
////        rotateArm = 10.f;
////        rotateLimit = -1;
////    }
////    if (rotateArm < -10)
////    {
////        rotateArm = -10.f;
////        rotateLimit = 1;
////    }
////
////	static bool canPress = true;
////
////	if (!Application::IsKeyPressed('Q'))
////		canPress = true;
////
////	// Light on
////	if (canPress && Application::IsKeyPressed('Q')) {
////		light[0].power = (light[0].power > 0) ? 0.0f : 3.0f; // Toggle Power between 0 and 2
////		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
////		canPress = false;
////	}
////	if (light[0].power > 0)
////	{
////		float ys = 10.f;
////		energy -= ys * _dt;
////	}
////	if (torchDead == true)
////	{
////		light[0].power = 0;
////		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
////	}
////	if (energy < 0)
////	{
////		energy = 0;
////	}
////	// Flashlight position and direction
////	light[0].position.Set(camera.position.x, camera.position.y, camera.position.z);
////	light[0].spotDirection = camera.position - camera.target;  // move direction of light along view vector
////
////	//Process  obj movement
////	objFactory.processInteraction();
////
////	static const float LSPEED = 10.f;
////	srand((unsigned)time(NULL));
////
////	static float rotateWorld = 1;
////
////	float run = 1.f;
////
////	if (Application::IsKeyPressed(MK_LBUTTON))
////	{
////		if (_elapsedTime >= nextBulletTime)
////		{
////			objFactory.createFactoryObject(new Bullet(this, camera.getPosition(), camera.getYaw(), camera.getPitch()));
////			nextBulletTime = _elapsedTime + coolDown;
////			soundStorage[0]->play3DSound(false, false, false, camPos);
////			bulletTouch = false;
////			swing = true;
////		}
////	}
////	if (swing == true)
////	{
////		swingTime++;
////	}
////
////	if (Application::IsKeyPressed('I'))
////	{
////		if (inventoryOpen && startTime >= cooldown)
////		{
////			inventoryOpen = false;
////			startTime = 0;
////		}
////		else if (startTime >= cooldown)
////		{
////			inventoryOpen = true;
////			startTime = 0;
////		}
////	}
////
////	vec3df footPos = { camera.getPosition().x, camera.getPosition().y - 20, camera.getPosition().z };
////	//FootStep Sound
////	if (Application::IsKeyPressed('W') && (_elapsedTime >= nextWalkTime))
////	{
////		nextWalkTime = _elapsedTime + coolDown + 0.5f;
////		soundStorage[5]->play3DSound(false, false, true, footPos);
////	}
////	if (Application::IsKeyPressed('A') && (_elapsedTime >= nextWalkTime))
////	{
////		nextWalkTime = _elapsedTime + coolDown + 0.5f;
////		soundStorage[5]->play3DSound(false, false, true, footPos);
////	}
////	if (Application::IsKeyPressed('S') && (_elapsedTime >= nextWalkTime))
////	{
////		nextWalkTime = _elapsedTime + coolDown + 0.5f;
////		soundStorage[5]->play3DSound(false, false, true, footPos);
////	}
////	if (Application::IsKeyPressed('D') && (_elapsedTime >= nextWalkTime))
////	{
////		nextWalkTime = _elapsedTime + coolDown + 0.5f;
////		soundStorage[5]->play3DSound(false, false, true, footPos);
////	}
////
////	if (Application::IsKeyPressed(VK_SPACE) && (_elapsedTime >= nextJump))
////	{
////		nextJump = _elapsedTime + coolDown;
////		soundStorage[4]->play3DSound(false, false, true, footPos);
////	}
////	if (Application::IsKeyPressed(VK_SHIFT) && (_elapsedTime >= nextRun))
////	{
////		nextRun = _elapsedTime + coolDown;
////		soundStorage[2]->play3DSound(false, false, true, footPos);
////	}
////
////	//Skybox Rotation
////	rotateSkybox += (float)(1 * rotateWorld * dt);
////
////	//Skybox
////	if (rotateSkybox > 360)
////	{
////		rotateSkybox = 0;
////	}
////
////	if (Application::IsKeyPressed(VK_NUMPAD5))
////	{
////		run = 3.f;
////	}
////
////	//Reset
////	if (Application::IsKeyPressed('R'))
////	{
////		resetAll();
////	}
////
////	if (Application::IsKeyPressed('7'))
////	{
////		light[0].type = Light::LIGHT_POINT;
////		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
////		light[1].type = Light::LIGHT_POINT;
////		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
////		//to do: switch light type to POINT and pass the information to shader
////	}
////	if (Application::IsKeyPressed('8'))
////	{
////		light[0].type = Light::LIGHT_DIRECTIONAL;
////		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
////		light[1].type = Light::LIGHT_DIRECTIONAL;
////		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
////		//to do: switch light type to DIRECTIONAL and pass the information to shader
////	}
////	if (Application::IsKeyPressed('9'))
////	{
////		light[0].type = Light::LIGHT_SPOT;
////		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
////		light[1].type = Light::LIGHT_SPOT;
////		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
////		//to do: switch light type to SPOT and pass the information to shader
////	}
////
////	camera.Update(dt);
////
////	//FPS Counter
////	FPS = 1 / (float)dt;
////
////	startTime++;
////
////	enemyUpdate(dt);
////
////	timeleft--;
////}
////
////void SceneBase::enemyUpdate(double dt)
////{
////	//-------This function is called in SceneBase::Update(double dt) to process Enemy interactions-----------------
////
////	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
////	{
////		(*it)->update();
////
////		for (vector<Object*>::iterator factoryIt = factoryIt = objFactory.Container.begin(); factoryIt != objFactory.Container.end(); factoryIt++)
////		{
////			if ((*factoryIt)->type == SceneBase::GEO_LIGHTBALL3)   //BULLET INTERACTION WITH ENEMY
////			{
////				if (((*factoryIt)->position_ - (*it)->_Position).Length() < 20 && bulletTouch == false)
////				{
////					if ((*it)->enemytype == 1)
////					{
////						(*it)->_Hp -= 10;
////						(*it)->healthBarSpider -= 2.f;
////						damaged = true;
////						bulletTouch = true;
////
////						if ((*it)->_Hp == 0)
////						{
////							(*it)->setState(2);  //  death is at enum 2
////						}
////					}
////					if ((*it)->enemytype == 2)
////					{
////						(*it)->_Hp -= 10;
////						(*it)->healthBarRobot1 -= 2.f;
////						damaged = true;
////						bulletTouch = true;
////
////						if ((*it)->_Hp == 0)
////						{
////							(*it)->setState(2);  //  death is at enum 2
////						}
////					}
////				}
////			}
////		}
////	}
////}
////void SceneBase::Render()
////{
////	srand((unsigned)time(NULL));
////
////	//Clear color & depth buffer every frame
////	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
////
////	Mtx44 MVP;
////
////	viewStack.LoadIdentity(); //No need camera for now, set it at World's origin
////	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
////	modelStack.LoadIdentity();
////
////	//Passing light position to shader
////	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
////
////	//Light 1
////	if (light[0].type == Light::LIGHT_DIRECTIONAL)
////	{
////		Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
////		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
////		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
////	}
////	else if (light[0].type == Light::LIGHT_SPOT)
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
////		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
////		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
////		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
////	}
////	else
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
////		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
////	}
////
////	//Light 2
////	if (light[1].type == Light::LIGHT_DIRECTIONAL)
////	{
////		Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
////		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
////		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
////	}
////	else if (light[1].type == Light::LIGHT_SPOT)
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
////		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
////		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
////		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
////	}
////	else
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
////		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
////	}
////
////	//Light 2
////	if (light[2].type == Light::LIGHT_DIRECTIONAL)
////	{
////		Vector3 lightDir(light[2].position.x, light[2].position.y, light[2].position.z);
////		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
////		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
////	}
////	else if (light[2].type == Light::LIGHT_SPOT)
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
////		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
////		Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
////		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
////	}
////	else
////	{
////		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
////		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
////	}
////
////
////	//Generate Axes
////	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top(); //Remember, matrix multiplication is the other way around
////	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
////	RenderMesh(meshList[GEO_AXES], false);
////
////	modelStack.PushMatrix();
////	modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
////	RenderSkybox();
////	modelStack.PopMatrix();
////
////	//Environment
////	renderMountains();
////	renderGround();
////	renderPosition();
////
////	renderText();
////
////	objFactory.renderFactoryObject();
////
////	renderEnemy();
////
////	renderSprites();
////
////	renderHUD();
////}
////
////void SceneBase::renderEnemy()
////{
////	for (vector<Enemy *> ::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
////	{
////		if (((*it)->_Position - camera.getPosition()).Length() < 10 && (*it)->getState() != Spider::spiderState::death &&
////			(*it)->getState() != Robot::robotState::death)
////		{
////			RenderMeshOnScreen(meshList[GEO_FLICKER], 40, 30, 80, 60);
////			vec3df bloodStartingLocation = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
////			if (_elapsedTime >= nextSplatter)
////				soundStorage[1]->play3DSound(false, false, false, bloodStartingLocation);
////			nextSplatter = _elapsedTime + coolDown;
////
////			health--;
////		}
////
////		switch ((*it)->enemytype)
////		{
////
////		case   1:    // ----------------Spider ----------------------------
////		{
////			if ((*it)->getState() != Spider::spiderState::death)
////			{
////				//Spider
////				modelStack.PushMatrix();
////				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
////				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////				modelStack.Scale(10, 10, 10);
////				RenderMesh(meshList[GEO_SPIDER], true);
////				modelStack.PopMatrix();
////
////				//Health Bar
////				modelStack.PushMatrix();
////				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 1.3f, (*it)->_Position.z);
////				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////				modelStack.Rotate(90, 0, 0, 1);
////				if ((*it)->healthBarSpider>0)
////					modelStack.Scale(1, 1, (*it)->healthBarSpider);
////				else
////					modelStack.Scale(1, 1, 1);
////				RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
////				modelStack.PopMatrix();
////
////			}
////		}
////		break;
////		case 2:  // ---------------Robot1 ----------------------
////		{
////			if ((*it)->getState() != Robot::robotState::death)
////			{
////				if ((*it)->robotType == 1)
////				{
////					//Robot
////					modelStack.PushMatrix();
////					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
////					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////					modelStack.PushMatrix();
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYTORSO], true);
////					RenderMesh(meshList[GEO_ENEMYHEAD], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 40, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -40, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTARM], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 40, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -40, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTARM], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 40, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -40, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTLEG], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 40, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -40, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTLEG], true);
////					modelStack.PopMatrix();
////					modelStack.PopMatrix();
////
////					//Health Bar
////					modelStack.PushMatrix();
////					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 1.3f, (*it)->_Position.z);
////					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////					modelStack.Rotate(90, 0, 0, 1);
////					if ((*it)->healthBarRobot1>0)
////						modelStack.Scale(1, 1, (*it)->healthBarRobot1);
////					else
////						modelStack.Scale(1, 1, 1);
////					RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
////					modelStack.PopMatrix();
////				}
////
////				if ((*it)->robotType == 2)
////				{
////					//Robot 2
////					modelStack.PushMatrix();
////					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
////					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////					modelStack.PushMatrix();
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYTORSO2], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTARM2], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTARM2], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 5, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -5, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTLEG2], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 5, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -5, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTLEG2], true);
////					modelStack.PopMatrix();
////					modelStack.PopMatrix();
////				}
////
////				if ((*it)->robotType == 3)
////				{
////					//Robot 3
////					modelStack.PushMatrix();
////					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
////					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////					modelStack.PushMatrix();
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYTORSO3], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTARM3], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTARM3], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 1, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -1, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTLEG3], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 1, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -1, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTLEG3], true);
////					modelStack.PopMatrix();
////					modelStack.PopMatrix();
////				}
////				if ((*it)->robotType == 4)
////				{
////					//Robot 4
////					modelStack.PushMatrix();
////					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
////					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
////					modelStack.PushMatrix();
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYTORSO4], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTARM4], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTARM4], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(-rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYRIGHTLEG4], true);
////					modelStack.PopMatrix();
////					modelStack.PushMatrix();
////					modelStack.Translate(0, 10, 0);
////					modelStack.Rotate(rotateArm, 0, 0, 1);
////					modelStack.Translate(0, -10, 0);
////					modelStack.Scale(10, 10, 10);
////					RenderMesh(meshList[GEO_ENEMYLEFTLEG4], true);
////					modelStack.PopMatrix();
////					modelStack.PopMatrix();
////				}
////			}
////		}
////		break;
////		}
////	}
////}
////
////void SceneBase::renderHUD()
////{
////	if (inventoryOpen)
////	{
////		if (startTime >= cooldown)
////		{
////			if (Application::IsKeyPressed(VK_DOWN)) // scroll down item list
////			{
////				global_inventory->CycleDisplay(0);
////				startTime = 0;
////			}
////			else if (Application::IsKeyPressed(VK_UP)) // scroll up item list
////			{
////				global_inventory->CycleDisplay(1);
////				startTime = 0;
////			}
////			else if (Application::IsKeyPressed('J')) // equip primary
////			{
////				global_inventory->equipItem(1);
////				startTime = 0;
////			}
////			else if (Application::IsKeyPressed('K')) // equip secondary
////			{
////				global_inventory->equipItem(0);
////				startTime = 0;
////			}
////		}
////		RenderMeshOnScreen(meshList[GEO_INVENTORY], 40, 27, 80, 65);
////		renderInventory();
////		renderStats();
////	}
////	else
////	{
////		//in game hud
////		RenderMeshOnScreen(meshList[GEO_GAME_HUD], 40, 32, 80, 65);
////
////		if (health > 0)
////		{
////			RenderMeshOnScreen(meshList[GEO_HP], 5 + 11.3 * health / 100, 6.1, 105 * health / 100, 9);
////		}
////		if (energy > 0)
////		{
////			RenderMeshOnScreen(meshList[GEO_EN], 5 + 11.3* energy / 10000, 2.3, 105 * energy / 10000, 9);
////		}
////		if (energy == 0)
////		{
////			torchDead = true;
////		}
////		if (timeleft > 0)
////		{
////			RenderMeshOnScreen(meshList[GEO_TIME], 58.6 + 11.3* timeleft / 60000, 14.5, 105 * timeleft / 60000, 11);
////		}
////		renderRemainingTime();
////		//minimap
////		RenderMeshOnScreen(meshList[GEO_MINI_GROUND], 10, 50, 15, 15);
////		RenderMeshOnScreen(meshList[GEO_MINI_PLAYER], 10.5 + ((camera.getPosition().x / 1000) * 14), 50 + ((camera.getPosition().z / 1000)* 14.4), 6, 6);
////		for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
////		{
////			if ((*it)->getState() != Robot::robotState::death || (*it)->getState() != Spider::spiderState::death)
////				RenderMeshOnScreen(meshList[GEO_MINI_ENEMY], 10.5 + (((*it)->_Position.x / 1000) * 14), 50 + (((*it)->_Position.z / 1000) * 14.4), 10, 10);
////		}
////	}
////}
////
////void SceneBase::renderInventory()
////{
////	if (!global_inventory->pointer)
////	{
////		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 20, 27 , 30);
////	}
////	else
////	{
////		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 10, 27 , 30);
////	}
////
////	ItemInfo* activeItem = global_inventory->getActiveItem();
////	if (activeItem->gettype() == "gun")
////	{
////		RenderMeshOnScreen(meshList[GEO_GUNI], 15, 35, 130, 130);
////	}
////	else if (activeItem->gettype() == "fist")
////	{
////		RenderMeshOnScreen(meshList[GEO_HANDI], 15, 34, 50, 50);
////	}
////	else if (activeItem->gettype() == "torch")
////	{
////		RenderMeshOnScreen(meshList[GEO_TORCHI], 15, 35, 150, 150);
////	}
////	ItemInfo* secondaryItem = global_inventory->getSecondaryItem();
////	if (secondaryItem->gettype() == "gun")
////	{
////		RenderMeshOnScreen(meshList[GEO_GUNI], 33, 35, 130, 130);
////	}
////	else if (secondaryItem->gettype() == "fist")
////	{
////		RenderMeshOnScreen(meshList[GEO_HANDI], 32.5, 35, 50, 50);
////	}
////	else if (secondaryItem->gettype() == "torch")
////	{
////		RenderMeshOnScreen(meshList[GEO_TORCHI], 33, 35, 150, 150);
////	}
////
////	ItemInfo* ItemDisplay1 = global_inventory->getDisplay1();
////	if (ItemDisplay1->gettype() == "gun")
////	{
////		RenderMeshOnScreen(meshList[GEO_GUNI], 12, 23, 60, 60);
////	}
////	else if (ItemDisplay1->gettype() == "fist")
////	{
////		RenderMeshOnScreen(meshList[GEO_HANDI], 10, 40, 5, 5);
////	}
////	else if (ItemDisplay1->gettype() == "torch")
////	{
////		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 23, 70, 70);
////	}
////	if (ItemDisplay1 == activeItem)
////	{
////		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 23.2, 6, 7.2);
////	}
////	else if (ItemDisplay1 == secondaryItem)
////	{
////		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 23.2, 6, 7.2);
////	}
////	ItemInfo* ItemDisplay2 = global_inventory->getDisplay2();
////	if (ItemDisplay2->gettype() == "gun")
////	{
////		RenderMeshOnScreen(meshList[GEO_GUNI], 10, 10, 50, 50);
////	}
////	else if (ItemDisplay2->gettype() == "fist")
////	{
////		RenderMeshOnScreen(meshList[GEO_HANDI], 12, 13, 25 , 25);
////	}
////	else if (ItemDisplay2->gettype() == "torch")
////	{
////		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 13, 70, 70);
////	}
////	if (ItemDisplay2 == activeItem)
////	{
////		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 13.7, 6, 7.2);
////	}
////	else if (ItemDisplay2 == secondaryItem)
////	{
////		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 13.7, 6, 7.2);
////	}
////	
////	//Potions
////	RenderMeshOnScreen(meshList[GEO_HEALTHPOTION], 29, 23.5, 100, 100);
////	renderPotionCount();
////	RenderMeshOnScreen(meshList[GEO_ANTIDOTE], 29, 14, 100, 100);
////	renderAntidoteCount();
////}
////
////void SceneBase::renderMountains()
////{
////
////	float mountainsCoordX[4];
////	float mountainsCoordZ[4];
////
////	mountainsCoordX[0] = -200.f;
////	mountainsCoordZ[0] = -100.f;
////
////	mountainsCoordX[1] = 200.f;
////	mountainsCoordZ[1] = -70.f;
////
////	mountainsCoordX[2] = 320;
////	mountainsCoordZ[2] = 200.f;
////
////	mountainsCoordX[3] = -20.f;
////	mountainsCoordZ[3] = 300.f;
////
////	mountainsCoordX[4] = 0.f;
////	mountainsCoordZ[4] = -250.f;
////
////	for (unsigned i = 0; i < 5; i++)
////	{
////		modelStack.PushMatrix();
////		modelStack.Translate(mountainsCoordX[i], -30.f, mountainsCoordZ[i]);
////		modelStack.Scale(100.f, 50.f, 100.f);
////		RenderMesh(meshList[GEO_MOUNTAIN], true);
////		modelStack.PopMatrix();
////	}
////}
////
////
////void SceneBase::RenderSkybox()
////{
////	//Day
////	if (cycle == false)
////	{
////		modelStack.PushMatrix();
////		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 0.f, 998.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_FRONT], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 0.f, -998.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_BACK], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 998.f, 0.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_TOP], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, -998.f, 0.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_BOTTOM], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(998.f, 0.f, 0.f);
////		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_LEFT], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(-998.f, 0.f, 0.f);
////		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_RIGHT], false);
////		modelStack.PopMatrix();
////
////		modelStack.PopMatrix();
////	}
////
////	//Night
////	if (cycle == true)
////	{
////		modelStack.PushMatrix();
////		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 0.f, 998.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_FRONTn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 0.f, -998.f);
////		//modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_BACKn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, 998.f, 0.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_TOPn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(0.f, -998.f, 0.f);
////		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_BOTTOMn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(998.f, 0.f, 0.f);
////		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_LEFTn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PushMatrix();
////		//scale, translate, rotate
////		modelStack.Translate(-998.f, 0.f, 0.f);
////		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
////		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
////
////		modelStack.Scale(2000.f, 2000.f, 2000.f);
////		RenderMesh(meshList[GEO_RIGHTn], false);
////		modelStack.PopMatrix();
////
////		modelStack.PopMatrix();
////	}
////}
////
////
////void SceneBase::renderGround()
////{
////	modelStack.PushMatrix();
////	modelStack.Translate(0.f, -30.f, 0.f);
////	modelStack.Scale(1000.f, 1000.f, 1000.f);
////	RenderMesh(meshList[GEO_GROUND], true);
////	modelStack.PopMatrix();
////
////	modelStack.PushMatrix();
////	RenderMesh(meshList[GEO_GUN_ICON], true);
////	modelStack.PopMatrix();
////}
////
////void SceneBase::renderSprites()
////{
////	//Gun
////	//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100, 0, 0, 0, 1);
////	//if (swing == false)
////	//{
////	//	RenderMeshOnScreen(meshList[GEO_GUN1], 65, 9, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime < 15)
////	//{
////	//	RenderMeshOnScreen(meshList[GEO_GUN2], 65, 12, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime > 15 && swingTime < 30)
////	//{
////	//	RenderMeshOnScreen(meshList[GEO_GUN3], 65, 11, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime > 30)
////	//{
////	//	swing = false;
////	//	swingTime = 0;
////	//}
////
////	//Cannon
////	//if (swing == false)
////	//{
////	//RenderMeshOnScreen(meshList[GEO_CANNON1], 50, 11, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime < 20)
////	//{
////	//RenderMeshOnScreen(meshList[GEO_CANNON2], 50, 13, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime > 20 && swingTime < 40)
////	//{
////	//RenderMeshOnScreen(meshList[GEO_CANNON3], 50, 12, 100, 100, 0, 0, 0, 1);
////	//}
////	//if (swing == true && swingTime > 40)
////	//{
////	//	swing = false;
////	//	swingTime = 0;
////	//}
////
////	if (global_inventory->getActiveItem()->gettype() == "fist" || global_inventory->getSecondaryItem()->gettype() == "fist")
////	{
////		if (swing == false)
////		{
////			//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100);
////			RenderMeshOnScreen(meshList[GEO_HANDR1], 65, 5, 100, 100);
////		}
////		//Punching hands
////		if (swing == true)
////		{
////			//RenderMeshOnScreen(meshList[GEO_HANDL2], 15, 10, 100, 100);
////			RenderMeshOnScreen(meshList[GEO_HANDR2], 65, 10, 100, 100);
////			if (swingTime > 40)
////			{
////				swing = false;
////				swingTime = 0;
////			}
////		}
////	}
////	else if (global_inventory->getActiveItem()->gettype() == "gun" || global_inventory->getSecondaryItem()->gettype() == "gun")
////	{
////		if (swing == false)
////		{
////			RenderMeshOnScreen(meshList[GEO_GUN1], 55, 10, 100, 100);
////		}
////		if (swing == true && swingTime < 15)
////		{
////			RenderMeshOnScreen(meshList[GEO_GUN2], 55, 10, 100, 100);
////		}
////		if (swing == true && swingTime > 15 && swingTime < 30)
////		{
////			RenderMeshOnScreen(meshList[GEO_GUN3], 55, 10, 100, 100);
////		}
////		if (swing == true && swingTime > 30)
////		{
////			swing = false;
////			swingTime = 0;
////		}
////	}
////	else if (global_inventory->getActiveItem()->gettype() == "torch" || global_inventory->getSecondaryItem()->gettype() == "torch")
////		RenderMeshOnScreen(meshList[GEO_TORCH], 25, 5, 150, 150);
////}
////
////
////void SceneBase::renderPosition()
////{
////	std::string sX = "X: " + std::to_string((int)camera.position.x),
////		sY = "Y: " + std::to_string((int)camera.position.y),
////		sZ = "Z: " + std::to_string((int)camera.position.z);
////
////	modelStack.PushMatrix();
////	//No transform needed
////	RenderTextOnScreen(meshList[GEO_X], sX, Color(0, 1, 0), 3, 23, 19);
////	RenderTextOnScreen(meshList[GEO_Y], sY, Color(0, 1, 0), 3, 23, 18);
////	RenderTextOnScreen(meshList[GEO_Z], sZ, Color(0, 1, 0), 3, 23, 17);
////
////	modelStack.PopMatrix();
////}
////
////
////void SceneBase::renderText()
////{
////	std::string sFPS = "FPS: " + std::to_string(FPS);
////	sFPS.resize(9);
////	RenderTextOnScreen(meshList[GEO_FPS], sFPS, Color(1, 1, 0), 2, 0, 29);
////}
////
////void SceneBase::renderRemainingTime()
////{
////
////	std::string rTime = "";
////	int tempTime = timeleft;
////	int seconds = 0;
////	int minutes = 0;
////	while (tempTime >= 60)
////	{
////		tempTime -= 60;
////		seconds += 1;
////	}
////	while (seconds > 60)
////	{
////		seconds -= 60;
////		minutes += 1;
////	}
////	if (seconds > 9)
////	{
////		rTime = std::to_string(minutes) + ":" + std::to_string(seconds);
////	}
////	else
////	{
////		rTime = std::to_string(minutes) + ":0" + std::to_string(seconds);
////	}
////	RenderTextOnScreen(meshList[GEO_COUNTDOWN], rTime, Color(1, 0 ,0), 2, 30, 7);
////}
////
////void SceneBase::renderPotionCount()
////{
////	std::string count = "";
////	count = std::to_string(potionCount);
////	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 10);
////}
////
////void SceneBase::renderAntidoteCount()
////{
////	std::string count = "";
////	count = std::to_string(antidoteCount);
////	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 5);
////}
////
////void SceneBase::renderStats()
////{
////	/*ItemInfo* active = global_inventory->getActiveItem();
////	string itemName = active->gettype();
////	RenderTextOnScreen(meshList[GEO_FPS], itemName, Color(0,0,0), 2, 25, 20);*/
////}
////
////void SceneBase::RenderMesh(Mesh *mesh, bool enableLight)
////{
////	Mtx44 MVP, modelView, modelView_inverse_transpose;
////
////	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
////	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
////	modelView = viewStack.Top() * modelStack.Top();
////	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
////	if (enableLight)
////	{
////		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
////		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
////		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);
////
////		//load material
////		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
////		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
////		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
////		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
////	}
////	else
////	{
////		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
////	}
////
////	if (mesh->textureID > 0)
////	{
////		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
////		glActiveTexture(GL_TEXTURE0);
////		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
////		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
////	}
////	else
////	{
////		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
////	}
////
////
////	mesh->Render(); //this line should only be called once
////	if (mesh->textureID > 0)
////	{
////		glBindTexture(GL_TEXTURE_2D, 0);
////	}
////}
////
////void SceneBase::RenderText(Mesh* mesh, std::string text, Color color)
////{
////	if (!mesh || mesh->textureID <= 0) //Proper error check
////	{
////		return;
////	}
////
////	glDisable(GL_DEPTH_TEST);
////	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
////	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
////	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
////	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
////	glActiveTexture(GL_TEXTURE0);
////	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
////	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
////	for (unsigned i = 0; i < text.length(); ++i)
////	{
////		Mtx44 characterSpacing;
////		characterSpacing.SetToTranslation(i * 1.0f, 0.f, 0); //1.0f is the spacing of each character, you may change this value
////		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
////		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
////
////		mesh->Render((unsigned)text[i] * 6, 6);
////	}
////	glBindTexture(GL_TEXTURE_2D, 0);
////	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
////	glEnable(GL_DEPTH_TEST);
////}
////
////void SceneBase::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
////{
////	if (!mesh || mesh->textureID <= 0) //Proper error check
////	{
////		return;
////	}
////
////	glDisable(GL_DEPTH_TEST);
////
////	Mtx44 ortho;
////	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
////	projectionStack.PushMatrix();
////	projectionStack.LoadMatrix(ortho);
////	viewStack.PushMatrix();
////	viewStack.LoadIdentity(); //No need camera for ortho mode
////	modelStack.PushMatrix();
////	modelStack.LoadIdentity(); //Reset modelStack
////	modelStack.Scale(size, size, size);
////	modelStack.Translate(x, y, 0);
////
////	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
////	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
////	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
////	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
////	glActiveTexture(GL_TEXTURE0);
////	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
////	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
////	for (unsigned i = 0; i < text.length(); ++i)
////	{
////		Mtx44 characterSpacing;
////		characterSpacing.SetToTranslation(i * 0.5f + 0.5f, 0.5f, 0); //0.5f beside i is the spacing of each character, you may change this value
////		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
////		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
////
////		mesh->Render((unsigned)text[i] * 6, 6);
////	}
////	glBindTexture(GL_TEXTURE_2D, 0);
////	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
////
////	//Add these code just before glEnable(GL_DEPTH_TEST);
////	projectionStack.PopMatrix();
////	viewStack.PopMatrix();
////	modelStack.PopMatrix();
////
////
////	glEnable(GL_DEPTH_TEST);
////}
////
////void SceneBase::RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey)
////{
////	glDisable(GL_DEPTH_TEST);
////	Mtx44 ortho;
////	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
////	projectionStack.PushMatrix();
////	projectionStack.LoadMatrix(ortho);
////	viewStack.PushMatrix();
////	viewStack.LoadIdentity(); //No need camera for ortho mode
////
////	modelStack.PushMatrix();
////	modelStack.LoadIdentity();
////	modelStack.Translate((float)x, (float)y, 0);
////	modelStack.Scale((float)sizex, (float)sizey, 1);
////	//to do: scale and translate accordingly
////	RenderMesh(mesh, false); //UI should not have light
////	projectionStack.PopMatrix();
////	viewStack.PopMatrix();
////	modelStack.PopMatrix();
////	glEnable(GL_DEPTH_TEST);
////}
////
////void SceneBase::resetAll()
////{
////	camera.position.Set(0.f, 0.f, 484.f);
////}
////
////void SceneBase::Exit()
////{
////	// Cleanup VBO here
////	for (int i = 0; i < NUM_GEOMETRY; ++i)
////	{
////		if (meshList[i] != NULL)
////		{
////			delete meshList[i];
////		}
////	}
////	glDeleteVertexArrays(1, &m_vertexArrayID);
////
////	glDeleteProgram(m_programID);
////}
//
//#include "SceneBase.h"
//#include "GL\glew.h"
//#include "Mtx44.h"
//#include "Application.h"
//#include "MeshBuilder.h"
//#include "LoadTGA.h"
//#include "LoadOBJ.h"
//
//#include "shader.hpp"
//#include "Utility.h"
//
//#include <iostream>
//#include <iomanip>
//#include <stdlib.h>
//
//#include "ItemInfo.h"
//#include "Inventory.h"
//
//
//using std::cout;
//using std::cin;
//
//SceneBase::SceneBase()
//{
//}
//
//SceneBase::~SceneBase()
//{
//}
//
//Inventory* global_inventory = 0;
//void SceneBase::Init()
//{
//	// Set background color to black 
//	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//	// Enable depth test
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//
//	// Enable blending
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	// Init VBO here
//
//	// Generate a default VAO for now
//	glGenVertexArrays(1, &m_vertexArrayID);
//	glBindVertexArray(m_vertexArrayID);
//
//	//Load vertex and fragment shaders
//	m_programID = LoadShaders("Shader//Texture.vertexshader", "Shader//Text.fragmentshader");
//
//	//Get a handle for our "MVP" uniform
//	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
//	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
//	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
//	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
//	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
//	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
//	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
//
//	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
//	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
//	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
//	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
//	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
//	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
//	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
//	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
//	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
//	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
//	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
//
//	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
//	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
//	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
//	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
//	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
//	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
//	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
//	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
//	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
//	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
//	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
//
//	m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
//	m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
//	m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
//	m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
//	m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
//	m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
//	m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
//	m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
//	m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
//	m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
//	m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");
//
//	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
//
//	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");
//
//	// Get a handle for our "colorTexture" uniform
//	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
//	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
//
//	// Get a handle for our "textColor" uniform
//	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
//	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");
//
//
//	// Use our shader
//	glUseProgram(m_programID);
//
//	for (int i = 0; i < NUM_GEOMETRY; ++i)
//	{
//		meshList[i] = NULL;
//	}
//
//	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("axes", 1, 1, 1);
//
//	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 20, 20, 1);
//	meshList[GEO_LIGHTBALL2] = MeshBuilder::GenerateSphere("lightball_2", Color(0.5f, 0.f, 0.f), 20, 20, 1);
//	meshList[GEO_LIGHTBALL3] = MeshBuilder::GenerateSphere("lightball_3", Color(1.f, 1.f, 0.f), 20, 20, 1);
//
//	meshList[GEO_GROUND] = MeshBuilder::GenerateQuad("grass", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_GROUND]->textureID = LoadTGA("Image//grass.tga");
//
//	//Skybox Day
//	meshList[GEO_FRONT] = MeshBuilder::GenerateQuad("front", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_FRONT]->textureID = LoadTGA("Image//front.tga");
//
//	meshList[GEO_BACK] = MeshBuilder::GenerateQuad("back", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BACK]->textureID = LoadTGA("Image//back.tga");
//
//	meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_TOP]->textureID = LoadTGA("Image//top.tga");
//
//	meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//bottom.tga");
//
//	meshList[GEO_LEFT] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_LEFT]->textureID = LoadTGA("Image//left.tga");
//
//	meshList[GEO_RIGHT] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_RIGHT]->textureID = LoadTGA("Image//right.tga");
//
//	//Skybox Night
//	meshList[GEO_FRONTn] = MeshBuilder::GenerateQuad("frontn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_FRONTn]->textureID = LoadTGA("Image//frontn.tga");
//
//	meshList[GEO_BACKn] = MeshBuilder::GenerateQuad("backn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BACKn]->textureID = LoadTGA("Image//backn.tga");
//
//	meshList[GEO_TOPn] = MeshBuilder::GenerateQuad("topn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_TOPn]->textureID = LoadTGA("Image//topn.tga");
//
//	meshList[GEO_BOTTOMn] = MeshBuilder::GenerateQuad("bottomn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_BOTTOMn]->textureID = LoadTGA("Image//bottomn.tga");
//
//	meshList[GEO_LEFTn] = MeshBuilder::GenerateQuad("leftn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_LEFTn]->textureID = LoadTGA("Image//leftn.tga");
//
//	meshList[GEO_RIGHTn] = MeshBuilder::GenerateQuad("rightn", Color(1, 1, 1), 1.f, 1.f);
//	meshList[GEO_RIGHTn]->textureID = LoadTGA("Image//rightn.tga");
//
//	//Text
//	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
//	meshList[GEO_TEXT]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_X] = MeshBuilder::GenerateText("x", 16, 16);
//	meshList[GEO_X]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_Y] = MeshBuilder::GenerateText("y", 16, 16);
//	meshList[GEO_Y]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_Z] = MeshBuilder::GenerateText("z", 16, 16);
//	meshList[GEO_Z]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_FPS] = MeshBuilder::GenerateText("FPS", 16, 16);
//	meshList[GEO_FPS]->textureID = LoadTGA("Image//comic.tga");
//
//	meshList[GEO_COUNTDOWN] = MeshBuilder::GenerateText("Time", 16, 16);
//	meshList[GEO_COUNTDOWN]->textureID = LoadTGA("Image//comic.tga");
//
//	//Environment
//	meshList[GEO_MOUNTAIN] = MeshBuilder::GenerateOBJ("mountain", "OBJ//mountain.obj");
//	meshList[GEO_MOUNTAIN]->textureID = LoadTGA("Image//objects.tga");
//
//	meshList[GEO_MOUNTAIN_2] = MeshBuilder::GenerateOBJ("mountain_2", "OBJ//mountain.obj");
//	meshList[GEO_MOUNTAIN_2]->textureID = LoadTGA("Image//objects.tga");
//
//	meshList[GEO_MESSAGES] = MeshBuilder::GenerateText("messages", 16, 16);
//	meshList[GEO_MESSAGES]->textureID = LoadTGA("Image//comic.tga");
//
//	//Sprites
//	meshList[GEO_HANDL1] = MeshBuilder::GenerateOBJ("handL1", "OBJ//quad.obj");
//	meshList[GEO_HANDL1]->textureID = LoadTGA("Image//Sprites//HandL1.tga");
//	meshList[GEO_HANDR1] = MeshBuilder::GenerateOBJ("handR1", "OBJ//quad.obj");
//	meshList[GEO_HANDR1]->textureID = LoadTGA("Image//Sprites//HandR1.tga");
//	meshList[GEO_HANDL2] = MeshBuilder::GenerateOBJ("handL2", "OBJ//quad.obj");
//	meshList[GEO_HANDL2]->textureID = LoadTGA("Image//Sprites//HandL2.tga");
//	meshList[GEO_HANDR2] = MeshBuilder::GenerateOBJ("handR2", "OBJ//quad.obj");
//	meshList[GEO_HANDR2]->textureID = LoadTGA("Image//Sprites//HandR2.tga");
//	meshList[GEO_HANDI] = MeshBuilder::GenerateOBJ("handI", "OBJ//quad.obj");
//	meshList[GEO_HANDI]->textureID = LoadTGA("Image//Sprites//HandI.tga");
//	meshList[GEO_GUN1] = MeshBuilder::GenerateOBJ("gun1", "OBJ//quad.obj");
//	meshList[GEO_GUN1]->textureID = LoadTGA("Image//Sprites//Gun1.tga");
//	meshList[GEO_GUN2] = MeshBuilder::GenerateOBJ("gun2", "OBJ//quad.obj");
//	meshList[GEO_GUN2]->textureID = LoadTGA("Image//Sprites//Gun2.tga");
//	meshList[GEO_GUN3] = MeshBuilder::GenerateOBJ("gun3", "OBJ//quad.obj");
//	meshList[GEO_GUN3]->textureID = LoadTGA("Image//Sprites//Gun3.tga");
//	meshList[GEO_GUNI] = MeshBuilder::GenerateOBJ("gunI", "OBJ//quad.obj");
//	meshList[GEO_GUNI]->textureID = LoadTGA("Image//Sprites//GunI.tga");
//	meshList[GEO_SWORD1] = MeshBuilder::GenerateOBJ("sword1", "OBJ//quad.obj");
//	meshList[GEO_SWORD1]->textureID = LoadTGA("Image//Sprites//Sword1.tga");
//	meshList[GEO_SWORD2] = MeshBuilder::GenerateOBJ("sword2", "OBJ//quad.obj");
//	meshList[GEO_SWORD2]->textureID = LoadTGA("Image//Sprites//Sword2.tga");
//	meshList[GEO_SWORD3] = MeshBuilder::GenerateOBJ("sword3", "OBJ//quad.obj");
//	meshList[GEO_SWORD3]->textureID = LoadTGA("Image//Sprites//Sword3.tga");
//	meshList[GEO_SWORDI] = MeshBuilder::GenerateOBJ("swordI", "OBJ//quad.obj");
//	meshList[GEO_SWORDI]->textureID = LoadTGA("Image//Sprites//SwordI.tga");
//	meshList[GEO_TORCH] = MeshBuilder::GenerateOBJ("torch", "OBJ//quad.obj");
//	meshList[GEO_TORCH]->textureID = LoadTGA("Image//Sprites//Torch.tga");
//	meshList[GEO_TORCHI] = MeshBuilder::GenerateOBJ("torchI", "OBJ//quad.obj");
//	meshList[GEO_TORCHI]->textureID = LoadTGA("Image//Sprites//TorchI.tga");
//	meshList[GEO_HEALTHPOTION] = MeshBuilder::GenerateOBJ("healthPotion", "OBJ//quad.obj");
//	meshList[GEO_HEALTHPOTION]->textureID = LoadTGA("Image//Sprites//HealthPotion.tga");
//	meshList[GEO_ANTIDOTE] = MeshBuilder::GenerateOBJ("antidote", "OBJ//quad.obj");
//	meshList[GEO_ANTIDOTE]->textureID = LoadTGA("Image//Sprites//Antidote.tga");
//
//	meshList[GEO_GUN_ICON] = MeshBuilder::GenerateOBJ("antidote", "OBJ//Wall.obj");
//	meshList[GEO_GUN_ICON]->textureID = LoadTGA("Image//Sprites//GunIcon.tga");
//
//	//Item
//	meshList[GEO_INVENTORY] = MeshBuilder::GenerateOBJ("Inventory", "OBJ//inventory.obj");
//	meshList[GEO_INVENTORY]->textureID = LoadTGA("Image//inventory.tga");
//
//	meshList[GEO_MINI_PLAYER] = MeshBuilder::GenerateOBJ("mini_player", "OBJ//inventory.obj");
//	meshList[GEO_MINI_PLAYER]->textureID = LoadTGA("Image//mini_player.tga");
//
//	meshList[GEO_MINI_GROUND] = MeshBuilder::GenerateOBJ("mini_ground", "OBJ//inventory.obj");
//	meshList[GEO_MINI_GROUND]->textureID = LoadTGA("Image//grass.tga");
//
//	meshList[GEO_MINI_ENEMY] = MeshBuilder::GenerateOBJ("mini_enemy", "OBJ//inventory.obj");
//	meshList[GEO_MINI_ENEMY]->textureID = LoadTGA("Image//mini_enemy.tga");
//
//	meshList[GEO_GAME_HUD] = MeshBuilder::GenerateOBJ("game_hud", "OBJ//inventory.obj");
//	meshList[GEO_GAME_HUD]->textureID = LoadTGA("Image//game_hud.tga");
//
//	meshList[GEO_HP] = MeshBuilder::GenerateOBJ("game_hp", "OBJ//inventory.obj");
//	meshList[GEO_HP]->textureID = LoadTGA("Image//hp_bar.tga");
//
//	meshList[GEO_EN] = MeshBuilder::GenerateOBJ("game_en", "OBJ//inventory.obj");
//	meshList[GEO_EN]->textureID = LoadTGA("Image//en_bar.tga");
//
//	//Enemy 
//	meshList[GEO_ENEMYHEAD] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyHead.obj");
//	meshList[GEO_ENEMYHEAD]->textureID = LoadTGA("Image//Enemy//EnemyHead.tga");
//
//	meshList[GEO_ENEMYRIGHTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYLEFTARM] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYLEFTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyLeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYRIGHTLEG] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyRightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG]->textureID = LoadTGA("Image//Enemy//EnemyBodyParts.tga");
//
//	meshList[GEO_ENEMYTORSO] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//EnemyTorso.obj");
//	meshList[GEO_ENEMYTORSO]->textureID = LoadTGA("Image//Enemy//EnemyTorso.tga");
//
//	//Enemy 2
//	meshList[GEO_ENEMYRIGHTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2RightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//	meshList[GEO_ENEMYTORSO2] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy2Torso.obj");
//	meshList[GEO_ENEMYTORSO2]->textureID = LoadTGA("Image//Enemy//Enemy2BodyParts.tga");
//
//	//Enemy 3
//	meshList[GEO_ENEMYRIGHTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3RightLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//	meshList[GEO_ENEMYTORSO3] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy3Torso.obj");
//	meshList[GEO_ENEMYTORSO3]->textureID = LoadTGA("Image//Enemy//Enemy3BodyParts.tga");
//
//	//Enemy 4
//	meshList[GEO_ENEMYRIGHTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RightArm.obj");
//	meshList[GEO_ENEMYRIGHTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYLEFTARM4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftArm.obj");
//	meshList[GEO_ENEMYLEFTARM4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYLEFTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4LeftLeg.obj");
//	meshList[GEO_ENEMYLEFTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYRIGHTLEG4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4RighLeg.obj");
//	meshList[GEO_ENEMYRIGHTLEG4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//	meshList[GEO_ENEMYTORSO4] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Enemy4Torso.obj");
//	meshList[GEO_ENEMYTORSO4]->textureID = LoadTGA("Image//Enemy//Enemy4BodyParts.tga");
//
//	//Flicker
//	meshList[GEO_FLICKER] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//quad.obj");
//	meshList[GEO_FLICKER]->textureID = LoadTGA("Image//blood//bloodflicker.tga");
//
//
//	meshList[GEO_SPIDER] = MeshBuilder::GenerateOBJ("EnemyHead", "OBJ//Enemy//Spider.obj");
//	meshList[GEO_SPIDER]->textureID = LoadTGA("Image//Enemy//RobotSpider.tga");
//
//	meshList[GEO_ENEMYHEALTHBAR] = MeshBuilder::GenerateQuad("enemyHealthBar", Color(1.0f, 0.0f, 0.0f), 1, 1);
//
//	meshList[GEO_ARROW] = MeshBuilder::GenerateOBJ("Arrow", "OBJ//inventory.obj");
//	meshList[GEO_ARROW]->textureID = LoadTGA("Image//Arrow.tga");
//
//	meshList[GEO_ACTIVE_SELECT] = MeshBuilder::GenerateOBJ("active_select", "OBJ//inventory.obj");
//	meshList[GEO_ACTIVE_SELECT]->textureID = LoadTGA("Image//active_select.tga");
//
//	meshList[GEO_SECONDARY_SELECT] = MeshBuilder::GenerateOBJ("secondary_select", "OBJ//inventory.obj");
//	meshList[GEO_SECONDARY_SELECT]->textureID = LoadTGA("Image//secondary_select.tga");
//
//	meshList[GEO_TIME] = MeshBuilder::GenerateOBJ("time_bar", "OBJ//inventory.obj");
//	meshList[GEO_TIME]->textureID = LoadTGA("Image//time_bar.tga");
//
//	//Prevent Jerk
//	camera.Init(Vector3(0, 0, 484), Vector3(0, 0, 0), Vector3(0, 1, 0));
//
//	//Projection
//	Mtx44 projection;
//	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 4000.f);
//	projectionStack.LoadMatrix(projection);
//
//	//Spot light
//	light[0].type = Light::LIGHT_SPOT;
//	light[0].position.Set(0, 10, 0);// this is overidden at the update
//	light[0].color.Set(1, 1, 1);
//	light[0].power = 0;
//	light[0].kC = 1.f;
//	light[0].kL = 0.01f;
//	light[0].kQ = 0.001f;
//	light[0].cosCutoff = cos(Math::DegreeToRadian(25)); // higher angle = more area covered with light
//	light[0].cosInner = cos(Math::DegreeToRadian(15)); // use to toggle inner light , lower angle  = light more concentrated
//	light[0].exponent = 3.f;
//	light[0].spotDirection.Set(0.f, 1.f, 0.f); // this is overidden at the update
//
//	light[1].type = Light::LIGHT_POINT;
//	light[1].position.Set(0.f, 1000.f, 0.f);
//	light[1].color.Set(1.f, 0.f, 0.f);
//	light[1].power = 10;
//	light[1].kC = 1.f;
//	light[1].kL = 0.01f;
//	light[1].kQ = 0.001f;
//	light[1].cosCutoff = cos(Math::DegreeToRadian(45));
//	light[1].cosInner = cos(Math::DegreeToRadian(30));
//	light[1].exponent = 3.f;
//	light[1].spotDirection.Set(0.f, 1.f, 0.f);
//
//	light[2].type = Light::LIGHT_SPOT;
//	light[2].position.Set(0.f, 0.f, 50.f);
//	light[2].color.Set(1.f, 1.f, 0.f);
//	light[2].power = 0;
//	light[2].kC = 1.f;
//	light[2].kL = 0.01f;
//	light[2].kQ = 0.001f;
//	light[2].cosCutoff = cos(Math::DegreeToRadian(45));
//	light[2].cosInner = cos(Math::DegreeToRadian(30));
//	light[2].exponent = 3.f;
//	light[2].spotDirection.Set(0.f, 1.f, 0.f);
//
//	// Make sure you pass uniform parameters after glUseProgram()
//	glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &light[0].color.r);
//	glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//	glUniform1f(m_parameters[U_LIGHT0_KC], light[0].kC);
//	glUniform1f(m_parameters[U_LIGHT0_KL], light[0].kL);
//	glUniform1f(m_parameters[U_LIGHT0_KQ], light[0].kQ);
//	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], light[0].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT0_COSINNER], light[0].cosInner);
//	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], light[0].exponent);
//
//	glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &light[1].color.r);
//	glUniform1f(m_parameters[U_LIGHT1_POWER], light[1].power);
//	glUniform1f(m_parameters[U_LIGHT1_KC], light[1].kC);
//	glUniform1f(m_parameters[U_LIGHT1_KL], light[1].kL);
//	glUniform1f(m_parameters[U_LIGHT1_KQ], light[1].kQ);
//	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], light[1].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT1_COSINNER], light[1].cosInner);
//	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], light[1].exponent);
//
//	glUniform1i(m_parameters[U_LIGHT2_TYPE], light[2].type);
//	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &light[2].color.r);
//	glUniform1f(m_parameters[U_LIGHT2_POWER], light[2].power);
//	glUniform1f(m_parameters[U_LIGHT2_KC], light[2].kC);
//	glUniform1f(m_parameters[U_LIGHT2_KL], light[2].kL);
//	glUniform1f(m_parameters[U_LIGHT2_KQ], light[2].kQ);
//	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], light[2].cosCutoff);
//	glUniform1f(m_parameters[U_LIGHT2_COSINNER], light[2].cosInner);
//	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], light[2].exponent);
//
//	// Make sure you pass uniform parameters after glUseProgram()
//	glUniform1i(m_parameters[U_NUMLIGHTS], 3);
//
//
//	// Param 1 - name of sound ---- Param 2 -distance sound able to travel --- Param 3 - volume of sound (0 to 1)
//	soundStorage.push_back(new Sound("gunshot.mp3", 1000, 1));
//	soundStorage.push_back(new Sound("splatter.mp3", 1000, 1));
//	soundStorage.push_back(new Sound("run.mp3", 1000, 0.5));
//	soundStorage.push_back(new Sound("backgroundmusic.mp3"));
//	soundStorage.push_back(new Sound("jump.mp3", 1000, 0.5));
//	soundStorage.push_back(new Sound("footstep.mp3", 1000, 1));
//
//	/* vec3df somePosition = { 0, 0,0};
//	 soundStorage[1]->play3DSound(true, false, false, somePosition);*/
//
//	/*soundStorage[3]->play2DSound(true, false, false); */
//
//	/*objFactory.createFactoryObject(new Enemy(this, Vector3(Math::RandFloatMinMax(-50, 50), 0, Math::RandFloatMinMax(-50, 50))) );*/
//
//	//----------------Inventory--------------
//	inventoryOpen = false;
//
//	//initialise singleton of inventory class
//
//	if (global_inventory == 0)
//	{
//		global_inventory = new Inventory();
//		global_inventory->setdefined(1);
//	}
//	//type , damage , range , reload speed , attack speed
//	ItemInfo* gun = new ItemInfo("gun", 20, 20, 10, 15);
//	global_inventory->addItem(gun);
//
//	ItemInfo* torch = new ItemInfo("torch", 0, 50, 0, 10);
//	global_inventory->addItem(torch);
//	// adding items to inventory
//	ItemInfo* fist = new ItemInfo();
//	global_inventory->addItem(fist);
//
//	//delay between keypresses while in menu
//	startTime = 0.0f;
//	cooldown = 15.0f;
//
//	//speed ,damage ,hp, range ,this
//	Enemy * newEnemy = new Spider(70.f, 5.f, 50.f, 100.f);
//	newEnemy->addWaypoint(Vector3(200, 0, 200));
//	newEnemy->addWaypoint(Vector3(200, 0, -200));
//	newEnemy->addWaypoint(Vector3(-200, 0, -200));
//	newEnemy->addWaypoint(Vector3(-200, 0, 200));
//	enemyStorage.push_back(newEnemy);
//
//	// speed , damage ,hp , range , this , int(used to identify which type of robot)
//	Enemy * newEnemy2 = new Robot(70.f, 5.f, 100.f, 100.f, 1);
//	newEnemy2->addWaypoint(Vector3(300, 0, -100));
//	newEnemy2->addWaypoint(Vector3(400, 0, -400));
//	newEnemy2->addWaypoint(Vector3(-400, 0, -400));
//	newEnemy2->addWaypoint(Vector3(-400, 0, 400));
//	enemyStorage.push_back(newEnemy2);
//
//	Enemy * newEnemy3 = new Spider(70.f, 5.f, 50.f, 100.f);
//	newEnemy3->addWaypoint(Vector3(-400, 0, 200));
//	newEnemy3->addWaypoint(Vector3(300, 0, -300));
//	newEnemy3->addWaypoint(Vector3(-2300, 0, -300));
//	newEnemy3->addWaypoint(Vector3(-2300, 0, 200));
//	enemyStorage.push_back(newEnemy3);
//
//	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		(*it)->_Position = (*it)->currWaypoint->getPosition();
//	}
//}
//
//void SceneBase::Update(double dt)
//{
//	vec3df camPos = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
//	Vector3 view = camera.target - camera.position;
//	vec3df dir = { view.x, view.y, view.z };
//	vec3df up = { camera.up.x, camera.up.y, camera.up.z };
//	vec3df zero = { 0, 0, 0 };
//
//	for (unsigned i = 0; i < soundStorage.size(); ++i)
//	{
//		soundStorage[i]->getSoundEngine()->setListenerPosition(camPos, dir.normalize(), zero, up.normalize());
//		soundStorage[i]->getSoundEngine()->update();
//	}
//
//	Robot::dtFromScene(dt);
//	Robot::positionFromCamera(camera);
//
//	Spider::dtFromScene(dt);
//	Spider::positionFromCamera(camera);
//
//	//Bullet::dtFromScene(dt);
//	//Bullet::positionFromCamera(camera);
//
//	_dt = (float)dt;
//	_elapsedTime += _dt;
//
//	static float rotateLimit = 1;
//	rotateArm += (float)(50 * rotateLimit * dt);
//    if (rotateArm > 10)
//    {
//        rotateArm = 10.f;
//        rotateLimit = -1;
//    }
//    if (rotateArm < -10)
//    {
//        rotateArm = -10.f;
//        rotateLimit = 1;
//    }
//
//	static bool canPress = true;
//
//	if (!Application::IsKeyPressed('Q'))
//		canPress = true;
//
//	// Light on
//	if (canPress && Application::IsKeyPressed('Q')) {
//		light[0].power = (light[0].power > 0) ? 0.0f : 3.0f; // Toggle Power between 0 and 2
//		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//		canPress = false;
//	}
//	if (light[0].power > 0)
//	{
//		float ys = 10.f;
//		energy -= ys * _dt;
//	}
//	if (torchDead == true)
//	{
//		light[0].power = 0;
//		glUniform1f(m_parameters[U_LIGHT0_POWER], light[0].power);
//	}
//	if (energy < 0)
//	{
//		energy = 0;
//	}
//	// Flashlight position and direction
//	light[0].position.Set(camera.position.x, camera.position.y, camera.position.z);
//	light[0].spotDirection = camera.position - camera.target;  // move direction of light along view vector
//
//	//Process  obj movement
//	objFactory.processInteraction();
//
//	static const float LSPEED = 10.f;
//	srand((unsigned)time(NULL));
//
//	static float rotateWorld = 1;
//
//	float run = 1.f;
//
//	if (Application::IsKeyPressed(MK_LBUTTON))
//	{
//		if (_elapsedTime >= nextBulletTime)
//		{
//			objFactory.createFactoryObject(new Bullet(this, camera.getPosition(), camera.getYaw(), camera.getPitch()));
//			nextBulletTime = _elapsedTime + coolDown;
//			soundStorage[0]->play3DSound(false, false, false, camPos);
//			bulletTouch = false;
//			swing = true;
//		}
//	}
//	if (swing == true)
//	{
//		swingTime++;
//	}
//
//	if (Application::IsKeyPressed('I'))
//	{
//		if (inventoryOpen && startTime >= cooldown)
//		{
//			inventoryOpen = false;
//			startTime = 0;
//		}
//		else if (startTime >= cooldown)
//		{
//			inventoryOpen = true;
//			startTime = 0;
//		}
//	}
//
//	vec3df footPos = { camera.getPosition().x, camera.getPosition().y - 20, camera.getPosition().z };
//	//FootStep Sound
//	if (Application::IsKeyPressed('W') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('A') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('S') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed('D') && (_elapsedTime >= nextWalkTime))
//	{
//		nextWalkTime = _elapsedTime + coolDown + 0.5f;
//		soundStorage[5]->play3DSound(false, false, true, footPos);
//	}
//
//	if (Application::IsKeyPressed(VK_SPACE) && (_elapsedTime >= nextJump))
//	{
//		nextJump = _elapsedTime + coolDown;
//		soundStorage[4]->play3DSound(false, false, true, footPos);
//	}
//	if (Application::IsKeyPressed(VK_SHIFT) && (_elapsedTime >= nextRun))
//	{
//		nextRun = _elapsedTime + coolDown;
//		soundStorage[2]->play3DSound(false, false, true, footPos);
//	}
//
//	//Skybox Rotation
//	rotateSkybox += (float)(1 * rotateWorld * dt);
//
//	//Skybox
//	if (rotateSkybox > 360)
//	{
//		rotateSkybox = 0;
//	}
//
//	if (Application::IsKeyPressed(VK_NUMPAD5))
//	{
//		run = 3.f;
//	}
//
//	//Reset
//	if (Application::IsKeyPressed('R'))
//	{
//		resetAll();
//	}
//
//	if (Application::IsKeyPressed('7'))
//	{
//		light[0].type = Light::LIGHT_POINT;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_POINT;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to POINT and pass the information to shader
//	}
//	if (Application::IsKeyPressed('8'))
//	{
//		light[0].type = Light::LIGHT_DIRECTIONAL;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_DIRECTIONAL;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to DIRECTIONAL and pass the information to shader
//	}
//	if (Application::IsKeyPressed('9'))
//	{
//		light[0].type = Light::LIGHT_SPOT;
//		glUniform1i(m_parameters[U_LIGHT0_TYPE], light[0].type);
//		light[1].type = Light::LIGHT_SPOT;
//		glUniform1i(m_parameters[U_LIGHT1_TYPE], light[1].type);
//		//to do: switch light type to SPOT and pass the information to shader
//	}
//
//	camera.Update(dt);
//
//	//FPS Counter
//	FPS = 1 / (float)dt;
//
//	startTime++;
//
//	enemyUpdate(dt);
//
//	timeleft--;
//}
//
//void SceneBase::enemyUpdate(double dt)
//{
//	//-------This function is called in SceneBase::Update(double dt) to process Enemy interactions-----------------
//
//	for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		(*it)->update();
//
//		for (vector<Object*>::iterator factoryIt = factoryIt = objFactory.Container.begin(); factoryIt != objFactory.Container.end(); factoryIt++)
//		{
//			if ((*factoryIt)->type == SceneBase::GEO_LIGHTBALL3)   //BULLET INTERACTION WITH ENEMY
//			{
//				if (((*factoryIt)->position_ - (*it)->_Position).Length() < 20 && bulletTouch == false)
//				{
//					if ((*it)->enemytype == 1)
//					{
//						(*it)->_Hp -= 10;
//						(*it)->healthBarSpider -= 2.f;
//						damaged = true;
//						bulletTouch = true;
//
//						if ((*it)->_Hp == 0)
//						{
//							(*it)->setState(2);  //  death is at enum 2
//						}
//					}
//					if ((*it)->enemytype == 2)
//					{
//						(*it)->_Hp -= 10;
//						(*it)->healthBarRobot1 -= 2.f;
//						damaged = true;
//						bulletTouch = true;
//
//						if ((*it)->_Hp == 0)
//						{
//							(*it)->setState(2);  //  death is at enum 2
//						}
//					}
//
//				}
//			}
//		}
//	}
//}
//void SceneBase::Render()
//{
//	srand((unsigned)time(NULL));
//
//	//Clear color & depth buffer every frame
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//	Mtx44 MVP;
//
//	viewStack.LoadIdentity(); //No need camera for now, set it at World's origin
//	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
//	modelStack.LoadIdentity();
//
//	//Passing light position to shader
//	Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//
//	//Light 1
//	if (light[0].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[0].position.x, light[0].position.y, light[0].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[0].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[0].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[0].position;
//		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//	//Light 2
//	if (light[1].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[1].position.x, light[1].position.y, light[1].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[1].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[1].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[1].position;
//		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//	//Light 2
//	if (light[2].type == Light::LIGHT_DIRECTIONAL)
//	{
//		Vector3 lightDir(light[2].position.x, light[2].position.y, light[2].position.z);
//		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
//	}
//	else if (light[2].type == Light::LIGHT_SPOT)
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
//		Vector3 spotDirection_cameraspace = viewStack.Top() * light[2].spotDirection;
//		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
//	}
//	else
//	{
//		Position lightPosition_cameraspace = viewStack.Top() * light[2].position;
//		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
//	}
//
//
//	//Generate Axes
//	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top(); //Remember, matrix multiplication is the other way around
//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//	RenderMesh(meshList[GEO_AXES], false);
//
//	modelStack.PushMatrix();
//	modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
//	RenderSkybox();
//	modelStack.PopMatrix();
//
//	//Environment
//	renderMountains();
//	renderGround();
//	renderPosition();
//
//	renderText();
//
//	objFactory.renderFactoryObject();
//
//	renderEnemy();
//
//	renderSprites();
//
//	renderHUD();
//}
//
//void SceneBase::renderEnemy()
//{
//	for (vector<Enemy *> ::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//	{
//		if (((*it)->_Position - camera.getPosition()).Length() < 10 && (*it)->getState() != Spider::spiderState::death &&
//			(*it)->getState() != Robot::robotState::death)
//		{
//			RenderMeshOnScreen(meshList[GEO_FLICKER], 40, 30, 80, 60);
//			vec3df bloodStartingLocation = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
//			if (_elapsedTime >= nextSplatter)
//				soundStorage[1]->play3DSound(false, false, false, bloodStartingLocation);
//			nextSplatter = _elapsedTime + coolDown;
//
//			health--;
//		}
//
//		switch ((*it)->enemytype)
//		{
//
//		case   1:    // ----------------Spider ----------------------------
//		{
//			if ((*it)->getState() != Spider::spiderState::death)
//			{
//				//Spider
//				modelStack.PushMatrix();
//				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//				modelStack.Scale(10, 10, 10);
//				RenderMesh(meshList[GEO_SPIDER], true);
//				modelStack.PopMatrix();
//
//				//Health Bar
//				modelStack.PushMatrix();
//				modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 1.3f, (*it)->_Position.z);
//				modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//				modelStack.Rotate(90, 0, 0, 1);
//				if ((*it)->healthBarSpider>0)
//					modelStack.Scale(1, 1, (*it)->healthBarSpider);
//				else
//					modelStack.Scale(1, 1, 1);
//				RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
//				modelStack.PopMatrix();
//
//			}
//		}
//		break;
//		case 2:  // ---------------Robot1 ----------------------
//		{
//			if ((*it)->getState() != Robot::robotState::death)
//			{
//				if ((*it)->robotType == 1)
//				{
//					//Robot
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y-30.f, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO], true);
//					RenderMesh(meshList[GEO_ENEMYHEAD], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 40, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -40, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//
//					//Health Bar
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y + 30.f, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.Rotate(90, 0, 0, 1);
//					if ((*it)->healthBarRobot1>0)
//						modelStack.Scale(1, 1, (*it)->healthBarRobot1);
//					else
//						modelStack.Scale(1, 1, 1);
//					RenderMesh(meshList[GEO_ENEMYHEALTHBAR], true);
//					modelStack.PopMatrix();
//				}
//
//				if ((*it)->robotType == 2)
//				{
//					//Robot 2
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 5, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -5, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG2], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 5, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -5, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG2], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//
//				if ((*it)->robotType == 3)
//				{
//					//Robot 3
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 1, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -1, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG3], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 1, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -1, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG3], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//				if ((*it)->robotType == 4)
//				{
//					//Robot 4
//					modelStack.PushMatrix();
//					modelStack.Translate((*it)->_Position.x, (*it)->_Position.y, (*it)->_Position.z);
//					modelStack.Rotate((*it)->_Rotation, 0, 1, 0);
//					modelStack.PushMatrix();
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYTORSO4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTARM4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTARM4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(-rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYRIGHTLEG4], true);
//					modelStack.PopMatrix();
//					modelStack.PushMatrix();
//					modelStack.Translate(0, 10, 0);
//					modelStack.Rotate(rotateArm, 0, 0, 1);
//					modelStack.Translate(0, -10, 0);
//					modelStack.Scale(10, 10, 10);
//					RenderMesh(meshList[GEO_ENEMYLEFTLEG4], true);
//					modelStack.PopMatrix();
//					modelStack.PopMatrix();
//				}
//			}
//		}
//		break;
//		}
//	}
//}
//
//void SceneBase::renderHUD()
//{
//	if (inventoryOpen)
//	{
//		if (startTime >= cooldown)
//		{
//			if (Application::IsKeyPressed(VK_DOWN)) // scroll down item list
//			{
//				global_inventory->CycleDisplay(0);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed(VK_UP)) // scroll up item list
//			{
//				global_inventory->CycleDisplay(1);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed('J')) // equip primary
//			{
//				global_inventory->equipItem(1);
//				startTime = 0;
//			}
//			else if (Application::IsKeyPressed('K')) // equip secondary
//			{
//				global_inventory->equipItem(0);
//				startTime = 0;
//			}
//		}
//		RenderMeshOnScreen(meshList[GEO_INVENTORY], 40, 27, 80, 65);
//		renderInventory();
//		renderStats();
//	}
//	else
//	{
//		//in game hud
//		RenderMeshOnScreen(meshList[GEO_GAME_HUD], 40, 32, 80, 65);
//
//		if (health > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_HP], 5 + 11.3 * health / 100, 6.1, 105 * health / 100, 9);
//		}
//		if (energy > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_EN], 5 + 11.3* energy / 10000, 2.3, 105 * energy / 10000, 9);
//		}
//		if (energy == 0)
//		{
//			torchDead = true;
//		}
//		if (timeleft > 0)
//		{
//			RenderMeshOnScreen(meshList[GEO_TIME], 58.6 + 11.3* timeleft / 60000, 14.5, 105 * timeleft / 60000, 11);
//		}
//		renderRemainingTime();
//		//minimap
//		RenderMeshOnScreen(meshList[GEO_MINI_GROUND], 10, 50, 15, 15);
//		RenderMeshOnScreen(meshList[GEO_MINI_PLAYER], 10.5 + ((camera.getPosition().x / 1000) * 14), 50 + ((camera.getPosition().z / 1000)* 14.4), 6, 6);
//		for (vector<Enemy*>::iterator it = enemyStorage.begin(); it != enemyStorage.end(); it++)
//		{
//			if ((*it)->getState() != Robot::robotState::death || (*it)->getState() != Spider::spiderState::death)
//				RenderMeshOnScreen(meshList[GEO_MINI_ENEMY], 10.5 + (((*it)->_Position.x / 1000) * 14), 50 + (((*it)->_Position.z / 1000) * 14.4), 10, 10);
//		}
//	}
//}
//
//void SceneBase::renderInventory()
//{
//	if (!global_inventory->pointer)
//	{
//		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 20, 27 , 30);
//	}
//	else
//	{
//		RenderMeshOnScreen(meshList[GEO_ARROW], 20, 10, 27 , 30);
//	}
//
//	ItemInfo* activeItem = global_inventory->getActiveItem();
//	if (activeItem->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 15, 35, 130, 130);
//	}
//	else if (activeItem->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 15, 34, 50, 50);
//	}
//	else if (activeItem->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 15, 35, 150, 150);
//	}
//	ItemInfo* secondaryItem = global_inventory->getSecondaryItem();
//	if (secondaryItem->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 33, 35, 130, 130);
//	}
//	else if (secondaryItem->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 32.5, 35, 50, 50);
//	}
//	else if (secondaryItem->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 33, 35, 150, 150);
//	}
//
//	ItemInfo* ItemDisplay1 = global_inventory->getDisplay1();
//	if (ItemDisplay1->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 12, 23, 60, 60);
//	}
//	else if (ItemDisplay1->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 10, 40, 5, 5);
//	}
//	else if (ItemDisplay1->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 23, 70, 70);
//	}
//	if (ItemDisplay1 == activeItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 23.2, 6, 7.2);
//	}
//	else if (ItemDisplay1 == secondaryItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 23.2, 6, 7.2);
//	}
//	ItemInfo* ItemDisplay2 = global_inventory->getDisplay2();
//	if (ItemDisplay2->gettype() == "gun")
//	{
//		RenderMeshOnScreen(meshList[GEO_GUNI], 10, 10, 50, 50);
//	}
//	else if (ItemDisplay2->gettype() == "fist")
//	{
//		RenderMeshOnScreen(meshList[GEO_HANDI], 12, 13, 25 , 25);
//	}
//	else if (ItemDisplay2->gettype() == "torch")
//	{
//		RenderMeshOnScreen(meshList[GEO_TORCHI], 12, 13, 70, 70);
//	}
//	if (ItemDisplay2 == activeItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_ACTIVE_SELECT], 12, 13.7, 6, 7.2);
//	}
//	else if (ItemDisplay2 == secondaryItem)
//	{
//		RenderMeshOnScreen(meshList[GEO_SECONDARY_SELECT], 12, 13.7, 6, 7.2);
//	}
//	
//	//Potions
//	RenderMeshOnScreen(meshList[GEO_HEALTHPOTION], 29, 23.5, 100, 100);
//	renderPotionCount();
//	RenderMeshOnScreen(meshList[GEO_ANTIDOTE], 29, 14, 100, 100);
//	renderAntidoteCount();
//}
//
//void SceneBase::renderMountains()
//{
//
//	float mountainsCoordX[4];
//	float mountainsCoordZ[4];
//
//	mountainsCoordX[0] = -200.f;
//	mountainsCoordZ[0] = -100.f;
//
//	mountainsCoordX[1] = 200.f;
//	mountainsCoordZ[1] = -70.f;
//
//	mountainsCoordX[2] = 320;
//	mountainsCoordZ[2] = 200.f;
//
//	mountainsCoordX[3] = -20.f;
//	mountainsCoordZ[3] = 300.f;
//
//	mountainsCoordX[4] = 0.f;
//	mountainsCoordZ[4] = -250.f;
//
//	for (unsigned i = 0; i < 5; i++)
//	{
//		modelStack.PushMatrix();
//		modelStack.Translate(mountainsCoordX[i], -30.f, mountainsCoordZ[i]);
//		modelStack.Scale(100.f, 50.f, 100.f);
//		RenderMesh(meshList[GEO_MOUNTAIN], true);
//		modelStack.PopMatrix();
//	}
//}
//
//
//void SceneBase::RenderSkybox()
//{
//	//Day
//	if (cycle == false)
//	{
//		modelStack.PushMatrix();
//		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, 998.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_FRONT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, -998.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BACK], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_TOP], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, -998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BOTTOM], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(998.f, 0.f, 0.f);
//		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_LEFT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(-998.f, 0.f, 0.f);
//		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_RIGHT], false);
//		modelStack.PopMatrix();
//
//		modelStack.PopMatrix();
//	}
//
//	//Night
//	if (cycle == true)
//	{
//		modelStack.PushMatrix();
//		modelStack.Rotate(rotateSkybox, 0.f, 1.f, 0.f);
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, 998.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_FRONTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 0.f, -998.f);
//		//modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BACKn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, 998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(180.f, 1.f, 0.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_TOPn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(0.f, -998.f, 0.f);
//		modelStack.Rotate(180.f, 0.f, 1.f, 0.f);
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_BOTTOMn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(998.f, 0.f, 0.f);
//		modelStack.Rotate(-90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_LEFTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PushMatrix();
//		//scale, translate, rotate
//		modelStack.Translate(-998.f, 0.f, 0.f);
//		modelStack.Rotate(90.f, 0.f, 1.f, 0.f);
//		modelStack.Rotate(90.f, 1.f, 0.f, 0.f);
//
//		modelStack.Scale(2000.f, 2000.f, 2000.f);
//		RenderMesh(meshList[GEO_RIGHTn], false);
//		modelStack.PopMatrix();
//
//		modelStack.PopMatrix();
//	}
//}
//
//
//void SceneBase::renderGround()
//{
//	modelStack.PushMatrix();
//	modelStack.Translate(0.f, -30.f, 0.f);
//	modelStack.Scale(1000.f, 1000.f, 1000.f);
//	RenderMesh(meshList[GEO_GROUND], true);
//	modelStack.PopMatrix();
//
//	modelStack.PushMatrix();
//	RenderMesh(meshList[GEO_GUN_ICON], true);
//	modelStack.PopMatrix();
//}
//
//void SceneBase::renderSprites()
//{
//	//Gun
//	//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100, 0, 0, 0, 1);
//	//if (swing == false)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN1], 65, 9, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime < 15)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN2], 65, 12, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 15 && swingTime < 30)
//	//{
//	//	RenderMeshOnScreen(meshList[GEO_GUN3], 65, 11, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 30)
//	//{
//	//	swing = false;
//	//	swingTime = 0;
//	//}
//
//	//Cannon
//	//if (swing == false)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON1], 50, 11, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime < 20)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON2], 50, 13, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 20 && swingTime < 40)
//	//{
//	//RenderMeshOnScreen(meshList[GEO_CANNON3], 50, 12, 100, 100, 0, 0, 0, 1);
//	//}
//	//if (swing == true && swingTime > 40)
//	//{
//	//	swing = false;
//	//	swingTime = 0;
//	//}
//
//	if (global_inventory->getActiveItem()->gettype() == "fist" || global_inventory->getSecondaryItem()->gettype() == "fist")
//	{
//		if (swing == false)
//		{
//			//RenderMeshOnScreen(meshList[GEO_HANDL1], 15, 5, 100, 100);
//			RenderMeshOnScreen(meshList[GEO_HANDR1], 65, 5, 100, 100);
//		}
//		//Punching hands
//		if (swing == true)
//		{
//			//RenderMeshOnScreen(meshList[GEO_HANDL2], 15, 10, 100, 100);
//			RenderMeshOnScreen(meshList[GEO_HANDR2], 65, 10, 100, 100);
//			if (swingTime > 40)
//			{
//				swing = false;
//				swingTime = 0;
//			}
//		}
//	}
//	else if (global_inventory->getActiveItem()->gettype() == "gun" || global_inventory->getSecondaryItem()->gettype() == "gun")
//	{
//		if (swing == false)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN1], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime < 15)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN2], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime > 15 && swingTime < 30)
//		{
//			RenderMeshOnScreen(meshList[GEO_GUN3], 55, 10, 100, 100);
//		}
//		if (swing == true && swingTime > 30)
//		{
//			swing = false;
//			swingTime = 0;
//		}
//	}
//	else if (global_inventory->getActiveItem()->gettype() == "torch" || global_inventory->getSecondaryItem()->gettype() == "torch")
//		RenderMeshOnScreen(meshList[GEO_TORCH], 25, 5, 150, 150);
//}
//
//
//void SceneBase::renderPosition()
//{
//	std::string sX = "X: " + std::to_string((int)camera.position.x),
//		sY = "Y: " + std::to_string((int)camera.position.y),
//		sZ = "Z: " + std::to_string((int)camera.position.z);
//
//	modelStack.PushMatrix();
//	//No transform needed
//	RenderTextOnScreen(meshList[GEO_X], sX, Color(0, 1, 0), 3, 23, 19);
//	RenderTextOnScreen(meshList[GEO_Y], sY, Color(0, 1, 0), 3, 23, 18);
//	RenderTextOnScreen(meshList[GEO_Z], sZ, Color(0, 1, 0), 3, 23, 17);
//
//	modelStack.PopMatrix();
//}
//
//
//void SceneBase::renderText()
//{
//	std::string sFPS = "FPS: " + std::to_string(FPS);
//	sFPS.resize(9);
//	RenderTextOnScreen(meshList[GEO_FPS], sFPS, Color(1, 1, 0), 2, 0, 29);
//}
//
//void SceneBase::renderRemainingTime()
//{
//
//	std::string rTime = "";
//	int tempTime = timeleft;
//	int seconds = 0;
//	int minutes = 0;
//	while (tempTime >= 60)
//	{
//		tempTime -= 60;
//		seconds += 1;
//	}
//	while (seconds > 60)
//	{
//		seconds -= 60;
//		minutes += 1;
//	}
//	if (seconds > 9)
//	{
//		rTime = std::to_string(minutes) + ":" + std::to_string(seconds);
//	}
//	else
//	{
//		rTime = std::to_string(minutes) + ":0" + std::to_string(seconds);
//	}
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], rTime, Color(1, 0 ,0), 2, 30, 7);
//}
//
//void SceneBase::renderPotionCount()
//{
//	std::string count = "";
//	count = std::to_string(potionCount);
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 10);
//}
//
//void SceneBase::renderAntidoteCount()
//{
//	std::string count = "";
//	count = std::to_string(antidoteCount);
//	RenderTextOnScreen(meshList[GEO_COUNTDOWN], count, Color(1, 0, 0), 2, 15.5, 5);
//}
//
//void SceneBase::renderStats()
//{
//	/*ItemInfo* active = global_inventory->getActiveItem();
//	string itemName = active->gettype();
//	RenderTextOnScreen(meshList[GEO_FPS], itemName, Color(0,0,0), 2, 25, 20);*/
//}
//
//void SceneBase::RenderMesh(Mesh *mesh, bool enableLight)
//{
//	Mtx44 MVP, modelView, modelView_inverse_transpose;
//
//	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//	modelView = viewStack.Top() * modelStack.Top();
//	glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
//	if (enableLight)
//	{
//		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
//		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
//		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);
//
//		//load material
//		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
//		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
//		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
//		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
//	}
//	else
//	{
//		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	}
//
//	if (mesh->textureID > 0)
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	}
//	else
//	{
//		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
//	}
//
//
//	mesh->Render(); //this line should only be called once
//	if (mesh->textureID > 0)
//	{
//		glBindTexture(GL_TEXTURE_2D, 0);
//	}
//}
//
//void SceneBase::RenderText(Mesh* mesh, std::string text, Color color)
//{
//	if (!mesh || mesh->textureID <= 0) //Proper error check
//	{
//		return;
//	}
//
//	glDisable(GL_DEPTH_TEST);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
//	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
//	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	for (unsigned i = 0; i < text.length(); ++i)
//	{
//		Mtx44 characterSpacing;
//		characterSpacing.SetToTranslation(i * 1.0f, 0.f, 0); //1.0f is the spacing of each character, you may change this value
//		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
//		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//
//		mesh->Render((unsigned)text[i] * 6, 6);
//	}
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
//{
//	if (!mesh || mesh->textureID <= 0) //Proper error check
//	{
//		return;
//	}
//
//	glDisable(GL_DEPTH_TEST);
//
//	Mtx44 ortho;
//	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
//	projectionStack.PushMatrix();
//	projectionStack.LoadMatrix(ortho);
//	viewStack.PushMatrix();
//	viewStack.LoadIdentity(); //No need camera for ortho mode
//	modelStack.PushMatrix();
//	modelStack.LoadIdentity(); //Reset modelStack
//	modelStack.Scale(size, size, size);
//	modelStack.Translate(x, y, 0);
//
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
//	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
//	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
//	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
//	for (unsigned i = 0; i < text.length(); ++i)
//	{
//		Mtx44 characterSpacing;
//		characterSpacing.SetToTranslation(i * 0.5f + 0.5f, 0.5f, 0); //0.5f beside i is the spacing of each character, you may change this value
//		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
//		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
//
//		mesh->Render((unsigned)text[i] * 6, 6);
//	}
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
//
//	//Add these code just before glEnable(GL_DEPTH_TEST);
//	projectionStack.PopMatrix();
//	viewStack.PopMatrix();
//	modelStack.PopMatrix();
//
//
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey)
//{
//	glDisable(GL_DEPTH_TEST);
//	Mtx44 ortho;
//	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
//	projectionStack.PushMatrix();
//	projectionStack.LoadMatrix(ortho);
//	viewStack.PushMatrix();
//	viewStack.LoadIdentity(); //No need camera for ortho mode
//
//	modelStack.PushMatrix();
//	modelStack.LoadIdentity();
//	modelStack.Translate((float)x, (float)y, 0);
//	modelStack.Scale((float)sizex, (float)sizey, 1);
//	//to do: scale and translate accordingly
//	RenderMesh(mesh, false); //UI should not have light
//	projectionStack.PopMatrix();
//	viewStack.PopMatrix();
//	modelStack.PopMatrix();
//	glEnable(GL_DEPTH_TEST);
//}
//
//void SceneBase::resetAll()
//{
//	camera.position.Set(0.f, 0.f, 484.f);
//}
//
//void SceneBase::Exit()
//{
//	// Cleanup VBO here
//	for (int i = 0; i < NUM_GEOMETRY; ++i)
//	{
//		if (meshList[i] != NULL)
//		{
//			delete meshList[i];
//		}
//	}
//	glDeleteVertexArrays(1, &m_vertexArrayID);
//
//	glDeleteProgram(m_programID);
//}
//
