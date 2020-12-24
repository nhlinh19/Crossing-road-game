#pragma once

#include <string>
#include "SFML/Graphics.hpp"
#include "../../Factory.h"

class ButtonInterface
{
protected:
	sf::RectangleShape rec;
	sf::Text text;
public:
	void draw();
	virtual void onClick() {}
	virtual bool isClicked(sf::Vector2i point) = 0;
};

void ButtonInterface::draw()
{
	sf::RenderWindow* window = Factory::getRenderWindow();
	window->draw(rec);
	window->draw(text);
}