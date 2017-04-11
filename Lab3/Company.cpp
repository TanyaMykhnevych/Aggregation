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


	this->employees = new Employee[empNumber];
	for (int i = 0; i < empNumber; i++) {
		this->employees[i] = employees[i];
	}
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
	setCompany(name, country, creationYear, empNumber, employees);
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

void Company::setname(const char * nam)
{
	char* temp;
	temp = new char[strlen(nam) + 1];
	strcpy_s(temp, strlen(nam) + 1, nam);
	delete[] name;
	name = temp;
}

void Company::setcountry(const char * countr)
{
	char* temp;
	temp = new char[strlen(countr) + 1];
	strcpy_s(temp, strlen(countr) + 1, countr);
	delete[] country;
	country = temp;
}

void Company::setcreationYear(const int year)
{
	if (year > 1700 && year < 2017) {
		this->creationYear = year;
	}
	else {
		cout << "Invalid value creationYear\n" << endl;
	}
}


void Company::setemployees(const int empsNum, const Employee * employees)
{
	empNumber = empsNum;
	this->employees = new Employee[empNumber];
	for (int i = 0; i < empNumber; i++) {
		this->employees[i] = employees[i];
	}
}


bool Company::checkIfContainsEmployee(Employee & e)
{
	for (int i = 0; i < empNumber; i++) {
		if (employees[i] == e)
			return true;
	}
	return false;
}


Employee & Company::getEmployee(int id)
{
	for (int i = 0; i < empNumber; i++) {
		if (employees[i].getid() == id)
			return employees[i];
	}
	return Employee();
}


bool Company::addEmployee(Employee & e)
{
	bool added = false;
	Employee *newArray = new Employee[++empNumber];

	for (int i = 0; i < empNumber - 1; i++)
	{		
		newArray[i] = employees[i];
	}

	newArray[empNumber - 1] = e;
	added = true;

	if (!added) {
		return false;
	}
	delete[] employees;
	employees = newArray;
	return true;
}



bool Company::removeEmployee(const int index)
{		
	bool deleted = false;
	Employee *newArray = new Employee[empNumber - 1];

	for (int i = 0; i < empNumber - 1; i++)
	{
		if (i == index) {
			deleted = true;
		}
		newArray[i] = deleted ? employees[i + 1] : employees[i];
	}
	if (!deleted) {
		return false;
	}
	delete[] employees;
	employees = newArray;
	this->empNumber--;
	return true;
}

//для Боречки)
void Company::sortEmpsBySurname()
{
}

//для Боречки)
void Company::sortEmpsBySalary()
{
}


const Company & Company::operator=(const Company &c)
{
	char* nam; char* countr;
	Employee *e;
	if (this != &c) {
		nam = new char[strlen(c.name) + 1];
		countr = new char[strlen(c.country) + 1];

		strcpy_s(nam, strlen(c.name) + 1, c.name);
		strcpy_s(countr, strlen(c.country) + 1, c.country);

		e = new Employee[c.empNumber];
		for (int i = 0; i < empNumber; i++) {
			e[i] = c.employees[i];
		}

		delete[] name;
		delete[] country;
		delete[] employees;

		setCompany(nam, countr, c.creationYear, c.empNumber, e);

		return *this;
	}
	else cout << "Avoid copying to itself" << endl;
	return *this;
}


bool Company::operator==(const Company& c) const
{
	bool firstPart = (strcmp(name, c.name) == 0)
		&& (strcmp(country, c.country) == 0)
		&& creationYear == c.creationYear
		&& empNumber == c.empNumber;

	if (!firstPart)
		return false;

	bool secondPart = false;

	for (int i = 0; i < empNumber; i++) {
		if (employees[i] == c.employees[i]) {
			secondPart = true;
		}
		else {
			return false;
		}
	}

	if (firstPart&&secondPart)
		return true;
	return false;
}


bool Company::operator!=(const Company& c) const
{
	bool firstPart = !((strcmp(name, c.name) == 0)
		&& (strcmp(country, c.country) == 0)
		&& creationYear == c.creationYear
		&& empNumber == c.empNumber);

	if (!firstPart)
		return false;
	
	for (int i = 0; i < empNumber; i++) {
		if (employees[i] != c.employees[i]) {
			return true;
		}		
	}

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

	cout << "Employees:" << endl;
	for (int i = 0; i < c.empNumber; i++) {
		cout << c.employees[i] << endl;
	}

	return os;
}

const Employee& Company::operator[](int i)  const   // rvalue
{
	if ((i >= 0) && (i < empNumber))
		return employees[i];
	else
		exit(-1);
}

Employee& Company::operator[](int i) { 			// lvalue		
	if ((i >= 0) && (i < empNumber))
		return employees[i];
	else
		exit(-1);
}
