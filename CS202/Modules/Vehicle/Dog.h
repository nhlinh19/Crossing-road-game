#pragma once

class Dog : public VehicleInterface {
public:
	Dog();
};

Dog::Dog() {
	this->filename = ".\\Debug\\dog.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
