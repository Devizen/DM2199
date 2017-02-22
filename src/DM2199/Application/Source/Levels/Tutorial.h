#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "../Scene.h"
#include "../SceneMainMenu.h"
#include "../Camera.h"
#include "../Camera3.h"
#include "../Mesh.h"
#include "MatrixStack.h"
#include "../Light.h"
#include "../FactoryObject.h"
#include "../Enemy.h"
#include "../Sound.h"

//Randomize
#include <stdlib.h>
#include <time.h>
#include <vector>

using std::vector;

class Tutorial : public Scene
{

	friend class Object;
	friend class Bullet;
	friend class Enemy;
	friend class Sound;
	friend class Camera3;
	friend class SceneMainMenu;

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

		//Enemy 1
		GEO_ENEMYHEAD,
		GEO_ENEMYLEFTARM,
		GEO_ENEMYRIGHTARM,
		GEO_ENEMYLEFTLEG,
		GEO_ENEMYRIGHTLEG,
		GEO_ENEMYTORSO,

		//Enemy 2
		GEO_ENEMYLEFTARM2,
		GEO_ENEMYRIGHTARM2,
		GEO_ENEMYLEFTLEG2,
		GEO_ENEMYRIGHTLEG2,
		GEO_ENEMYTORSO2,

		//Enemy 3
		GEO_ENEMYLEFTARM3,
		GEO_ENEMYRIGHTARM3,
		GEO_ENEMYLEFTLEG3,
		GEO_ENEMYRIGHTLEG3,
		GEO_ENEMYTORSO3,

		//Enemy 4
		GEO_ENEMYLEFTARM4,
		GEO_ENEMYRIGHTARM4,
		GEO_ENEMYLEFTLEG4,
		GEO_ENEMYRIGHTLEG4,
		GEO_ENEMYTORSO4,

		GEO_FLICKER,
		GEO_HP75,
		GEO_HP50,
		GEO_HP25,

		//Item & Inventory
		GEO_SWORD,

		//minimap
		GEO_MINI_PLAYER,
		GEO_MINI_GROUND,
		GEO_MINI_ENEMY,

		GEO_INVENTORY,
		GEO_GAME_HUD,
		GEO_HP,

		GEO_EN,
		GEO_ARROW,
		GEO_ACTIVE_SELECT,
		GEO_SECONDARY_SELECT,
		GEO_TIME,

		GEO_COUNTDOWN,

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
		GEO_HANDI,
		GEO_GUN1,
		GEO_GUN2,
		GEO_GUN3,
		GEO_GUNI,
		GEO_SWORD1,
		GEO_SWORD2,
		GEO_SWORD3,
		GEO_SWORDI,
		GEO_TORCH,
		GEO_TORCHI,
		GEO_HEALTHPOTION,
		GEO_ANTIDOTE,

		//Electric Field
		GEO_ELECTRIC_FIELD,

		//Portal Lightball
		GEO_LIGHTBALL3,

		//Pause Menu
		PAUSE,
		ARROW,

		//Spider
		GEO_SPIDER,

		GEO_ENEMYHEALTHBAR,

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

	enum MENU
	{
		CONTINUE = 0,
		BACKTOMAINMENU,
	};

	unsigned m_parameters[U_TOTAL];


=======
    friend class Object;
    friend class Bullet;
    friend class Sound;
    friend class Spider;
    friend class Robot;

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

        //Enemy 1
        GEO_ENEMYHEAD,
        GEO_ENEMYLEFTARM,
        GEO_ENEMYRIGHTARM,
        GEO_ENEMYLEFTLEG,
        GEO_ENEMYRIGHTLEG,
        GEO_ENEMYTORSO,

        //Enemy 2
        GEO_ENEMYLEFTARM2,
        GEO_ENEMYRIGHTARM2,
        GEO_ENEMYLEFTLEG2,
        GEO_ENEMYRIGHTLEG2,
        GEO_ENEMYTORSO2,

        //Enemy 3
        GEO_ENEMYLEFTARM3,
        GEO_ENEMYRIGHTARM3,
        GEO_ENEMYLEFTLEG3,
        GEO_ENEMYRIGHTLEG3,
        GEO_ENEMYTORSO3,

        //Enemy 4
        GEO_ENEMYLEFTARM4,
        GEO_ENEMYRIGHTARM4,
        GEO_ENEMYLEFTLEG4,
        GEO_ENEMYRIGHTLEG4,
        GEO_ENEMYTORSO4,

        GEO_FLICKER,
        GEO_HP75,
        GEO_HP50,
        GEO_HP25,

        //Item & Inventory
        GEO_SWORD,
        GEO_TORCH,

        //minimap
        GEO_MINI_PLAYER,
        GEO_MINI_GROUND,
        GEO_MINI_ENEMY,

        GEO_INVENTORY,
        GEO_GAME_HUD,
        GEO_HP,

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

        //Spider
        GEO_SPIDER,



        GEO_ENEMYHEALTHBAR,


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
>>>>>>> cd36b4f7b3fdd3d54a961307a042fffb32eb3d8f

public:
    Tutorial();
    ~Tutorial();

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

	//Torch
	bool torchDead = false;

	//Sprites
	void renderSprites();
	bool swing = false;

	//Potion
	int potionCount = 3;
	int usedPotionTime = 0;
	bool potionUsed = false;
	bool noPotion = false;
	bool notHurt = false;
	bool usedPotionOnce = false;
	bool usedPotionText = false;

	//Antidote
	int antidoteCount = 0;
	int usedAntidoteTime = 0;
	bool antidoteUsed = false;
	bool noAntidote = false;
	bool notPoisoned = false;
	bool usedAntidoteOnce = false;
	bool usedAntidoteText = false;

	//Electric field
	void renderElectricField();

    //Reset All Settings
    void resetAll();



	FactoryObject objFactory;
	float _dt;
	float _elapsedTime = 0;
	float swingTime = 0;

    //Sound
    std::vector<Sound *> soundStorage;


    bool inventoryOpen;

    float startTime;
    float cooldown;


	//Enemy
	void enemyUpdate(double dt);

	float rotateArm = 0.f;

	float rotateIndividualArm = 0.f;
	float rotateLeftArm = 0.f;
	bool robotShoot = false;
	bool shootArmDown = true;
	bool broughtDown = true;
	float scaleDamage = 0.2f;

	bool bulletTouch = false;
	bool damaged = false; // character to enemy

	std::vector<Enemy *> enemyStorage;

	int energy = 10000;
	int timeleft = 60000;

private:
	vector<string>objectName;
	vector<string>objectTexture;
	vector<string>objectPosX;
	vector<string>objectPosZ;
	unsigned m_vertexArrayID;
	Mesh* meshListPredefined[totalObjects];
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
	void RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey, float rotateAngle, float xAxis, float yAxis, float zAxis);
	void renderPosition();

	// Cool Down Time
	const float coolDown = 0.25f;
	//Cool down between shooting each bullet
	float nextBulletTime = 0;
	//Cool Down between each walk sound
	float nextWalkTime = 0;

	//Delay for placing objects
	float pressDelay = 0.f;

	//Choosing Object, 0 is mountain.
	int selectObject = 0;

	//Enabling and Disabling Collison.
	bool passCol;

	//Pause Menu
	MENU selectOptions = CONTINUE;
	//Render Pause Menu
	void pause();
	//Check if Pause Menu was called
	bool pauseActivate;

	//Cooldown for Button Pressed
	const float cooldownPressed = 0.5f;
=======
    bool bulletTouch = false;
    bool damaged = false; // character to enemy

    std::vector<Enemy *> enemyStorage;

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

    void renderInventory();
    //Text
    void RenderText(Mesh* mesh, std::string text, Color color);
    void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
    void RenderMeshOnScreen(Mesh* mesh, float x, float y, float sizex, float sizey);
    void renderPosition();

    // Cool Down Time
    const float coolDown = 0.3f;
    //Cool down between shooting each bullet
    float nextBulletTime = 0.f;
    //Cool Down between each walk sound
    float nextWalkTime = 0.f;

	float nextJump = 0.f;

	float nextSplatter = 0.f;

	float nextRun = 0.f;

	float nextPotion = 0.f;

	float nextRobotShoot = 0.f;

	void renderRemainingTime();
	void renderStats();
	void renderPotionCount();
	void renderAntidoteCount();

	void renderInventory();
	void renderHUD();
	void renderEnemy();

	void renderObjects();
};

#endif