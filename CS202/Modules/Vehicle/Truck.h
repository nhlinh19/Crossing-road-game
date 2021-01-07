#pragma once
#include "VehicleInterface.h"

class Truck : public VehicleInterface {
public:
	Truck();
};

Truck::Truck() {
	this->filename = "Images\\truck.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}