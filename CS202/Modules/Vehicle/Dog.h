#pragma once

class Dog : public VehicleInterface {
public:
	Dog();
};

Dog::Dog() {
	this->filename = "Images\\dog.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
