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

void Employee::setEmployee(const char * name, const char * surname, const int age, const char * department, const char * position, const int yearsWorked, const double salary)
{	
	this->id = ++maxId;

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
	id = ++maxId;
	age = yearsWorked = 0;
	salary = 0;
	name = "";
	surname = "";		
	department = "";
	position = "";
}

Employee::Employee(const char * name, const char * surname, const int age)
{
	setEmployee(name, surname, age, "", "", 0, 0);
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
	maxId--;
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

void Employee::setname(const char * nam)
{
	char* temp;
	temp = new char[strlen(nam) + 1];
	strcpy_s(temp, strlen(nam) + 1, nam);
	delete[] name;
	name = temp;
}

void Employee::setsurname(const char * surnam)
{
	char* temp;
	temp = new char[strlen(surnam) + 1];
	strcpy_s(temp, strlen(surnam) + 1, surnam);
	delete[] surname;
	surname = temp;
}

void Employee::setage(const int a)
{
	if (a > 18 && a < 90) {
		this->age = a;
	}
	else {
		cout << "Invalid value age/n" << endl;
	}
}

void Employee::setdepartment(const char * depart)
{
	char* temp;
	temp = new char[strlen(depart) + 1];
	strcpy_s(temp, strlen(depart) + 1, depart);
	delete[] department;
	department = temp;
}

void Employee::setposition(const char * pos)
{
	char* temp;
	temp = new char[strlen(pos) + 1];
	strcpy_s(temp, strlen(pos) + 1, pos);
	delete[] position;
	position = temp;
}

void Employee::setyearsWorked(const int years)
{
	if (years > 0 && years < 80) {
		this->yearsWorked = years;
	}
	else {
		cout << "Invalid value yearsWorked\n" << endl;
	}
}

void Employee::setsalary(const double sal)
{
	if (sal > 0) {
		this->salary = sal;
	}
	else {
		cout << "Invalid value salary\n" << endl;
	}
}

void Employee::increaseSalary(double difference)
{
	salary += difference;
}

void Employee::decreaseSalary(double difference)
{
	if (difference > salary) {
		salary = 0;
	}
	salary -= difference;
}

void Employee::changeDepartment(char * newDepartment)
{
	char* temp;
	temp = new char[strlen(newDepartment) + 1];
	strcpy_s(temp, strlen(newDepartment) + 1, newDepartment);
	delete[] department;
	department = temp;
}

void Employee::changePosition(char * newPosition)
{
	char* temp;
	temp = new char[strlen(newPosition) + 1];
	strcpy_s(temp, strlen(newPosition) + 1, newPosition);
	delete[] position;
	position = temp;
}

const Employee & Employee::operator=(const Employee& e)
{
	char* nam; char* sur;
	char* dep; char* pos;
	if (this != &e) {
		nam = new char[strlen(e.name) + 1];
		sur = new char[strlen(e.surname) + 1];
		dep = new char[strlen(e.department) + 1];
		pos = new char[strlen(e.position) + 1];

		strcpy_s(nam, strlen(e.name) + 1, e.name);
		strcpy_s(sur, strlen(e.surname) + 1, e.surname);
		strcpy_s(dep, strlen(e.department) + 1, e.department);
		strcpy_s(pos, strlen(e.position) + 1, e.position);

		delete[] name;
		delete[] surname;
		delete[] department;
		delete[] position;

		name = nam;
		surname = sur;
		age = e.age;
		department = dep;
		position = pos;
		yearsWorked = e.yearsWorked;
		salary = e.salary;

		return *this;
	}
	else cout << "Avoid copying to itself" << endl;
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
	return !((strcmp(name, e.name) == 0)
		&& (strcmp(surname, e.surname) == 0)
		&& (strcmp(department, e.department) == 0)
		&& (strcmp(position, e.position) == 0)
		&& (age == e.age)
		&& (yearsWorked == e.yearsWorked)
		&& (salary == e.salary));
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

ostream & operator<<(ostream & os, Employee & e)
{	
	cout << "Id: " << e.id << "\n"
		<< "Name: " << e.getname() << "\n"		
		<< "Surname: " << e.getsurname() << "\n"
		<< "Age: "<< e.getage() << "\n"
		<< "Position: " << e.getposition() << "\n"
		<< "Department: "<< e.getdepartment() << "\n"
		<< "YearsWorked: " << e.getyearsWorked() << "\n"
		<< "Salary: " << e.getsalary() << endl;

	return os;
}
