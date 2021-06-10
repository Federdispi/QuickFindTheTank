#include "tank_enemy.h"

tank_enemy::tank_enemy(int _x, int _y, float _speed)
	:x(_x), y(_y), speed(_speed)
{
	if (!tank_texture.loadFromFile("tank2.png"))
	{
		std::cout << "l'image tank.png n'a pas pu etre chargee" << std::endl;
	}
	if (!turret_texture.loadFromFile("turret2.png"))
	{
		std::cout << "l'image turret.png n'a pas pu etre chargee" << std::endl;
	}
	turret_sprite.setTexture(turret_texture);
	turret_sprite.setOrigin(18, 20); //on d�finie le centre de la tourelle
	turret_sprite.setPosition(x, y); //on positionne la tourelle par rapport au centre du tank
	tank_sprite.setTexture(tank_texture);
	tank_sprite.setPosition(x, y);
	tank_sprite.setOrigin(31, 45); //on d�finie le centre de l'image du tank
}

void tank_enemy::move_u()
{
	tank_sprite.setRotation(0);
	y = y - (speed);
	tank_sprite.setPosition(x, y);
}

void tank_enemy::move_d()
{
	tank_sprite.setRotation(180); //on tourne le tank
	y = y + (speed);
	tank_sprite.setPosition(x, y);
}

void tank_enemy::move_l()
{
	tank_sprite.setRotation(270); //on tourne le tank
	x = x - (speed);
	tank_sprite.setPosition(x, y);
}

void tank_enemy::move_r()
{
	tank_sprite.setRotation(90); //on tourne le tank
	x = x + (speed);
	tank_sprite.setPosition(x, y);
}

sf::Sprite tank_enemy::get_sprite_tank()
{
	return tank_sprite;
}

sf::Sprite tank_enemy::get_sprite_turret()
{
	return turret_sprite;
}

int tank_enemy::get_x()
{
	return x;
}

int tank_enemy::get_y()
{
	return y;
}

float tank_enemy::get_speed()
{
	return speed;
}

void tank_enemy::set_x(int _x)
{
	x = _x;
	tank_sprite.setPosition(x, y);
	turret_sprite.setPosition(x, y);
}

void tank_enemy::set_y(int _y)
{
	y = _y;
	tank_sprite.setPosition(x, y);
	turret_sprite.setPosition(x, y);
}

void tank_enemy::turret(int _x,int _y)//pour actualiser la position de la tourelle
{
	turret_sprite.setPosition(x, y);
	float angle = atan2((_y - y), (_x - x)) * 180 / 3.141592654;
	turret_sprite.setRotation(angle);
}