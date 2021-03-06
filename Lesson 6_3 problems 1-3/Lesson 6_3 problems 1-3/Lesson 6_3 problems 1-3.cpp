// Lesson 6_3 problems 1-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int getInt()
{
	while (true)
	{
		std::cout << "Enter an integer value 1 to 10:";
		short value;
		std::cin >> value;

		if (std::cin.fail()) // has a previous extraction failed?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
		}
		else // else our extraction succeeded
			if (value>0 && value < 10)
				return value; // so return the value we extracted
	}		
}


int main()
{
	// Problem 1
	
	int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
	
	// Problem 2

	int desiredValue = getInt();

	int arrayLength = sizeof(array) / sizeof(array[0]);
	for (int count = 0; count < arrayLength; ++count)
		std::cout << "Number " << count << " in the array is " << array[count] << std::endl;

	for (int count = 0; count < arrayLength; ++count)
	{
		if (array[count] == desiredValue)
		{
			std::cout << "The index of your value is: " << count << std::endl;
			break;
		}
			
	}
	
	// Problem 3
	int scores[] = { 84, 92, 76, 81, 56 };
    const int numStudents = sizeof(scores) / sizeof(scores[0]);
 
    int maxIndex = 0; // keep track of our largest score
 
    // now look for a larger score
    for (int student = 0; student < numStudents; ++student)
        if (scores[student] > scores[maxIndex])
            maxIndex = student;
 
    std::cout << "The best score was " << scores[maxIndex] << '\n';
 

	// Cleanup
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

