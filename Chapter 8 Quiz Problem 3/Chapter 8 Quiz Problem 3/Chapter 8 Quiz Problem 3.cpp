// Chapter 8 Quiz Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime> // for time()
#include <cstdlib> // for rand() and srand()

class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
private:
	MonsterType m_type;
	std::string m_name;
	std::string m_roar;
	int m_hitpoints;
public:
	Monster(MonsterType type, std::string name, std::string roar, int hp)
		: m_type{ type },
		m_name{ name },
		m_roar{ roar },
		m_hitpoints{ hp } 
	{
	}

	std::string getTypeString()
	{
		switch (m_type)
		{
			case Dragon: return "Dragon";
			case Goblin: return "Goblin";
			case Ogre: return "Ogre";
			case Orc: return "Orc";
			case Skeleton: return "Skeleton";
			case Troll: return "Troll";
			case Vampire: return "Vampire";
			case Zombie: return "Zombie";
		}
	}

	void print()
	{
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitpoints << " hit points and says " << m_roar << std::endl;
	}


};

class MonsterGenerator
{
public:
	static Monster generateMonster()
	{
		static std::string names[6]{ "Bones", "Barry", "Timothy","Rex","Max","Aurelius" };
		static std::string roars[6]{ "*fwoosh*", "*rattle*", "*rawr*","*rawwwwwwwwr*","*hullo*","*quite, quite*" };

		return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)), names[getRandomNumber(0, 5)], roars[getRandomNumber(0, 5)], getRandomNumber(1,100));
	}

	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
};

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // If using Visual Studio, discard first random value

	Monster m = MonsterGenerator::generateMonster();
	m.print();

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}

