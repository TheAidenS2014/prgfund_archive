//
// TheAidenS2014
// Last revised 2/20/2024
//
// Simple cable billing terminal app
//

#include <iostream>
#include <iomanip>
using namespace std;

// identification - to be filled at runtime
int accountNumber;
int premiumNumber; // number of premium channels
int	connectNumber; // number of service connections (B only)
char customerType;
string customerTypeName;
double amountDue;

// named constants - residential customers
const double RES_BILL_PROC_FEES = 4.50;     // R processing fees
const double RES_BASIC_SERV_COST = 20.50;   // R service costs
const double RES_COST_PREM_CHANNEL = 7.50;  // R premium channels cost

// named constants - business customers
const double BUS_BILL_PROC_FEES = 15.00;    // B processing fees
const double BUS_BASIC_SERV_COST = 75.00;   // B service costs
const double BUS_COST_PREM_CHANNEL = 50.00; // B premium channels cost
const double BUS_BASIC_CONN_COST = 5.00;    // B service connections cost

int main()
{
	// get account details
	cout << "Please input your account number:\n\> ";
	cin >> accountNumber;
	cout << "Please enter customer type (\"R\" for Residential or \"B\" for Business):\n\> ";
	cin >> customerType;
	cout << endl;

	// determine account type, customize plan, then determine amount due
	switch (customerType)
	{
		case 'r': // residential type
		case 'R': 
			customerTypeName = "Residential";

			cout << "How many premium channels do you want?: ";
			cin >> premiumNumber;
			
			amountDue = RES_BILL_PROC_FEES + RES_BASIC_SERV_COST + premiumNumber * RES_COST_PREM_CHANNEL;
			
			break;
		// end of case r / R

		case 'b': // business type
		case 'B': 
			customerTypeName = "Business";

			cout << "How many service connections?: ";
			cin >> connectNumber;
			cout << "How many premium channels?:    ";
			cin >> premiumNumber;
			
			if (connectNumber < 10)
				amountDue = BUS_BILL_PROC_FEES + BUS_BASIC_SERV_COST + premiumNumber * BUS_COST_PREM_CHANNEL;
			else
				amountDue = BUS_BILL_PROC_FEES + (connectNumber - 10) * BUS_BASIC_CONN_COST + premiumNumber * BUS_COST_PREM_CHANNEL;
			
			break;
		// end of case b / B

		default : // invalid type
			cout << "Sorry, but that is an invalid account type. Please try again.";
			break;
	}
	// end of switch

	// output results
	cout << endl;
	if (customerTypeName != "") // why show amount if account is invalid?
	{
		cout << "The amount due for " << customerTypeName << " Account #" << accountNumber << " is:\n\> $";
		cout << fixed << setprecision(2) << amountDue; // "fixed" forces amountDue to be a decimal, so it appears properly
		cout << endl;
	}

	return 0; // finish!
}

// © 2024 TheAidenS2014