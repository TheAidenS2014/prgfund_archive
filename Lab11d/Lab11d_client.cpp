//
// Written by TheAidenS2014
// Last modified 10/30/2024
// 
// Lab11d: "Custom Class Hierarchy"
// A rather complex hierarchy, created
// by yours truly, which represents a
// college's attendance and class
// breakdown.
//

#include "Lab11d_CampusDetails.h"
#include <iostream>
using namespace std;

int main()
{
	// define students
	Student student_steve("Steve", 23, 93.2247, "Agriculture");
	Student student_alex("Alex", 24, 89.8889, "Animal Science");
	Student student_frank("Frank", 25, 78.2336, "Construction Management");
	Student student_emma("Emma", 22, 97.0018, "Early Childhood Education");
	// define teachers
	Teacher teacher_bob("Bob", 37, 6, "Government");
	Teacher teacher_oscar("Oscar", 45, 15, "Liberal Arts");

	// define classes
	SchoolClass class_gov;
	class_gov.storeStudent(student_steve);
	class_gov.storeStudent(student_alex);
	class_gov.setTeacher(teacher_bob);
	class_gov.setSubject("US Government");
	SchoolClass class_anthro;
	class_anthro.storeStudent(student_frank);
	class_anthro.storeStudent(student_emma);
	class_anthro.setTeacher(teacher_oscar);
	class_anthro.setSubject("Anthropology");

	// define college
	Campus this_college;
	this_college.storeClass(class_gov);
	this_college.storeClass(class_anthro);

	// display contents
	cout << "\n";
	this_college.print();

	return 0; // finish! [PRG EXIT]
}