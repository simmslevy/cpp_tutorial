// Lesson 8_3 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Point3d
{
	double m_x;
	double m_y;
	double m_z;
public:
	void setValues(int x, int y, int z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	
	void print()
	{
		std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
	}

	bool isEqual(Point3d point)
	{
		return ((m_x == point.m_x) && (m_y == point.m_y) && (m_z == point.m_z));
	}
};

int main()
{
	Point3d point1;
	point1.setValues(1.0, 2.0, 3.0);

	Point3d point2;
	point2.setValues(1.0, 2.0, 3.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Point3d point3;
	point3.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

