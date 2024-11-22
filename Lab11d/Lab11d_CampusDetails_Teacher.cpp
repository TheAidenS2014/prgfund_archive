//
// Written by TheAidenS2014
// Last modified 10/30/2024
// Definition file for Lab11d
// 
// `Teacher` class
//

#include "Lab11d_CampusDetails.h"

void Teacher::setSeniority(int in_years)
{
	seniority = in_years;
}
void Teacher::setSubject(string in_subject)
{
	subject = in_subject;
}

int Teacher::getSeniority()
{
	return seniority;
}
string Teacher::getSubject()
{
	return subject;
}

Teacher::Teacher()
{
	Person::name = "TBD";
	Person::age = 0;
	seniority = 0;
	subject = "TBD";
}
Teacher::Teacher(string in_name, int in_age, int in_years, string in_subject)
{
	Person::name = in_name;
	Person::age = in_age;
	seniority = in_years;
	subject = in_subject;
}