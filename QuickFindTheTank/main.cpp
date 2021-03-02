#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include "gameWorld.h"

int main()
{
	float windowHeight = 1080;
	float windowWidth = 1920;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuickFindTheTank Beta", sf::Style::Fullscreen);

	GameWorld gameWorld = GameWorld();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		for (int i = 0; i < gameWorld.gridHeight; i++) 
		{
			for (int j = 0; j < gameWorld.gridLength; j++) 
			{
				window.draw(gameWorld.tiles[i][j]->sprite);
			}
		}

		window.display();
	}
}