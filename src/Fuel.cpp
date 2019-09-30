#include "Fuel.h"

Fuel::Fuel(int a) {
	switch(a){
		case 1:
			benza.setFillColor(sf::Color(255,255,255));
			benza.setPointCount(4);
			benza.setPoint(0, sf::Vector2f(100,100));
			benza.setPoint(1, sf::Vector2f(100,300));
			benza.setPoint(2, sf::Vector2f(200,300));
			benza.setPoint(3, sf::Vector2f(200,100));
		break;
		case 2:
			benza.setFillColor(sf::Color(0,0,0));
			benza.setPointCount(4);
			benza.setPoint(0, sf::Vector2f(110,120));
			benza.setPoint(1, sf::Vector2f(110,170));
			benza.setPoint(2, sf::Vector2f(190,170));
			benza.setPoint(3, sf::Vector2f(190,120));
		break;
	}

	value = 100;
	powerup = 0;

}

Fuel::~Fuel() {

}

void Fuel::draw(sf::RenderWindow& w){
	w.draw(benza);
}

