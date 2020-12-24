#include <iostream>
#include <vector>
#include <string>
//#include <sfml\Graphics.hpp>
#include "Controllers/MainMenu.h"
int main()
{
    sf::RenderWindow *window = Factory::getRenderWindow();

    MainMenu menu;

  /*  sf::Texture playerTexture;
    playerTexture.loadFromFile("C:\\Users\\admin\\source\\repos\\CS202\\Debug\\game_of_throne.png");

    sf::Sprite player;
    player.setTexture(playerTexture);*/
    window->setKeyRepeatEnabled(false);
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        menu.showMenu();


        //sf::Font font;
        //font.loadFromFile("C:\\Users\\admin\\source\\repos\\CS202\\CS202\\Fonts\\arial.ttf");

        //sf::Text text;
        //text.setFont(font);
        //text.setCharacterSize(24);
        //text.setString("asdfsdf");
        //text.setFillColor(sf::Color::Red);

        //window->draw(text);

        //window->draw(player);
        window->display();
    }

    return 0;
}
