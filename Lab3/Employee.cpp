#include "stdafx.h"
#include "Employee.h"


Employee::Employee()
{
}

Employee::Employee(const char * name, const char * surname, const int age)
{
}

Employee::Employee(const char * name, const char * surname, const int age,
	const char * department, const char * position, const int yearsWorked, const double salary)
{
}

Employee::Employee(const Employee &)
{
}


Employee::~Employee()
{
}

const char * Employee::getname() const
{
	return nullptr;
}

const char * Employee::getsurname() const
{
	return nullptr;
}

const int Employee::getage() const
{
	return 0;
}

const char * Employee::getdepartment() const
{
	return nullptr;
}

const char * Employee::getposition() const
{
	return nullptr;
}

const int Employee::getyearsWorked() const
{
	return 0;
}

const double Employee::getsalary() const
{
	return 0.0;
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
