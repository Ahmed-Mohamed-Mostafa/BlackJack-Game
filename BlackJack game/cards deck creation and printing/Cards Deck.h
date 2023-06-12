#include <iostream>
#include <array>		//c++ 20
#include <algorithm>	//std::shuffle
#include <random>
#ifndef CARDS_DECK_H
#define CARDS_DECK_H

enum class Rank
{
	two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, max_rank
};

enum class Suit
{
	clubs, diamonds, hearts, spades, max_suit
};

struct Card
{
	Rank rank;
	Suit suit;
};

void printCard(const Card& card);

using ArrayOfCards = std::array<Card, 52>;	//using an aliases for readability 
ArrayOfCards createDeck();

void printDeck(const ArrayOfCards& cardsArray);

void shuffleDeck(ArrayOfCards& cardsArray);

int getCardValue(const Card& card);

#endif // !CARDS_DECK_H
