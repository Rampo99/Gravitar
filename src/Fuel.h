#ifndef FUEL_H
#define FUEL_H


#include <SFML/Graphics.hpp>


class Fuel {

public:
	Fuel();
	void draw(sf::RenderWindow& w);
	void settype(int a);
	void position(int x, int y);
	void rotation(double x);
	bool isdraw;
	bool isAlive();
	void hit();
	sf::ConvexShape getShape();
	int getType();

private:
	sf::ConvexShape benza;
	int value, health, type;

};


#endif
