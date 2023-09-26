#include "deck.h"


Deck::Deck()
{

    // Inicializar las variables miembro

    // Generar el mazo de cartas
  //  deckCards = generateDeck();
    std::vector<Card> mazo = generateDeck();
    std::vector<sf::Sprite> cardSprites;
    std::vector<sf::Texture> cardTextures;


    float cardX = 1.0f; // Posición inicial en el eje X   //100.0
    float cardY = 10.0f; // Posición inicial en el eje Y //100.0
    float cardSpacing = 80.0f; //// Espaciado entre las cartas //20.0

    // Cargar las texturas de las cartas
    for (const auto& carta : mazo)
    {
        std::string filePath = "deck/";

        if (carta.getColor() == 0)
        {
            filePath = filePath + "r" + std::to_string(carta.getNumber()) + ".png";
            cout << "color red " << endl;
        }
        else if (carta.getColor() == 1)
        {
            filePath = filePath + "y" + std::to_string(carta.getNumber()) + ".png";
            cout << "color yellow " << endl;
        }
        else if (carta.getColor() == 2)
        {
            filePath = filePath + "g" + std::to_string(carta.getNumber()) + ".png";
            cout << "color green " << endl;
        }
        else if (carta.getColor() == 3)
        {
            filePath = filePath + "b" + std::to_string(carta.getNumber()) + ".png";
            cout << "color blue " << endl;
        }
        else if (carta.getColor() == 4)
        {
            filePath = filePath + "N" + std::to_string(carta.getNumber()) + ".png";
            cout << "color wild " << endl;
        }

        Texture cardTexture;
        if (!cardTexture.loadFromFile(filePath))
        {
            cout << "Error al cargar la ruta: " << filePath << endl;
        }

        cardTextures.push_back(cardTexture);
    }

    // Crear las sprites de las cartas
    for (int i = 0; i < mazo.size(); i++)
    {
        sf::Sprite cardSprite;
        cardSprite.setTexture(cardTextures[i]);
        cardSprite.setPosition(cardX, cardY);

        cardSprites.push_back(cardSprite);

        cardX += 70.0f;  //20,0
        // cardY += 100.0f; //20.0
        cardX += cardSpacing; // Aumentar la posición en el eje X por el espaciado
    }


};
vector<Card> Deck::generateDeck() {


    vector<Card> deck;
  
   
    for (int color = 0; color <= 3; color++)
    {
        for (int number = 0; number <= 12; number++)
        {
            if (number <= 9)
            {
                Card card(number, color,0,0);
                card.setNumber(number);
                card.setColor(color);
                card.setPosX_Y(0,0);
                deck.push_back(card);

                if (number != 0)
                {
                    deck.push_back(card);
                }
            }
            else
            {
                Card card( number, color, 0, 0);
          
                card.setNumber(number);
                card.setColor(color);
                card.setPosX_Y( 0, 0);

                deck.push_back(card);
                deck.push_back(card);
            }
        }
   
    }
    //////  Agregar las cartas comodín 
    for (int color = 0; color < 4; color++)
    {
        for (int number = 13; number < 15; number++)
        {
            Card card( number, 4, 0, 0);
            card.setNumber(number);
            card.setColor(4);  //color negro (4)
            deck.push_back(card);
       
        }
    }
    //////////////////////////


    //for (int color = 0; color <= 3; color++)
    //{
    //    for (int number = 0; number <= 12; number++)
    //    {
    //        // ...
    //        deck.push_back(card);

    //        // Cargar la textura y establecer la posición de la sprite
    //        card.texture.loadFromFile("ruta_de_la_imagen.png");
    //        card.sprite.setTexture(card.texture);
    //        card.sprite.setPosition(card.getPosX(), card.getPosY());
    //    }
    //    // ...
    //}
    getRandomCard(deck);
    return deck;
}


void Deck::getRandomCard(vector<Card> &randomCards)
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        int index1 = rand() % randomCards.size();
        int index2 = rand() % randomCards.size();
        swap(randomCards[index1], randomCards[index2]);
    }
    //random_shuffle(randomCards.begin(), randomCards.end());
}

void Deck::draaw()
{
    std::vector<Card> deck = generateDeck();
    int i = 0;

    Card segundaCarta = deck[1];
    getRandomCard(deck);
    for (const auto& carta : deck) {
        std::cout << "dir " << i++ << " = " << &deck << " : " << " -  "
            << carta.getNumber() << " -  " << carta.getColor() << " : "
            << carta.getPosX() << " : " << carta.getPosY() << std::endl;

    }
    
}


    void Deck::draws(sf::RenderWindow & window)
    {
        std::vector<Card> mazo = generateDeck();
        std::vector<sf::Sprite> cardSprites;
        std::vector<sf::Texture> cardTextures;

        for (const auto& carta : mazo) {
            sf::Texture cardTexture;
            cardTexture.loadFromFile("deck/red_zero.png");
            cardTextures.push_back(cardTexture);

            sf::Sprite cardSprite(cardTexture);
            cardSprite.setPosition(100, 200);
            // Configura la posición y otros atributos del sprite según sea necesario

            cardSprites.push_back(cardSprite);
        }

        for (const auto& sprite : cardSprites) {
            window.draw(sprite);
        }
    }
	//Card card;
    /*
	std::vector<Card> mazo =generateDeck();
	int i = 0;
	//getRandomCard(mazo);
	for (const auto& carta : mazo) {

		std::cout << "dir "<< i++ << " = "<<&mazo<<" id " <<carta.Id << " : " << " -  "
			<< carta.Number  << " -  " << carta.Color << std::endl;

        cout<<"id =" << &carta.Id << endl;
        cout << "num =" << &carta.Number<< endl;
        cout << "colr =" << &carta.Color << endl;

		//c.display();
		//  cout<<i++<<" : " << &mazo << endl;
	}*/

		
vector<Card> Deck::getDeck()
{
	return deckCards;
}

void Deck::setDeck(vector<Card> deck)
{
	this->deckCards = deck;
}


