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
		vector<Card> generateDeck();
		vector<Card> getDeck();
		void setDeck(vector<Card>);	

		void getRandomCard(vector<Card> &);
	private:

		Sprite** getCardBackArray(const Sprite&, int);
		void initializeCenterCard(Card&);
};

