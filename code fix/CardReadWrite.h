#pragma once

#include <iostream>
#include <fstream>
#include <string>

class CardReadWrite
{
private:
	std::string cardFront;
	std::string cardBack;
public:
	CardReadWrite();
	~CardReadWrite();
	std::string getCardFront();
	std::string getCardBack();	
	void setCardFront(std::string cardFront);
	void setCardBack(std::string cardBack);
	void printCardToFile();
	void readCardToVector();
};

