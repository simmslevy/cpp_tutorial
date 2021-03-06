// Lesson 8_5a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class RGBA
{
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;
public:
	RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t blue = 0, std::uint8_t alpha = 255)
		: m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{
	}

	void print()
	{
		std::cout << "r=" << static_cast<int>(m_red);
		std::cout << " g=" << static_cast<int>(m_green);
		std::cout << " b=" << static_cast<int>(m_blue);
		std::cout << " a=" << static_cast<int>(m_alpha) << std::endl;
	}
};

int main()
{
	RGBA teal(0, 127, 127);
	teal.print();

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

