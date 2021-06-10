#include "Menu_MAP.h"


Menu_MAP::Menu_MAP() //Load background of Menu
{
	if (!backgroundTexture.loadFromFile("background Menu.png"))
	{
		std::cout << "Erreur de chargement du fond d'ecran du menu" << std::endl;
	}
	else
		background.setTexture(backgroundTexture);
}


void Menu_MAP::drawBackground(sf::RenderWindow& window) //Draw background
{
	window.draw(background);
}