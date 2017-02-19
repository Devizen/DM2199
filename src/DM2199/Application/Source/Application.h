
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

    static void ChangeScene(int sceneNumber); //0 == Splash, 1 == Main Menu, 2 == Game
    static bool loadSceneTime(bool started);
    //void timeUpdate(float time);
    //float returnTime();
private:
	//Declare a window object
	StopWatch m_timer;
};

#endif