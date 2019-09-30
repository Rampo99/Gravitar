#include "SpaceShip.h"

SpaceShip::SpaceShip() {
	x = 0;
	y = 0;
	ship.setFillColor(sf::Color(255,255,255));
	ship.setPointCount(4);
	ship.setPoint(0, sf::Vector2f(0,30));
	ship.setPoint(1, sf::Vector2f(30,60));
	ship.setPoint(2, sf::Vector2f(100,30));
	ship.setPoint(3, sf::Vector2f(30,0));
	ship.setPosition(683,384);
}

SpaceShip::~SpaceShip() {
}

void SpaceShip::onEvent(sf::Event& event) {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        x = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        y = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        x = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        y = -1;
}

void SpaceShip::draw(sf::RenderWindow& w){

	w.draw(ship);
}
