// Lesson 4.x quiz Monster List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>


enum class Monstertype
{
	OGRE,
	SLIME,
	DRAGON,
	ORC,
	GIANTSPIDER
};

struct Monster
{
	Monstertype type;
	std::string name;
	int health;
};

std::string montype(Monstertype type)
{
	if (type == Monstertype::OGRE)
		return "Ogre";
	else if (type == Monstertype::SLIME)
		return "Slime";
	else if (type == Monstertype::DRAGON)
		return "Dragon";
	else if (type == Monstertype::ORC)
		return "Orc";
	else if (type == Monstertype::GIANTSPIDER)
		return "Giant Spider";
}

void printMonster(Monster monster)
{
	std::cout << "This " << montype(monster.type) << " is named " << monster.name << " and has " << monster.health << " health." << std::endl;
}

int main()
{
	Monster torg = { Monstertype::OGRE, "Torg", 145 };
	Monster blurp = { Monstertype::SLIME, "Blupr", 23 };
	printMonster(torg);
	printMonster(blurp);
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
    return 0;
}

