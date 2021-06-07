#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class bullet
{
private:
	float x;
	float y;
	float speedx;
	float speedy;
	int speed;
	int angle;
	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
public:
	bullet(float _x, float _y, int _speed, sf::Vector2i souris);
	~bullet();
	int get_x();
	int get_y();
	sf::Sprite get_sprite();
	void moove();
};

