// Chapter 6 Quiz Problem 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


enum class CardRank
{
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANKS
};

enum class CardSuit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES,
	MAX_SUITS
};

struct Card
{
	CardSuit suit;
	CardRank rank;
};

void printCard(const Card &card)
{
	switch (card.rank)
	{
		case CardRank::TWO:			std::cout << '2';	break;
		case CardRank::THREE:		std::cout << '3';	break;
		case CardRank::FOUR:		std::cout << '4';	break;
		case CardRank::FIVE:		std::cout << '5';	break;
		case CardRank::SIX:			std::cout << '6';	break;
		case CardRank::SEVEN:		std::cout << '7';	break;
		case CardRank::EIGHT:		std::cout << '8';	break;
		case CardRank::NINE:		std::cout << '9';	break;
		case CardRank::TEN:			std::cout << 'T';	break;
		case CardRank::JACK:		std::cout << 'J';	break;
		case CardRank::QUEEN:		std::cout << 'Q';	break;
		case CardRank::KING:		std::cout << 'K';	break;
		case CardRank::ACE:			std::cout << 'A';	break;
	}
	switch (card.suit)
	{
		case CardSuit::CLUBS:		std::cout << 'C'; break;
		case CardSuit::DIAMONDS:	std::cout << 'D'; break;
		case CardSuit::HEARTS:		std::cout << 'H'; break;
		case CardSuit::SPADES:		std::cout << 'S'; break;
	}
}

void printDeck(const std::array<Card, 52> &deck)
{
	for (Card card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << '\n';
}

void swapCard(Card &x, Card &y)
{
	Card temp = x;
	x = y;
	y = temp;
}



int getRandomCard()											// Chooses a random number between 0 and 51
{	
	static const double fraction = 1.0 / (RAND_MAX + 1.0);  // static used for efficiency, so we only calculate this value once
															// evenly distribute the random number across our range
	return static_cast<int>((52) * (rand() * fraction));
}

void shuffleDeck(std::array<Card, 52> &deck)
{
	for (int index = 0; index < 52; ++index)
	{
		int randomIndex = getRandomCard();
		swapCard(deck[index], deck[randomIndex]);
	}
}

int getCardValue(Card &card)
{
	switch (card.rank)
	{
	case CardRank::TWO:			return 2;
	case CardRank::THREE:		return 3;
	case CardRank::FOUR:		return 4;
	case CardRank::FIVE:		return 5;
	case CardRank::SIX:			return 6;
	case CardRank::SEVEN:		return 7;
	case CardRank::EIGHT:		return 8;
	case CardRank::NINE:		return 9;
	case CardRank::TEN:			return 10;
	case CardRank::JACK:		return 10;
	case CardRank::QUEEN:		return 10;
	case CardRank::KING:		return 10;
	case CardRank::ACE:			return 11;
	}
}

bool playBlackjack(std::array<Card, 52> &deck)
{
	Card *cardPtr = &deck[0];
	int playerScore(0);
	int dealerScore(0);
	// deal dealer
	dealerScore += getCardValue(*cardPtr++);
	std::cout << "The dealer has " << dealerScore << " showing" << std::endl;
	playerScore += getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);
	std::cout << "You have " << playerScore << " showing" << std::endl;
	bool hit = true;
	while (hit)
	{
		std::cout << "Hit, y/n?";
		char input;
		std::cin >> input;
		if (input == 'y')
		{
			playerScore += getCardValue(*cardPtr++);
			std::cout << "You have " << playerScore << " showing" << std::endl;
			if (playerScore > 21)
			{
				std::cout << "You bust!" << std::endl;
				return false;
			}
		}
		else
			hit = false;
	}

	while (dealerScore < 17)
	{
		dealerScore += getCardValue(*cardPtr++);
		if (dealerScore > 21)
		{
			std::cout << "The dealer bust!" << std::endl;
			return true;
		}
	}

	std::cout << "You scored " << playerScore << ", the dealer scored " << dealerScore << std::endl;

	if (playerScore > dealerScore)
		return true;
	else
		return false;
}

int main()
{
	// Problem 6
	srand(static_cast<unsigned int>(time(0)));
	rand();
	std::array<Card, 52> deck;
	int index = 0;
	for (int suit = 0; suit < 4; ++suit)
	{
		for (int rank = 0; rank < 13; ++rank)
		{
			deck[index].rank = static_cast<CardRank>(rank);
			deck[index].suit = static_cast<CardSuit>(suit);
			++index;
		}
	}

	shuffleDeck(deck);
	bool win = playBlackjack(deck);
	if (win)
		std::cout << "You win!" << std::endl;
	else
		std::cout << "You lose!" << std::endl;

	// Problem 7

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
	return 0;
}

