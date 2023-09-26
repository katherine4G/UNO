#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
	Menu show;
	show.myMenu();
	return 0;
}

	//WINDOW//
	RenderWindow window(VideoMode(1444, 820), "-UNO CARDS GAME-");
	window.setFramerateLimit(60);	// definimos los frames por segundos (fps) a que correrá el programa





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


}