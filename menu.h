#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    void run();
    void processEvents();
    void update();
    void render();
private:
 //   Deck d;
    std::vector<sf::Sprite> cartas;  //
    const int width = 1722, height = 856;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text JvsJ;
    sf::Text JvsIA;
    sf::Text salirText;
    bool isPlaying;
   /* std::vector<Card> mazo = d.generateDeck();
    std::vector<sf::Sprite> cardSprites;
    std::vector<sf::Texture> cardTextures;*/

  
};
