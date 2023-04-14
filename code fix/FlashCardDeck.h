#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "FlashCardDeck.h"

class FlashCardDeck
{
// a class that has the base functionality of a flash card deck
private:
	std::string cardFront;
	std::string cardBack;
public:
	FlashCardDeck();
	FlashCardDeck(std::string cardFront, std::string cardBack);
	std::string getCardFront();
	std::string getCardBack();
	void setCardFront(std::string cardFront);
	void setCardBack(std::string cardBack);
};

