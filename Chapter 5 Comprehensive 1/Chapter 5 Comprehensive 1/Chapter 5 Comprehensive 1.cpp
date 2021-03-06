// Chapter 5 Comprehensive 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "constants.h"

// gets initial height from user and returns it
double getInitialHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double initialHeight;
	std::cin >> initialHeight;
	return initialHeight;
}

// Returns height from ground after "secondsPassed" seconds
double calculateHeight(double initialHeight, int secondsPassed)
{
	// Using formula: [ s = u * t + (a * t^2) / 2 ], here u(initial velocity) = 0
	double distanceFallen = (myConstants::gravity * secondsPassed * secondsPassed) / 2;
	double currentHeight = initialHeight - distanceFallen;

	return currentHeight;
}

// Prints height every second till ball has reached the ground
void printHeight(double height, int secondsPassed)
{
	if (height > 0.0)
	{
		std::cout << "At " << secondsPassed << " seconds, the ball is at height:\t" << height <<
			" meters\n";
	}
	else
		std::cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
}

int calculateAndPrintHeight(double initialHeight, int secondsPassed)
{
	double height = calculateHeight(initialHeight, secondsPassed);
	printHeight(height, secondsPassed);
	return height;
}

int main()
{
	const double initialHeight = getInitialHeight();

	int currentHeight = initialHeight;
	int seconds = 0;

	while (currentHeight > 0)
	{
		currentHeight = calculateAndPrintHeight(initialHeight, seconds);
		++seconds;
	}

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}