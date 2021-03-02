#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
private:
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> enemyPositions;
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpTiles();
public:
	std::vector<std::vector<GameTile*>> tiles;
	int gridLength;
	int gridHeight;
	GameWorld();
};

#endif // !GAMEWORLD_H