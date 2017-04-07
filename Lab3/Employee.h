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
	int id; // надо сделать статик, но почему-то не получается, исправить
	char* name;
	char* surname;
	unsigned int age;
	char* department;
	char* position;
	unsigned int yearsWorked;
	double salary;
	int maxId;  // надо сделать статик, но почему-то не получается, исправить

	void setEmployee(const char* name, const char* surname, const int age, const char* department,
		const char* position, const int yearsWorked, const double salary);

public:
	Employee();
	Employee(const char* name, const char* surname, const int age);
	Employee(const char* name, const char* surname, const int age, const char* department,
		const char* position, const int yearsWorked, const double salary);
	Employee(const Employee&);//copy constr
	~Employee();

	const char* getname() const;  // getter
	const char* getsurname() const;  // getter
	const int getage() const;  // getter
	const char* getdepartment() const;  // getter
	const char* getposition() const;  // getter
	const int getyearsWorked() const;  // getter
	const double getsalary() const;  // getter

	void setname(const char* name); //setter
	void setsurname(const char* surname); //setter
	void setage(const int age); //setter
	void setdepartment(const char* department); //setter
	void setposition(const char* position); //setter
	void setyearsWorked(const int yearsWorked); //setter
	void setsalary(const double salary); //setter

	void increaseSalary(double difference);
	void decreaseSalary(double difference);

	void changeDepartment(char* newDepartment);
	void changePosition(char* newPosition);

	const Employee& operator=(const Employee&);

	bool operator==(const Employee&) const;
	bool operator!=(const Employee&) const;

	bool operator<(const Employee&) const;
	bool operator<=(const Employee&) const;
	bool operator>(const Employee&) const;
	bool operator>=(const Employee&) const;	

	friend ostream& operator<<(ostream& os, Employee& e);

};

