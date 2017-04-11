#include <cstring>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;

#pragma once
class Employee
{
private:
	int id;
	char* name;
	char* surname;
	unsigned int age;
	char* department;
	char* position;
	unsigned int yearsWorked;
	double salary;
	static int maxId;

	void setEmployee(const char* name,
	                 const char* surname,
	                 const int age,
	                 const char* department,
	                 const char* position,
	                 const int yearsWorked,
	                 const double salary);

public:
	Employee();
	Employee(const Employee&);	//copy constr
	Employee(const char* name, const char* surname, const int age);
	Employee(const char* name,
	         const char* surname,
	         const int age,
	         const char* department,
	         const char* position,
	         const int yearsWorked,
	         const double salary);

	~Employee();

	int getId() const;

	const char* getName() const; // getter
	void setName(const char* name); //setter

	const char* getSurname() const; // getter
	void setSurname(const char* surname); //setter

	int getAge() const; // getter
	void setAge(const int age); //setter

	const char* getDepartment() const; // getter
	void setDepartment(const char* department); //setter

	const char* getPosition() const; // getter
	void setPosition(const char* position); //setter

	int getYearsWorked() const; // getter
	void setYearsWorked(const int yearsWorked); //setter

	double getSalary() const; // getter
	void setSalary(const double salary); //setter

	void increaseSalary(const double difference);
	void decreaseSalary(const double difference);

	void changeDepartment(const char* newDepartment);

	void changePosition(const char* newPosition);

	const Employee& operator=(const Employee&);

	bool operator==(const Employee&) const;
	bool operator!=(const Employee&) const;

	bool operator<(const Employee&) const;
	bool operator<=(const Employee&) const;
	bool operator>(const Employee&) const;
	bool operator>=(const Employee&) const;

	friend ostream& operator<<(ostream& os, Employee& e);
};
