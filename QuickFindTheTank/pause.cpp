#include "pause.h"
#include<stdio.h>
#include <iostream>




Pause::Pause(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf"))
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //handle error
	}

	pause[0].setFont(font);
	pause[0].setFillColor(sf::Color::White);
	pause[0].setString("PAUSE");
	pause[0].setCharacterSize(180);
	pause[0].setPosition(sf::Vector2f(width / 2 - 80, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	selectedItemIndex = 0;
}

Pause::~Pause()
{

}

void Pause::draw(sf::RenderWindow& window)
{
	window.draw(pause[0]);
}
