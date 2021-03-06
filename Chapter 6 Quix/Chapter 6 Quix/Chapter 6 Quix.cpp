// Chapter 6 Quix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>

enum ItemType
{
	ITEMTYPE_POTION,
	ITEMTYPE_TORCH,
	ITEMTYPE_ARROW,
	MAX_ITEMS
};
	
struct Student
{
	std::string *studentName;
	int *grade;
};

int countTotalItems(int *items)
{
	return items[0] + items[1] + items[2];
}


int getNumberStudents()
{
	std::cout << "Enter number of students: ";
	int numberStudents;
	std::cin >> numberStudents;
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	return numberStudents;
}

void swapperoni(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void printCString(char *array)
{
	for (array; *array != '\0'; ++array)
		std::cout << *array;
}

int main()
{
	//// Problem 1
	//int itemsCarried[ItemType::MAX_ITEMS]{ 2, 5, 10 };
	//std::cout << "You are carrying " << countTotalItems(itemsCarried) << " items." << std::endl;
	//
	//std::cin.clear(); // reset any error flags
	//std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character

	//// Problem 2
	//int length = getNumberStudents();

	//Student myClass;
	//myClass.grade = new int[length];
	//myClass.studentName = new std::string[length];

	//for (int count = 0; count < length; ++count)
	//{
	//	std::cout << "Enter student name of #" << count + 1 << ": ";
	//	std::getline(std::cin, myClass.studentName[count]);
	//	std::cout << "Enter " << myClass.studentName[count] <<"'s grade: ";
	//	std::cin >> myClass.grade[count];
	//	std::cin.clear(); // reset any error flags
	//	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	//}

	//for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	//{
	//	// smallestIndex is the index of the smallest element we’ve encountered this iteration
	//	// Start by assuming the smallest element is the first element of this iteration
	//	int largestIndex = startIndex;

	//	// Then look for a smaller element in the rest of the array
	//	for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
	//	{
	//		// If we've found an element that is smaller than our previously found smallest
	//		if (myClass.grade[currentIndex] > myClass.grade[largestIndex])
	//			// then keep track of it
	//			largestIndex = currentIndex;
	//	}

	//	// smallestIndex is now the smallest element in the remaining array
	//	// swap our start element with our smallest element (this sorts it into the correct place)
	//	std::swap(myClass.grade[startIndex], myClass.grade[largestIndex]);
	//	std::swap(myClass.studentName[startIndex], myClass.studentName[largestIndex]);
	//}

	//for (int count = 0; count < length; ++count)
	//	std::cout << myClass.studentName[count] << " got a grade of " << myClass.grade[count] << std::endl;

	//delete[] myClass.grade;
	//delete[] myClass.studentName;

	//// Problem 3
	//std::cout << "Enter a number: ";
	//int x;
	//int y;
	//std::cin >> x;
	//std::cout << "Enter another number: ";
	//std::cin >> y;
	//swapperoni(x, y);
	//std::cout << "New number 1: " << x << std::endl;
	//std::cout << "New number 2: " << y << std::endl;


	// Problem 4
	char myString[] = "Hello, world!";
	printCString(myString);


	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

