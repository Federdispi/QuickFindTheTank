#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#define MAX_NUMBER_OF_ITEMS 1 //Number of items

class Pause
{
public:
	Pause(float width, float height);
	~Pause();

	void draw(sf::RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text pause[MAX_NUMBER_OF_ITEMS];

};

