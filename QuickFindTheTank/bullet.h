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
	float speed;
	int angle;
	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
public:
	bullet(float _x, float _y, float _speed, sf::Vector2i souris);
	~bullet();
	int get_x();
	int get_y();
	sf::Sprite get_sprite();
	void moove(float time);
};

