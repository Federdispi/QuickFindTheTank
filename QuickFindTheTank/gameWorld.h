#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld
{
private:
	void setUpTiles();
public:
	std::vector<std::vector<GameTile*>> tiles;
	int gridLength;
	int gridHeight;
	GameWorld();
};

#endif // !GAMEWORLD_H