#include "score.h"
#include<stdio.h>
#include <iostream>




Score::Score(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf"))
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //Handle error
	}

	score[0].setFont(font); //Font of button
	score[0].setFillColor(sf::Color::Black); //Color of button
	score[0].setString("Menu"); //Name of button
	score[0].setCharacterSize(60); //Size of button
	score[0].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 3) * 3)); //Position of button

	selectedItemIndex = 0;
}

Score::~Score()
{

}

void Score::draw(sf::RenderWindow& window) //Draw the Score
{
	window.draw(score[0]);
}
