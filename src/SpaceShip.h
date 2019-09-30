#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include <SFML/Graphics.hpp>

class SpaceShip {

public:
	SpaceShip();
	virtual ~SpaceShip();
	void onEvent(sf::Event& event);
	void draw(sf::RenderWindow& w);
private:
	int x,y;
	sf::ConvexShape ship;

};

#endif
