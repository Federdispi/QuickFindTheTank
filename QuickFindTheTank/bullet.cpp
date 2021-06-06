#include "bullet.h"

bullet::bullet(int _x, int _y, int _speed)
	:x(_x),y(_y),speed(_speed)
{
	if (!bullet_texture.loadFromFile("bullet_bill.png"))
	{
		std::cout << "l'image bullet_bill.png n'a pas pu etre chargee" << std::endl;
	}
	bullet_sprite.setTexture(bullet_texture);
	bullet_sprite.setOrigin(8, 5);
	bullet_sprite.setPosition(x, y);
}

int bullet::get_x()
{
	return x;
}

int bullet::get_y()
{
	return y;
}

void bullet::moove(int _x, int _y, int _angle, sf::Vector2i souris)
{
	int a = (souris.y - _y / souris.x - _x); //coefficient directeur de la droite
	x += speed;
	y = a * x;
	bullet_sprite.setRotation(_angle);
	bullet_sprite.setPosition(x, y);
}