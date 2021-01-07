#pragma once

#include "../../Controllers/GameController.h"
#include "ButtonInterface.h"
class LoadGameButton : public ButtonInterface
{
public:
	LoadGameButton(float width, float height);
	void onClick();
	bool isClicked(sf::Vector2i point);
};

LoadGameButton::LoadGameButton(float width, float height) {
	rec.setSize(sf::Vector2f(width, height));

	text.setFont(*Factory::getFont());
	text.setString("Load Game");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
}

void LoadGameButton::onClick()
{
	std::cout << "sadfsadf";
}

bool LoadGameButton::isClicked(sf::Vector2i point)
{
	return rec.getGlobalBounds().contains(sf::Vector2f((float)point.x, (float)point.y));
}