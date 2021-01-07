#pragma once
class Police_car : public VehicleInterface {
public:
	Police_car();
};

Police_car::Police_car() {
	this->filename = "Images\\police_car.png";
	texture->loadFromFile(filename);
	this->sprite = new sf::Sprite();
	this->sprite->setTexture(*texture);
}
