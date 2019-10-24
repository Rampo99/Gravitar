#include "Bunker.h"

Bunker::Bunker() {
	isdraw = false;
	firespeed = 0;
	turrets = 0;
}

void Bunker::settype(int a){
	switch(a){
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
void Bunker::rotation(int x){
	bunker.rotate(x);
}
void Bunker::drawing(){
	bunker.setFillColor(sf::Color(255,255,255));
	bunker.setPointCount(20);
	bunker.setOrigin(135,250);
	bunker.setPoint(0, sf::Vector2f(100,100));
	bunker.setPoint(1, sf::Vector2f(100,150));
	bunker.setPoint(2, sf::Vector2f(110,150));
	bunker.setPoint(3, sf::Vector2f(110,250));
	bunker.setPoint(4, sf::Vector2f(160,250));
	bunker.setPoint(5, sf::Vector2f(160,150));
	bunker.setPoint(6, sf::Vector2f(170,150));
	bunker.setPoint(7, sf::Vector2f(170,100));
	bunker.setPoint(8, sf::Vector2f(160,100));
	bunker.setPoint(9, sf::Vector2f(160,110));
	bunker.setPoint(10, sf::Vector2f(150,110));
	bunker.setPoint(11, sf::Vector2f(150,100));
	bunker.setPoint(12, sf::Vector2f(140,100));
	bunker.setPoint(13, sf::Vector2f(140,110));
	bunker.setPoint(14, sf::Vector2f(130,110));
	bunker.setPoint(15, sf::Vector2f(130,100));
	bunker.setPoint(16, sf::Vector2f(120,100));
	bunker.setPoint(17, sf::Vector2f(120,110));
	bunker.setPoint(18, sf::Vector2f(110,110));
	bunker.setPoint(19, sf::Vector2f(110,100));
	isdraw = true;
}
void Bunker::position(int x, int y){
	bunker.setPosition(x,y);
}
void Bunker::draw(sf::RenderWindow& w){
	w.draw(bunker);
}

