#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Card :public Drawable
{   
   private:
        int PosX;
        int PosY;
        int Color;
        int Number;

   public:
        Card();
        ~Card(){}
        Card( int _color, int _num, int _x, int _y);  //identeficator
        void setColor(int);
        void setNumber(int);
        void setPosX_Y(int, int);   

        int getColor()const;
        int getNumber()const;
        int getPosX() const;
        int getPosY() const;

        void setTexture(Texture faceCard);
        void LockSprite();
        void UnlockSprite();

        void setSprite(const Sprite& t); //establezo la el sprite con una dirección de memoria tipo sprite.
        Sprite getSprite();
          
        bool ConsultarEstado();
        void Descubrir();
        virtual void draw(RenderTarget& rt, RenderStates rs) const;

  protected:
        sf::Sprite sprite;
        sf::Texture texture;
        Texture FaceCard, BackCard; 
        vector<Texture> faceCard, backCard;
      
        bool Upcard ; //know if the card is face down
    
};

