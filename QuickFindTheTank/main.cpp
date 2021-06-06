#pragma one
#include <SFML/Graphics.hpp>
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
#include "tank.h"
#include <vector>


int main()
{
	int a = 0;
	float windowHeight = 1080;
	float windowWidth = 1920;
    std::string name;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuickFindTheTank Beta", sf::Style::Fullscreen);

	Menu menu(window.getSize().x, window.getSize().y);
    
	GameWorld gameWorld = GameWorld();

    Menu_MAP Menu_MAP;

    tank tank_1 = tank(500, 500, 3);


#pragma region textbox
    sf::Font boomtank;
    boomtank.loadFromFile("boomtankPG.ttf");
    TextBox textbox1(35, sf::Color::White, false);
    textbox1.setFont(boomtank);
    textbox1.setPosition({ 100, 100 });
    textbox1.setLimit(true, 50);
#pragma endregion textbox
	
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
#pragma endregion Music

    music.play(); // Play menu music
    

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
			if (event.type == sf::Event::Closed)
				window.close();
            switch (event.type)
            {
            case sf::Event::TextEntered:
                textbox1.typedOn(event);
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        if (textbox1.getText() != "") // if a name has been entered
                        {
                        name = textbox1.getText();
                        std::cout << "Bouton play enclencher" << std::endl;
                        sound.play(); // Play the start-of-game soundtrack
                        a = 1;
                        }
                        else
                        {
                            std::cout << "Bouton play enclencher" << std::endl;
                            std::cout << "Veuillez entrer un nom" << std::endl;
                        }
                        break;
                    case 1:
                        std::cout << "Bouton score enclencher" << std::endl;
						a = 2;
                        break;
                    case 2:
                        window.close();
						return 0;
                        break;
                    }
                

                    break;
                }
                break;
            
            }
		}

		window.clear();

        if(a==1)  
        {
            music.stop();
            play(gameWorld, window);
            tank_1.turret(sf::Mouse::getPosition(window));
            window.draw(tank_1.get_sprite_tank());
            window.draw(tank_1.get_sprite_turret());

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                tank_1.move_u();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                tank_1.move_d();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                tank_1.move_r();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                tank_1.move_l();
            }
        }
        else if (a == 2) 
        {
            music.stop();
            score();
        }
        else 
        {
            Menu_MAP.drawBackground(window);
            menu.draw(window);
            textbox1.drawTo(window);
        }

		window.display();
	}

    return 0;
}