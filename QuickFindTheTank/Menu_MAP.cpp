#include "Menu_MAP.h"


Menu_MAP::Menu_MAP()
{
	if (!backgroundTexture.loadFromFile("Ecran menu.png"))
	{
		std::cout << "Erreur de chargement du fond d'ecran du menu" << std::endl;
	}
	else
		background.setTexture(backgroundTexture);
}


void Menu_MAP::drawBackground(sf::RenderWindow& window)
{
	window.draw(background);
}