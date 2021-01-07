#pragma once
#include <vector>
#include <deque>
#include "../Vehicle/CarFactory.h"
#include "../../Factory.h"
#include "TrafficLight.h"
#include "../People.h"

class LaneInterface
{
protected:
	std::deque<VehicleInterface*> vehicles;
	sf::RectangleShape rec;
	sf::Texture texture;
	sf::Vector2f velocity;
	int x;
	
	bool have_light = 0;
	TrafficLight light;

public:
	LaneInterface(int x);
	virtual void initialize() = 0;
	virtual void draw();
	virtual void update() = 0;

	bool checkCollision(People& p);
};

LaneInterface::LaneInterface(int x) {
	this->x = x;
}

void LaneInterface::draw() {
	sf::RenderWindow *window = Factory::getRenderWindow();
	
	this->update();
	for (auto& vehicle : vehicles) {
		vehicle->move();
		window->draw(*vehicle->getSprite());
	}
}

bool LaneInterface::checkCollision(People& p)
{
	sf::Sprite* player = p.getSprite();
	if (!rec.getGlobalBounds().intersects(player->getGlobalBounds()))
		return false;
	for (auto& vehicle : vehicles)
		if (player->getGlobalBounds().intersects(
			vehicle->getSprite()->getGlobalBounds()
			)
		)
		{
			return true;
		}
	return false;
}