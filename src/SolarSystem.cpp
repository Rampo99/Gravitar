#include "SolarSystem.h"


SolarSystem::SolarSystem(int n)
{
	sf::CircleShape alfa;
	sf::CircleShape beta;
	sf::CircleShape gamma;
	sf::CircleShape omega;
	what_s_s = n;
}


void SolarSystem::setupPlanets()
{
	Color colors[4];
	colors[0] = Color(25, 200, 80);
	colors[1] = Color(200, 80, 25);
	colors[2] = Color(80, 25, 200);
	colors[3] = Color(255, 100, 255);
	int i = what_s_s % 4;  // 4 lunghezza array colors
	if (alfacheck) {
		alfa.setRadius(50);
		alfa.setOrigin(50, 50);
		alfa.setPosition(450, 300);
		alfa.setFillColor(colors[i]);
	}
	if (betacheck) {
		beta.setRadius(50);
		beta.setOrigin(50, 50);
		beta.setPosition(450, 1080 - 300);
		beta.setFillColor(colors[i]);
	}
	if (gammacheck) {
		gamma.setRadius(50);
		gamma.setOrigin(50, 50);
		gamma.setPosition(1920 - 450, 300);
		gamma.setFillColor(colors[i]);
	}
	if (omegacheck) {
		omega.setRadius(50);
		omega.setOrigin(50, 50);
		omega.setPosition(1920 - 450, 1080 - 300);
		omega.setFillColor(colors[i]);
	}
}


bool SolarSystem::check()
{
	return !alfacheck && !betacheck && !gammacheck && !omegacheck;
}


int SolarSystem::checkcollide()
{
	/* Return int value based on which planet is visited.
	 * 0 = no planet (so no collision)
	 * 4 = alfa
	 * 5 = beta
	 * 6 = gamma
	 * 7 = omega */
	if (alfacheck)
		if ((ship.getx() >= alfa.getPosition().x - 55 && ship.getx() <= alfa.getPosition().x + 55) && (ship.gety() >= alfa.getPosition().y - 55 && ship.gety() <= alfa.getPosition().y + 55))
			return 4;  // player enters alfa

	if (betacheck)
		if ((ship.getx() >= beta.getPosition().x - 55 && ship.getx() <= beta.getPosition().x + 55) && (ship.gety() >= beta.getPosition().y - 55 && ship.gety() <= beta.getPosition().y + 55))
			return 5;  // player enters beta

	if (omegacheck)
		if((ship.getx() >= omega.getPosition().x - 55 && ship.getx() <= omega.getPosition().x + 55) && (ship.gety() >= omega.getPosition().y - 55 && ship.gety() <= omega.getPosition().y + 55))
			return 6;  // player enters omega

	if (gammacheck)
		if ((ship.getx() >= gamma.getPosition().x - 55 && ship.getx() <= gamma.getPosition().x + 55) && (ship.gety() >= gamma.getPosition().y - 55 && ship.gety() <= gamma.getPosition().y + 55))
			return 7;  // player enters gamma

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
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
			ship.direction(event);
			ship.ifShooting(event);
		}
		ship.move(window);
		ship.shoot();
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
		int tmp;
		if ((tmp = checkcollide()) != 0) {  // checkcollide must be != 0 cause 0 is value of no-collision
			return tmp;
		}
		window.display();
	}
	return 0;
}
