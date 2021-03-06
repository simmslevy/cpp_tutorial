// Lesson 9_6 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Car
{
private:
	std::string m_make;
	std::string m_model;

public:
	Car(std::string make, std::string model)
		: m_make(make), m_model(model)
	{
	}

	friend bool operator== (const Car &c1, const Car &c2);
	friend bool operator!= (const Car &c1, const Car &c2);
	friend bool operator< (const Car &c1, const Car &c2);
	friend std::ostream& operator<< (std::ostream &out, const Car &c2);
};

bool operator== (const Car &c1, const Car &c2)
{
	return (c1.m_make == c2.m_make &&
		c1.m_model == c2.m_model);
}

bool operator!= (const Car &c1, const Car &c2)
{
	return !(c1 == c2);
}

bool operator< (const Car &c1, const Car &c2)
{
	if (c1.m_make < c2.m_make)
		return true;
	if (c1.m_make == c2.m_make)
		if (c1.m_model < c2.m_model)
			return true;
		
	return false;
}

std::ostream& operator<< (std::ostream &out, const Car &c2)
{
	out << "(" << c2.m_make << ", " << c2.m_model << ")";
	return out;

}

int main()
{
	std::vector<Car> v;
	v.push_back(Car("Toyota", "Corolla"));
	v.push_back(Car("Honda", "Accord"));
	v.push_back(Car("Toyota", "Camry"));
	v.push_back(Car("Honda", "Civic"));

	std::sort(v.begin(), v.end()); // requires an overloaded operator<

	for (auto &car : v)
		std::cout << car << '\n'; // requires an overloaded operator<<

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}
