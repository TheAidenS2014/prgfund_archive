//
// TheAidenS2014
// Last modified 4/29/2024
//
// Basic terminal app that takes
// a set of user-inputted numbers
// and reports back information
// about that set (biggest, smallest,
// sum, and average).
//

using namespace std;
#include <iostream>
#include <iomanip>

double theArray[20], userInput;
double arraySum = 0, arrayAvg;
int arrayBiggest = 0, arraySmallest = 0;

int main()
{
	cout << "Please input a set of twenty numbers:\n> ";

	for (int index = 0; index < 20; index++)
	{
		cin >> userInput; // will accept numbers until `theArray` is full (even across multiple lines)
		theArray[index] = userInput;
		//cout << "index " << index << ": " << theArray[index] << endl;

		// biggest
		if (theArray[arrayBiggest] < theArray[index])
			arrayBiggest = index;

		// smallest
		if (theArray[arraySmallest] > theArray[index])
			arraySmallest = index;

		// sum
		arraySum += theArray[index];
	}

	// average
	arrayAvg = arraySum / 20;

	cout << "\nHere's some information about that set:" << endl;
	cout << "Biggest number:         " << theArray[arrayBiggest] << endl;
	cout << "Smallest number:        " << theArray[arraySmallest] << endl;
	cout << "Sum of all numbers:     " << arraySum << endl;
	cout << "Average of all numbers: " << arrayAvg << endl;

	return 0; // finish!
}