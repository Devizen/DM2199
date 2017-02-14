#ifndef SOUND_H
#define SOUND_H

#include <iostream>
#include <string>
#include <Windows.h> // window sleep function
#include "Vector3.h"  // For 3D position
#include <vector>

#include "include/irrKlang.h"
#pragma comment(lib, "irrklang.lib")

using namespace std;
using namespace irrklang;
using std::vector;

class Sound
{
public:
	Sound(string soundFile); // constructor 1 
	Sound(string soundFile, ik_f32 minDistance); // constructor 2 
	~Sound();
 	void play2DSound(bool loop, bool pause, bool startTrack); // Plays entire sound file (2D)  
	void play3DSound(bool loop, bool pause, bool startTrack, vec3df soundStartingLocation); // Plays entire sound file (3D)     

	ISoundEngine* getSoundEngine(){
		return soundEngine;
	}

	string fileName; // Error checking for valid sound file
	Vector3 position; // variable to set position for 3D sound
	int volume; // value of volume is between  0 (mute) and 1 (full volume)   ------> idk whether we need adjust volume

  
private:
	ISoundEngine* soundEngine; // instance of class ISoundEngine to start the sound

	// 2D
	ISound * currentSound2D;  // instance of class ISound to Choose which sound you want to play
	
	//3D
	ISound * currentSound3D;

	bool playLoop = false; // whether to loop the music
	bool startPause = false; // false == start the sound , true === pause the sound
	bool track = false; // set it to true if you want to use  ISoundSource::getPlayLength() 
                            /// getPlayLength() is to extract the sound duration

	
};


#endif