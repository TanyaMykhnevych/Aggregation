// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Employee.h"
#include "Company.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::ostream;
using std::istream;


int main()
{
	/*Employee e("Tatyasha", "Myx", 19);
	cout << e << endl;

	e.changeDepartment("No");
	e.setposition("senior");
	e.setage(23);
	cout << e << endl;

	Employee e1("Borechka", "Cherkas", 19, ".net", "senior", 5, 99999);
	cout << e1 << endl;

	e.increaseSalary(888845);

	cout << (e == e1) << endl;
	cout << (e != e1) << endl;
	cout << (e > e1) << endl;
	cout << (e < e1) << endl;

	e = e1;
	cout << e << endl;*/

	Employee em[4] = {
		Employee("Vasya", "Ivanov", 25, ".net", "senior", 5, 99999),
		Employee("Nata", "Petrova", 25, ".net", "middle", 5, 1020),
		Employee("Lena", "Sidorova", 40, "java", "senior", 20, 46512),
		Employee("John", "Smith", 18, "php", "junior", 1, 978)
	};
	
	

	Company c("DataArt", "USA", 2003, 4, em);

	/*cout << c << endl;

	Company a("Epam", "Ukraine", 2005);
	a.setemployees(4, em);


	cout << a << endl;

	bool b = a.checkIfContainsEmployee(Employee("Vasya", "Ivanov", 25, ".net", "senior", 5, 99999));

	cout << b << endl;

	a = c;

	cout << a << endl;

	cout << (a == c) << endl;

	cout << a[2] << endl;

	a[3] = a[2];

	cout << a[3];*/

	Employee emp("Ann", "Black", 35, "java", "middle", 10, 98462);

	c.addEmployee(emp);

	cout << c << endl;

	system("pause");
    return 0;
}

