//
// TheAidenS2014
// Last modified 3/26/2024
//
// A simple guessing game
// with a new number
// generated per launch.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// global variables
int randNum;

// functions
int getRandom()
{
	srand(time(0));				// NOTE: will only generate a random number once
	randNum = rand() % 100 + 1; // get random number between 1 and 100

	return randNum;
}

// primary script
int main()
{
	// main() exclusive variables
	int userGuess = 0, userGuess_old, guessCounter = 0;

	getRandom(); // get random number, assign it to randNum
	cout << "I'm thinking of a number between 1 and 100. Can you guess it?";
	//cout << randNum; // for testing

	do {
		userGuess_old = userGuess;
		cout << "\n> ";
		cin >> userGuess;

		if (userGuess > randNum)
			cout << "Nope! Too high!";
		if (userGuess < randNum)
			cout << "Nope! Too low!";

		guessCounter++;
	} while (userGuess != randNum);

	cout << "\nYeah, that's it!";
	cout << "\nYou got it in " << guessCounter;
	if (guessCounter == 1)
		cout << " try. Nice!";
	else
		cout << " tries.";

	cout << endl;
	return 0; // finish!
}

// © 2024 TheAidenS2014