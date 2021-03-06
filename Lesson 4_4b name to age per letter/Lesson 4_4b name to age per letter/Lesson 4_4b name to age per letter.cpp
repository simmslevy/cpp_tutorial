// Lesson 4_4b name to age per letter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


int main()
{
	std::cout << "Enter your full name: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Enter your age: ";
	float age;
	std::cin >> age;
	std::cout << "You've lived " << age / name.length() << " years for each letter in your name.";
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

