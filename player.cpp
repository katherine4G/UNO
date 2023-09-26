#include "player.h"

Player::Player()
{
	vector<vector<Card>> playersHand(3, vector<Card>());
}
vector<vector<Card>> Player::dealCards( )
{

    vector<Card> deck = generateDeck();
    getRandomCard(deck);

    vector<vector<Card>> playersHand(3, vector<Card>());

    for (int i = 0; i < 8; i++) {
        playersHand[0].push_back(deck[i]);
    }

    for (int i = 8; i < 16; i++) {
        playersHand[1].push_back(deck[i]);
    }

    for (int i = 16; i < 24; i++) {
        playersHand[2].push_back(deck[i]);
    }

	////////////vector<vector<Card>> playersHand = p.dealCards();
	

	// Acceder a las cartas del primer jugador   ////YO
	
	vector<Card> player1Hand = playersHand[0];
	cout << sizeof(playersHand) << ", ";

		cout << endl;
	for (const Card& card : player1Hand)
	{
		card.getNumber(); card.getColor(); card.getPosX();  card.getPosY();
		//cout << "cartas jugador 1 = " << card.getNumber() << card.getColor() << card.getPosX()<<card.getPosY()<<endl;
		cout << sizeof(player1Hand) <<", ";
	}
	cout << endl;
	// Acceder a las cartas del segundo jugador   ///IA
	vector<Card> player2Hand = playersHand[1];
	for (const Card& card : player2Hand) {
		card.getNumber(); card.getColor(); card.getPosX();  card.getPosY();
		//cout << "cartas jugador Robot = " << card.getNumber() << card.getColor() << card.getPosX() << card.getPosY() << endl;
		cout << sizeof(player2Hand) << ", ";
	}
	cout << endl;
	// Acceder a las cartas del tercer jugador  ///Jugador 2
	vector<Card> player3Hand = playersHand[2];
	for (const Card& card : player3Hand) {
		card.getNumber(); card.getColor(); card.getPosX();  card.getPosY();
		//cout << "cartas jugador 2 = " << card.getNumber() << card.getColor() << card.getPosX() << card.getPosY() << endl;
		cout << sizeof(player3Hand) << ", ";
	}
	cout << endl;

   return playersHand;
}

//vector<Card> Player::reparteMazo()
//{
//	dealCards();
//
//}

