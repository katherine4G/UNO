#include "game.h"

GameLogic::GameLogic() 
{
	//define rules

}
 void GameLogic::displayMenu()
{ 
	RenderWindow window(VideoMode(width, height), "SFML window");
	window.setFramerateLimit(60);

	//Fondo
	Texture texture;
	texture.loadFromFile("interfaz/menu.png");
	Sprite fondo(texture);

	//text
	sf::Font font;
	font.loadFromFile("Fonts/BlackOpsOne-Regular.ttf");

	// Create a text
	sf::Text text("VS IA", font,90);
	//text.setCharacterSize(90);
	text.setPosition(300, 600);
	text.setStyle(sf::Text::Bold); //Regular = 0 , Bold = 1 << 0 , Italic = 1 << 1 , Underlined = 1 << 2 ,StrikeThrough = 1 << 3
	text.setFillColor(sf::Color::White);
	
	//output Text
	sf::String playerInput;
	Text playerText;// ('', font, size);

	while (window.isOpen())
	{
		Event event;
		// Procesamos la pila de eventos
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::TextEntered)
			{
				playerInput += event.text.unicode;
				playerText.setString(playerInput);
			}
			// Si el evento es de tipo Closed cerramos la ventana
			if (event.type == Event::EventType::Closed) window.close();

			
		}

		window.clear();
		window.draw(fondo);
		window.draw(text);
		

		window.draw(playerText);
		window.display();
	}

}
//////////////////////////////
 /*
 void GameLogic::windowTh()
 {
	 
	RenderWindow window(VideoMode(width, height), "SFML window");
	window.setFramerateLimit(60);

	//Fondo
	Texture texture;
	texture.loadFromFile("interfaz/fondo.jpg");
	Sprite fondo(texture);

	//CARDS
	vector<Sprite> sprites;

	Texture image, img2, img3, btn;
	image.loadFromFile("deck/red_zero.png");
	img2.loadFromFile("deck/red_one.png");
	img3.loadFromFile("deck/backUNO.png");
	btn.loadFromFile("interfaz/UNObtn.png");


	Sprite sprite, spr2, spr3, sBtn;
	sprite.setTexture(image);
	spr2.setTexture(img2);
	spr3.setTexture(img3);
	sBtn.setTexture(btn);
	//a la Sprite le agregamos su propia TExtura
	sprite.setPosition(100, 100);
	spr2.setPosition(200, 100);
	spr3.setPosition(300, 100);
	sBtn.setPosition(800, 450);
	//Cargamos el VECTOR con más datos
	sprites.push_back(sprite);
	sprites.push_back(spr2);
	sprites.push_back(spr3);
	sprites.push_back(sBtn);

	//Fic
	std::locale locale;
	sf::String s;
		std::string s1 = s.toAnsiString(locale);
	s = sf::String("hello", locale);

	while (window.isOpen())
	{
		Event event;
		// Procesamos la pila de eventos
		while (window.pollEvent(event))
		{
			// Si el evento es de tipo Closed cerramos la ventana
			if (event.type == Event::EventType::Closed) window.close();


		}

		window.clear(Color(180, 60, 95));
		window.draw(fondo);
		for (const auto& n : sprites) window.draw(n); //dibuja la sprite delvector
		window.display();
	}
 }
*/

