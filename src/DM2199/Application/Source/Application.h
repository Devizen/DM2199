
#ifndef APPLICATION_H
#define APPLICATION_H

#include "timer.h"

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	//bool IsKeyPressed(unsigned short key);
	static bool IsKeyPressed(unsigned short key);

    double switchScene = 0.0;
    double switchScene1 = 0.0;


    static void ChangeScene(int sceneNumber); //0 == Splash, 1 == Main Menu, 2 == Game
    static void loadSceneTime(unsigned time);
    //void timeUpdate(float time);
    //float returnTime();
private:
	//Declare a window object
	StopWatch m_timer;
};

#endif