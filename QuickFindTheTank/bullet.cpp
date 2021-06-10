#include "bullet.h"

bullet::bullet(float _x, float _y, float _speed, sf::Vector2i souris)
	:x(_x),y(_y),speed(_speed)
{
	if (!bullet_texture.loadFromFile("bullet_bill.png"))
	{
		std::cout << "l'image bullet_bill.png n'a pas pu etre chargee" << std::endl;
	}
	angle = atan2((souris.y - y), (souris.x - x)) * 180 / 3.141592654;
	speedx = cos(angle * 3.141592654 / 180) * speed;
	speedy = sin(angle * 3.141592654 / 180) * speed;
	bullet_sprite.setTexture(bullet_texture);
	bullet_sprite.setOrigin(8, 5);
	bullet_sprite.setPosition(x, y);
	bullet_sprite.setRotation(angle);
}

bullet::~bullet()
{
}

int bullet::get_x()
{
	return x;
}

int bullet::get_y()
{
	return y;
}

sf::Sprite bullet::get_sprite()
{
	return bullet_sprite;
}

void bullet::moove(float time)
{
	x = x + (speedx * time);
	y = y + (speedy * time);
	bullet_sprite.setPosition(x, y);
}