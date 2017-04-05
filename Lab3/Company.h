#include "Employee.h"

#pragma once
class Company
{
private:
	char *name;
	char *country;
	int creationYear;
	int empNumber;
	Employee* employees;

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

	void addEnployee(Employee& e);
	void editEmployee(int id, Employee& e);
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

	const char& operator[](int)const;   // right value
	char& operator[](int);// left value


};

