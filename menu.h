#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class Menu {
public:
    Menu();
    void run();
    void processEvents();
    void render();
private:

    std::vector<sf::Sprite> cards;  
    const int width = 1722, height = 856;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Font font;
    sf::Text JvsJ;
    sf::Text JvsIA;
    sf::Text exitText;
    bool isPlaying;

  
};
