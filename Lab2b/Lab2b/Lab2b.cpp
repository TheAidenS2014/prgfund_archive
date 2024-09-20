//
// TheAidenS2014
//
// Calculate the volume of a user defined cylinder
//

#include <iostream>
using namespace std;

double height = 0;
double radius = 0;
double volume = 0;
const double pi = 3.14159;

int main()
{
	// get data from user
	cout << "Enter the height of the cylinder: ";
	cin >> height;
	cout << "Enter the radius of the cylinder: ";
	cin >> radius;
	
	// solve and output result
	volume = pi * height * (radius * radius); // r^2
	cout << "The volume of the cylinder is: " << volume << endl; // finish!

	// exit code
	return 0;
}

// © 2024 TheAidenS2014