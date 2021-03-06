// Lesson 11_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Fruit
{
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name = "Kerby", std::string color = "Pink") : m_name{ name }, m_color{ color } {}

	std::string getName() const { return m_name; }
	std::string getColor() const { return m_color; }

};

class Apple : public Fruit
{
	double m_fiber;
public:
	Apple(std::string name = "Kerby", std::string color = "Pink", double fiber = 0) : m_fiber{ fiber }, Fruit(name,color){}

	double getFiber() const { return m_fiber; }

	friend std::ostream& operator<< (std::ostream &out, const Apple &apple);
};

class Banana : public Fruit
{
public:
	Banana(std::string name = "Kerby", std::string color = "Pink") : Fruit(name, color){}

	friend std::ostream& operator<< (std::ostream &out, const Banana &banana);
};

std::ostream& operator<< (std::ostream &out, const Apple &apple)
{
	out << "Apple (" << apple.getName() << ", " << apple.getColor() << ", " << apple.m_fiber << ")" << std::endl;
	return out;
}

std::ostream& operator<< (std::ostream &out, const Banana &banana)
{
	out << "Banana (" << banana.getName() << ", " << banana.getColor() << ", "  << ")" << std::endl;
	return out;
}

int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;

	const Banana b("Cavendish", "yellow");
	std::cout << b;


	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}