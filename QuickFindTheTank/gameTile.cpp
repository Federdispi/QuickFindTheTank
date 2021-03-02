#include "gameTile.h"
GameTile::GameTile(std::string _textureName, float _x, float _y, bool _isPassable, bool _isDestructible)
	:isPassable(_isPassable), isDestructible(_isDestructible)
{
	if (!setUpSprite(_textureName))
		return;
	pos = sf::Vector2f(_x, _y);
	sprite.setPosition(pos);
}
bool GameTile::setUpSprite(std::string _textureName)
{
	if (!texture.loadFromFile(_textureName))
		return false;
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
	return true;
}