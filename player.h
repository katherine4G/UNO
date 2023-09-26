#pragma once
#include "deck.h"

class Player:public Deck
{
	private:

		int currentPlayer = 0;
		const int HANDSIZE = 8;
		vector<Player> players;

	public:

		Player();
		~Player(){}

		vector<vector<Card>> dealCards();
	
		vector<Card> getPlayerHand(int playerIndex);
		void player_index_hand(int playerIndex);
		
	/*	Card getCard(int) const;
		bool addCard(const Sprite&, int x, int y);
		Card* removeCard(int, bool);
		int getNoOfCards() const;*/
	
	private:

		void reSize(int);
		

};
