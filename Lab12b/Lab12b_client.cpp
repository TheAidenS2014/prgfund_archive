//
// Written by TheAidenS2014
// Last modified 11/11/2024
//
// Lab12b: "Abstract class and subclasses"
// Creates two objects derived from children
// of the abstract class `Employee` and
// prints their contents to the terminal.
//

#include "Lab12b_EmployeeDetails.h"
#include <iostream>

int main()
{
	// create objects dynamically
	FullTime* employee_lisa = new FullTime(883505109, 200.00, 2750);
	PartTime* employee_avani = new PartTime(456367788, 20, 90);

	// display the contents of the objects
	std::cout << "\n---=== Lisa  ===---\n";
	employee_lisa->print();
	std::cout << "\n---=== Avani ===---\n";
	employee_avani->print();

	return 0; // [PRG EXIT]
}