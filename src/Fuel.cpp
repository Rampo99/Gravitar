#include "Fuel.h"


Fuel::Fuel()
{
	value = 100;
	isdraw = false;
}


void Fuel::settype(int a)
{
	benza.setFillColor(sf::Color::Blue);
	benza.setPointCount(4);
	benza.setOrigin(15, 30);
	benza.setPoint(0, sf::Vector2f(0, 0));
	benza.setPoint(1, sf::Vector2f(0, 30));
	benza.setPoint(2, sf::Vector2f(30, 30));
	benza.setPoint(3, sf::Vector2f(30, 0));
	isdraw = true;
}


void Fuel::rotation(double x)
{
	benza.rotate(x);
}


void Fuel::position(int x, int y)
{
	benza.setPosition(x,y);
}


void Fuel::draw(sf::RenderWindow& w)
{
	w.draw(benza);
}
