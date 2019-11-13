#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	sf::CircleShape alfa;
	sf::CircleShape beta;
	sf::CircleShape gamma;
	sf::CircleShape omega;
	Spaceship ship;
}
void SolarSystem::setShip(Spaceship& s){
	ship = s;
}
void SolarSystem::setupPlanets(){
	if(alfacheck){
		alfa.setOrigin(10,10);
		alfa.setPosition(100,100);
		alfa.setRadius(20);
	}
	if(betacheck){
		beta.setOrigin(10,10);
		beta.setPosition(100,500);
		beta.setRadius(20);
	}
	if(gammacheck){
		gamma.setOrigin(10,10);
		gamma.setPosition(500,100);
		gamma.setRadius(20);
	}
	if(omegacheck){
		omega.setOrigin(10,10);
		omega.setPosition(500,500);
		omega.setRadius(20);
	}
}
bool SolarSystem::check(){
	return (!alfacheck && !betacheck && !gammacheck && !omegacheck);
}
int SolarSystem::checkcollide(){
	if(alfacheck)
		if((ship.getx() >= alfa.getPosition().x - 30 && ship.getx() <= alfa.getPosition().x + 30) && (ship.gety() >= alfa.getPosition().y - 30 && ship.gety() <= alfa.getPosition().y + 30)){
			return 4;
		}

	if(betacheck)
		if((ship.getx() >= beta.getPosition().x - 30 && ship.getx() <= beta.getPosition().x + 30) && (ship.gety() >= beta.getPosition().y - 30 && ship.gety() <= beta.getPosition().y + 30)){
			return 5;
		}
	if(omegacheck)
		if((ship.getx() >= omega.getPosition().x - 30 && ship.getx() <= omega.getPosition().x + 30) && (ship.gety() >= omega.getPosition().y - 30 && ship.gety() <= omega.getPosition().y + 30)){
			return 6;
		}
	if(gammacheck)
		if((ship.getx() >= gamma.getPosition().x - 30 && ship.getx() <= gamma.getPosition().x + 30) && (ship.gety() >= gamma.getPosition().y - 30 && ship.gety() <= gamma.getPosition().y + 30)){
			return 7;
		}
	return 0;
}
int SolarSystem::Run(sf::RenderWindow &window){
	setupPlanets();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Escape){
					return 0;
				}

			}
			ship.direction(event);
			ship.ifShooting(event);
		}
		ship.move(window);
		ship.shoot(bullets);
		window.clear();
		ship.draw(window);
		if(alfacheck)
			window.draw(alfa);
		if(betacheck)
			window.draw(beta);
		if(gammacheck)
			window.draw(gamma);
		if(omegacheck)
			window.draw(omega);
		for(it = bullets.begin(); it != bullets.end(); ) {
			(*it)->move();
			if ((*it)->isAlive(window)) {
				(*it)->draw(window);
				it++;
			}
			else {
				delete *it;
				it = bullets.erase(it);
			}
		}
		if(checkcollide() != 0){
			ship.reset();
			return checkcollide();
		}

		window.display();
	}
	return 0;
}
