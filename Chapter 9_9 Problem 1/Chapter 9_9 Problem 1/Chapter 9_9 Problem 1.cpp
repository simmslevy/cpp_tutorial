// Chapter 9_9 Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


class Mystring
{
	std::string m_phrase;
public:
	Mystring(std::string phrase) : m_phrase {phrase}{}

	std::string operator() (int index, int length) 
	{ 
		std::string substring;
		for (int count = 0; count < length; ++count)
			substring += m_phrase[index + count];
		return substring; 
	}
};

int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 5); // start at index 7 and return 5 characters

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

