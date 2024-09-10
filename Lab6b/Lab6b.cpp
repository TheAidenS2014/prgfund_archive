//
// TheAidenS2014
// Last modified 4/2/2024
//
// Displays the contents of
// "Cinderella.txt" on the
// terminal.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream theFile;
string theText;

int main()
{
	cout << endl;

	// open the file (stored with project file)
	theFile.open("Cinderella.txt");
	if (!theFile.is_open())
	{
		cout << "Unable to open file \"Cinderella.txt\".";
		return 1; // error! [EXIT]
	}

	// display the contents of the file
	while (!theFile.eof())
	{
		getline(theFile, theText); // stores a new line per loop...
		cout << theText << endl;   // ...then displays the line
	}

	// close the file
	theFile.close();

	return 0; // finish! [EXIT]
}