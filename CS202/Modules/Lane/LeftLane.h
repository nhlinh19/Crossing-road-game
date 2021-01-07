#pragma once
#include "LaneInterface.h"

class LeftLane : public LaneInterface
{
public:
	LeftLane(int x);
	void initialize();
	void update();
};

LeftLane::LeftLane(int x) : LaneInterface(x) {}

void LeftLane::initialize()
{
	srand(time(NULL));
	float speed = static_cast<float>(rand()) / RAND_MAX;
	velocity = sf::Vector2f(speed, 0);

	light.initialize(x, true);

	float lastPos = 0;
	VehicleInterface* vehicle;
	srand(static_cast<unsigned int> (time(nullptr)));
	while (lastPos < 1280) {
		vehicle = CarFactory::getRandom();
		vehicle->setVelocity(velocity);
		lastPos += (vehicles.empty() ? 0 : vehicles.back()->getSprite()->getGlobalBounds().width) + static_cast<float>(rand() % 500);
		vehicle->getSprite()->setPosition(sf::Vector2f(lastPos, x));
		vehicles.push_back(vehicle);
	}
}

void LeftLane::update()
{
	if (!vehicles.empty()) {
		float firstPos = vehicles.front()->getSprite()->getPosition().x;
		if (firstPos > 0) {
			vehicles.push_front(CarFactory::getRandom());

			float pos = firstPos - vehicles.front()->getSprite()->getGlobalBounds().width - static_cast<float>(rand() % 500);
			vehicles.front()->getSprite()->setPosition(pos, x);
			vehicles.front()->setVelocity(velocity);
		}
		if (vehicles.back()->getSprite()->getPosition().x > 1280) {
			vehicles.pop_back();
		}
	}
}