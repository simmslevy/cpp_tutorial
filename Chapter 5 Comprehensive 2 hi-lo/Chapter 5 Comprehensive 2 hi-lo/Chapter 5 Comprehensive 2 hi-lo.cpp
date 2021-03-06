// Chapter 5 Comprehensive 2 hi-lo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

int  randoInteger()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	int min = 1;
	int max = 100;
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
	// evenly distribute the random number across our range
	return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

int getGuess(int guessNumber)
{
	
	while (true) // Loop until user enters a valid input
	{
		std::cout << "Guess #" << guessNumber << ":";
		int guess;
		std::cin >> guess;

		if (std::cin.fail()) // has a previous extraction failed?
		{
			// yep, so let's handle the failure
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
		}
		else // else our extraction succeeded
		{
			std::cin.ignore(32767, '\n'); // remove any extraneous input
			return guess; // so return the value we extracted
		}
	}
}

bool anotherGame()
{
	std::cout << "Would you like to play again (y/n)? ";
	char yesNo;
	std::cin >> yesNo;
	switch (yesNo)
	{
	case 'y':
		return true;
	case 'n':
		return false;
	default:
		return anotherGame();
	}

}

void playGame()
{
	std::cout << "Let's play a game. I'm thinking of a number. you have 7 tries to guess what it is." << std::endl;
	int currentGuess;
	int secretNumber = randoInteger();
	//std::cout << "The secret number is: " << secretNumber << std::endl; // comment this line out for final game, used for testing only
	int guessNumber = 1;
	for (; guessNumber < 8; ++guessNumber)
	{
		currentGuess = getGuess(guessNumber);
		if (secretNumber == currentGuess)
		{
			std::cout << "Correct! You win!" << std::endl;
			break;
		}
		else if (secretNumber > currentGuess)
			std::cout << "Your guess is too low." << std::endl;
		else if (secretNumber < currentGuess)
			std::cout << "Your guess is too high." << std::endl;

	}
	if (guessNumber > 7)
		std::cout << "Sorry, you lose. The correct number was " << secretNumber << "." << std::endl;
}

int main()
{
	bool playAgain;
	do
	{
		playGame();
		playAgain = anotherGame();
	} while (playAgain);
	std::cout << "Thank you for playing.";
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

