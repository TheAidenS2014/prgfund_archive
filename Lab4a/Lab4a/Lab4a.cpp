//
// TheAidenS2014
// Last revised 2/29/2024
//
// Determines a loan payment plan
// from user submitted loan data
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double loanPrinciple, loanIntRate, loanYears, loanPayment;

int main()
{
	// get data from user
	// - principle, interest rate, years
	cout << "Please input the following information regarding your loan.\n";
	cout << "The principle of the loan:        ";
	cin >> loanPrinciple;
	cout << "The interest rate (as a percent): ";
	cin >> loanIntRate;
	cout << "The number of years on the loan:  ";
	cin >> loanYears;
	cout << endl;

	// do the math
	loanIntRate = loanIntRate / 100; // convert from percent to decimal
									 // NOTE: might double convert if user inputed a preconverted rate
	// payment = PR / (1 - (1 + R)^-N)
	loanPayment = (loanPrinciple * (loanIntRate / 12)) / (1 - pow((1 + (loanIntRate / 12)), (-1 * (12 * loanYears))));

	// display results
	cout << "Alright! Here's the payment plan on your loan.\n";
	cout << "Original Loan Amount: $" << fixed << setprecision(2) << loanPrinciple << endl;
	cout << "Monthly Payment:      $" << fixed << setprecision(2) << loanPayment << endl;
	cout << "Total Payments:       $" << fixed << setprecision(2) << (loanPayment * (12 * loanYears)) << endl;

	cout << "\nIf something seems incorrect about these numbers, please review your inputted values and try again.\n"; // covering my bases
	return 0; // finish!
}

// © 2024 TheAidenS2014