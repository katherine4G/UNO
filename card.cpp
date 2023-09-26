#include "card.h"

Card::Card()
{
	PosX = 0;
	PosY = 0;
	Color = 0;
	Number = 0;
	Upcard = false; //know if the card is face down

}

Card::Card(int _num,int _color,int _x,int _y)
{
	this->Number = _num;
	this->Color = _color;
	this->PosX = _x;
	this->PosY = _y;
	sprite.setPosition((int)_x,(int) _y);

	if (!BackCard.loadFromFile("deck/backUNO.png"))
	{
		cout << "Error al cargar textura trasera" << endl;
	}

}

//setters
void Card::setNumber(int _num) { Number = _num; }
void Card::setColor(int _color) { Color = _color; }
void Card::setPosX_Y(int x, int y)
{
	PosX = x;
	PosY = y;
	sprite.setPosition(Vector2f(x, y));
}

//getters
int Card::getNumber() const { return Number; }
int Card::getColor() const { return Color; }
int Card::getPosX() const { return PosX; }
int Card::getPosY() const { return PosY; }

void Card::setTexture(Texture faceCard)
{
	FaceCard = faceCard;
}
void Card::setSprite(const Sprite& s) 
{
	sprite = s; 
}

void Card::LockSprite()
{
	sprite.setTexture(BackCard);
}

void Card::UnlockSprite()
{
	sprite.setTexture(FaceCard);
}

Sprite Card::getSprite() { return Sprite(); }


bool Card::ConsultarEstado() {
	return Upcard;
}
void Card::Descubrir() {
	Upcard = true;
}
void Card::draw(RenderTarget& rt, RenderStates rs) const {
	rt.draw(sprite, rs);
}
