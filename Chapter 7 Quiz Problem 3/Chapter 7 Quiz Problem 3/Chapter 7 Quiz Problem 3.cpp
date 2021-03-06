// Chapter 7 Quiz Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


// Iterative
//int binarySearch(int *array, int target, int min, int max)
//{
//	if ((target < array[min]) || (target > array[max]))
//		return -1;
//	while (true)
//	{
//		if (min > max)
//			return -1;
//		int midpoint = (max - min) / 2 + min;
//		if (array[midpoint] == target)
//			return midpoint;
//		else if (array[midpoint] > target)
//			max = midpoint - 1;
//		else if (array[midpoint] < target)
//			min = midpoint + 1;
//	}
//}

// Recursive
int binarySearch(int *array, int target, int min, int max)
{
	if (min > max)
		return -1;
	int midpoint = (max - min) / 2 + min;
	if (array[midpoint] == target)
		return midpoint;
	else if (array[midpoint] > target)
		return binarySearch(array, target, min, midpoint - 1);
	else if (array[midpoint] < target)
		return binarySearch(array, target, min + 1, max);
}


int main()
{
	int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

	// We're going to test a bunch of values to see if they produce the expected results
	const int numTestValues = 9;
	// Here are the test values
	int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
	// And here are the expected results for each value
	int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };

	// Loop through all of the test values
	for (int count = 0; count < numTestValues; ++count)
	{
		// See if our test value is in the array
		int index = binarySearch(array, testValues[count], 0, 14);
		// If it matches our expected value, then great!
		if (index == expectedValues[count])
			std::cout << "test value " << testValues[count] << " passed!\n";
		else // otherwise, our binarySearch() function must be broken
			std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
	}

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}