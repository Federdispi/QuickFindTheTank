#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#ifndef GAMETILE_H
#define GAMETILE_H



class GameTile
{
public:
	bool isPassable;
	bool isDestructible;
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;
	GameTile(std::string _textureName, float _x, float _y, bool _isPassable, bool _isDestructible);
	bool setUpSprite(std::string _textureName);
};

#endif // !GAMETILE_H