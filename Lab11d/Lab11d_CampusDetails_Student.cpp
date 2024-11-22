//
// Written by TheAidenS2014
// Last modified 10/30/2024
// Definition file for Lab11d
// 
// `Student` class
//

#include "Lab11d_CampusDetails.h"

void Student::setGrade(float in_grade)
{
	grade = in_grade;
}
void Student::setMajor(string in_major)
{
	major = in_major;
}

float Student::getGrade()
{
	return grade;
}
string Student::getMajor()
{
	return major;
}

Student::Student()
{
	Person::name = "TBD";
	Person::age = 0;
	grade = 0;
	major = "TBD";
}
Student::Student(string in_name, int in_age, float in_grade, string in_major)
{
	Person::name = in_name;
	Person::age = in_age;
	grade = in_grade;
	major = in_major;
}