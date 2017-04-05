#include "stdafx.h"
#include "Employee.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;



void Employee::setEmployee(const char * name, const char * surname, const int age, const char * department, const char * position, const int yearsWorked, const double salary)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);

	this->age = age;

	this->department = new char[strlen(department) + 1];
	strcpy_s(this->department, strlen(department) + 1, department);

	this->position = new char[strlen(position) + 1];
	strcpy_s(this->position, strlen(position) + 1, position);

	this->yearsWorked = yearsWorked;
	this->salary = salary;
}

Employee::Employee()
{
	age = yearsWorked = 0;
	salary = 0;
	name = "";
	surname = "";		
	department = "";
	position = "";
}

Employee::Employee(const char * name, const char * surname, const int age)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);

	this->age = age;

}

Employee::Employee(const char * name, const char * surname, const int age,
	const char * department, const char * position, const int yearsWorked, const double salary)
{
	setEmployee(name, surname, age, department, position, yearsWorked, salary);
}

Employee::Employee(const Employee& e)
{
	setEmployee(e.name, e.surname, e.age, e.department, e.position, e.yearsWorked, e.salary);
}


Employee::~Employee()
{
	delete[] name;
	delete[] surname;
	delete[] department;
	delete[] position;
}

const char * Employee::getname() const
{
	return name;
}

const char * Employee::getsurname() const
{
	return surname;
}

const int Employee::getage() const
{
	return age;
}

const char * Employee::getdepartment() const
{
	return department;
}

const char * Employee::getposition() const
{
	return position;
}

const int Employee::getyearsWorked() const
{
	return yearsWorked;
}

const double Employee::getsalary() const
{
	return salary;
}

void Employee::setname(const char * name)
{
}

void Employee::setsurname(const char * surname)
{
}

void Employee::setage(const int age)
{
}

void Employee::setdepartment(const char * department)
{
}

void Employee::setposition(const char * position)
{
}

void Employee::setyearsWorked(const int yearsWorked)
{
}

void Employee::setsalary(const double salary)
{
}

void Employee::increaseSalary(double difference)
{
}

void Employee::decreaseSalary(double difference)
{
}

void Employee::changeDepartment(char * newDepartment)
{
}

void Employee::changePosition(char * newPosition)
{
}

const Employee & Employee::operator=(const Employee &)
{
	// TODO: insert return statement here
}

bool Employee::operator==(const Employee &) const
{
	return false;
}

bool Employee::operator!=(const Employee &) const
{
	return false;
}

bool Employee::operator<(const Employee &) const
{
	return false;
}

bool Employee::operator<=(const Employee &) const
{
	return false;
}

bool Employee::operator>(const Employee &) const
{
	return false;
}

bool Employee::operator>=(const Employee &) const
{
	return false;
}
