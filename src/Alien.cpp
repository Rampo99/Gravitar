#include "Alien.h"

Alien::Alien() {
	alien.setFillColor(sf::Color(255,255,255));
	alien.setPointCount(12);
	alien.setPoint(0, sf::Vector2f(100,100));
	alien.setPoint(1, sf::Vector2f(100,150));
	alien.setPoint(2, sf::Vector2f(110,150));
	alien.setPoint(3, sf::Vector2f(110,140));
	alien.setPoint(4, sf::Vector2f(120,140));
	alien.setPoint(5, sf::Vector2f(120,150));
	alien.setPoint(6, sf::Vector2f(130,150));
	alien.setPoint(7, sf::Vector2f(130,140));
	alien.setPoint(8, sf::Vector2f(140,140));
	alien.setPoint(9, sf::Vector2f(140,150));
	alien.setPoint(10, sf::Vector2f(150,150));
	alien.setPoint(11, sf::Vector2f(150,100));
}

Alien::~Alien() {
}

void Alien::draw(sf::RenderWindow& w){
	w.draw(alien);
}
