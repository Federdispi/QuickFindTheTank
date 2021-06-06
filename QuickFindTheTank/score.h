#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#define MAX_NUMBER_OF_ITEMS 1 //Number of items

class Score
{
public:
	Score(float width, float height);
	~Score();

	void draw(sf::RenderWindow& window);
	int GetPressedItem() { return selectedItemIndex; }


private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text score[MAX_NUMBER_OF_ITEMS];

};

