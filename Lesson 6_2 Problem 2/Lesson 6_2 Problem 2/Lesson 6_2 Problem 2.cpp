// Lesson 6_2 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace Animalnames
{
	enum Aimalnames
	{
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS
	};
}

int main()
{
	int animalLegs[Animalnames::MAX_ANIMALS] = { 2,4,4,4,2,0 };
	std::cout << animalLegs[Animalnames::ELEPHANT];
	return 0;
}

