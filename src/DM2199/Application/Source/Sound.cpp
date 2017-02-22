#include "Sound.h"

 ISoundEngine* Sound::soundEngine = createIrrKlangDevice();

Sound::Sound(string soundFile, ik_f32 volume)
{
	//Starting up the Sound Engine
	
	currentSound2D = NULL;


	if (!soundEngine) // creation of soundEngine instance fail
	{
		cout << "Error: Could not create sound engine" << endl;
	}

	if (soundFile != "")
		fileName = soundFile;

	soundEngine->setSoundVolume(volume);
}




Sound::Sound(string soundFile, ik_f32 minDistance, ik_f32 volume)
{
	//Starting up the Sound Engine
	soundEngine = createIrrKlangDevice();
	currentSound3D = NULL;

	
	soundEngine->setDefault3DSoundMinDistance(minDistance);

	if (!soundEngine) // creation of soundEngine instance fail
	{
		cout << "Error: Could not create sound engine" << endl;
	}

	if (soundFile != "")
		fileName = soundFile;
	
	soundEngine->setSoundVolume(volume);
}



Sound::~Sound()
{
	//drop is similar as deleting fucntion
	soundEngine->drop();
	currentSound2D->drop();
	currentSound3D->drop();
}



void Sound::play2DSound(bool loop, bool pause, bool startTrack)
{
	if (fileName == "\0")
	{
		cout << "Error: no sound file is selected" << endl;
		return;                                                                                                 
	}

	//c_str  returns a pointer that points to an array of char

	// play2D(const char *soundFileName, bool playLooped=false, bool startPaused=false, bool track=false)

	// Responsible for playing the sound !!!!!
	currentSound2D = soundEngine->play2D(fileName.c_str(), loop , pause, startTrack); // ISoundEngine class reference


	//if (!currentSound2D)
	//{
	//	cout << "Error could not play file" << endl;
	//	return;
	//}

}

void Sound::play3DSound(bool loop, bool pause, bool startTrack, vec3df soundStartingLocation)
{
	if (fileName == "\0")
	{
		cout << "Error: no sound file is selected" << endl;
		return;
	}
  
	currentSound3D = soundEngine->play3D(fileName.c_str(), soundStartingLocation, loop, pause, startTrack);

	 
}








