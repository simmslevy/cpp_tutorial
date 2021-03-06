// Lesson 10_3 Problem 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(std::string name)
		: m_name(name)
	{
	}

	std::string getName() { return m_name; }
};

class Department
{
private:
	std::vector<Teacher> m_teacher;

public:
	/*Department(Teacher *teacher = nullptr)
	{
		m_teacher.push_back(*teacher);
	}*/

	void add(Teacher *teacher)
	{
		m_teacher.push_back(*teacher);
	}

	friend std::ostream& operator<< (std::ostream &out, Department &dep);

	
};


std::ostream& operator<< (std::ostream &out, Department &dep)
{
	out << "Department:";
	for (int count = 0; count < dep.m_teacher.size(); ++count)
		out << dep.m_teacher[count].getName() << " ";
	out << std::endl;
	return out;

}

int main()
{
	// Create a teacher outside the scope of the Department
	Teacher *t1 = new Teacher("Bob"); // create a teacher
	Teacher *t2 = new Teacher("Frank");
	Teacher *t3 = new Teacher("Beth");

	{
		// Create a department and use the constructor parameter to pass
		// the teacher to it.
		Department dept; // create an empty Department
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);

		std::cout << dept;

	} // dept goes out of scope here and is destroyed

	std::cout << t1->getName() << " still exists!\n";
	std::cout << t2->getName() << " still exists!\n";
	std::cout << t3->getName() << " still exists!\n";

	delete t1;
	delete t2;
	delete t3;

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

	return 0;
}