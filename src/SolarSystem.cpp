#include "SolarSystem.h"


SolarSystem::SolarSystem()
{
	sf::CircleShape alfa;
	sf::CircleShape beta;
	sf::CircleShape gamma;
	sf::CircleShape omega;
	//Spaceship ship;
}


void SolarSystem::setShip(Spaceship& s)
{
	ship = s;
}


void SolarSystem::setupPlanets()
{
	if (alfacheck) {
		alfa.setOrigin(10, 10);
		alfa.setPosition(100, 100);
		alfa.setRadius(20);
	}
	if (betacheck) {
		beta.setOrigin(10, 10);
		beta.setPosition(100, 500);
		beta.setRadius(20);
	}
	if (gammacheck) {
		gamma.setOrigin(10, 10);
		gamma.setPosition(500, 100);
		gamma.setRadius(20);
	}
	if (omegacheck) {
		omega.setOrigin(10, 10);
		omega.setPosition(500, 500);
		omega.setRadius(20);
	}
}


bool SolarSystem::check()
{
	return !alfacheck && !betacheck && !gammacheck && !omegacheck;
}


int SolarSystem::checkcollide()
{
	/* Return int value based on which planet is joined.
	 * 0 = no planet (so no collision)
	 * 4 = alfa
	 * 5 = beta
	 * 6 = gamma
	 * 7 = omega */
	if (alfacheck)
		if ((ship.getx() >= alfa.getPosition().x - 30 && ship.getx() <= alfa.getPosition().x + 30) && (ship.gety() >= alfa.getPosition().y - 30 && ship.gety() <= alfa.getPosition().y + 30))
			return 4;  // player enters alfa

	if (betacheck)
		if ((ship.getx() >= beta.getPosition().x - 30 && ship.getx() <= beta.getPosition().x + 30) && (ship.gety() >= beta.getPosition().y - 30 && ship.gety() <= beta.getPosition().y + 30))
			return 5;  // player enters beta

	if (omegacheck)
		if((ship.getx() >= omega.getPosition().x - 30 && ship.getx() <= omega.getPosition().x + 30) && (ship.gety() >= omega.getPosition().y - 30 && ship.gety() <= omega.getPosition().y + 30))
			return 6;  // player enters omega

	if (gammacheck)
		if ((ship.getx() >= gamma.getPosition().x - 30 && ship.getx() <= gamma.getPosition().x + 30) && (ship.gety() >= gamma.getPosition().y - 30 && ship.gety() <= gamma.getPosition().y + 30))
			return 7;  // plater enters gamma

	return 0; //0 = no collision
}


int SolarSystem::Run(sf::RenderWindow &window)
{
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
		ship.shoot();
		window.clear();
		ship.draw(window);
		ship.drawBullets(window);
		if(alfacheck)
			window.draw(alfa);
		if(betacheck)
			window.draw(beta);
		if(gammacheck)
			window.draw(gamma);
		if(omegacheck)
			window.draw(omega);
		if (checkcollide() != 0) {  // checkcollide must be != 0 cause 0 is value of no-collision
			ship.reset();
			return checkcollide();
		}
		window.display();
	}
	return 0;
}
