#include "Game.h"
#include "Player.h"

///////////// ERROR LINNK1168     taskkill /F /IM UNO.exe ///////////////////////

#include <iostream>
#include "Menu.h"

int main() {
	Menu menu; Player p;GameLogic g;
	p.dealCards(); 
	//
	//Deck d;
//	d.draaw();
	//menu.run();
	//g.menu();
	//g.window2();

	return 0;
}




//
//int main()
//{
//
//	//setlocale(LC_ALL, "spanish");
//	
//	//Card c; 
//	// Deck d;
//	//Player p;
//	 GameLogic g; 
//	 
////	d.draaw();
//	//p.dealCards();
////	g.menu();
//	g.window2();
//
//	return 0;
//}
//	
	//d.draw();

/*		vector<Card> deck = d. generateDeck();

	if (deck.size() >= 2) {
		Card segundaCarta = deck[3];
		int number = segundaCarta.getNumber();
		int color = segundaCarta.getColor();

		cout << "Number: " << number << endl;
		cout << "Color: " << color << endl;
	}
	else {
		cout << "No hay suficientes cartas en el mazo" << endl;
	}

	std::vector<Card> mazo = d.generateDeck(); // Supongamos que tienes una función para cargar el mazo

	std::vector<sf::Texture> cardTextures;
	std::vector<sf::Sprite> cardSprites;

	loadCardTextures(mazo, cardTextures, cardSprites);*/




