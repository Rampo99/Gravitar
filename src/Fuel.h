#ifndef FUEL_H_
#define FUEL_H_

#include <SFML/Graphics.hpp>

class Fuel {
public:
	Fuel();
	void draw(sf::RenderWindow& w);
	void settype(int a);
	void position(int x, int y);
	bool isdraw;
private:
	sf::ConvexShape benza;
	int value;
};

#endif
