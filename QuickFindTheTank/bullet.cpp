#include "bullet.h"

bullet::bullet(float _x, float _y, float _speed, sf::Vector2i souris)
	:x(_x),y(_y),speed(_speed)
{
	if (!bullet_texture.loadFromFile("bullet_bill.png"))
	{
		std::cout << "l'image bullet_bill.png n'a pas pu etre chargee" << std::endl;
	}
	angle = atan2((souris.y - y), (souris.x - x)) * 180 / 3.141592654; //determine l'angle de la balle
	speedx = cos(angle * 3.141592654 / 180) * speed; //detrmine la vitesse sur x
	speedy = sin(angle * 3.141592654 / 180) * speed;//determine la vitesse sur y
	bullet_sprite.setTexture(bullet_texture);
	bullet_sprite.setOrigin(8, 5);
	bullet_sprite.setPosition(x, y);
	bullet_sprite.setRotation(angle);
}

bullet::~bullet()//destructeur
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

void bullet::moove() //fonction pour actualiser la position de la balle
{
	x = x + (speedx);
	y = y + (speedy);
	bullet_sprite.setPosition(x, y);
}