#include <SFML/Graphics.hpp>

class Screen {
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};
