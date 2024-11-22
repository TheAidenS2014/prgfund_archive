//
// Written by TheAidenS2014
// Last modified 10/30/2024
// Header file for Lab11d
//

#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

//
// campus
// -> class
//   -> student
//   -> teacher
//     -> person
//

struct Person
{
	string name = "TBD";
	int age = 0;
};

class Student : public Person
{
	float grade = 0;
	string major = "TBD";

public:
	void setGrade(float);
	void setMajor(string);
	
	float getGrade();
	string getMajor();

	Student();
	Student(string, int, float, string);
};
class Teacher : public Person
{
	int seniority = 0;
	string subject = "TBD";

public:
	void setSeniority(int);
	void setSubject(string);

	int getSeniority();
	string getSubject();

	Teacher();
	Teacher(string, int, int, string);
};

class SchoolClass
{
	vector<Student> registeredStudent;
	Teacher subjectTeacher;
	string subject = "TBD";

public:
	void storeStudent(const Student&);
	void setTeacher(const Teacher&);
	void setSubject(string);

	Student getStudent(int);
	Teacher getTeacher();
	string getSubject();

	SchoolClass();

	int getSize();
	void print();
};
class Campus
{
	vector<SchoolClass> officialClass;

public:
	void storeClass(const SchoolClass&);

	SchoolClass getClass(int);

	Campus();

	void print();
};

//
// NOTE: `SchoolClass` and `Campus` don't have
//		 default constructors with arguments due
//		 to their use of arrays.
//