#pragma once

#include "VehicleInterface.h"

class Dinosaur : public VehicleInterface {
public:
	Dinosaur();
};

Dinosaur::Dinosaur() {
	this->filename = ".\\Debug\\dinosaur.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
