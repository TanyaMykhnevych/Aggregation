#include "stdafx.h"
#include "Company.h"


Company::Company()
{
}

Company::Company(const char * name, const char * country, const int creationYear)
{
}

Company::Company(const char * name, const char * country, const int creationYear, const int empNumber, const Employee * employees)
{
}


Company::Company(const Company & c)
{
}

Company::~Company()
{
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

bool Company::operator==(const Company &) const
{
	return false;
}

bool Company::operator!=(const Employee &) const
{
	return false;
}

bool Company::operator<(const Company &) const
{
	return false;
}

bool Company::operator<=(const Company &) const
{
	return false;
}

bool Company::operator>(const Company &) const
{
	return false;
}

bool Company::operator>=(const Company &) const
{
	return false;
}

const char & Company::operator[](int) const
{
	// TODO: insert return statement here
}

char & Company::operator[](int)
{
	// TODO: insert return statement here
}
