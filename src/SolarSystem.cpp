#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	sf::CircleShape alfa;
	alfacheck = true;
	sf::CircleShape beta;
	betacheck = true;
	sf::CircleShape gamma;
	gammacheck = true;
	sf::CircleShape omega;
	omegacheck = true;
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

int SolarSystem::checkcollide(){
	if(alfacheck)
	if((ship.getx() >= alfa.getPosition().x - 30 && ship.getx() <= alfa.getPosition().x + 30) && (ship.gety() >= alfa.getPosition().y - 30 && ship.gety() <= alfa.getPosition().y + 30)){
		return 2;
		alfacheck = false;
	}
	if(betacheck)
	if((ship.getx() >= beta.getPosition().x - 30 && ship.getx() <= beta.getPosition().x + 30) && (ship.gety() >= beta.getPosition().y - 30 && ship.gety() <= beta.getPosition().y + 30)){
		betacheck = false;
		return 2;
	}
	if(gammacheck)
	if((ship.getx() >= omega.getPosition().x - 30 && ship.getx() <= omega.getPosition().x + 30) && (ship.gety() >= omega.getPosition().y - 30 && ship.gety() <= omega.getPosition().y + 30)){
		gammacheck = false;
		return 2;
	}
	if(omegacheck)
	if((ship.getx() >= gamma.getPosition().x - 30 && ship.getx() <= gamma.getPosition().x + 30) && (ship.gety() >= gamma.getPosition().y - 30 && ship.gety() <= gamma.getPosition().y + 30)){
		omegacheck = false;
		return 2;
	}

	return 0;
}
int SolarSystem::Run(sf::RenderWindow &window){
	setupPlanets();
	if(!alfacheck && !betacheck && !gammacheck && !omegacheck) return 4;
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
		window.draw(alfa);
		window.draw(beta);
		window.draw(gamma);
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
		if(checkcollide() == 2)	return checkcollide();

		window.display();
	}
	return 0;
}
