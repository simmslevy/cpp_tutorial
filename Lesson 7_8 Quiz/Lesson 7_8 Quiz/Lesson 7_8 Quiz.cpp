// Lesson 7_8 Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef int(*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char op;
	arithmeticFcn fcn;
};





int getInteger()
{
	std::cout << "Please enter an integer: ";
	int number;
	std::cin >> number;
	return number;
}

char getOperator()
{
	char op;
	do
	{
		std::cout << "Please enter an arithmetic operator (+, -, *, /): ";
		std::cin >> op;
	} 
	while (op != '+' && op != '-' && op != '*' && op != '/');
	return op;
}


int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

static arithmeticStruct arithmeticArray[] = {
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};

arithmeticFcn getArithmeticFunction(char op)
{
	// Method 1
	/*switch (op)
	{
		case '+':	return add;
		case '-':	return subtract;
		case '*':	return multiply;
		case '/':	return divide;
	}*/

	// Method 2
	for (const auto element : arithmeticArray)
	{
		if (element.op == op)
			return element.fcn;
	}
}


int main()
{
	int x(getInteger());
	char op(getOperator());
	int y(getInteger());

	// Method 1
	arithmeticFcn fcn = getArithmeticFunction(op);
	std::cout << fcn(x, y) << std::endl;



	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}

