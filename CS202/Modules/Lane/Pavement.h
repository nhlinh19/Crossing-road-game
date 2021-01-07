#pragma once
#include "LaneInterface.h"

class Pavement : public LaneInterface {
public:
	void initialize();
	Pavement(int x);
	void update();
};

Pavement::Pavement(int x) : LaneInterface(x) {}

void Pavement::initialize() {
	srand(time(NULL));
	float speed = 0;
	velocity = sf::Vector2f(speed, 0);
	float lastPos = 0;
	VehicleInterface* vehicle;
	srand(static_cast<unsigned int> (time(nullptr)));
	while (lastPos < 1280) {
		vehicle = new Tree();
		vehicle->setVelocity(velocity);
		lastPos += (vehicles.empty() ? 0 : vehicles.back()->getSprite()->getGlobalBounds().width) + static_cast<float>(rand() % 350);
		vehicle->getSprite()->setPosition(sf::Vector2f(lastPos, x));
		vehicles.push_back(vehicle);
	}
}

void Pavement::update() {
}