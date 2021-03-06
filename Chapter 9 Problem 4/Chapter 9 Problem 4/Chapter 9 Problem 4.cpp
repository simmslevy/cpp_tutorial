// Chapter 9 Problem 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

class FixedPoint2
{
	int16_t m_integer;
	int8_t m_decimal;
public:
	FixedPoint2(int16_t x, int8_t y) : m_integer{ x }, m_decimal{ y } 
	{
		if (m_decimal < 0 && !(m_integer < 0))
			m_integer = -m_integer;
		else if (m_integer < 0 && !(m_decimal < 0))
			m_decimal = -m_decimal;
	}

	FixedPoint2(double x)
	{
		m_integer = static_cast<int16_t>(x);
		m_decimal = static_cast<int8_t>(round((x - m_integer) * 100));
	}

	operator double() { return (static_cast<double>(m_integer) + static_cast<double>(m_decimal) / 100); }

	friend std::ostream& operator<< (std::ostream &out, const FixedPoint2 fp2);
	friend std::istream& operator>> (std::istream &in, FixedPoint2 &fp2);

	friend bool operator== (const FixedPoint2 &fp1, const FixedPoint2 &fp2);
	FixedPoint2 operator-() const;
	friend FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2);
};

std::ostream& operator<< (std::ostream &out, FixedPoint2 fp2)
{
	// Since operator<< is a friend of the Point class, we can access Point's members directly.
	out << double(fp2);

	return out;
}

std::istream& operator>> (std::istream &in, FixedPoint2 &fp2)
{
	// Since operator>> is a friend of the Point class, we can access Point's members directly.
	// note that parameter point must be non-const so we can modify the class members with the input values
	//char decimalHolder;
	//in >> fp2.m_integer;
	//in >> decimalHolder;
	//in >> fp2.m_decimal;
	//fp2.m_decimal = round(fp2.m_decimal / 100);
	//if (fp2.m_integer < 0)
	//	fp2.m_decimal = -fp2.m_decimal;
	double temp;
	in >> temp;
	fp2 = FixedPoint2(temp);
	return in;
}

bool operator== (const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
	return (fp1.m_decimal == fp2.m_decimal &&
		fp1.m_integer == fp2.m_integer);
}

FixedPoint2 FixedPoint2::operator-() const
{
	return FixedPoint2(- m_integer, - m_decimal);
}

FixedPoint2 operator+(const FixedPoint2 &fp1, const FixedPoint2 &fp2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	int8_t tempCarry((fp1.m_decimal + fp2.m_decimal) / 100);
	int8_t tempDecimal((fp1.m_decimal + fp2.m_decimal) - tempCarry * 100);
	int16_t tempInteger(fp1.m_integer + fp2.m_integer + tempCarry);
	if (tempInteger < 0 && !(tempDecimal < 0))
	{
		++tempInteger;
		tempDecimal = -(100 - tempDecimal);
	}
	else if (tempDecimal < 0 && !(tempInteger < 0))
	{
		--tempInteger;
		tempDecimal = 100 + tempDecimal;
	}
	return FixedPoint2(tempInteger,tempDecimal);
}

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.23) == FixedPoint2(1.98)) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(1.50) == FixedPoint2(2.25)) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.23) == FixedPoint2(-1.98)) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(-1.50) == FixedPoint2(-2.25)) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.23) == FixedPoint2(-0.48)) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2(0.75) + FixedPoint2(-1.50) == FixedPoint2(-0.75)) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.23) == FixedPoint2(0.48)) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2(-0.75) + FixedPoint2(1.50) == FixedPoint2(0.75)) << '\n'; // first negative, possible decimal overflow
}

int main()
{
	testAddition();

	FixedPoint2 a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';


	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

