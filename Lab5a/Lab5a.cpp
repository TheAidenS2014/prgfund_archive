// 
// TheAidenS2014
// Last revised 3/3/2024
//
// A simple loop that quits
// when the user types "q",
// presented as a guessing
// game (with extra flair)
//

#include <iostream>
using namespace std;

char userInput, userInput_old;
int counter = 0;

int main()
{
	cout << "I'm thinking of a letter. Can you guess it?";

	while (userInput != 'q')
	{
		userInput_old = userInput; // save previous guess before user tries again

		cout << "\n\> ";
		cin >> userInput;

		if (userInput != 'q' && !isdigit(userInput)) // if guess is a letter besides "q"
			cout << "\nHmm... that's not it. Try again.";
		if (isdigit(userInput)) // if guess is a number
			cout << "\nThat's a number silly! Try again.";

		counter++;
	}

	// successful guess
	if (counter == 1)
		cout << "\nYowzers! You figured it out in only " << counter << " try!";
		//cout << "\nYour previous guess was \"" << userInput_old << "\"!"; // NOTE: userInput_old will always be blank here
	else {
		cout << "\nYeah, that's it! You figured it out in " << counter << " tries!";
		cout << "\nYour previous guess was \"" << userInput_old << "\"!";
	}

	cout << endl;
	return 0; // finish!
}

// © 2024 TheAidenS2014