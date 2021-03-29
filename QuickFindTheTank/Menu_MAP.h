#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class Menu_MAP
{
public:
	Menu_MAP();
	void drawBackground(sf::RenderWindow& window);

private:
	sf::Texture backgroundTexture;
	sf::Sprite background;
};
#endif
