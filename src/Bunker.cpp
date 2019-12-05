#include "Bunker.h"


Bunker::Bunker() {
	isdraw = false;
	firespeed = 0;
	turrets = 0;
}


void Bunker::settype(int a)
{
	switch (a) {
	case 1:
		turrets = 1;
		firespeed = 1.5;
		break;
	case 2:
		turrets = 2;
		firespeed = 1;
		break;
	}
}


void Bunker::rotation(double x)
{
	bunker.rotate(x);
}


void Bunker::drawing()
{
	bunker.setFillColor(sf::Color::Blue);
	bunker.setPointCount(20);
	bunker.setOrigin(135,250);
	bunker.setPoint(0, sf::Vector2f(100, 100));
	bunker.setPoint(1, sf::Vector2f(100, 125));
	bunker.setPoint(2, sf::Vector2f(105, 125));
	bunker.setPoint(3, sf::Vector2f(105, 144));
	bunker.setPoint(4, sf::Vector2f(130, 144));
	bunker.setPoint(5, sf::Vector2f(130, 125));
	bunker.setPoint(6, sf::Vector2f(135, 125));
	bunker.setPoint(7, sf::Vector2f(135, 100));
	bunker.setPoint(8, sf::Vector2f(130, 100));
	bunker.setPoint(9, sf::Vector2f(130, 105));
	bunker.setPoint(10, sf::Vector2f(125, 105));
	bunker.setPoint(11, sf::Vector2f(125, 100));
	bunker.setPoint(12, sf::Vector2f(120, 100));
	bunker.setPoint(13, sf::Vector2f(120, 105));
	bunker.setPoint(14, sf::Vector2f(115, 105));
	bunker.setPoint(15, sf::Vector2f(115, 100));
	bunker.setPoint(16, sf::Vector2f(110, 100));
	bunker.setPoint(17, sf::Vector2f(110, 105));
	bunker.setPoint(18, sf::Vector2f(105, 105));
	bunker.setPoint(19, sf::Vector2f(105, 100));
	isdraw = true;
}


void Bunker::position(int x, int y)
{
	bunker.setPosition(x,y);
}


void Bunker::draw(sf::RenderWindow& w)
{
	w.draw(bunker);
}
