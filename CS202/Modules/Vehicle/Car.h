#pragma once

#include "VehicleInterface.h"

class Car : public VehicleInterface
{

public:
	Car();
};

Car::Car()
{
	this->filename = "Images\\car.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}