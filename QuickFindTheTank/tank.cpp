#include "tank.h"

tank::tank(int _x, int _y, float _speed)
	:x(_x),y(_y),speed(_speed)
{
	if (!tank_texture.loadFromFile("tank.png"))
	{
		std::cout << "l'image tank.png n'a pas pu etre chargee" << std::endl;
	}
	if (!turret_texture.loadFromFile("turret.png"))
	{
		std::cout << "l'image turret.png n'a pas pu etre chargee" << std::endl;
	}
	turret_sprite.setTexture(turret_texture);
	turret_sprite.setOrigin(18,20); //on définie le centre de la tourelle
	turret_sprite.setPosition(x, y); //on positionne la tourelle par rapport au centre du tank
	tank_sprite.setTexture(tank_texture);
	tank_sprite.setPosition(x, y);
	tank_sprite.setOrigin(31, 45); //on définie le centre de l'image du tank
}

void tank::move_u(float time)
{
	tank_sprite.setRotation(0);
	y = y - (speed * time);
	tank_sprite.setPosition(x, y);
}

void tank::move_d(float time)
{
	tank_sprite.setRotation(180); //on tourne le tank
	y = y + (speed * time);
	tank_sprite.setPosition(x, y);
}

void tank::move_l(float time)
{
	tank_sprite.setRotation(270); //on tourne le tank
	x = x - (speed * time);
	tank_sprite.setPosition(x, y);
}

void tank::move_r(float time)
{
	tank_sprite.setRotation(90); //on tourne le tank
	x = x + (speed * time);
	tank_sprite.setPosition(x, y);
}

sf::Sprite tank::get_sprite_tank()
{
	return tank_sprite;
}

sf::Sprite tank::get_sprite_turret()
{
	return turret_sprite;
}

int tank::get_x()
{
	return x;
}

int tank::get_y()
{
	return y;
}

float tank::get_speed()
{
	return speed;
}

void tank::turret(sf::Vector2i souris) //pour actualiser la position de la tourelle
{
	turret_sprite.setPosition(x, y);
	float angle = atan2((souris.y - y), (souris.x - x)) * 180 / 3.141592654;
	turret_sprite.setRotation(angle);
}