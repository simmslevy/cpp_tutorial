// Lesson 8_3 Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Stack
{
	int m_array[10];
	int m_length;
public:
	void reset()
	{
		m_length = 0;
		for (int &element : m_array)
			element = 0;
	}

	bool push(int value)
	{
		if (m_length > 9)
			return false;
		m_array[m_length++] = value;
		return true;
	}

	bool pop()
	{
		if (m_length)
		{
			m_array[--m_length] = 0;
			return true;
		}
		return false;
	}

	void print()
	{
		std::cout << "( ";
		for (int count = 0; count < m_length; ++count)
			std::cout << m_array[count] << " ";
		std::cout << ")" << std::endl;
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

