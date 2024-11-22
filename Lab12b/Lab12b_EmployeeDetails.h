//
// Written by TheAidenS2014
// Last modified 11/11/2024
// Header file for Lab12b
//

#pragma once
#include <iostream>

class Employee
{
	int employeeID;

public:
	Employee() = delete;
	Employee(int in_id)
	{
		employeeID = in_id;
	}

	/*void setEmployeeID(int in_id)
	{
		employeeID = in_id;
	}*/
	int getEmployeeID() const
	{
		return employeeID;
	}
	
	virtual float calculatePay() const = 0;
	virtual void print() const = 0;
};

class FullTime : public Employee
{
	float bonus;
	float salary;

public:
	FullTime() = delete;
	FullTime(int in_id, float in_bonus, float in_salary) : Employee(in_id)
	{
		bonus = in_bonus;
		salary = in_salary;
	}

	float calculatePay() const override
	{
		return salary + bonus;
	}
	void print() const override
	{
		std::cout << "Employee ID: " << getEmployeeID() << "\n";
		std::cout << "Full Time Employee\n";
		std::cout << "- Salary: " << salary << "\n";
		std::cout << "- Bonus:  " << bonus << "\n";
		std::cout << "- Pay:    $" << calculatePay() << "\n";
	}
};

class PartTime : public Employee
{
	int hours;
	float rate;

public:
	PartTime() = delete;
	PartTime(int in_id, int in_hours, float in_rate) : Employee(in_id)
	{
		hours = in_hours;
		rate = in_rate;
	}

	float calculatePay() const override
	{
		return static_cast<float>(hours) * rate;
	}
	void print() const override
	{
		std::cout << "Employee ID: " << getEmployeeID() << "\n";
		std::cout << "Part Time Employee\n";
		std::cout << "- Hours: " << hours << "\n";
		std::cout << "- Rate:  " << rate << "\n";
		std::cout << "- Pay:   $" << calculatePay() << "\n";
	}
};