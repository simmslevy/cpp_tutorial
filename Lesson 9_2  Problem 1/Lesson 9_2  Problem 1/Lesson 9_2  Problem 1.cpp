// Lesson 9_2  Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Fraction
{
	int m_numerator;
	int m_denominator;
public:
	Fraction(int numerator = 1, int denominator = 1) : m_numerator{ numerator }, m_denominator{ denominator } 
	{
		reduce();
	}

	void print()
	{
		std::cout << m_numerator << '/' << m_denominator << std::endl;
	}

	int gcd(int a, int b) {
		return (b == 0) ? (a > 0 ? a : -a) : Fraction::gcd(b, a % b);
	}

	void reduce()
	{
		int factor = gcd(m_numerator, m_denominator);
		m_numerator /= factor;
		m_denominator /= factor;
	}

	friend Fraction operator*(const Fraction &f1, const Fraction &f2);
	friend Fraction operator*(const Fraction &f1, const int x);
	friend Fraction operator*(const int x, const Fraction &f2);

	friend std::ostream& operator<< (std::ostream &out, const Fraction &f);
	friend std::istream& operator>> (std::istream &in, Fraction &f);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}

Fraction operator*(const Fraction &f1, const int x)
{
	return Fraction(f1.m_numerator * x, f1.m_denominator);
}

Fraction operator*(const int x, const Fraction &f1)
{
	return operator*(f1, x);
}


std::ostream& operator<< (std::ostream &out, const Fraction &f)
{
	out << f.m_numerator << "/" << f.m_denominator;
	
	return out;
}

std::istream& operator>> (std::istream &in, Fraction &f)
{
	char c;
	in >> f.m_numerator;
	in >> c;
	in >> f.m_denominator;

	f.reduce();

	return in;

}


int main()
{
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;

	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;

	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';



	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}

