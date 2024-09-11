//
// Written by TheAidenS2014
// Code last modified 8/29/2024
// Project rebuilt 9/10/2024
// 
// Reads sets of names from
// an array, displaying them
// and their length. Also
// displays initials and a
// random sequence from each
// full name.
//

using namespace std;
#include <iostream>
#include <iomanip>

const int FULLNAMES_XSIZE = 3, // not necessary,
FULLNAMES_YSIZE = 5; // but handy
string fullNames[FULLNAMES_YSIZE][FULLNAMES_XSIZE]
{
	// first,  middle,		 last
	   "John", "Doe",       "Smith",
	   "Kate", "Garry",     "Hudson",
	   "Tina", "Stamatina", "Fey",
	   "Hugh", "Mungo",     "Grant",
	   "Uma",  "Karuna",    "Thurman",
};

int main()
{
	// NOTE: code is staggered to be more readable
	//		 and for ease of debugging.

	for (int index_y = 0; index_y < FULLNAMES_YSIZE; index_y++)
	{
		string name_cache = "";
		int rand_pos;

		// first name + length
		cout << "Your first name is \"" << fullNames[index_y][0] << "\", ";
		cout << "which is " << fullNames[index_y][0].length() << " characters long." << endl;
		name_cache.append(fullNames[index_y][0] + " ");

		// middle name + length
		cout << "Your middle name is \"" << fullNames[index_y][1] << "\", ";
		cout << "which is " << fullNames[index_y][1].length() << " characters long." << endl;
		name_cache.append(fullNames[index_y][1] + " ");

		// last name + length
		cout << "Your last name is \"" << fullNames[index_y][2] << "\", ";
		cout << "which is " << fullNames[index_y][2].length() << " characters long." << endl;
		name_cache.append(fullNames[index_y][2]);

		// initials + full name length
		cout << "Your initials are \"" << fullNames[index_y][0].substr(0, 1) << fullNames[index_y][1].substr(0, 1) << fullNames[index_y][2].substr(0, 1);
		cout << "\". The length of your entire name (including spaces) is " << name_cache.length() << " characters long." << endl;

		// random sequence
		srand(time(0));
		rand_pos = rand() % name_cache.length();
		if (rand_pos > name_cache.length() - 5) // enforces a length of 5 and stops it overflowing bounds of the string
			rand_pos -= 5;
		cout << "A random sequence of five letters in your name is \"" << name_cache.substr(rand_pos, 5) << "\".\n" << endl;
	}

	return 0; // finish!
}