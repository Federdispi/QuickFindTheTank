#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


class tank
{
private:
	int x;
	int y;
	int speed;
	sf::Texture tank_texture;
	sf::Texture turret_texture;
	sf::Sprite tank_sprite;
	sf::Sprite turret_sprite;
public:
	tank(int _x, int _y, int _speed);
	int get_x();
	int get_y();
	sf::Sprite get_sprite_tank();
	sf::Sprite get_sprite_turret();
	void move_u(); //move up
	void move_d(); //move down
	void move_r(); //move right
	void move_l(); //move left
	void turret(sf::Vector2i souris);
};