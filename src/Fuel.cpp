#include "Fuel.h"


Fuel::Fuel()
{
	value = 100;
	isdraw = false;
}


void Fuel::settype(int a)
{
	switch (a) {
	case 1:
		benza.setFillColor(sf::Color(255,255,255));
		benza.setPointCount(4);
		benza.setOrigin(150,300);
		benza.setPoint(0, sf::Vector2f(100,100));
		benza.setPoint(1, sf::Vector2f(100,300));
		benza.setPoint(2, sf::Vector2f(200,300));
		benza.setPoint(3, sf::Vector2f(200,100));
		break;
	case 2:
		benza.setFillColor(sf::Color(0,0,0));
		benza.setPointCount(4);
		benza.setOrigin(150,170);
		benza.setPoint(0, sf::Vector2f(110,120));
		benza.setPoint(1, sf::Vector2f(110,170));
		benza.setPoint(2, sf::Vector2f(190,170));
		benza.setPoint(3, sf::Vector2f(190,120));
		break;
	}
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
