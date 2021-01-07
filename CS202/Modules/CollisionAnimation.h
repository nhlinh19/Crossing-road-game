#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "../Factory.h"

class CollisionAnimation
{
private:
    std::vector<sf::Sprite*> frames;
    const int vector_size = 9; //if size > 9 check ctor
    sf::Texture texture;
public:
    CollisionAnimation();
    void draw();
};

CollisionAnimation::CollisionAnimation()
{
    std::string filename = "././Frame0.png";
    for (int i = 0; i < vector_size; i++)
    {
        filename[filename.size() - 5] = '0' + i + 1;
        texture.loadFromFile(filename);
        frames.push_back(new sf::Sprite);
        frames[i]->setTexture(texture);
    }
}

void CollisionAnimation::draw()
{
    sf::RenderWindow *window = Factory::getRenderWindow();

    for (auto& frame : frames)
    {
        window->draw(*frame);
    }
}