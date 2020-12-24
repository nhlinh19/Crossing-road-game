#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "../Modules/People.h"

class GameController
{
private:
	People player;
public:
	GameController();
	void start();
};

GameController::GameController()
{

}

void GameController::start() {
	sf::RenderWindow* window = Factory::getRenderWindow();

	window->clear();

	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				switch (event.text.unicode)
				{
				case sf::Keyboard::A:
					player.moveLeft();
					break;
				case sf::Keyboard::S:
					player.moveDown();
					break;
				case sf::Keyboard::W:
					player.moveUp();
					break;
				case sf::Keyboard::D:
					player.moveRight();
					break;
				default:
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.text.unicode)
				{
				case sf::Keyboard::A:
					player.moveRight();
					break;
				case sf::Keyboard::S:
					player.moveUp();
					break;
				case sf::Keyboard::W:
					player.moveDown();
					break;
				case sf::Keyboard::D:
					player.moveLeft();
					break;
				default:
					break;
				}
				break;
			defaults:
				break;
			}
		}
		window->clear();
		player.move();
		player.draw();
		sf::sleep(sf::microseconds(1000));
		window->display();
	}
	
}