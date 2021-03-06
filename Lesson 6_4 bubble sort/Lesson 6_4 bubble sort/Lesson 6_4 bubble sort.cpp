// Lesson 6_4 bubble sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <utility>


const int length(9);
int array[length] = { 6, 3, 2, 9, 7, 1, 5, 4, 8 };

int main()
{
	short value = 7; // &value = 0012FF60
	short otherValue = 3; // &otherValue = 0012FF54

	short *ptr = &value;

	std::cout << &value << '\n';
	std::cout << value << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	*ptr = 9;

	std::cout << &value << '\n';
	std::cout << value << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	ptr = &otherValue;

	std::cout << &otherValue << '\n';
	std::cout << otherValue << '\n';
	std::cout << ptr << '\n';
	std::cout << *ptr << '\n';
	std::cout << '\n';

	std::cout << sizeof(ptr) << '\n';
	std::cout << sizeof(*ptr) << '\n';
	//for (int index = 0; index < length; ++index)
	//	std::cout << array[index] << " ";
	//std::cout << std::endl;
	//bool swapit;
	//for (int i = 0; i < length - 1; ++i)
	//{
	//	swapit = false;
	//	for (int j = 0; j < length - 1 - i; ++j)
	//	{
	//		if (array[j] > array[j + 1])
	//		{
	//			swapit = true;
	//			std::swap(array[j], array[j + 1]);
	//		}
	//	}

	//	if (!swapit)
	//	{
	//		std::cout << "Stopping after: " << i+1 << " iterations." << std::endl;
	//		break;
	//	}
	//		
	//}
	//for (int index = 0; index < length; ++index)
	//	std::cout << array[index] << " ";
	//std::cout << std::endl;
	//std::cin.clear(); // reset any error flags
	//std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	//std::cin.get(); // get one more char from the user
	//return 0;
}

