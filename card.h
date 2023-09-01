#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Card : public Drawable { // para poder dibujar la carta
private:
	Texture faceCard, backCard;  //textura, textureblock
	Sprite sprite;
	string type;
	string color;
	string num;
	bool  upcard = false; //Descubierta//know if the card is face down

public:
	Card() {}
	~Card() {}
	Card(string typ, string colo, string n, int x, int y); //
	void setText(Texture face);
	void blockSprite(); //back card
	void showSprite();  //face card
	string Wtype();     //Whats type? normal - actionType - wildType;
	string Wcolor();
	string Wnum();
	bool statecard(); //Stade of the card  (to face or back)?
	void downCard();  //upcard=true
	virtual void draw(RenderTarget& rt, RenderStates& rs) const;
};

Card::Card(string typ, string colo, string n, int x, int y)
{
    this->type = typ;
    this->color = colo;
    this->num = n;
    sprite.setPosition(x, y);
    if (!backCard.loadFromFile("deck/UNOback.png"))
        cout << "error al cargar textura de fondo" << endl;

}
void Card::setText(Texture face)
{
    this->faceCard = face;

}
void Card::blockSprite()
{
    sprite.setTexture(backCard);
}
void Card::showSprite()
{
    sprite.setTexture(faceCard);
}
string Card::Wtype()
{
    return type;
}

string Card::Wcolor()
{
    return color;
}

string Card::Wnum()
{
    return num;
}

bool Card::statecard()
{
    return upcard;
}
void Card::downCard() {
    upcard = true;
}
void Card::draw(RenderTarget& rt, RenderStates& rs) const
{
    rt.draw(sprite, rs);
}