#include "Employee.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;


#pragma once
class Company
{
private:
	char *name;
	char *country;
	int creationYear;
	int empNumber;
	Employee* employees;

	void setCompany(const char* name, const char* country, const int creationYear, const int empNumber, const Employee* employees);

public:
	Company();
	Company(const char* name, const char* country, const int creationYear);
	Company(const char* name, const char* country, const int creationYear, const int empNumber, const Employee* employees);
	Company(const Company& c);
	~Company();

	const char* getname() const;
	const char* getcountry() const;
	const int getcreationYear() const;
	const int getempNumber() const;
	const Employee* getemployees() const;

	void setname(const char* name); //setter
	void setcountry(const char* country);
	void setcreationYear(const int creationYear);
	void setemployees(const Employee* employees);

	bool checkIfContainsEmployee(Employee& e);
	Employee& getEmployee(int id);
	void addEmployee(Employee& e);
	void removeEmployee(int id);
	void sortEmpsBySurname();
	void sortEmpsBySalary();


	const Company& operator=(const Company&);

	bool operator==(const Company&) const;
	bool operator!=(const Company&) const;

	bool operator<(const Company&) const;
	bool operator<=(const Company&) const;
	bool operator>(const Company&) const;
	bool operator>=(const Company&) const;

	friend ostream& operator<<(ostream& os, Company& ñ);

	const Employee& Company::operator[](int i)  const;
	Employee& Company::operator[](int i);
};

