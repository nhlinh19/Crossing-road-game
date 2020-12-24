#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class VehicleInterface
{
protected:
	std::string filename = "";
	sf::Sprite *sprite = nullptr;
public:
	VehicleInterface();
	VehicleInterface(std::string filename);
	void setSource(std::string filename);
	virtual sf::Sprite getSprite() {};
};