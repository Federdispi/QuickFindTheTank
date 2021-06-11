#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
public:
	//sets up all the tiles
	void setUpTiles();
	//vector with all the tiles
	std::vector<std::vector<GameTile*>> tiles;
	int gridLength;
	int gridHeight;
	//constructor
	GameWorld();
};

#endif // !GAMEWORLD_H