#include "score.h"
#include<stdio.h>
#include <iostream>




Score::Score(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf"))
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //handle error
	}

	score[0].setFont(font);
	score[0].setFillColor(sf::Color::Black);
	score[0].setString("Menu");
	score[0].setCharacterSize(60);
	score[0].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 3) * 3));

	selectedItemIndex = 0;
}

Score::~Score()
{

}

void Score::draw(sf::RenderWindow& window)
{
	window.draw(score[0]);
}
