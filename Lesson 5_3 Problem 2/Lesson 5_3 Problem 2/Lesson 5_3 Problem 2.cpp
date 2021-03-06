// Lesson 5_3 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

enum class Animal
{
	PIG,
	CHICKEN,
	GOAT,
	CAT,
	DOG,
	OSTRICH
};



void printAnimals(Animal animal)
{
	switch (animal)
	{
		case Animal::PIG:
			std::cout << "A pig has 4 legs" << std::endl;
			break;
		case Animal::CHICKEN:
			std::cout << "A chicken has 2 legs" << std::endl;
			break;
		case Animal::GOAT:
			std::cout << "A goat has 4 legs" << std::endl;
			break;
		case Animal::CAT:
			std::cout << "A cat has 4 legs" << std::endl;
			break;
		case Animal::DOG:
			std::cout << "A dog has 4 legs" << std::endl;
			break;
		case Animal::OSTRICH:
			std::cout << "A ostrich has 2 legs" << std::endl;
			break;
		default:
			std::cout << "Unknown Animal";
			break;
	}
}

int main()
{
	Animal cat = Animal::CAT;
	Animal chicken = Animal::CHICKEN;
	printAnimals(cat);
	printAnimals(chicken);
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

