#pragma once

#include "VehicleInterface.h"

class Car2 : public VehicleInterface {
public:
	Car2();
};

Car2::Car2() {
	this->filename = ".\\Debug\\car2.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
