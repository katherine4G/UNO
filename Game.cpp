#include "game.h"

GameLogic::GameLogic() 
{
    Deck d;
  
	//reglas
 
}
Player p;
void GameLogic::window2()
{
    RenderWindow window(VideoMode(width, height), "UNO");
    window.setFramerateLimit(60);

    std::vector<Card> mazo = p.getPlayerHand(0);

    std::vector<sf::Sprite> cardSprites;
    std::vector<sf::Texture> cardTextures;

    float cardX = 1.0f; // Posición inicial en el eje X  
    float cardY = 10.0f; // Posición inicial en el eje Y 
    float cardSpacing = 80.0f; //// Espaciado entre las cartas 

    // texturas de las cartas
    for (const auto& carta : mazo)
    {
        std::string filePath = "deck/";

        if (carta.getColor() == 0)
        {
            filePath = filePath + "r" + std::to_string(carta.getNumber()) + ".png";
            //  cout << "color red " << endl;
        }
        else if (carta.getColor() == 1)
        {
            filePath = filePath + "y" + std::to_string(carta.getNumber()) + ".png";
            //  cout << "color yellow " << endl;
        }
        else if (carta.getColor() == 2)
        {
            filePath = filePath + "g" + std::to_string(carta.getNumber()) + ".png";
            //  cout << "color green " << endl;
        }
        else if (carta.getColor() == 3)
        {
            filePath = filePath + "b" + std::to_string(carta.getNumber()) + ".png";
            // cout << "color blue " << endl;
        }
        else if (carta.getColor() == 4)
        {
            filePath = filePath + "N" + std::to_string(carta.getNumber()) + ".png";
            //   cout << "color wild " << endl;
        }

        Texture cardTexture;
        if (!cardTexture.loadFromFile(filePath)) cout << "Error al cargar la ruta: " << filePath << endl;
 
        cardTextures.push_back(cardTexture);

    }

    // sprites de cada carta
    for (int i = 0; i < mazo.size(); i++)
    {
        sf::Sprite cardSprite;
        cardSprite.setTexture(cardTextures[i]);
        cardSprite.setPosition(cardX, cardY);

        cardSprites.push_back(cardSprite);

        cardX += 70.0f;  
        // cardY += 100.0f; 
        cardX += cardSpacing; 
    }

    // segudno jugador
    std::vector<Card> mazo2 = p.getPlayerHand(1);

    std::vector<sf::Sprite> cardSprites2;
    std::vector<sf::Texture> cardTextures2;

    float cardX2 = 1.0f;
    float cardY2 = 600.0f; 
    float cardSpacing2 = 80.0f;
    for (const auto& carta : mazo2)
    {
        std::string filePath = "deck/";

        if (carta.getColor() == 0)
        {
            filePath = filePath + "r" + std::to_string(carta.getNumber()) + ".png";
        }
        else if (carta.getColor() == 1)
        {
            filePath = filePath + "y" + std::to_string(carta.getNumber()) + ".png";
        }
        else if (carta.getColor() == 2)
        {
            filePath = filePath + "g" + std::to_string(carta.getNumber()) + ".png";
        }
        else if (carta.getColor() == 3)
        {
            filePath = filePath + "b" + std::to_string(carta.getNumber()) + ".png";
        }
        else if (carta.getColor() == 4)
        {
            filePath = filePath + "N" + std::to_string(carta.getNumber()) + ".png";
        }

        Texture cardTexture;
        if (!cardTexture.loadFromFile(filePath))
        {
            cout << "Error al cargar la ruta: " << filePath << endl;
        }

        cardTextures2.push_back(cardTexture);
    }

    // Crear las sprites de las cartas
    for (int i = 0; i < mazo2.size(); i++)
    {
        sf::Sprite cardSprite;
        cardSprite.setTexture(cardTextures2[i]);
        cardSprite.setPosition(cardX2, cardY2);

        cardSprites2.push_back(cardSprite);

        cardX2 += 70.0f;  
       // cardY2 += 90.0f; //20.0
        cardX2 += cardSpacing2;
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
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    
                }
            }

                    
        }

        window.clear(Color(190,20,78));
        for (const auto& sprite : cardSprites)
        {
            window.draw(sprite);
        }
        for (const auto& sprite : cardSprites2)
        {
            window.draw(sprite);
        }
        window.display();
    }
}

