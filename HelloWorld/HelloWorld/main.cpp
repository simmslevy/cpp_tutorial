#include "stdafx.h"
#include <iostream>
//#include "Header.h"

//int readNumber();

//int writeNumber(int x);

int main()
{
	std::cout << "Enter a double value: ";
	double x;
	double y;
	std::cin >> x;
	std::cout << "Enter a double value: ";
	std::cin >> y;
	std::cout << "Enter one of the following: +, -, *, or /:";
	char z;
	std::cin >> z;
	//std::cout << x << " " << y << " " << z;
	double plus(x + y);
	double minus(x - y);
	double multi(x*y);
	double divide(x / y);
	if (z == '+')
		std::cout << x << " " << z << " " << y << " = " << plus;
	if (z == '-')
		std::cout << x << " " << z << " " << y << " = " << minus;
	if (z == '*')
		std::cout << x << " " << z << " " << y << " = " << multi;
	if (z == '/')
		std::cout << x << " " << z << " " << y << " = " << divide;
	
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}