#pragma once
#include<SFML/Graphics.hpp>
#include <vector>

#define MAX_NUMBER_OF_ITEMS 3 //Number of items

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	
	void draw(sf::RenderWindow &window); 
	void MoveUp(); //If we want to move on the top button
	void MoveDown(); //If we want to move on the bottom button
	int GetPressedItem() { return selectedItemIndex; }
	

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	
};

