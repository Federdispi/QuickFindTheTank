#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include "gameWorld.h"
#include "Menu.h"
#include <iostream>
#include "play.h"
#include "score.h"
#include <string>
#include "TextBox.h"


int main()
{
	int a = 0;
	float windowHeight = 1080;
	float windowWidth = 1920;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "QuickFindTheTank Beta", sf::Style::Fullscreen);

	Menu menu(window.getSize().x, window.getSize().y);

	GameWorld gameWorld = GameWorld();

    sf::Texture bgtex;
    bgtex.loadFromFile("Ecran menu.png");

    sf::String playerInput;
    sf::Text playerText;
    sf::Font arial;
    arial.loadFromFile("arial.ttf");
    TextBox textbox1(15, sf::Color::White, false);
    textbox1.setFont(arial);
    textbox1.setPosition({ 100, 100 });
    textbox1.setLimit(true, 50);
	
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
                        if (textbox1.getText() != "") 
                        {
                        std::cout << "Bouton play enclencher" << std::endl;
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

        sf::Sprite bg;
        bg.setScale(sf::Vector2f(window.getView().getSize().x, window.getView().getSize().y));
        bg.setOrigin(sf::Vector2f(0, 0));
        bg.setTexture(bgtex, true);

		window.clear();

        window.draw(bg);
        if(a==1)  
        {
            play(gameWorld, window);
        }
        else if (a == 2) 
        {
            score();
        }
        else 
        {
            menu.draw(window);
            textbox1.drawTo(window);
        }

		window.display();
	}

    return 0;
}