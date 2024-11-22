// 
// Written by TheAidenS2014
// Last modified 10/28/2024
// 
// Lab11c: "`Car` class with composition"
// Defines a `Car` object and simulates
// driving it with text.
//

#include "Lab11c_CarDetails.h"
using namespace std;

int main()
{
	Car rp_car("medium", 2);

	cout << "\nCar details:\n";
	cout << "Engine volume:\t" << rp_car.getEngineVolume() << " liters\n";
	cout << "Tire size:\t" << rp_car.getTireSize() << "\n";
	
	cout << "\nLet's go for a drive! Are you ready?\n";
	system("PAUSE");
	cout << "\n";
	rp_car.beginDrive();

	return 0;
}