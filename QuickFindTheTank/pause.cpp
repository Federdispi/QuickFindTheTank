#include "pause.h"
#include<stdio.h>
#include <iostream>




Pause::Pause(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf"))
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //Handle error
	}

	pause[0].setFont(font); //Font of button
	pause[0].setFillColor(sf::Color::White); //Color of button
	pause[0].setString("PAUSE"); //Name of button
	pause[0].setCharacterSize(180); //Size of button
	pause[0].setPosition(sf::Vector2f(width / 2 - 190, height / (MAX_NUMBER_OF_ITEMS + 4) * 2)); //Position of button

	selectedItemIndex = 0;
}

Pause::~Pause()
{

}

void Pause::draw(sf::RenderWindow& window) //Draw the pause function
{
	window.draw(pause[0]);
}
