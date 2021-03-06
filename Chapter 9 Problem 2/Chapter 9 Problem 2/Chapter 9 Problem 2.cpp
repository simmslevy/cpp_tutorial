// Chapter 9 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Average
{
	int32_t m_sum;
	int8_t m_number;

public:
	Average() : m_sum{0}, m_number{0} {}

	friend std::ostream& operator<< (std::ostream &out, const Average &average);
	Average& operator+=(int x);
};

std::ostream& operator<< (std::ostream &out, const Average &average)
{
	if (average.m_number > 0)
		out << (static_cast<float>(average.m_sum) / static_cast<float>(average.m_number));
	else
		out << 0;
	return out;
}

Average& Average::operator+=(int x)
{
	m_sum += x;
	++m_number;
	return *this;
}


int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	
	return 0;
}

