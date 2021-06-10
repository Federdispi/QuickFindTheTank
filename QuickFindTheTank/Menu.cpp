#include "Menu.h"
#include<stdio.h>
#include <iostream>



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("boomtankPG.ttf")) 
	{
		std::cout << "Erreur de chargement de la police d'ecriture" << std::endl; //Handle error
	}
	

	menu[0].setFont(font); //Font of button
	menu[0].setFillColor(sf::Color::Red); //Color of button
	menu[0].setString("Play"); //Name of button
	menu[0].setCharacterSize(60); //Size of button
	menu[0].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 1)); //Position of button

	menu[1].setFont(font); //Font of button
	menu[1].setFillColor(sf::Color::White); //Color of button
	menu[1].setString("Score"); //Name of button
	menu[1].setCharacterSize(60); //Size of button
	menu[1].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 2)); //Position of button

	menu[2].setFont(font); //Font of button
	menu[2].setFillColor(sf::Color::White); //Color of button
	menu[2].setString("Exit"); //Name of button
	menu[2].setCharacterSize(60); //Size of button
	menu[2].setPosition(sf::Vector2f(width / 2 - 60, height / (MAX_NUMBER_OF_ITEMS + 1) * 3)); //Position of button


	selectedItemIndex = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window) //Draw the Menu
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() //change to the top button
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() //change to the bottom button
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
