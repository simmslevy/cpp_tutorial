// Lesson 7_11 Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int factorial(int number)
{
	if (number <= 0)
		return 1;
	else if (number == 1)
		return 1;
	else
		return number * factorial(number - 1);
}

int sumDigit(int number)
{
	int onesPlace;
	if (number <= 0)
		return 0;
	else
	{
		onesPlace = number % 10;
		return onesPlace + sumDigit(number / 10);
	}

}

void printBinary(unsigned int x)
{
	// Termination case
	if (x > 1)
		printBinary(x / 2);

	// Print out the remainders (in reverse order)
	std::cout << x % 2;
}

int main()
{
 //   // Problem 1
	//std::cout << "Please enter an integer: ";
	//int number;
	//std::cin >> number;
	//std::cout << factorial(number) << std::endl;

	//// Problem 2
	//std::cout << "Please enter an integer: ";
	//int number;
	//std::cin >> number;
	//std::cout << sumDigit(number) << std::endl;

	// Problem 3

	std::cout << "Please enter an integer: ";
	int number;
	std::cin >> number;
	unsigned int nuh = number;
	std::cout << nuh << std::endl;
	printBinary(number);

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

