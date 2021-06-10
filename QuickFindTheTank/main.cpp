#pragma one
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "gameTile.h"
#include "gameWorld.h"
#include "Menu.h"
#include <iostream>
#include "play.h"
#include "score.h"
#include <string>
#include "TextBox.h"
#include "Menu_MAP.h"
#include <SFML/Audio.hpp>
#include "score.h"
#include "tank.h"
#include "bullet.h"
#include "tank_enemy.h"
#include <time.h>



int main()
{
    srand((unsigned int)time(0)); //rand()%6+1 pour un nombre aleatoire entre 1 et 6
    int a = 0, b = 0, c = 0, d = 0;
    float time = 0;
	float windowHeight = 1080;
	float windowWidth = 1920;
    int direction = rand() % 4 + 1;
    std::string name;
    do {
        sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuickFindTheTank Beta", sf::Style::Fullscreen);

        Menu menu(window.getSize().x, window.getSize().y); //Menu

        window.setFramerateLimit(60);

        GameWorld gameWorld = GameWorld(); //Map
        
        Menu_MAP Menu_MAP; //Menu map

        tank tank_1 = tank(480, 540, 5);

        tank_enemy tankE_1 = tank_enemy(1340, 450, 5);

        sf::Clock clock;
        sf::Clock clock2;
        sf::Clock main;

        sf::Time last_frame = main.getElapsedTime();
        sf::Time time;

        std::vector<bullet*> tablo_bullet;

        std::vector<bullet*> tablo_bulletE;
        
        //Textbox for name
#pragma region textbox
        sf::Font boomtank;
        boomtank.loadFromFile("boomtankPG.ttf");
        TextBox textbox1(35, sf::Color::White, false);
        textbox1.setFont(boomtank);
        textbox1.setPosition({ 100, 100 });
        textbox1.setLimit(true, 50);
#pragma endregion textbox 
        //Music initialization
#pragma region Music
            sf::Music music;
            if (!music.openFromFile("SOUNDTRACK TANK.ogg"))
                std::cout << "Erreur de chargement de la musique" << std::endl;

            sf::SoundBuffer buffer;
            if (!buffer.loadFromFile("Round Start.ogg"))
                std::cout << "Erreur de chargement de la bande sonore" << std::endl;
            sf::Sound sound;
            sound.setBuffer(buffer);

            sf::SoundBuffer buffer2;
            if (!buffer2.loadFromFile("Round End.ogg"))
                std::cout << "Erreur de chargement de la bande sonore" << std::endl;
            sf::Sound sound2;
            sound2.setBuffer(buffer2);

            sf::SoundBuffer buffer3;
            if (!buffer3.loadFromFile("Game Over.ogg"))
                std::cout << "Erreur de chargement de la bande sonore" << std::endl;
            sf::Sound sound3;
            sound3.setBuffer(buffer3);

            sf::Music music2;
            if (!music2.openFromFile("Results.ogg"))
                std::cout << "Erreur de chargement de la musique" << std::endl;

            sf::Music music3;
            if (!music3.openFromFile("Menu TANK.ogg"))
                std::cout << "Erreur de chargement de la musique" << std::endl;

            sf::SoundBuffer buffer4;
            if (!buffer4.loadFromFile("shoot.ogg"))
                std::cout << "Erreur de chargement de la bande sonore" << std::endl;
            sf::Sound sound4;
            sound4.setBuffer(buffer4);
#pragma endregion Music
        
        music3.play(); // Play menu music
        

        while (window.isOpen()) {
            sf::Event event;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                textbox1.setSelected(true);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                textbox1.setSelected(false);
            }

            
            while (window.pollEvent(event)) {
                if (a == 3) // if we come from a game, reset d to 0
                {
                    a = 0; //reset
                    b = 0;
                    c = 0;
                    d = 0;
                    music3.play(); // Play menu music after a game
                    tablo_bullet.clear();
                    tablo_bulletE.clear();
                    gameWorld.setUpTiles();
                }
                
                music2.stop();


                if (event.type == sf::Event::Closed)
                    window.close();

                if (a == 0) //If we are in the Menu we can write in the textbox
                {
                    if (event.type == sf::Event::TextEntered) //If text was entered
                        textbox1.typedOn(event); //Writing in the textbox 
                }

               
                switch (event.type)
                    {
                    case sf::Event::KeyReleased: //If a key was released
                        switch (event.key.code)
                        {
                            if (d != 2) //If we are in Score, the key up and down don't have effect
                            {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                            }
                            
                        case sf::Keyboard::Enter:
                            d = 1; //d = 1 so we can't write in textbox
                            if (a == 0) //If we came from Menu
                            {
                                switch (menu.GetPressedItem())
                                {
                                case 0: //a pseudo has been written
                                    if (textbox1.getText() != "") //If a name has been entered
                                    {
                                        name = textbox1.getText();
                                        std::cout << "Bouton play enclencher" << std::endl;
                                        if (b == 0)
                                        {
                                            sound.play(); // Play the start-of-game soundtrack
                                            b = 1;
                                            music.play(); //Play game music
                                        }
                                        clock.restart();
                                        clock2.restart();
                                        main.restart();
                                        a = 1; //Play game
                                    }
                                    else
                                    {
                                        d = 0; //The name has not been written, reset from d to 0 to be able to write in the textbox
                                        std::cout << "Bouton play enclencher" << std::endl;
                                        std::cout << "Veuillez entrer un nom" << std::endl;
                                    }
                                    break;
                                case 1:
                                    std::cout << "Bouton score enclencher" << std::endl;
                                    a = 2; //Score
                                    break;
                                case 2:
                                    window.close(); //The game is closed
                                    return 0;
                                    break;
                                }
                                

                                
                            }
                            else if (a == 2) //If we came from Score 
                            {
                                    std::cout << "retour au menu" << std::endl;
                                    a = 3; //Return to the start of the program (Menu)
                            }
                            break;

                            
                        case sf::Keyboard::E:
                            if (a == 1) 
                            {
                                std::cout << "Fin de la partie" << std::endl;
                                a = 2; //Go to Score
                                d = 2; //The key up and down haven't effect
                            }
                            break;

                        }
                        break;


                    }

               
            }
      

            window.clear();
            sf::Time elapsed = clock.getElapsedTime();
            time = main.getElapsedTime() - last_frame;
            main.restart();
            if (elapsed.asSeconds() > 2)
            {
                tablo_bulletE.push_back(new bullet(tankE_1.get_x(), tankE_1.get_y(), 4, sf::Vector2i(tank_1.get_x(), tank_1.get_y()))); //tablo_bullet.pop_back sf::Vector2i(tank_1.get_x(), tank_1.get_y())
                clock.restart();
                direction = rand() % 4 + 1;
            }

            if (a == 1) //If we want to play 
            {
                music3.stop(); //Stop the music of Menu
                play(gameWorld, window); //Game map
                sf::Time elapsed2 = clock2.getElapsedTime();
                for (int z = 0; z < tablo_bullet.size(); z++)
                {
                    tablo_bullet[z]->moove();
                    if (!tablo_bullet[z]->touche)
                        window.draw(tablo_bullet[z]->get_sprite());
                    if (tablo_bullet[z]->get_sprite().getGlobalBounds().intersects(tankE_1.get_sprite_tank().getGlobalBounds()))
                    {
                        a = 2;
                        d = 2;
                    }
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tablo_bullet[z]->get_sprite().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                            {
                                if (gameWorld.tiles[i][j]->isDestructible)
                                {
                                    gameWorld.tiles[i][j]->isDestructible = false;
                                    gameWorld.tiles[i][j]->isPassable = true;
                                    if (gameWorld.tiles[i][j]->setUpSprite("ground.png"))
                                        std::cout << "Texture changee correctement" << std::endl;
                                }
                                else
                                {
                                    tablo_bullet[z]->touche = true;
                                    tablo_bullet[z]->~bullet();
                                    //tablo_bullet.erase(tablo_bullet.begin() + z);
                                }
                            }

                        }
                    }
                }
                for (int z = 0; z < tablo_bulletE.size(); z++)
                {
                    tablo_bulletE[z]->moove();
                    window.draw(tablo_bulletE[z]->get_sprite());
                    if (tablo_bulletE[z]->get_sprite().getGlobalBounds().intersects(tank_1.get_sprite_tank().getGlobalBounds()))
                    {
                        a = 2;
                        d = 2;
                    }
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tablo_bulletE[z]->get_sprite().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                            {
                                if (gameWorld.tiles[i][j]->isDestructible)
                                {
                                    gameWorld.tiles[i][j]->isDestructible = false;
                                    gameWorld.tiles[i][j]->isPassable = true;
                                    if (gameWorld.tiles[i][j]->setUpSprite("ground.png"))
                                        std::cout << "Texture changee correctement" << std::endl;
                                }
                                else
                                {
                                    tablo_bulletE[z]->~bullet();
                                    //tablo_bulletE.erase(tablo_bulletE.begin() + z);
                                    tablo_bulletE.erase(tablo_bulletE.begin() + z);
                                }
                            }
                        }
                    }
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    textbox1.setSelected(true);
                }
                tank_1.turret(sf::Mouse::getPosition(window));
                tankE_1.turret(tank_1.get_x(), tank_1.get_y());
                window.draw(tank_1.get_sprite_tank());
                window.draw(tank_1.get_sprite_turret());
                window.draw(tankE_1.get_sprite_tank());
                window.draw(tankE_1.get_sprite_turret());

                switch (direction)
                {
                case 1:
                    if(tankE_1.get_y()>120)
                        tankE_1.move_u();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tankE_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tankE_1.move_d();
                        }
                    }
                    break;
                case 2:
                    if (tankE_1.get_y() < 960)
                        tankE_1.move_d();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tankE_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tankE_1.move_u();
                        }
                    }
                    break;
                case 3:
                    if (tankE_1.get_x() < 1800)
                        tankE_1.move_r();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tankE_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tankE_1.move_l();
                        }
                    }
                    break;
                case 4:
                    if (tankE_1.get_x() > 120)
                        tankE_1.move_l();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tankE_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tankE_1.move_r();
                        }
                    }
                    break;
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    if (tank_1.get_y() > 120)
                        tank_1.move_u();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tank_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tank_1.move_d();
                        }
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    if (tank_1.get_y() < 960)
                        tank_1.move_d();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tank_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tank_1.move_u();
                        }
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (tank_1.get_x() < 1800)
                        tank_1.move_r();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tank_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tank_1.move_l();
                        }
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    if (tank_1.get_x() > 120)
                        tank_1.move_l();
                    for (int i = 0; i < gameWorld.gridHeight; i++)
                    {
                        for (int j = 0; j < gameWorld.gridLength; j++)
                        {
                            if (tank_1.get_sprite_tank().getGlobalBounds().intersects(gameWorld.tiles[i][j]->sprite.getGlobalBounds()) && !gameWorld.tiles[i][j]->isPassable)
                                tank_1.move_r();
                        }
                    }
                }


                if (tank_1.get_sprite_tank().getGlobalBounds().intersects(tankE_1.get_sprite_tank().getGlobalBounds()))
                {
                    a = 2;
                    d = 2;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if (elapsed2.asSeconds() > 2)
                    {
                        tablo_bullet.push_back(new bullet(tank_1.get_x(), tank_1.get_y(), 4, sf::Mouse::getPosition(window))); //tablo_bullet.pop_back
                        sound4.play(); // Play the shoot sound
                        clock2.restart();
                    }
                }
            }
            else if (a == 2) //If we want go to Score
            {
                music.stop(); //Stop the music of Game
                music3.stop(); //Stop the music of Menu
                while (c == 0) //Loop to start the Score music (loop necessary because otherwise the music starts late)
                {
                    music2.play(); //Music of Score
                    c = 1; //To get out of the loop
                }
                Score score(window.getSize().x, window.getSize().y); //Score
                Menu_MAP.drawBackground(window); //Score map = Menu map
                score.draw(window);
            }
            
            else //Menu Drawing
            {
                Menu_MAP.drawBackground(window);
                menu.draw(window);
                textbox1.drawTo(window);
            }

            window.display();
        }
        music.~Music();
        music2.~Music();
        music3.~Music();
        sound.~Sound();
        sound2.~Sound();
        sound3.~Sound();    
    } while (a == 3); //Loop to return to the start of the program after Score

    return 0;
}

