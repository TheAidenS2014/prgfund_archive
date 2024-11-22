//
// Written by TheAidenS2014
// Last modified 11/21/2024
// Header file for "Lab11c"
//

#pragma once
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <random>
#include <windows.h>
#include <mmsystem.h>
using std::cout;

// layer 3:
class Window
{
public:
	void rollDown()
	{
		cout << "Rolling down window...\n";
	}
};

// layer 2:
class Door
{
public:
	Window windowObject;
	void openDoor()
	{
		cout << "Opening door...\n";
	}
};

class Tire
{
	std::string tireSize;

public:
	void inflateTire(int user_psi)
	{
		cout << "Inflating tire by " << user_psi << " psi...\n";
	}

	void setTireSize(std::string user_tire_size)
	{
		tireSize = user_tire_size;
	}
	std::string getTireSize()
	{
		return tireSize;
	}
};

class Engine
{
	double engineVolume; // liters

public:
	void startEngine()
	{
		cout << "Starting engine...\n";
	}
	void accelerate()
	{
		cout << "Accelerating engine!\n";
	}

	void setEngineVolume(double user_engine_vol)
	{
		engineVolume = user_engine_vol;
	}
	double getEngineVolume()
	{
		return engineVolume;
	}
};

// layer 1:
class Car
{
	Engine engineObject;
	Tire tireObject[4];
	Door driverDoor;
	Door passengerDoor;

public:
	Car() = delete;
	Car(std::string user_tire_size, double user_engine_vol)
	{
		for (int amount = 0; amount < 4; amount++)
		{
			tireObject[amount].setTireSize(user_tire_size);
		}
		engineObject.setEngineVolume(user_engine_vol);
	}

	std::string getTireSize()
	{
		return tireObject[0].getTireSize();
	}
	double getEngineVolume()
	{
		return engineObject.getEngineVolume();
	}

	void beginDrive()
	{
		// driver opens their door
		cout << "Unlocking driver door...\n";
		driverDoor.openDoor();
		PlaySound(TEXT("sound/door.wav"), NULL, SND_FILENAME); // see credit #1
		cout << "\n";
		
		// start engine
		cout << "Buckling up in driver's seat...\n";
		engineObject.startEngine();
		PlaySound(TEXT("sound/engine.wav"), NULL, SND_FILENAME); // see credit #2
		cout << "\n";

		// roll passenger door window down
		passengerDoor.windowObject.rollDown();
		cout << "\n";

		// inflate any tire by 32 psi
		srand(time(0));
		int random_tire = rand() % 4;
		cout << "Warning on the dash: tire #" << random_tire + 1 << " is low!\n";
		cout << "Getting out of car to fix...\n";
		driverDoor.openDoor();
		PlaySound(TEXT("sound/door.wav"), NULL, SND_FILENAME); // see credit #1

		cout << "Getting pump from trunk...\n";
		tireObject[random_tire].inflateTire(32);
		cout << "Returning pump to trunk...\n";
		driverDoor.openDoor();
		PlaySound(TEXT("sound/door.wav"), NULL, SND_FILENAME); // see credit #1

		cout << "Buckling up in driver's seat...\n";
		cout << "\n";

		// accelerate
		cout << "Foot on the gas...\n";
		system("PAUSE");
		cout << "\n";
		engineObject.accelerate();
		PlaySound(TEXT("sound/car.wav"), NULL, SND_FILENAME); // see credit #3
	}
};

//
// SOUNDS USED:
// 1. car door opening3 by supersnd			 -- https://freesound.org/s/260075/ -- License: Creative Commons 0
// 2. Car Engine Start.wav by tbsounddesigns -- https://freesound.org/s/405322/ -- License: Creative Commons 0
// 3. car_6 by dfeeka						 -- https://freesound.org/s/716081/ -- License: Creative Commons 0
//