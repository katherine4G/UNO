#pragma once
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "card.h"
using namespace std;
using namespace sf;
/*
* DECK (CARDS TYPES)
* num= 0-1-2-3-4-5-6-7-8-9
* color= Red-Green-Blue-Yellow
* actionType=reverse-skip- Plus 2
* wildType=changeColor- Plus 4
*/
class Deck
{
private:
	string number, color, actionType, wildType;


	void getRandomCard(int&, int&);
	void addCardInPlayer(Player&, int, bool);
	int getCardSelectedID(const Player&, int, int);
	void initializePC(Player&);
	Sprite** getCardBackArray(const Sprite&, int);
	void initializeCenterCard(Card&);
	void initializePlayer(Player&);
	int announceWinner(int, int);
	int getIndexOfBars(const Card&);
	int getColorOfMouseClick(int, int);
	char getColorOfIndex(int);
	int pcAutoPlay(Player&, const Card&);
	bool changeTurn(int&, const Card&, bool);
	bool hasValidMove(Player& p, const Card& c);
public:

	Deck();
	~Deck() {}



};
Deck::Deck()
{

}
