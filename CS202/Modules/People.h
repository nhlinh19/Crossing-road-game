#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "../Factory.h"

class People
{
private:
	std::string filename = "C:\\Users\\admin\\source\\repos\\CS202\\Debug\\game_of_throne.png";
	sf::Sprite player;
	sf::Texture playerTexture;
	sf::Vector2f velocity;
public:
	People();
	//People(std::string filename);
	//void setSource(std::string filename); //Set the character image
	void draw();
	void move();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
};

People::People() {
	playerTexture.loadFromFile(filename);
	player.setTexture(playerTexture);
}
void People::draw() {
	sf::RenderWindow* window = Factory::getRenderWindow();
	window->draw(player);
}

void People::move() {
	player.move(velocity);
}

void People::moveDown() {
	velocity.y += 1.f;
}

void People::moveUp() {
	velocity.y -= 1.f;
}

void People::moveLeft() {
	velocity.x -= 1.f;
}

void People::moveRight() {
	velocity.x += 1.f;
}