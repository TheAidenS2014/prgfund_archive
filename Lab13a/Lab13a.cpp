// 
// Written by TheAidenS2014
// Last modified 11/21/2024
//
// Lab13a: "Overloading arithmetic
//	operators for a Matrix class"
// 
// Displays some matrices and does
// some operations with them. It then
// repeats, but using user submitted
// matrices.
//

#include "Lab13a_MatrixData.h"
#include <iostream>

using namespace std;

int main()
{
	// create matrices dynamically
	Matrix* matrix_supplied_one = new Matrix(1, 2, 3, 4);
	Matrix* matrix_supplied_two = new Matrix(5, 6, 7, 8);

	// display matrices
	cout << "Matrix #1:\n";
	printMatrix(*matrix_supplied_one);
	cout << "Matrix #2:\n";
	printMatrix(*matrix_supplied_two);

	// do operations
	cout << "\nAdding M#1 and M#2...\n";
	printMatrix(*matrix_supplied_one + *matrix_supplied_two);
	cout << "\nSubtracting M#1 and M#2...\n";
	printMatrix(*matrix_supplied_one - *matrix_supplied_two);
	cout << "\nMultiplying M#1 and M#2...\n";
	printMatrix(*matrix_supplied_one * *matrix_supplied_two);

	// delete matrices
	delete matrix_supplied_one;
	delete matrix_supplied_two;

	/* SPACER */ cout << "\n===---==--=--=--==---===\n";

	cout << "\nNow it's your turn!\nPress \"Enter\" to continue...";
	cin.get(); // alternative to calling the Windows Command Prompt's "pause"

	cout << "\nPlease input two new matrices with spaces between the numbers.";
	cout << "\n--- Each matrix must have four data points! ---\n";
	double user_data_one, user_data_two, user_data_three, user_data_four,
		   user_data_five, user_data_six, user_data_seven, user_data_eight;
	cout << "Matrix #1: ";
	cin >> user_data_one >> user_data_two >> user_data_three >> user_data_four;
	cout << "Matrix #2: ";
	cin >> user_data_five >> user_data_six >> user_data_seven >> user_data_eight;
	cout << "\n";

	// create user matrices dynamically
	Matrix* matrix_user_one = new Matrix(user_data_one, user_data_two, user_data_three, user_data_four);
	Matrix* matrix_user_two = new Matrix(user_data_five, user_data_six, user_data_seven, user_data_eight);

	// display user matrices
	cout << "Matrix #1:\n";
	printMatrix(*matrix_user_one);
	cout << "Matrix #2:\n";
	printMatrix(*matrix_user_two);

	// do operations on user matrices
	cout << "\nAdding M#1 and M#2...\n";
	printMatrix(*matrix_user_one + *matrix_user_two);
	cout << "\nSubtracting M#1 and M#2...\n";
	printMatrix(*matrix_user_one - *matrix_user_two);
	cout << "\nMultiplying M#1 and M#2...\n";
	printMatrix(*matrix_user_one * *matrix_user_two);

	// delete user matrices
	delete matrix_user_one;
	delete matrix_user_two;

	return 0;
}