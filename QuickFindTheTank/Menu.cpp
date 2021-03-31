#include "Menu.h"
#include<stdio.h>
#include <iostream>



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf")) 
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //handle error
	}
	

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setCharacterSize(60);
	menu[0].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Score");
	menu[1].setCharacterSize(60);
	menu[1].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(60);
	menu[2].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));


	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
