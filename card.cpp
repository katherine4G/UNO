#include "card.h"

Card::Card()
{
	PosX = 0;
	PosY = 0;
	Color = 0;
	Number = 0;
	Upcard = false; //Descubierta//know if the card is face down

}



Card::Card(int _num,int _color,int _x,int _y)
{
	this->Number = _num;
	this->Color = _color;
	this->PosX = _x;
	this->PosY = _y;
	sprite.setPosition((int)_x,(int) _y);

	//red cards: for (int i = 0; i < faceCard.size(); i++) faceCard[i].loadFromFile("deck/r"+to_string(i)+".png");


	std::string filePath = "deck/", r = "r", g = "g", b = "b", y = "y", N = "N";
	for (int i = 0; i < faceCard.size(); i++)
	{
		//if(!faceCard[i].loadFromFile("")) cout << "Error al cargar textura frontal" << endl;
			 if (getNumber() == i && getColor() == 0)  faceCard[i].loadFromFile(filePath + r + std::to_string(i) + ".png");
		else if (getNumber() == i && getColor() == 1)  faceCard[i].loadFromFile(filePath + y + std::to_string(i) + ".png");
		else if (getNumber() == i && getColor() == 2)  faceCard[i].loadFromFile(filePath + g + std::to_string(i) + ".png");
		else if (getNumber() == i && getColor() == 3)  faceCard[i].loadFromFile(filePath + b + std::to_string(i) + ".png");
		else if (getNumber() == 4 && getColor() == 4)  faceCard[i].loadFromFile(filePath + N + std::to_string(i) + ".png");
		getPosX();getPosY();
		

	}

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
int Card::getPosX() const { return PosX+10; }
int Card::getPosY() const { return PosY; }

void Card::setTexture(Texture faceCard) {
	FaceCard = faceCard;
}
void Card::setSprite(const Sprite& s) { sprite = s; }

void Card::LockSprite() {
	sprite.setTexture(BackCard);
}

void Card::UnlockSprite() { sprite.setTexture(FaceCard); }

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

void Card::display()
{
	cout  << " - color: " << this->Color << " - numero: " << this->Number << " - x: " << this->PosX << " - y: " << this->PosY <<endl;
}
