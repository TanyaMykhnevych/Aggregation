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
	Employee e("Tatyasha", "Myx", 19, ".net", "senior", 2, 100000);
	cout << e << endl;

	system("pause");
    return 0;
}

