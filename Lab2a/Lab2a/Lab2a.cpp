//
// TheAidenS2014
//
// Converts user-inputed Fahrenheit to Celsius
//

#include <iostream>
using namespace std;

float fahrenheit = 0;
float celsius = 0;

int main()
{
	cout << "Enter the temperature in degree Fahrenheit: "; // no endl so input and text are together
	cin >> fahrenheit;

	// math and output
	celsius = (fahrenheit - 32) * 5 / 9;
	cout << "The temperature in degree Celsius: " << celsius << endl;

	// exit code
	return 0;
}