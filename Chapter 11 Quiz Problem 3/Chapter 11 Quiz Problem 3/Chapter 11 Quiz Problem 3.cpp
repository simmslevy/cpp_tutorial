// Chapter 11 Quiz Problem 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()


class Creature
{
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_gold;
protected:
	int m_damage;


public:
	Creature(std::string name, char symbol, int health, int damage, int gold) 
		: m_name{ name }, m_symbol{ symbol }, m_health{ health }, m_damage{ damage }, m_gold{ gold }
	{
	}

	std::string getName() { return m_name; }
	char getSymbol() { return m_symbol; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
	int getGold() { return m_gold; }

	void reduceHealth(int damage) { m_health -= damage; }
	bool isDead() { return (m_health <= 0); }
	void addGold(int gold) { m_gold += gold; }
};


class Player : public Creature
{
	int m_level;
public:
	Player(std::string name) : m_level{ 1 }, Creature(name, '@', 10, 1, 0) {}

	void levelUp() 
	{
		++m_level;
		++m_damage;
	}

	int getLevel() { return m_level; }

	bool hasWon() { return (m_level >= 20); }
};


class Monster : public Creature
{
public:
	struct MonsterData
	{
		std::string s_name;
		char s_symbol;
		int s_health;
		int s_damage;
		int s_gold;
	};

	

public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};


	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type) : Creature(monsterData[type].s_name, monsterData[type].s_symbol, monsterData[type].s_health, monsterData[type].s_damage, monsterData[type].s_gold) {}

	static Monster getRandomMonster()
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																					 // evenly distribute the random number across our range
		return Monster(static_cast<Type>(static_cast<int>(rand() * fraction * MAX_TYPES)));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{"slime", 's', 1, 1, 10 }
};

bool runAway()
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<bool>(static_cast<int>(rand() * fraction * (2)));
}


void attackMonster(Player &p, Monster &m)
{
	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage." << std::endl;
	m.reduceHealth(p.getDamage());
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << "." << std::endl;
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << "." << std::endl;
		std::cout << "You found " << m.getGold() << " gold." << std::endl;
		p.addGold(m.getGold());
	}
}

void attackPlayer(Player &p, Monster &m)
{
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage." << std::endl;
	p.reduceHealth(m.getDamage());
	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold." << std::endl;
		std::cout << "Too bad you can't take it with you!" << std::endl;
	}

}

void fightMonster(Player &p, Monster &m)
{
	char action;
	std::cout << "(r)un or (f)ight: ";
	std::cin >> action;
	if (action == 'f')
	{
		attackMonster(p, m);
		//std::cout << "Monster has " << m.getHealth() << " left!" << std::endl;
		if (m.isDead())
		{
			return;
		}
		else
		{
			attackPlayer(p, m);
			if (p.isDead())
				return;
			else
				fightMonster(p, m);
		}
	}
	else if (action == 'r')
	{ 
		if (runAway())
		{ 
			std::cout << "You have succesffully fled." << std::endl;
			return;
		}
		else
		{
			std::cout << "You failed to flee." << std::endl;
			attackPlayer(p, m);
			if (p.isDead())
				return;
			else
				fightMonster(p, m);
		}
	}

}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	Player p(name);
	std::cout << "Welcome, " << p.getName() << std::endl;
	
	while (true)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ")." << std::endl;
		fightMonster(p, m);
		if (p.isDead())
			break;
		if (p.hasWon())
		{
			std::cout << "You have won! You had " << p.getGold() << " gold!" << std::endl;
			break;
		}
	}


	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

    return 0;
}

