#pragma once

#include "card.h"
#include <algorithm>
#include <random>
#include <SFML/Graphics.hpp>

class Deck : public Card
{
	private:
		vector<Card> deckCards;

	public:
		Deck();
		~Deck() {}
		vector<Card> generateDeck();//int, int, int
		//vector<vector<Card>> dealCards(); lo pasé a player
		vector<Card> getDeck();
		void setDeck(vector<Card>);	
		void draaw();
		void draws(sf::RenderWindow& window);
	//	void mostrarD() {}
		void getRandomCard(vector<Card> &);
	private:
		
		
		Sprite** getCardBackArray(const Sprite&, int);
		void initializeCenterCard(Card&);
};
/*			DECK (CARDS TYPES)
	____________________________________________________________
	|  0  1  2  3  4  5  6  7  8  9   10   11   12              | ---> Pos
	|( 0  11 22 33 44 55 66 77 88 99 SkSk RvRv P2P2) * 4colores | ---> Normal
	|-----------------------------------------------------------|
	| 13 13 13 13 14 14 14 14									| ---> Pos
	|(+4 +4 +4 +4 Cc Cc Cc Cc) * 1 color						| ---> Wild
	-------------------------------------------------------------
	RED=0 - YELLOW=1 - GREEN=2 - BLUE=3 - BLACK=4

	col(doble*norm)-!doble  + black(Wild)
	4(2x13) -4 +  1(2 x 4)) = 100 -4 + 8   = 108 cartas   */