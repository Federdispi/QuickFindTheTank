#include "gameWorld.h"
void play(GameWorld gameWorld, sf::RenderWindow &window)
{
    for (int i = 0; i < gameWorld.gridHeight; i++)
    {
        for (int j = 0; j < gameWorld.gridLength; j++)
        {
            window.draw(gameWorld.tiles[i][j]->sprite);
        }
    }
}
