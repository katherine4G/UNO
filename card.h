#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Card :public Drawable
{ 
   public:
        Card();
        ~Card(){}
        Card( int _color, int _num, int _x, int _y);  //identeficator, color, number,x,y
        void setColor(int);
        void setNumber(int);
        void setPosX_Y(int, int);  //estblecer la posicion de c/u     

        int getColor()const;
        int getNumber()const;
        int getPosX() const;
        int getPosY() const;

       void setTexture(Texture faceCard);
        void LockSprite();
        void UnlockSprite();

        void setSprite(const Sprite& t); //establezo la el sprite con una dirección de memoria tipo sprite.
        Sprite getSprite();
          
        void display();
        bool ConsultarEstado();
        void Descubrir();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;
  protected:
        sf::Sprite sprite;
        sf::Texture texture;
        Texture FaceCard, BackCard;  //textura, textureblock
        vector<Texture> faceCard, backCard;
        int PosX;
        int PosY;
        int Color;
        int Number;
        bool Upcard ; //Descubierta//know if the card is face down
    
};

