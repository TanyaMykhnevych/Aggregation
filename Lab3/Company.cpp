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


void Company::setCompany(const char* name,
                         const char* country,
                         const int creationYear,
                         const int empCount,
                         const Employee* employees)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	delete[] this->country;
	this->country = new char[strlen(country) + 1];
	strcpy_s(this->country, strlen(country) + 1, country);

	this->creationYear = creationYear;
	this->empNumber = empCount;

	delete[] this->employees;
	this->employees = new Employee[empCount];
	for (int i = 0; i < empCount; i++)
	{
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

Company::Company(const char* name,
                 const char* country,
                 const int creationYear)
{
	setCompany(name, country, creationYear, 0, nullptr);
}

Company::Company(const char* name,
                 const char* country,
                 const int creationYear,
                 const int empNumber,
                 const Employee* employees)
{
	setCompany(name, country, creationYear, empNumber, employees);
}

Company::Company(const Company& c)
{
	setCompany(c.name, c.country, c.creationYear, c.empNumber, c.employees);
}

Company::~Company()
{
	delete[] name;
	delete[] country;
	delete[] employees;
}

const char* Company::getName() const
{
	return name;
}

void Company::setName(const char* name)
{
	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char* Company::getCountry() const
{
	return country;
}

void Company::setCountry(const char* country)
{
	delete[] this->country;

	this->country = new char[strlen(country) + 1];
	strcpy_s(this->country, strlen(country) + 1, country);
}

int Company::getCreationYear() const
{
	return creationYear;
}

void Company::setCreationYear(const int year)
{
	if (year > 1700 && year <= 2017)
	{
		this->creationYear = year;
	}
	else
	{
		cout << "Invalid value creationYear\n" << endl;
	}
}

int Company::getEmployeeNumber() const
{
	return empNumber;
}

const Employee* Company::getEmployees() const
{
	return employees;
}

void Company::setEmployees(const int empsCount, const Employee* newEmps)
{
	empNumber = empsCount;

	delete[] this->employees;
	this->employees = new Employee[empNumber];

	for (int i = 0; i < empNumber; i++)
	{
		this->employees[i] = newEmps[i];
	}
}

bool Company::checkIfContainsEmployee(const Employee& e) const
{
	for (int i = 0; i < empNumber; i++)
	{
		if (employees[i] == e)
			return true;
	}

	return false;
}

bool Company::checkIfContainsEmployeeId(const int empId) const
{
	for (int i = 0; i < empNumber; i++)
	{
		if (employees[i].getId() == empId)
			return true;
	}

	return false;
}


bool Company::getEmployee(const int empId, Employee& emp) const
{
	for (int i = 0; i < empNumber; i++)
	{
		if (employees[i].getId() == empId)
		{
			emp = employees[i];
			return true;
		}
	}

	return false;
}


bool Company::addEmployee(const Employee& e)
{
	Employee* newArray = new Employee[++empNumber];

	for (int i = 0; i < empNumber - 1; i++)
	{
		newArray[i] = employees[i];
	}

	newArray[empNumber - 1] = e;

	delete[] this->employees;
	this->employees = newArray;

	return true;
}

bool Company::removeEmployeeByIndex(const int index)
{
	if (index >= empNumber || index < 0)
	{
		return false;
	}

	Employee* newArray = new Employee[empNumber - 1];

	for (int i = 0; i < empNumber - 1; i++)
	{
		newArray[i] = i >= index ? employees[i + 1] : employees[i];
	}

	delete[] employees;
	employees = newArray;
	this->empNumber--;
	return true;
}

bool Company::removeEmployeeById(const int id)
{
	bool deleted = false;
	Employee* newArray = new Employee[empNumber - 1];

	for (int i = 0; i < empNumber - 1; i++)
	{
		if (employees[i].getId() == id)
		{
			deleted = true;
		}

		newArray[i] = deleted ? employees[i + 1] : employees[i];
	}

	if (!deleted)
	{
		delete[] newArray;
		return false;
	}

	delete[] employees;
	employees = newArray;
	empNumber--;
	return true;
}

void Company::sortEmpsBySurname() const
{
	for (int i = 0; i < empNumber - 1; i++)
	{
		for (int j = i + 1; j < empNumber; j++)
		{
			int result = strcmp(employees[i].getSurname(), employees[j].getSurname());

			if (result > 0)
			{
				Employee& tempEmp = employees[i];
				employees[i] = employees[j];
				employees[j] = tempEmp;

				i = -1;
				break;
			}
		}
	}
}

void Company::sortEmpsBySalary() const
{
	for (int i = 0; i < empNumber - 1; i++)
	{
		for (int j = i + 1; j < empNumber; j++)
		{
			if (employees[i].getSalary() > employees[j].getSalary())
			{
				Employee& tempEmp = employees[i];
				employees[i] = employees[j];
				employees[j] = tempEmp;

				i = -1;
				break;
			}
		}
	}
}


const Company& Company::operator=(const Company& c)
{
	char* name;
	char* country;
	Employee* e;

	if (this != &c)
	{
		name = new char[strlen(c.name) + 1];
		country = new char[strlen(c.country) + 1];

		strcpy_s(name, strlen(c.name) + 1, c.name);
		strcpy_s(country, strlen(c.country) + 1, c.country);

		e = new Employee[c.empNumber];
		for (int i = 0; i < empNumber; i++)
		{
			e[i] = c.employees[i];
		}

		setCompany(name, country, c.creationYear, c.empNumber, e);

		delete[] name;
		delete[] country;
		delete[] e;
	}
	else
	{
		cout << "Avoid copying to itself" << endl;
	}

	return *this;
}


bool Company::operator==(const Company& c) const
{
	bool equalsWithoutEmps = strcmp(name, c.name) == 0
		&& strcmp(country, c.country) == 0
		&& creationYear == c.creationYear
		&& empNumber == c.empNumber;

	if (!equalsWithoutEmps)
		return false;

	for (int i = 0; i < empNumber; i++)
	{
		if (employees[i] != c.employees[i])
		{
			return false;
		}
	}

	return true;
}


bool Company::operator!=(const Company& c) const
{
	return !(*this == c);

	//bool equalsWithoutEmps = !(strcmp(name, c.name) == 0
	//	&& strcmp(country, c.country) == 0
	//	&& creationYear == c.creationYear
	//	&& empNumber == c.empNumber);

	//if (!equalsWithoutEmps)
	//	return false;

	//for (int i = 0; i < empNumber; i++)
	//{
	//	if (employees[i] != c.employees[i])
	//	{
	//		return true;
	//	}
	//}

	//return false;
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


ostream& operator<<(ostream& os, Company& c)
{
	os << "Name: " << c.getName() << "\n"
		<< "Country: " << c.getCountry() << "\n"
		<< "CreationYear: " << c.getCreationYear() << "\n"
		<< "EmployeesNumber: " << c.getEmployeeNumber() << endl;

	os << "Employees:" << endl;
	for (int i = 0; i < c.empNumber; i++)
	{
		os << c.employees[i] << endl;
	}

	return os;
}

const Employee& Company::operator[](int i) const // rvalue
{
	if (i >= 0 && i < empNumber)
		return employees[i];

	exit(-1);
}

Employee& Company::operator[](int i) // lvalue		
{
	if (i >= 0 && i < empNumber)
		return employees[i];
	
	exit(-1);
}
