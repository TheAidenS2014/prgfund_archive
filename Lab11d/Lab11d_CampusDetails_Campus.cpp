//
// Written by TheAidenS2014
// Last modified 10/30/2024
// Definition file for Lab11d
// 
// `Campus` class
//

#include "Lab11d_CampusDetails.h"
#include <iostream>
using std::cout;

void Campus::storeClass(const SchoolClass &in_class)
{
	officialClass.push_back(in_class);
}

SchoolClass Campus::getClass(int index)
{
	return officialClass.at(index);
}

Campus::Campus()
{
	storeClass(SchoolClass());
}

void Campus::print()
{

	for (int campus_loop = 1; campus_loop < this->officialClass.size(); campus_loop++)
	{
		cout << "========= Class #" << campus_loop << " =========\n"
			<< "Subject:       " << this->getClass(campus_loop).getSubject() << "\n"
			<< "# of Students: " << this->getClass(campus_loop).getSize() - 1 << "\n\n";

		cout << "========= Class #" << campus_loop << ", Teacher =========\n"
			<< "Name:      " << this->getClass(campus_loop).getTeacher().name << "\n"
			<< "Age:       " << this->getClass(campus_loop).getTeacher().age << "\n"
			<< "Seniority: " << this->getClass(campus_loop).getTeacher().getSeniority() << "\n"
			<< "Subject:   " << this->getClass(campus_loop).getTeacher().getSubject() << "\n\n";

		for (int class_loop = 1; class_loop < this->getClass(campus_loop).getSize(); class_loop++)
		{
			cout << "========= Class #" << campus_loop << ", Student #" << class_loop << " ========= \n"
				<< "Name:  " << this->getClass(campus_loop).getStudent(class_loop).name << "\n"
				<< "Age:   " << this->getClass(campus_loop).getStudent(class_loop).age << "\n"
				<< "Grade: " << this->getClass(campus_loop).getStudent(class_loop).getGrade() << "\n"
				<< "Major: " << this->getClass(campus_loop).getStudent(class_loop).getMajor() << "\n";
		}

		cout << "\n\n\n";
	}
}