//
// TheAidenS2014
// Last revised 3/82024
//
// Shows the factorial of
// a user submitted number,
// with a little extra flair.
//

#include <iostream>
#include <iomanip>
using namespace std;

double userNumber;
double fctrlResult = 1;
double fctrlRecursive;			// the "counter" that gets recursively multiplied into userNumber
const int USERNUMBER_MAX = 170;

int main()
{	
	//cout << "Note: some numbers may be too large to solve." << endl;
	cout << "Enter a positive number: ";
	cin >> userNumber;

	cout << "\n" << userNumber << "! = "; // (1/2) shows what the factorial looks like

	if (userNumber >= 0)
	{
		for (fctrlRecursive = 1; fctrlRecursive <= userNumber; fctrlRecursive++)
			// sets fctrlRecursive to 1, compares it to userNumber, then increases it by 1 every loop
			// loop ends after fctrlRecursive passes userNumber
		{
			fctrlResult = fctrlResult * fctrlRecursive; // multiplies fctrlResult by an increasing fcrtlRecursive, emulating a factorial operation

			if (fctrlRecursive == userNumber) // (2/2) shows what the factorial looks like
				cout << fctrlRecursive; // end of equation
			else
				cout << fctrlRecursive << "*";
		}
	}
	else
		cout << "DNE";  // if not a positive number, then bail
	
	if (userNumber <= USERNUMBER_MAX && userNumber >= 0)
		// standard output for any number between 0 and 170
		cout << "\n\nAnswer: " << fixed << setprecision(0) << fctrlResult;
	else if (userNumber > USERNUMBER_MAX)
		// output for numbers bigger then 170
		// NOTE: userNumber is "inf" here as the factorial can't be represented with doubles, so this check hides that problem
		cout << "\n\nAnswer is too large to compute!";
	else
		// output for anything else, including negatives and non-numbers
		cout << "\n\nYour number must be a non-negative integer.";

	cout << endl;
	return 0;
}