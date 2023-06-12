#include "Cards Deck.h"

void printCard(const Card& card)
{
	switch (card.rank)
	{
	case Rank::two:		std::cout << "2";
		break;
	case Rank::three:	std::cout << "3";
		break;
	case Rank::four:	std::cout << "4";
		break;
	case Rank::five:	std::cout << "5";
		break;
	case Rank::six:		std::cout << "6";
		break;
	case Rank::seven:	std::cout << "7";
		break;
	case Rank::eight:	std::cout << "8";
		break;
	case Rank::nine:	std::cout << "9";
		break;
	case Rank::ten:		std::cout << "10";
		break;
	case Rank::jack:	std::cout << "J";
		break;
	case Rank::queen:	std::cout << "Q";
		break;
	case Rank::king:	std::cout << "K";
		break;
	case Rank::ace:		std::cout << "A";
		break;
	default:			std::cout << "?";
		break;
	}
	switch (card.suit)
	{
	case Suit::clubs:		std::cout << "C";
		break;
	case Suit::diamonds:	std::cout << "D";
		break;
	case Suit::hearts:		std::cout << "H";
		break;
	case Suit::spades:		std::cout << "S";
		break;
	default:				std::cout << "?";
		break;
	}
}

using ArrayOfCards = std::array<Card, 52>;	//using an aliases for readability 
ArrayOfCards createDeck()
{
	ArrayOfCards cardsArray{};
	int currentRank{ 0 };
	int currentSuit{ 0 };

	// we have to use reference with Card& as if we didn't the changes happening to every card(element) after every iteration
	// will not be saved 
	for (Card& card : cardsArray)
	{
		card.rank = static_cast <Rank> (currentRank);
		card.suit = static_cast <Suit> (currentSuit);
		++currentRank;

		if (currentRank == static_cast<int>(Rank::max_rank))
		{
			++currentSuit;
			currentRank = 0;
		}
	}
	return cardsArray;
}

void printDeck(const ArrayOfCards& cardsArray)
{
	for (int index{ 0 }; index < cardsArray.size(); ++index)
	{
		printCard(cardsArray[index]);
		std::cout << "\t";

		if ((index + 1) % 10 == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n\n\n";
}

void shuffleDeck(ArrayOfCards& cardsArray)
{
	static std::mt19937 mt{ std::random_device{}() };
	std::shuffle(cardsArray.begin(), cardsArray.end(), mt);
}

int getCardValue(const Card& card)
{
	switch (card.rank)
	{
	case Rank::two:		return 2;
	case Rank::three:	return 3;
	case Rank::four:	return 4;
	case Rank::five:	return 5;
	case Rank::six:		return 6;
	case Rank::seven:	return 7;
	case Rank::eight:	return 8;
	case Rank::nine:	return 9;
	case Rank::ten:		return 10;
	case Rank::jack:	return 10;
	case Rank::queen:	return 10;
	case Rank::king:	return 10;
	case Rank::ace:		return 11;
	default:			break;
	}
}