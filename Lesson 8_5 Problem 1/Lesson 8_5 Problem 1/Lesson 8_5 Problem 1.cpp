// Lesson 8_5 Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<string>

class Ball
{
	std::string m_color;
	double m_radius;
public:
	/*Ball()
	{
		m_color = "black";
		m_radius = 10.0;
	}

	Ball(std::string color)
	{
		m_color = color;
		m_radius = 10.0;
	}*/

	Ball(std::string color = "black", double radius = 10.0)
	{
		m_color = color;
		m_radius = radius;
	}

	Ball(double radius)
	{
		m_radius = radius;
		m_color = "black";
	}

	void print()
	{
		std::cout << "color: " << m_color << ", radius: " << m_radius << std::endl;
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

