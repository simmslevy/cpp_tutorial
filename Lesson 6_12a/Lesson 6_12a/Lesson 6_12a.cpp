// Lesson 6_12a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>



int main()
{
	std::string array[] = { "Alex", "Betty", "Caroline", "Dave","Emily", "Fred", "Greg", "Holly" };
	
	std::cout << "Enter a name: ";
	std::string nameCheck;
	std::getline(std::cin, nameCheck);

	bool nameFound(false);

	for (const auto name : array)
		if (name == nameCheck)
		{
			nameFound = true;
			break;
		}

	if (nameFound)
		std::cout << nameCheck << " was found." << std::endl;
	else
		std::cout << nameCheck << " was not found." << std::endl;
		
	

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

