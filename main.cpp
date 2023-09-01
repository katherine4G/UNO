#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main() {

	//WINDOW//
	RenderWindow window(VideoMode(1444, 820), "-UNO CARDS GAME-");
	window.setFramerateLimit(60);	// definimos los frames por segundos (fps) a que correrá el programa

	//BACKGROUND//
	Texture texture;
	if (!texture.loadFromFile("deck/background.png")) {
		cout << "error al cargar textura de fondo" << endl;
		system("pause");
	}
	Sprite background(texture); //set sprite at texture

	//CARD
	//Card Card("","","",)

		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)  window.close();
			}
			window.clear();
			window.draw(background);
			window.display();
		}

	return 0;

}