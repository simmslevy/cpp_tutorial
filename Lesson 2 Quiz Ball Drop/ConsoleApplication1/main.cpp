// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "constants.h"
#include <iostream>

double newHeight(double height, int seconds)
{
	return height - myConstants::gravity * seconds * seconds / 2;
}

double enterHeight()
{
	std::cout << "Enter the initial height of the tower in meters: ";
	double height;
	std::cin >> height;
	return height;
}

void printHeight(int seconds, double height)
{
	if (height > 0)
		std::cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters" << std::endl;
	else
		std::cout << "At " << seconds << " seconds, the ball is at height: 0 meters" << std::endl;
}

int main()
{
	double initialHeight(enterHeight());
	std::cout << "At 0 seconds, the ball is at height: " << initialHeight << " meters" << std::endl;
	double height(newHeight(initialHeight, 1));
	printHeight(1, height);
	printHeight(2, newHeight(initialHeight, 2));
	printHeight(3, newHeight(initialHeight, 3));
	printHeight(4, newHeight(initialHeight, 4));
	printHeight(5, newHeight(initialHeight, 5));
    return 0;
}

