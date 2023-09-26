#include "menu.h"
#include "Game.h"

Menu::Menu() : window(sf::VideoMode(width, height), "UNO"), isPlaying(true) {
    // Cargar la textura del fondo
    backgroundTexture.loadFromFile("interfaz/menu.png");
    backgroundSprite.setTexture(backgroundTexture);

    font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

    // BOT�N de "Jugador vs jugador"
    JvsJ.setFont(font);
    JvsJ.setString("Jugador VS jugador");
    JvsJ.setCharacterSize(70);
    JvsJ.setFillColor(sf::Color::White);
    JvsJ.setPosition(450, 450);

    // BOT�N de "Jugador VS IA"
    JvsIA.setFont(font);
    JvsIA.setString("Jugador VS IA");
    JvsIA.setCharacterSize(70);
    JvsIA.setFillColor(sf::Color::White);
    JvsIA.setPosition(550, 560);

    // BOT�N de "Salir"
    salirText.setFont(font);
    salirText.setString("Salir");
    salirText.setCharacterSize(70);
    salirText.setFillColor(sf::Color::Red);
    salirText.setPosition(730, 700);

    for (int i = 0; i < 7; i++) {
        sf::Texture texture;
        texture.loadFromFile("cartas/" + std::to_string(i) + ".png");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setPosition(100 + i * 100, 200);
        cartas.push_back(sprite);
    }

}

void Menu::run() {
    while (window.isOpen() && isPlaying) {
        processEvents();
        render();
    }
}

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
                    // Acci�n para el bot�n "Jugador"
                    JvsJ.setFillColor(Color::Green);
                    // Deck();
                    GameLogic g;
                    g.window2();
                }
                if (JvsIA.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                {
                    // Acci�n para el bot�n "IA"
                    JvsIA.setFillColor(Color::Green);
                    Deck();
                   // window2();
                }

                else if (salirText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    // Acci�n para el bot�n "Salir"
                    salirText.setFillColor(Color::White);
                    isPlaying = false;
                }
            }
        }
    }
}

void Menu::update() {
    //// Actualizar el estado del men�
    //for (const auto& carta : deck)
    //{
    //    // ...
    //    // Usar la sprite en tu RenderWindow
    //    window.draw(carta.sprite);
    //}
  
}

void Menu::render() 
{
    window.clear();
    window.draw(backgroundSprite);
    window.draw(JvsJ);
    window.draw(JvsIA);
    window.draw(salirText);
    for (const auto& carta : cartas) {
        window.draw(carta);
    }
    window.display();
}