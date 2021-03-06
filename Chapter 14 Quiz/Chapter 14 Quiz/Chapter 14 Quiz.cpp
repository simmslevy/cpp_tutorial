// Chapter 14 Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdexcept>

class Fraction
{
	int m_numerator;
	int m_denominator;
public:
	Fraction(int num, int den) : m_numerator{ num }, m_denominator{ den } 
	{
		if (den == 0)
			throw std::runtime_error("Error");
	}
	


	void print()
	{
		std::cout << m_numerator << '/' << m_denominator << std::endl; 
	}
};



int main()
{
	std::cout << "Enter the numerator: ";
	int num;
	std::cin >> num;
	std::cout << "Enter the denominator: ";
	int den;
	std::cin >> den;
	try
	{
		Fraction f(num, den);
		f.print();
	}
	catch (std::exception)
	{
		std::cerr << "Your fraction has an invalid denominator. \n";
	}
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

