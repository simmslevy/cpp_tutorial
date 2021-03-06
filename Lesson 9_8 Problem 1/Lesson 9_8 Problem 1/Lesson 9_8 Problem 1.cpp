// Lesson 9_8 Problem 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
	std::string name;
	char grade;
};

class GradeMap
{
	std::vector<StudentGrade> m_map;
public:
	GradeMap()	{}

	char& operator[] (std::string name);
};

char& GradeMap::operator[] (std::string name)
{
	for (StudentGrade &element : m_map)
	{
		if (element.name == name)
			return element.grade;
	}

	StudentGrade newGrade;
	newGrade.name = name;
	m_map.push_back(newGrade);
	return m_map.back().grade;
}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

    return 0;
}

