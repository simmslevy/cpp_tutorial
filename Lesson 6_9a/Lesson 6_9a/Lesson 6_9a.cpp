// Lesson 6_9a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>

int getInt()
{
	std::cout << "Please enter desired number of names: ";
	int numberNames;
	std::cin >> numberNames;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	return numberNames;
}

std::string getName()
{
	std::cout << "Please enter desired a name: ";
	std::string name;
	std::getline(std::cin, name);
	return name;
}

int main()
{
    // Get # of names
	int numberNames = getInt();
	// Create array
	std::string *array = new std::string[numberNames];
	// Populate array
	for (int count(0); count < numberNames; ++count)
		array[count] = getName();


	// Sort array
	for (int startIndex = 0; startIndex < numberNames - 1; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallestIndex = startIndex;

		// Then look for a smaller element in the rest of the array
		for (int currentIndex = startIndex + 1; currentIndex < numberNames; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// then keep track of it
				smallestIndex = currentIndex;
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}


	// Print array
	for (int count(0); count < numberNames; ++count)
		std::cout << "Name #" << count + 1 << ": " << array[count] << std::endl;
	

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

