#include "menu.h"

Menu::Menu() : window(sf::VideoMode(width, height), "UNO"), isPlaying(true) {

    backgroundTexture.loadFromFile("interfaz/menu.png");
    backgroundSprite.setTexture(backgroundTexture);

    font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

    JvsJ.setFont(font);
    JvsJ.setString("Jugador VS jugador");
    JvsJ.setCharacterSize(70);
    JvsJ.setFillColor(sf::Color::White);
    JvsJ.setPosition(450, 450);

    JvsIA.setFont(font);
    JvsIA.setString("Jugador VS IA");
    JvsIA.setCharacterSize(70);
    JvsIA.setFillColor(sf::Color::White);
    JvsIA.setPosition(550, 560);

    exitText.setFont(font);
    exitText.setString("Salir");
    exitText.setCharacterSize(70);
    exitText.setFillColor(sf::Color::Red);
    exitText.setPosition(730, 700);

    for (int i = 0; i < 7; i++) {
        sf::Texture texture;
        texture.loadFromFile("cartas/" + std::to_string(i) + ".png");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(100 + i * 100, 200);
        cards.push_back(sprite);
    }

}

void Menu::run() {
    while (window.isOpen() && isPlaying)
    {
        processEvents();
        render();
    }
}
 GameLogic game;
void Menu::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                if (JvsJ.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                {
                    JvsJ.setFillColor(Color::Green);
                   
                    game.window2();
                }
                if (JvsIA.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                {
                    JvsIA.setFillColor(Color::Green);
                 
                    game.window2();
                }

                else if (exitText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    exitText.setFillColor(Color::White);
                    isPlaying = false;
                }
            }
        }
    }
}


void Menu::render() 
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(JvsJ);
    window.draw(JvsIA);
    window.draw(exitText);
    for (const auto& carta : cards) {
        window.draw(carta);
    }
    window.display();
}