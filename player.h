#pragma once
#include "deck.h"

class Player:public Deck
{
	private:

		int currentPlayer = 0;
		//int length;		
		const int HANDSIZE = 8;
		//vector<vector<Deck>> playersHand;
		
		vector<Player> players;
		



	public:
	//	void comer();  
	//	void jugar();
		Player();
		~Player(){}
		vector<vector<Card>> playersHand(int , vector<Card>());
		vector<vector<Card>> dealCards();
		vector<Card> reparteMazo();
		
	/*	Card getCard(int) const;
		bool addCard(const Sprite&, int x, int y);
		Card* removeCard(int, bool);
		int getNoOfCards() const;*/
	
	private:
		bool isValidIndex(int) const;
		void reSize(int);
		

};
