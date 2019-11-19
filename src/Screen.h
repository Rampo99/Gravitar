#ifndef Screen_H
#define Screen_H


#include <SFML/Graphics.hpp>


class Screen {

public :
	virtual int Run (sf::RenderWindow &App) = 0;

};


#endif
