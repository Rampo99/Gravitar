#ifndef Screen_H_
#define Screen_H_

#include <SFML/Graphics.hpp>

class Screen {
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif
