//
// TheAidenS2014
// Last modified 9/24/2024
// 
// Lab9a: "Creating and using a `Date` struct"
// Basic terminal program that stores
// three user submitted dates.
//

using namespace std;
#include <iostream>
#include <iomanip>
#include <map>

struct Date // Complex variable - stores a complete date (ex: 12/25/2012)
{
	string month;
	int day;
	int year;
};
const int MAX_USERDATES = 3;
Date userDates[MAX_USERDATES]{};

static void displayDateArray(Date dates_array[MAX_USERDATES])
{
	cout << setw(10) << left << "\nMonth" << " Day\t" << "Year\n";
	cout << "====================\n";
	for (int position = 0; position < MAX_USERDATES; position++)
		cout << setw(10) << left << dates_array[position].month << dates_array[position].day << "\t" << dates_array[position].year << "\n";
}

static int verifyDateArray(Date dates_array[MAX_USERDATES])
{
	map<string, string> month_reference =
	{
		{"Jan", "January"},		{"1", "January"},
		{"Feb", "February"},	{"2", "February"},
		{"Mar", "March"},		{"3", "March"},
		{"Apr", "April"},		{"4", "April"},
		{"May", "May"},			{"5", "May"},
		{"Jun", "June"},		{"6", "June"},
		{"Jul", "July"},		{"7", "July"},
		{"Aug", "August"},		{"8", "August"},
		{"Sep", "September"},	{"9", "September"},
		{"Oct", "October"},		{"10", "October"},
		{"Nov", "November"},	{"11", "November"},
		{"Dec", "December"},	{"12", "December"}
	};

	for (int position = 0; position < MAX_USERDATES; position++)
	{
		// capitalize first letter to match map table
		dates_array[position].month[0] = toupper(dates_array[position].month[0]);
		// convert short month name to full name
		dates_array[position].month = month_reference[dates_array[position].month.substr(0, 3)];
		
		if (dates_array[position].month.empty())
			// if month doesn't match anything in the table [EXIT]
			return 1;

		if (dates_array[position].day > 31 || dates_array[position].day < 1)
			// NOTE: assumes all months have 31 days
			// if day isn't possible [EXIT]
			return 2;
	}

	return 0; // everything looks good [EXIT]
}

int main()
{
	cout << "Please enter three calendar days: (ex: 12 25 2012)\n";
	for (int count = 0; count < MAX_USERDATES; count++)
	{
		// get dates from user, loop until array is full
		cout << "- Date #" << count + 1 << ": ";
		cin >> userDates[count].month;
		cin >> userDates[count].day;
		cin >> userDates[count].year;
	}

	// verify (and convert) dates
	if (verifyDateArray(userDates) == 0)
		// no issues, so display dates
		displayDateArray(userDates);
	else
	{
		// an issue was found; abort
		cout << "\n[ERROR] An invalid date was entered. Please try again.\n";
		return 1; // finish with error(s) [PRG EXIT]
	}

	return 0; // finish with no problems [PRG EXIT]
}

// © 2024 TheAidenS2014