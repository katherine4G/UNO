#include "menu.h"
#include "Game.h"

Menu::Menu() : window(sf::VideoMode(width, height), "UNO"), isPlaying(true) {
    // Cargar la textura del fondo
    backgroundTexture.loadFromFile("interfaz/menu.png");
    backgroundSprite.setTexture(backgroundTexture);

    font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

    // BOTÓN de "Jugador vs jugador"
    JvsJ.setFont(font);
    JvsJ.setString("Jugador VS jugador");
    JvsJ.setCharacterSize(70);
    JvsJ.setFillColor(sf::Color::White);
    JvsJ.setPosition(450, 450);

    // BOTÓN de "Jugador VS IA"
    JvsIA.setFont(font);
    JvsIA.setString("Jugador VS IA");
    JvsIA.setCharacterSize(70);
    JvsIA.setFillColor(sf::Color::White);
    JvsIA.setPosition(550, 560);

    // BOTÓN de "Salir"
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
                    // Acción para el botón "Jugador"
                    JvsJ.setFillColor(Color::Green);
                    // Deck();
                    GameLogic g;
                    g.window2();
                }
                if (JvsIA.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) 
                {
                    // Acción para el botón "IA"
                    JvsIA.setFillColor(Color::Green);
                    Deck();
                   // window2();
                }

                else if (salirText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
                {
                    // Acción para el botón "Salir"
                    salirText.setFillColor(Color::White);
                    isPlaying = false;
                }
            }
        }
    }
}

void Menu::update() {
    //// Actualizar el estado del menú
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