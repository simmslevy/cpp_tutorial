// Lesson 5_5 Problem 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// Loop between 1 and 5
int main()
{
	int outer = 1;
	while (outer <= 5)
	{
		// loop between 1 and outer
		int prespace = 1;
		while (prespace <= (5 - outer))
		{
			std::cout << "  ";
			++prespace;
		}
		
		int inner = outer;
		
		while (inner > 0)
			std::cout << inner-- << " ";

		// print a newline at the end of each row
		std::cout << "\n";
		++outer;
	}
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}