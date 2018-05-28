#ifndef STRINGVALUEPAIR_H
#define STRINGVALUEPAIR_H
#include <string>

template <class T>  // This is a template class, the user will provide the data type for T
class StringValuePair
{
private:
	std::string m_p1;
	T m_p2;

public:
	StringValuePair(const std::string& s, const T& t2) : m_p1{ s }, m_p2{ t2 } {}

	std::string& first() { return m_p1; }
	T& second() { return m_p2; }
	const std::string& first() const { return m_p1; }
	const T& second() const { return m_p2; }

};


#endif#pragma once
