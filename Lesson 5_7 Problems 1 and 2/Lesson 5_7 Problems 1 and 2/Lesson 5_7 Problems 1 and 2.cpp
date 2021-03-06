// Lesson 5_7 Problems 1 and 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void printNum(int top)
{
	int count = 0;
	for (; count <= top; )
	{
		std::cout << count << " ";
		++count;
	}
}

int sumTo(int target)
{
	int count = 1;
	int sum = 0;
	for (; count <= target; )
	{
		sum += count;
		++count;
	}
	return sum;
}

int main()
{
	printNum(20);
	int sum = sumTo(5);
	std::cout << std::endl << sum;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}

