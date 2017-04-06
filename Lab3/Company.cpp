#include "stdafx.h"
#include "Company.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;



void Company::setCompany(const char * name, const char * country, const int creationYear, const int empNumber, const Employee * employees)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->country = new char[strlen(country) + 1];
	strcpy_s(this->country, strlen(country) + 1, country);

	this->creationYear = creationYear;
	this->empNumber = empNumber;

	//сделать, как в лекции
	//this->employees = 
}

Company::Company()
{
	name = "";
	country = "";
	creationYear = empNumber = 0;
	employees = new Employee[0];
}

Company::Company(const char * name, const char * country, const int creationYear)
{
	setCompany(name, country, creationYear, 0, NULL);
}

Company::Company(const char * name, const char * country, const int creationYear, const int empNumber, const Employee * employees)
{
	setCompany(name, country, creationYear, creationYear, employees);
}


Company::Company(const Company& c)
{
	setCompany(c.name, c.country, c.creationYear, c.creationYear, c.employees);
}

Company::~Company()
{
	delete[] name;
	delete[] country;
	delete[] employees;
}

const char * Company::getname() const
{
	return name;
}

const char * Company::getcountry() const
{
	return country;
}

const int Company::getcreationYear() const
{
	return creationYear;
}

const int Company::getempNumber() const
{
	return empNumber;
}

const Employee * Company::getemployees() const
{
	return employees;
}

void Company::setname(const char * name)
{
}

void Company::setcountry(const char * country)
{
}

void Company::setcreationYear(const int creationYear)
{
	
}

void Company::setemployees(const Employee * employees)
{
}

void Company::addEnployee(Employee & e)
{
}

void Company::editEmployee(int id, Employee & e)
{
}

void Company::removeEmployee(int id)
{
}

void Company::sortEmpsBySurname()
{
}

void Company::sortEmpsBySalary()
{
}

const Company & Company::operator=(const Company &)
{
	// TODO: insert return statement here
}

bool Company::operator==(const Company& c) const
{
	return false;
}

bool Company::operator!=(const Company& c) const
{
	return false;
}

bool Company::operator<(const Company& c) const
{
	return empNumber < c.empNumber;
}

bool Company::operator<=(const Company& c) const
{
	return empNumber <= c.empNumber;
}

bool Company::operator>(const Company& c) const
{
	return empNumber > c.empNumber;
}

bool Company::operator>=(const Company& c) const
{
	return empNumber >= c.empNumber;
}

ostream & operator<<(ostream & os, Company & c)
{
	cout << "Name: " << c.getname() << "\n"
		<< "Country: " << c.getcountry() << "\n"
		<< "CreationYear: " << c.getcreationYear() << "\n"
		<< "EmployeesNumber: " << c.getempNumber() << endl;

	//тут еще надо вывести список работников, наверное

	return os;
}
