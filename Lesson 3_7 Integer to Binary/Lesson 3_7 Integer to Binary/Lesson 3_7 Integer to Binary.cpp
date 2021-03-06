// Lesson 3_7 Integer to Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int binDown(int number, int pow2)
{
	if (number >= pow2)
		std::cout << 1;
	else
		std::cout << 0;
	if (number >= pow2)
		number = number - pow2;
	return number;
}

int main()
{
	std::cout << "Input 0 to 255: ";
	int inputtednumber;
	std::cin >> inputtednumber;
	std::cout << "Your binary value is: ";
	inputtednumber = binDown(inputtednumber, 128);
	inputtednumber = binDown(inputtednumber, 64);
	inputtednumber = binDown(inputtednumber, 32);
	inputtednumber = binDown(inputtednumber, 16);
	std::cout << " ";
	inputtednumber = binDown(inputtednumber, 8);
	inputtednumber = binDown(inputtednumber, 4);
	inputtednumber = binDown(inputtednumber, 2);
	inputtednumber = binDown(inputtednumber, 1);
	std::cout << std::endl;
	return 0;
}

