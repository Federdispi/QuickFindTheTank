#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


class tank
{
private:
	int x;
	int y;
	float speed;
	sf::Texture tank_texture;
	sf::Texture turret_texture;
	sf::Sprite tank_sprite;
	sf::Sprite turret_sprite;
public:
	tank(int _x, int _y, float _speed);
	void set_x(int _x);
	void set_y(int _y);
	int get_x();
	int get_y();
	float get_speed();
	sf::Sprite get_sprite_tank();
	sf::Sprite get_sprite_turret();
	void move_u(float time); //move up
	void move_d(float time); //move down
	void move_r(float time); //move right
	void move_l(float time); //move left
	void turret(sf::Vector2i souris);
};