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

int Employee::maxId;

void Employee::setEmployee(const char* name,
                           const char* surname,
                           const int age,
                           const char* department,
                           const char* position,
                           const int yearsWorked,
                           const double salary)
{
	if (this->id != 0)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	if (this->id != 0)
	{
		delete[] this->surname;
	}
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);

	this->age = age;

	if (this->id != 0)
	{
		delete[] this->department;
	}
	this->department = new char[strlen(department) + 1];
	strcpy_s(this->department, strlen(department) + 1, department);

	if (this->id != 0)
	{
		delete[] this->position;
	}
	this->position = new char[strlen(position) + 1];
	strcpy_s(this->position, strlen(position) + 1, position);

	this->yearsWorked = yearsWorked;

	this->salary = salary;

	if (this->id == 0)
	{
		this->id = ++maxId;
	}
}

Employee::Employee()
{
	id = 0;
	setEmployee("", "", 0, "", "", 0, 0);
}

Employee::Employee(const char* name,
                   const char* surname,
                   const int age)
{
	id = 0;
	setEmployee(name, surname, age, "", "", 0, 0);
}

Employee::Employee(const char* name,
                   const char* surname,
                   const int age,
                   const char* department,
                   const char* position,
                   const int yearsWorked,
                   const double salary)
{
	id = 0;
	setEmployee(name, surname, age, department, position, yearsWorked, salary);
}

Employee::Employee(const Employee& e)
{
	this->id = e.id;
	setEmployee(e.name, e.surname, e.age, e.department, e.position, e.yearsWorked, e.salary);
}

Employee::~Employee()
{
	delete[] name;
	delete[] surname;
	delete[] department;
	delete[] position;
}

int Employee::getId() const
{
	return id;
}

const char* Employee::getName() const
{
	return name;
}

void Employee::setName(const char* newName)
{
	delete[] this->name;

	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

const char* Employee::getSurname() const
{
	return surname;
}

void Employee::setSurname(const char* newSurname)
{
	delete[] this->surname;

	this->surname = new char[strlen(newSurname) + 1];
	strcpy_s(this->surname, strlen(newSurname) + 1, newSurname);
}

int Employee::getAge() const
{
	return age;
}

void Employee::setAge(const int newAge)
{
	if (newAge >= 18 && newAge < 90)
	{
		this->age = newAge;
	}
	else
	{
		cout << "Invalid value age/n" << endl;
	}
}

const char* Employee::getDepartment() const
{
	return department;
}

void Employee::setDepartment(const char* newDepartment)
{
	delete[] this->department;

	this->department = new char[strlen(newDepartment) + 1];
	strcpy_s(this->department, strlen(newDepartment) + 1, newDepartment);
}

const char* Employee::getPosition() const
{
	return position;
}

void Employee::setPosition(const char* newPosition)
{
	delete[] this->position;

	this->position = new char[strlen(newPosition) + 1];
	strcpy_s(this->position, strlen(newPosition) + 1, newPosition);
}

int Employee::getYearsWorked() const
{
	return yearsWorked;
}

void Employee::setYearsWorked(const int newWorkedYears)
{
	if (newWorkedYears >= 0 && newWorkedYears < 80)
	{
		this->yearsWorked = newWorkedYears;
	}
	else
	{
		cout << "Invalid value yearsWorked\n" << endl;
	}
}

double Employee::getSalary() const
{
	return salary;
}

void Employee::setSalary(const double newSalary)
{
	if (newSalary >= 0)
	{
		this->salary = newSalary;
	}
	else
	{
		cout << "Invalid value salary\n" << endl;
	}
}

void Employee::increaseSalary(double difference)
{
	if (difference > 0)
	{
		salary += difference;
	}
	else
	{
		cout << "Invalid increase difference: " << difference << "\n" << endl;
	}
}

void Employee::decreaseSalary(double difference)
{
	if (salary > difference)
	{
		salary -= difference;
	}
	else
	{
		salary = 0;
	}
}

void Employee::changeDepartment(const char* newDepartment)
{
	delete[] this->department;

	this->department = new char[strlen(newDepartment) + 1];
	strcpy_s(this->department, strlen(newDepartment) + 1, newDepartment);
}

void Employee::changePosition(const char* newPosition)
{
	delete[] this->position;

	this->position = new char[strlen(newPosition) + 1];
	strcpy_s(this->position, strlen(newPosition) + 1, newPosition);
}

const Employee& Employee::operator=(const Employee& e)
{
	char* name;
	char* surname;
	char* department;
	char* position;

	if (this != &e)
	{
		name = new char[strlen(e.name) + 1];
		surname = new char[strlen(e.surname) + 1];
		department = new char[strlen(e.department) + 1];
		position = new char[strlen(e.position) + 1];

		strcpy_s(name, strlen(e.name) + 1, e.name);
		strcpy_s(surname, strlen(e.surname) + 1, e.surname);
		strcpy_s(department, strlen(e.department) + 1, e.department);
		strcpy_s(position, strlen(e.position) + 1, e.position);

		this->id = e.id;
		setEmployee(name, surname, e.age, department, position, e.yearsWorked, e.salary);

		delete[] name;
		delete[] surname;
		delete[] department;
		delete[] position;
	}
	else
	{
		cout << "Avoid copying to itself" << endl;
	}

	return *this;
}

bool Employee::operator==(const Employee& e) const
{
	return (strcmp(name, e.name) == 0)
		&& (strcmp(surname, e.surname) == 0)
		&& (strcmp(department, e.department) == 0)
		&& (strcmp(position, e.position) == 0)
		&& (age == e.age)
		&& (yearsWorked == e.yearsWorked)
		&& (salary == e.salary);
}

bool Employee::operator!=(const Employee& e) const
{
	return !(*this == e);

	//return !((strcmp(name, e.name) == 0)
	//	&& (strcmp(surname, e.surname) == 0)
	//	&& (strcmp(department, e.department) == 0)
	//	&& (strcmp(position, e.position) == 0)
	//	&& (age == e.age)
	//	&& (yearsWorked == e.yearsWorked)
	//	&& (salary == e.salary));
}

bool Employee::operator<(const Employee& e) const
{
	return salary < e.salary;
}

bool Employee::operator<=(const Employee& e) const
{
	return salary <= e.salary;
}

bool Employee::operator>(const Employee& e) const
{
	return salary > e.salary;
}

bool Employee::operator>=(const Employee& e) const
{
	return salary >= e.salary;
}

ostream& operator<<(ostream& os, Employee& e)
{
	os << "Id: " << e.id << "\n"
		<< "Name: " << e.name << "\n"
		<< "Surname: " << e.surname << "\n"
		<< "Age: " << e.age << "\n"
		<< "Position: " << e.position << "\n"
		<< "Department: " << e.department << "\n"
		<< "YearsWorked: " << e.yearsWorked << "\n"
		<< "Salary: " << e.salary << endl;

	return os;
}
