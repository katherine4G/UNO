#include "player.h"

Player::Player()
{
	vector<vector<Card>> playersHand(3, vector<Card>());
}

vector<Card> Player::getPlayerHand(int playerIndex) {
	vector<vector<Card>> playersHand = dealCards();

    // Verificar si el índice del jugador es válido
    if (playerIndex < 0 || playerIndex >= playersHand.size()) 
        cout << " el índice es inválido" << endl;
        

    return playersHand[playerIndex];
}

vector<vector<Card>> Player::dealCards() 
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

    return playersHand;
}

void Player::player_index_hand(int playerIndex)
{
    vector<Card> playerHand = getPlayerHand(playerIndex);

    for (const Card& card : playerHand)
    {
        card.getNumber(); card.getColor(); card.getPosX(); card.getPosY();
        // cout << "Número: " << card.getNumber() << ", Color: " << card.getColor() << ", PosX: "<< card.getPosX() << ", PosY: " << card.getPosY() << endl;
    }

}