// Chapter 12 Quiz Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

class Shape
{

public:
	
	virtual std::ostream& print(std::ostream &out) const = 0;

	friend std::ostream& operator<< (std::ostream &out, const Shape &p)
	{
		return p.print(out);
	}

	virtual ~Shape() {}

};


class Point
{
private:
	int m_x = 0;
	int m_y = 0;
	int m_z = 0;

public:
	Point(int x, int y, int z)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	friend std::ostream& operator<<(std::ostream &out, const Point &p)
	{
		out << "Point(" << p.m_x << ", " << p.m_y << ", " << p.m_z << ")";
		return out;
	}
};

class Triangle : public Shape
{
	Point m_point1;
	Point m_point2;
	Point m_point3;
public:
	Triangle(Point p1, Point p2, Point p3) : m_point1{ p1 }, m_point2{ p2 }, m_point3{ p3 } {}

	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Triangle(" << m_point1 << ", " << m_point2 << ", " << m_point3 << ")";
		return out;
	}


};

class Circle : public Shape
{
	Point m_point;
	int m_radius;
public:
	Circle(Point p, int radius) : m_point{ p }, m_radius{ radius } {}
	
	virtual std::ostream& print(std::ostream &out) const
	{
		out << "Circle(" << m_point << ", radius" << m_radius << ")";
		return out;
	}

	int getRadius() { return m_radius; }
};

int getLargestRadius(std::vector<Shape*> &v)
{
	int maxRadius(0);
	for (Shape* e : v)
		if (dynamic_cast<Circle*>(e))
			if (dynamic_cast<Circle*>(e)->getRadius() > maxRadius)
				maxRadius = dynamic_cast<Circle*>(e)->getRadius();
	return maxRadius;
}

int main()
{
	std::vector<Shape*> v;
	v.push_back(new Circle(Point(1, 2, 3), 7));
	v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
	v.push_back(new Circle(Point(4, 5, 6), 3));

	for (Shape* e : v)
		std::cout << *e << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	for (Shape* e : v)
		delete[] e;

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

