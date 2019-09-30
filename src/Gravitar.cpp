#include <SFML/Graphics.hpp>
#include "SpaceShip.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1366,768), "Gravitar");
    window.setFramerateLimit(60);
    SpaceShip sp;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        sp.draw(window);
        window.display();
    }

    return 0;
}
