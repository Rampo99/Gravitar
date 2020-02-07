#include "Fuel.h"


Fuel::Fuel()
{
	value = 100;
	isdraw = false;
	health = 1;
}


void Fuel::settype(int a)
{
	if (type == 1)
		benza.setFillColor(sf::Color::Blue);
	else  // type == 2
		benza.setFillColor(sf::Color(255, 165, 0));
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
	if (isAlive())
		w.draw(benza);
}


bool Fuel::isAlive() {
	return health > 0;
}


void Fuel::hit()
{
	health--;
}


sf::ConvexShape Fuel::getShape()
{
	return benza;
}


int Fuel::getType()
{
	return type;
}
