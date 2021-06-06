#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class bullet
{
private:
	int x;
	int y;
	int speed;
	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
public:
	bullet(int _x, int _y, int _speed);
	int get_x();
	int get_y();
	void moove(int x, int y, int angle, sf::Vector2i souris);
};

