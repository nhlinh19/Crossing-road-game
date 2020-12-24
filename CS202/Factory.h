#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sfml\Graphics.hpp>
//#include "Controllers/GameController.h"

class Factory
{
private:
	static sf::RenderWindow *window;
	static sf::Font* font;

public:
	static sf::RenderWindow* getRenderWindow();
	static sf::Font* getFont();
};

sf::RenderWindow* Factory::window = nullptr;
sf::Font* Factory::font = nullptr;

sf::RenderWindow* Factory::getRenderWindow()
{
	if (nullptr == Factory::window) {
		Factory::window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Game");
	}
	return Factory::window;
}

sf::Font* Factory::getFont()
{
	if (nullptr == Factory::font) {
		Factory::font = new sf::Font();
		font->loadFromFile("C:\\Users\\admin\\source\\repos\\CS202\\CS202\\Fonts\\arial.ttf");
	}
	return font;
}