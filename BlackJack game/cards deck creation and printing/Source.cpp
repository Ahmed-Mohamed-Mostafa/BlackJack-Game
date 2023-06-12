#include "Cards Deck.h"

namespace Constants
{
	constexpr int g_maximumScore{ 21 };
	constexpr int g_minimumDealerScore{ 17 };
}

Card pickRandomCard(const ArrayOfCards& cardsArray)
{
	static std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution randomCard{ 1 , 52 };

	return cardsArray[randomCard(mt)];
}

bool playerHit(int playerCardsSum)
{
	for (;;)
	{
		std::cout << "your current cards' total value is: " << playerCardsSum << "\n";
		std::cout << "if you want to STAND press s or if you want to HIT press h\n";
		char playerDecision{};
		std::cin >> playerDecision;
	
		if (playerDecision == 'h')
		{
			return true;
		}
		else if (playerDecision == 's')
		{
			return false;
		}
	}

}

int playerTurn(const ArrayOfCards& cardsArray)
{
	std::cout << "-------  PLAYER'S TURN  -------\n";
	int playerCardsSum{ 0 };
	playerCardsSum += getCardValue(pickRandomCard(cardsArray));
	playerCardsSum += getCardValue(pickRandomCard(cardsArray));
	for (; playerHit(playerCardsSum); )
	{
		playerCardsSum += getCardValue(pickRandomCard(cardsArray));
		if (playerCardsSum > Constants::g_maximumScore)
		{
			std::cout << "your current cards' total value is: " << playerCardsSum << "\n";
			return 0;
		}
	}
	return playerCardsSum;
}

int dealerTurn(const ArrayOfCards& cardsArray , int dealerInitialScore)
{
	std::cout << "-------  DEALER'S TURN  -------\n";
	int playerCardsSum{ dealerInitialScore };
	while (playerCardsSum < Constants::g_minimumDealerScore)
	{
		playerCardsSum += getCardValue(pickRandomCard(cardsArray));
		std::cout << "your current cards' total value is: " << playerCardsSum << "\n";
	}
	if (playerCardsSum > Constants::g_maximumScore)
	{	return 0;	}
	
	for (; playerHit(playerCardsSum); )
	{
		playerCardsSum += getCardValue(pickRandomCard(cardsArray));
		if (playerCardsSum > Constants::g_maximumScore)
		{
			std::cout << "your current cards' total value is: " << playerCardsSum << "\n";
			return 0;
		}
	}
	return playerCardsSum;
}

bool playBlackJack(const ArrayOfCards& cardsArray)
{
	int dealerInitialScore{ getCardValue(pickRandomCard(cardsArray)) };
	std::cout << "the dealer is showing " << dealerInitialScore << "\n\n";

	int playerScore{ playerTurn(cardsArray) };
	if (playerScore == 0)
	{
		return false;
	}

	int dealerScore{ dealerTurn(cardsArray , dealerInitialScore) };
	if (dealerScore == 0)
	{
		return true;
	}

	return (playerScore > dealerScore ? true : false);
}

int main()
{
	ArrayOfCards cardsArray{ createDeck() };
	shuffleDeck(cardsArray);
	printDeck(cardsArray);

	if (playBlackJack(cardsArray))
	{
		std::cout << "Player wins!\nGame over";
	}
	else 
	{
		std::cout << "Dealer wins!\nGame over";
	}
		
	return 0;
}