//
// Written by TheAidenS2014
// Last modified 11/21/2024
// 
// Lab12a: "Basic Practice with Pointers"
// A class and an integer accessed via pointers.
// 
// Reuses `Student` class from Lab11d,
// although adjusted to be independent.
//

#include <iostream>
using namespace std;

int particularVariable = 9;

class Student
{
	string name = "TBD";
	int age = 0;
	float grade = 0;
	string major = "TBD";

public:
	void setName (string in_name )	{ name = in_name;	}
	void setAge  (int in_age	 )	{ age = in_age;		}
	void setGrade(float in_grade )	{ grade = in_grade; }
	void setMajor(string in_major)	{ major = in_major; }

	string getName()  const	{ return name;	}
	int    getAge()   const	{ return age;	}
	float  getGrade() const	{ return grade;	}
	string getMajor() const	{ return major;	}

	Student() = delete;
	Student(string in_name, int in_age, float in_grade, string in_major)
	{
		setName(in_name);
		setAge(in_age);
		setGrade(in_grade);
		setMajor(in_major);
	}

	void printDetails() const
	{
		cout << "Name:  " << getName() << "\n";
		cout << "Age:   " << getAge() << "\n";
		cout << "Grade: " << getGrade() << "\n";
		cout << "Major: " << getMajor() << "\n";
	}
};

int main()
{
	int* request;
	request = &particularVariable;
	cout << "\n=== DEFAULT VALUE ===\n";
	cout << "Memory location of `particularVariable`: " << request << "\n";
	cout << "Data stored in `particularVariable`:     " << *request << "\n";

	particularVariable = (particularVariable * 28) + 4;
	cout << "\n=== MODIFIED VALUE ===\n";
	cout << "Memory location of `particularVariable`: " << request << "\n";
	cout << "Data stored in `particularVariable`:     " << *request << "\n";

	cout << endl; // spacer

	Student* particularStudent = new Student{ "Jared", 19, 88.5534, "English" };
	cout << "Details of `particularStudent`:\n";
	particularStudent->printDetails();

	return 0; // finish! [EXIT PRG]
}