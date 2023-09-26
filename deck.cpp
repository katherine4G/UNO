#include "deck.h"


Deck::Deck()
{

};
vector<Card> Deck::generateDeck() {

    vector<Card> deck;
  
    for (int color = 0; color <= 3; color++)
    {
        for (int number = 0; number <= 12; number++)
        {
            if (number <= 9)
            {
                Card card(number, color,0,0);
                card.setNumber(number);
                card.setColor(color);
                card.setPosX_Y(0,0);
                deck.push_back(card);

                if (number != 0)
                {
                    deck.push_back(card);
                }
            }
            else
            {
                Card card( number, color, 0, 0);
          
                card.setNumber(number);
                card.setColor(color);
                card.setPosX_Y( 0, 0);

                deck.push_back(card);
                deck.push_back(card);
            }
        }
   
    }
    //comodín 
    for (int color = 0; color < 4; color++)
    {
        for (int number = 13; number < 15; number++)
        {
            Card card( number, 4, 0, 0);
            card.setNumber(number);
            card.setColor(4);  //color negro (4)
            deck.push_back(card);
       
        }
    }
    getRandomCard(deck);
    return deck;
}


void Deck::getRandomCard(vector<Card> &randomCards)
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int index1 = rand() % randomCards.size();
        int index2 = rand() % randomCards.size();
        swap(randomCards[index1], randomCards[index2]);
    }

}

vector<Card> Deck::getDeck()
{
	return deckCards;
}

void Deck::setDeck(vector<Card> deck)
{
	this->deckCards = deck;
}

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
