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

//Randomize
#include <stdlib.h>
#include <time.h>

class SceneBase : public Scene
{
	friend class Object;
	friend class Bullet;
	friend class Enemy;

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




        //Text
        GEO_TEXT,

        //UI
        GEO_FACE,
        GEO_BACKGROUND,
        GEO_MESSAGES,

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

    //Reset All Settings
    void resetAll();

	FactoryObject objFactory;
	float _dt;
	float _elapsedTime = 0;


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
    void RenderMeshOnScreen(Mesh* mesh, int x, int y, int sizex, int sizey);
    void renderPosition();


	//Cool down between shooting each bullet
	const float bulletCoolDown = 0.2f;
	float nextBulletTime = 0;

};



#endif