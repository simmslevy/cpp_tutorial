// Lesson 4_1 NumberSwitcher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getNum(bool big)
{
	if (big)
		std::cout << "Enter a larger integer: ";
	else
		std::cout << "Enter an integer: ";
	int num;
	std::cin >> num;
	return num;
}

int main()
{
	int smol = getNum(false);
	int big = getNum(true);
	if (smol > big)
	{
		std::cout << "Swapping the values" << std::endl;
		int tempsmol = big;
		big = smol;
		smol = tempsmol;
	}
	std::cout << "The smaller value is " << smol << std::endl;
	std::cout << "The bigger value is " << big << std::endl;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}

