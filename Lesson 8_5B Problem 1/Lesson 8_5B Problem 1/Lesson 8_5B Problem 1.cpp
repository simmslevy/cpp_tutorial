// Lesson 8_5B Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

class Ball
{
private:
	std::string m_color = "black";
	double m_radius = 10.0;

public:
	// Default constructor with no parameters
	Ball()
	{
	}

	// Constructor with only color parameter (radius will use default value)
	Ball(const std::string &color)
		: m_color {color}
	{
	}

	// Constructor with only radius parameter (color will use default value)
	Ball(double radius)
		: m_radius {radius}
	{
	}

	// Constructor with both color and radius parameters
	Ball(const std::string &color, double radius)
		: m_radius {radius}, m_color {color}
	{
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();


	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}