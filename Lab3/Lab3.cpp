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
	Employee e("Tatyasha", "Myx", 19);
	cout << e << endl;

	e.changeDepartment("No");
	e.setposition("senior");
	e.setage(23);
	cout << e << endl;

	Employee e1("Borechka", "Cherkas", 19, ".net", "senior", 5, 99999);
	cout << e1 << endl;

	e = e1;
	cout << e << endl;

	system("pause");
    return 0;
}

