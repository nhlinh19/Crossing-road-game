#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class VehicleInterface
{
protected:
	std::string filename = "";
	sf::Texture* texture;
	sf::Sprite *sprite;
	sf::Vector2f velocity;
public:
	VehicleInterface();
	virtual sf::Sprite *getSprite();
	void move();
	void setVelocity(sf::Vector2f velocity);
};

VehicleInterface::VehicleInterface()
{
	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();
	velocity = sf::Vector2f(1.f, 0.f);
}
sf::Sprite *VehicleInterface::getSprite()
{
	return this->sprite;
}

void VehicleInterface::move()
{
	this->sprite->move(velocity);
}

void VehicleInterface::setVelocity(sf::Vector2f velocity) 
{
	this->velocity = velocity;
}