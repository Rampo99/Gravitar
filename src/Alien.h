#ifndef ALIEN_H
#define ALIEN_H


#include <SFML/Graphics.hpp>


class Alien {

public:
	Alien();
	virtual ~Alien();
	void draw(sf::RenderWindow& w);

private:
	sf::ConvexShape alien;

};


#endif
