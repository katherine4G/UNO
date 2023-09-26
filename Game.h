#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Text.hpp>
#include "player.h"


class GameLogic //: public Drawable
{
	private:
		const int width = 1722, height = 856; // window's background
		int selectedItemIndex = 0;
		Text text;
		Font font;
		Sprite sprite;
		bool gameOver = false;


	public:
		GameLogic();
		~GameLogic() {}
		void displayMenu();

        void window2()
        {
            RenderWindow window(VideoMode(width, height), "UNO");
            window.setFramerateLimit(60);

            //Player p;
            Deck d;
            std::vector<Card> mazo = d.generateDeck();
           // std::vector<Card> mazo = p.dealCards();
            std::vector<sf::Sprite> cardSprites;
            std::vector<sf::Texture> cardTextures;

            float cardX = 1.0f; // Posición inicial en el eje X   //100.0
            float cardY = 10.0f; // Posición inicial en el eje Y //100.0
            float cardSpacing = 80.0f; //// Espaciado entre las cartas //20.0

            // Cargar las texturas de las cartas
            for (const auto& carta : mazo)
            {
                std::string filePath = "deck/";

                if (carta.getColor() == 0)
                {
                    filePath = filePath + "r" + std::to_string(carta.getNumber()) + ".png";
                    cout << "color red " << endl;
                }
                else if (carta.getColor() == 1)
                {
                    filePath = filePath + "y" + std::to_string(carta.getNumber()) + ".png";
                    cout << "color yellow " << endl;
                }
                else if (carta.getColor() == 2)
                {
                    filePath = filePath + "g" + std::to_string(carta.getNumber()) + ".png";
                    cout << "color green " << endl;
                }
                else if (carta.getColor() == 3)
                {
                    filePath = filePath + "b" + std::to_string(carta.getNumber()) + ".png";
                    cout << "color blue " << endl;
                }
                else if (carta.getColor() == 4)
                {
                    filePath = filePath + "N" + std::to_string(carta.getNumber()) + ".png";
                    cout << "color wild " << endl;
                }

                Texture cardTexture;
                if (!cardTexture.loadFromFile(filePath))
                {
                    cout << "Error al cargar la ruta: " << filePath << endl;
                }

                cardTextures.push_back(cardTexture);
            }

            // Crear las sprites de las cartas
            for (int i = 0; i < mazo.size(); i++)
            {
                sf::Sprite cardSprite;
                cardSprite.setTexture(cardTextures[i]);
                cardSprite.setPosition(cardX, cardY);

                cardSprites.push_back(cardSprite);

                cardX += 70.0f;  //20,0
               // cardY += 100.0f; //20.0
                cardX += cardSpacing; // Aumentar la posición en el eje X por el espaciado
            }

            while (window.isOpen())
            {
                Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == Event::EventType::Closed)
                    {
                        window.close();
                    }
                }

                window.clear();
                for (const auto& sprite : cardSprites)
                {
                    window.draw(sprite);
                }
                window.display();
            }
        }

		void windowTh();
		void addCardInPlayer(Player&, int, bool);
		int getCardSelectedID(const Player&, int, int);
		void initializePC(Player&);
		
};