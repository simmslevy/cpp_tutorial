// Chapter 9 Quiz Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class IntArray
{
	int m_size;
	int *m_array = nullptr;

public:

	IntArray(int length) : m_size{ length } 
	{
		m_array = new int[length] {0};
	}

	IntArray(const IntArray &array) :
		m_size(array.m_size)
	{
		// Allocate a new array
		m_array = new int[m_size];

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];
	}

	~IntArray()
	{
		delete [] m_array;
	}

	int& operator[] (const int index);
	friend std::ostream& operator<< (std::ostream &out, const IntArray &array);

	// Assignment operator that does a deep copy
	IntArray& operator= (const IntArray &array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		m_size = array.m_size;

		// Allocate a new array
		m_array = new int[m_size];

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_size; ++count)
			m_array[count] = array.m_array[count];

		return *this;
	}

};

int& IntArray::operator[] (const int index)
{
	if (index >= 0 && index < m_size)
		return m_array[index];
}

std::ostream& operator<< (std::ostream &out, const IntArray &array)
{
	for (int count = 0; count < array.m_size; ++count)
		out << array.m_array[count] << " ";
	return out;

}

IntArray fillArray()
{
	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}