#ifndef SCENEBASE_H
#define SCENEBASE_H

#include "Scene.h"
#include "Camera.h"
#include "Camera3.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "FactoryObject.h"
#include "Enemy.h"
#include "Sound.h"

//Randomize
#include <stdlib.h>
#include <time.h>

class SceneBase : public Scene
{
	friend class Object;
	friend class Bullet;
	friend class Enemy;
	friend class Sound;

    enum GEOMETRY_TYPE
    {
        GEO_FLOOR = 0,
        GEO_AXES,
        GEO_X,
        GEO_Y,
        GEO_Z,
        GEO_FPS,

        GEO_LIGHTBALL,
        GEO_LIGHTBALL2,

        //Skybox Day
        GEO_LEFT,
        GEO_RIGHT,
        GEO_TOP,
        GEO_BOTTOM,
        GEO_FRONT,
        GEO_BACK,

        //SkyBox Night
        GEO_LEFTn,
        GEO_RIGHTn,
        GEO_TOPn,
        GEO_BOTTOMn,
        GEO_FRONTn,
        GEO_BACKn,

        //Environment
        GEO_MOUNTAIN,
        GEO_MOUNTAIN_2,
        GEO_GROUND,

		//Enemy 
		GEO_ENEMYHEAD,
		GEO_ENEMYLEFTARM,
		GEO_ENEMYRIGHTARM,
		GEO_ENEMYLEFTLEG,
		GEO_ENEMYRIGHTLEG,
		GEO_ENEMYTORSO,
		
		GEO_FLICKER,
		GEO_HP75,
		GEO_HP50,
		GEO_HP25,

      
        //Text
        GEO_TEXT,

        //UI
        GEO_FACE,
        GEO_BACKGROUND,
        GEO_MESSAGES,

		//Sprites
		GEO_HANDL1,
		GEO_HANDL2,
		GEO_HANDR1,
		GEO_HANDR2,
		GEO_GUN1,
		GEO_GUN2,
		GEO_GUN3,
		GEO_CANNON1,
		GEO_CANNON2,
		GEO_CANNON3,
		GEO_SWORD1,
		GEO_SWORD2,
		GEO_SWORD3,


        //Portal Lightball
        GEO_LIGHTBALL3,

        NUM_GEOMETRY,
    };

    enum UNIFORM_TYPE
    {
        U_MVP = 0,
        U_MODELVIEW,
        U_MODELVIEW_INVERSE_TRANSPOSE,
        U_MATERIAL_AMBIENT,
        U_MATERIAL_DIFFUSE,
        U_MATERIAL_SPECULAR,
        U_MATERIAL_SHININESS,
        U_LIGHT0_POSITION,
        U_LIGHT0_COLOR,
        U_LIGHT0_POWER,
        U_LIGHT0_KC,
        U_LIGHT0_KL,
        U_LIGHT0_KQ,

        U_LIGHT0_TYPE,
        U_LIGHT0_SPOTDIRECTION,
        U_LIGHT0_COSCUTOFF,
        U_LIGHT0_COSINNER,
        U_LIGHT0_EXPONENT,

        U_LIGHT1_POSITION,
        U_LIGHT1_COLOR,
        U_LIGHT1_POWER,
        U_LIGHT1_KC,
        U_LIGHT1_KL,
        U_LIGHT1_KQ,

        U_LIGHT1_TYPE,
        U_LIGHT1_SPOTDIRECTION,
        U_LIGHT1_COSCUTOFF,
        U_LIGHT1_COSINNER,
        U_LIGHT1_EXPONENT,

        U_LIGHT2_POSITION,
        U_LIGHT2_COLOR,
        U_LIGHT2_POWER,
        U_LIGHT2_KC,
        U_LIGHT2_KL,
        U_LIGHT2_KQ,

        U_LIGHT2_TYPE,
        U_LIGHT2_SPOTDIRECTION,
        U_LIGHT2_COSCUTOFF,
        U_LIGHT2_COSINNER,
        U_LIGHT2_EXPONENT,

        U_LIGHTENABLED,
        U_NUMLIGHTS,

        U_COLOR_TEXTURE_ENABLED,
        U_COLOR_TEXTURE,

        //Text
        U_TEXT_ENABLED,
        U_TEXT_COLOR,

        U_TOTAL,
    };


    unsigned m_parameters[U_TOTAL];

public:
    SceneBase();
    ~SceneBase();

    void RenderMesh(Mesh *mesh, bool enableLight);
    void renderGround();
    void renderMountains();


    virtual void Init();
    virtual void Update(double dt);
    virtual void Render();
    virtual void Exit();

    float rotateAngle;

    float FPS;


    //Day/Night Cycle
    bool cycle = false;
    bool night = false;
    unsigned cycleState = 0;
    void cycleCheck();
    void renderLightSwitch();

    //Text
    void renderText();

	//Sprites
	void renderSprites();

    //Reset All Settings
    void resetAll();

	FactoryObject objFactory;
	float _dt;
	float _elapsedTime = 0;

	//Sound
	std::vector<Sound *> soundStorage;

private:
    unsigned m_vertexArrayID;
    Mesh* meshList[NUM_GEOMETRY];
    unsigned m_programID;

    Camera3 camera;

    MS modelStack, viewStack, projectionStack;

    //Normal
    Light light[3];

    //Skybox
    void RenderSkybox();
    void renderEndBox();
    float rotateSkybox;

    //Text
    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
    void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey, int sizez, int rotation);
    void renderPosition();

	// Cool Down Time
	const float coolDown = 0.2f;
	//Cool down between shooting each bullet
	float nextBulletTime = 0;
	//Cool Down between each walk sound
	float nextWalkTime = 0;

};



#endif