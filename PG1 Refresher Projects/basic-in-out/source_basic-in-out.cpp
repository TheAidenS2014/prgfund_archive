//
// Written by TheAidenS2014
// Code last modified 8/27/2024
// Project rebuilt 9/10/2024
// 
// Simple input-output review.
// Calculates the user's final
// grade then displays it and
// their letter grade.
//

using namespace std;
#include <iostream>

const double WEIGHT_LABS = .60,		// 60%
WEIGHT_QUIZZES = .15,	// 15%
WEIGHT_EXAM = .10,		// 10%
WEIGHT_FINAL = .15;	// 15%
double user_labs, user_quizzes, user_exam, user_final, grade;

int main()
{
	cout << "Please input your average grade in the following categories:" << endl;
	// get user data
	cout << "Labs: ";
	cin >> user_labs;
	cout << "Quizzes: ";
	cin >> user_quizzes;
	cout << "Exam 1: ";
	cin >> user_exam;
	cout << "Final: ";
	cin >> user_final;

	// calculate grade
	grade = (user_labs * WEIGHT_LABS) + (user_quizzes * WEIGHT_QUIZZES) + (user_exam * WEIGHT_EXAM) + (user_final * WEIGHT_FINAL);

	cout << "\nYour grade is " << grade;
	// analyze grade and report the letter grade
	if (grade >= 90)
		// 90 - 100
		cout << ", which is an A! Fantastic!";
	else if (grade >= 80)
		// 80 - 89
		cout << ", which is a B! Well done!";
	else if (grade >= 70)
		// 70 - 79
		cout << ", which is a C. Good effort!";
	else if (grade >= 60)
		// 60 - 69
		cout << "\a, which is a D. At least you passed.";
	else
		// 0 - 59
		cout << "\a, which is an F. See you next semester.";

	return 0; // finish!
}

// © 2024 TheAidenS2014