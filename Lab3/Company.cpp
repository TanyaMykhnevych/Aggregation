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


//��������
void Company::setCompany(const char * name, const char * country, const int creationYear, const int empNumber, const Employee * employees)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->country = new char[strlen(country) + 1];
	strcpy_s(this->country, strlen(country) + 1, country);

	this->creationYear = creationYear;
	this->empNumber = empNumber;

	//�������, ��� � ������
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

//��������
void Company::setemployees(const Employee * employees)
{
}

//��������
bool Company::checkIfContainsEmployee(Employee & e)
{
	return false;
}

//��������
Employee & Company::findEmployee(int id)
{
	// TODO: insert return statement here
}

//��������
void Company::addEmployee(Employee & e)
{
	empNumber++;
}

//��������
void Company::removeEmployee(int id)
{
	empNumber--;
}

//��������
void Company::sortEmpsBySurname()
{
}

//��������
void Company::sortEmpsBySalary()
{
}

//��������
const Company & Company::operator=(const Company &)
{
	// TODO: insert return statement here
}

//��������
bool Company::operator==(const Company& c) const
{
	return (strcmp(name, c.name) == 0)
		&& (strcmp(country, c.country) == 0)
		&& creationYear == c.creationYear
		&& empNumber == c.empNumber;

	//� ��� �� ���������� ����������� ������ ���������� &&....
		
}

//��������
bool Company::operator!=(const Company& c) const
{
	return !((strcmp(name, c.name) == 0)
		&& (strcmp(country, c.country) == 0)
		&& creationYear == c.creationYear
		&& empNumber == c.empNumber);

	//� ��� �� ���������� ����������� ������ ���������� &&....
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

//��������
ostream & operator<<(ostream & os, Company & c)
{
	cout << "Name: " << c.getname() << "\n"
		<< "Country: " << c.getcountry() << "\n"
		<< "CreationYear: " << c.getcreationYear() << "\n"
		<< "EmployeesNumber: " << c.getempNumber() << endl;

	//��� ��� ���� ������� ������ ����������, ��������

	return os;
}

const Employee& Company::operator[](int i)  const   // rvalue
{						
	if ((i >= 0) && (i<empNumber))
		return employees[i];
	else	
		exit(-1);
}

Employee& Company::operator[](int i) { 			// lvalue		
	if ((i >= 0) && (i<empNumber))
		return employees[i];
	else	
		exit(-1);
}
