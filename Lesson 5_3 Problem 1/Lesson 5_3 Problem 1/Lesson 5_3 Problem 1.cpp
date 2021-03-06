// Lesson 5_3 Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getNumber()
{
	std::cout << "Gimme an integer: ";
	int number;
	std::cin >> number;
	return number;
}

char getOperator()
{
	std::cout << "Give me an arithmetic operator (+, -, *, /, or %): ";
	char op;
	std::cin >> op;
	return op;
}

int performOp(int num1, int num2, char op)
{
	switch (op)
	{
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2;
		case '%':
			return num1 % num2;
	}
}

int main()
{
	int number1 = getNumber();
	int number2 = getNumber();
	char op = getOperator();
	std::cout << "Answer: " << performOp(number1, number2, op) << std::endl;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

