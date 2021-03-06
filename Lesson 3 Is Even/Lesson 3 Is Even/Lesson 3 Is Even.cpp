// Lesson 3 Is Even.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int enterNumber()
{
	std::cout << "Enter the integer: ";
	int number;
	std::cin >> number;
	return number;
}

bool isEven(int x)
{
	return ((x % 2) == 0);
}

int main()
{
	int x(enterNumber());
	bool even(isEven(x));
	if (even)
		std::cout << "Even!" << std::endl;
	else
		std::cout << "Odd!" << std::endl;
    return 0;
}

