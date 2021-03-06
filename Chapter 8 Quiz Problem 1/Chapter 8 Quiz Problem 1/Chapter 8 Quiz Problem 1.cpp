// Chapter 8 Quiz Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>



class Point2d
{
	double m_x;
	double m_y;

public:
	Point2d(double x = 0.0, double y = 0.0) : m_x{ x }, m_y{ y } {}

	void print()
	{
		std::cout << "Point2d(" << m_x << ", " << m_y << ");" << std::endl;
	}

	/*double distanceTo(Point2d p2)
	{
		return sqrt( (m_x - p2.m_x)*(m_x - p2.m_x) + (m_y - p2.m_y)*(m_y - p2.m_y));
	}*/
	friend double distanceFrom(Point2d p1, Point2d p2);
};

double distanceFrom(Point2d p1, Point2d p2)
{
	return sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
}

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';
	
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

