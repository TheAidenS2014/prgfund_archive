//
// Written by TheAidenS2014
// Code last modified 9/9/2024
// Project rebuilt 9/10/2024
//
// Credit card number validator
// via a vector arrays.
// The method used here is mostly
// for demonstration purposes,
// so it's not super optimized.
//

using namespace std;
#include <iostream>
#include <vector>

vector<int> creditCardNumber = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
// 4 5 5 6 7 3 7 5 8 6 8 9 9 8 5 - known working (fake) ccn

static void displayCCN()
{
	for (int digit = 0; digit < creditCardNumber.size(); digit++)
	{
		cout << creditCardNumber[digit] << " ";
	}
	cout << "\n\n";
}

int main()
{
	// get ccn from user
	int user_input;
	cout << "Please input your 16 digit credit card number (with spaces between the digits) for validation:\n> ";
	for (int digit = 0; digit < creditCardNumber.size(); digit++)
	{
		cin >> user_input;
		creditCardNumber[digit] = user_input;
	}
	cout << endl;

	// display unmodified ccn
	cout << "Original CCN:\n> ";
	displayCCN();

	// drop last digit
	cout << "1. Remove last digit:\n> ";
	int lastCCNdigit = creditCardNumber.back();
	creditCardNumber.pop_back();
	displayCCN();

	// reverse ccn
	cout << "2. Reverse CCN:\n> ";
	reverse(creditCardNumber.begin(), creditCardNumber.end());
	displayCCN();

	// multiply odd digits
	cout << "3. Double the digits in the odd position:\n> ";
	for (int digit = 0; digit < creditCardNumber.size(); digit++)
	{
		if (digit % 2 == 0)
			creditCardNumber[digit] = creditCardNumber[digit] * 2;
	}
	displayCCN();

	// if digit > 9, subtract 9
	cout << "4. If any of those digits are over 9, then reduce them by 9:\n> ";
	for (int digit = 0; digit < creditCardNumber.size(); digit++)
	{
		if (creditCardNumber[digit] > 9)
			creditCardNumber[digit] -= 9;
	}
	displayCCN();

	// add all digits, mod by 10
	cout << "5. Add up all of the digits, then mod the sum by 10 to validate CCN:\n> ";
	int sum = 0;
	for (int digit = 0; digit < creditCardNumber.size(); digit++)
	{
		sum += creditCardNumber[digit];
	}
	sum = sum % 10;

	// validate ccn
	if (sum == lastCCNdigit)
		cout << sum << " = " << lastCCNdigit << "; " << "Card is valid!" << endl;
	else
		cout << sum << " =/= " << lastCCNdigit << "; " << "Card is invalid!" << endl;

	return 0; // finish! [EXIT PROGRAM]
}

// © 2024 TheAidenS2014