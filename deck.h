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
* 
* actionType=reverse-skip- Plus 2
* wildType=changeColor- Plus 4
*/
class Deck
{
private:
	string number, color, actionType, wildType;


public:

	Deck();
	~Deck() {}



};
Deck::Deck()
{

}
