#include "Employee.h"
#include "cstring"
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
	char* name;
	char* country;
	int creationYear;
	int empNumber;
	Employee* employees;

	void setCompany(const char* name, const char* country, const int creationYear, const int empNumber, const Employee* employees);

public:
	Company();
	Company(const char* name,
	        const char* country,
	        const int creationYear);
	Company(const char* name,
	        const char* country,
	        const int creationYear,
	        const int empNumber,
	        const Employee* employees);
	Company(const Company& c);
	~Company();

	const char* getName() const;
	void setName(const char* name);

	const char* getCountry() const;
	void setCountry(const char* country);

	int getCreationYear() const;
	void setCreationYear(const int creationYear);

	int getEmployeeNumber() const;

	const Employee* getEmployees() const;
	void setEmployees(const int empsNum, const Employee* employees);

	bool checkIfContainsEmployee(const Employee& e) const;
	bool checkIfContainsEmployeeId(const int e) const;
	bool Company::getEmployee(const int empId, Employee& emp) const;
	bool addEmployee(const Employee& e);
	bool removeEmployeeByIndex(const int index);
	bool removeEmployeeById(const int id);
	void sortEmpsBySurname() const;
	void sortEmpsBySalary() const;

	const Company& operator=(const Company&);

	bool operator==(const Company&) const;
	bool operator!=(const Company&) const;

	bool operator<(const Company&) const;
	bool operator<=(const Company&) const;
	bool operator>(const Company&) const;
	bool operator>=(const Company&) const;

	friend ostream& operator<<(ostream& os, Company& ñ);

	const Employee& Company::operator[](int i) const;
	Employee& Company::operator[](int i);
};
