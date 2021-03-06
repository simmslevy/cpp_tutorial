// Chapter 11 Quiz Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


class Fruit
{
	std::string m_name;
	std::string m_color;
public:
	Fruit(std::string name = "apple", std::string color = "red") : m_name{ name }, m_color{ color } {}
	std::string getName() { return m_name; }
	std::string getColor() { return m_color; }
};


class Apple : public Fruit
{
public:
	Apple(std::string color = "red") : Fruit("apple", color) {}
	Apple(std::string color, std::string name) : Fruit(name, color) {}
};

class Banana : public Fruit
{
public:
	Banana(std::string name = "banana", std::string color = "yellow") : Fruit(name, color) {}
};

class GrannySmith : public Apple
{
public:
	GrannySmith(std::string color = "green") : Apple(color,"granny smith apple") {}
};

int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

