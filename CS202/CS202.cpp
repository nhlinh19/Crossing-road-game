#include <iostream>
#include <vector>
#include <string>
#include <sfml\Graphics.hpp>
#include "Controllers/MainMenu.h"
#include "Modules/Vehicle/CarFactory.h"
#include "Controllers/PauseMenu.h"


int main()
{
    sf::RenderWindow *window = Factory::getRenderWindow();

    //MainMenu menu;
    PauseMenu menu(5);
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
        //menu.showMenu();
        menu.showMenu();
        window->display();
    }

    return 0;
}
