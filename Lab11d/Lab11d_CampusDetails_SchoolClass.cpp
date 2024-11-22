//
// Written by TheAidenS2014
// Last modified 10/30/2024
// Definition file for Lab11d
// 
// `SchoolClass` class
//

#include "Lab11d_CampusDetails.h"
#include <iostream>
using std::cout;

void SchoolClass::storeStudent(const Student& in_student)
{
	registeredStudent.push_back(in_student);
}
void SchoolClass::setTeacher(const Teacher& in_teacher)
{
	subjectTeacher = in_teacher;
}
void SchoolClass::setSubject(string in_subject)
{
	subject = in_subject;
}

Student SchoolClass::getStudent(int index)
{
	return registeredStudent.at(index);
}
Teacher SchoolClass::getTeacher()
{
	return subjectTeacher;
}
string SchoolClass::getSubject()
{
	return subject;
}

SchoolClass::SchoolClass()
{
	storeStudent(Student());
	setTeacher(Teacher());
	setSubject("TBD");
}

int SchoolClass::getSize()
{
	return registeredStudent.size();
}

void SchoolClass::print()
{
	cout << "========= Class Details =========\n"
		 << "Subject:       " << this->subject << "\n"
		 << "# of Students: " << this->registeredStudent.size() - 1 << "\n\n";

	cout << "========= Teacher =========\n"
		 << "Name:      " << this->getTeacher().name << "\n"
		 << "Age:       " << this->getTeacher().age << "\n"
		 << "Seniority: " << this->getTeacher().getSeniority() << "\n"
		 << "Subject:   " << this->getTeacher().getSubject() << "\n\n";
	
	for (int class_loop = 1; class_loop < this->getSize(); class_loop++)
	{
		cout << "========= Student #" << class_loop << " ========= \n"
			 << "Name:  " << this->getStudent(class_loop).name << "\n"
			 << "Age:   " << this->getStudent(class_loop).age << "\n"
			 << "Grade: " << this->getStudent(class_loop).getGrade() << "\n"
			 << "Major: " << this->getStudent(class_loop).getMajor() << "\n";
	}
}