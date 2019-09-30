#ifndef FUEL_H_
#define FUEL_H_

#include <SFML/Graphics.hpp>

class Fuel {
public:
	Fuel(int a);
	virtual ~Fuel();
	void draw(sf::RenderWindow& w);

private:
	sf::ConvexShape benza;
	int value, powerup;
};

#endif
