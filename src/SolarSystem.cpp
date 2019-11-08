#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	bunkers = 2;
	fuels = 1;
	rightorleft = 0;
}

void SolarSystem::setupPlanets(){
	alfa.setnBunkers(bunkers);
	beta.setnBunkers(bunkers+1);
	gamma.setnBunkers(bunkers+2);
	omega.setnBunkers(bunkers+3);
	bunkers++;
	alfa.setnFuels(fuels);
	beta.setnFuels(fuels+1);
	gamma.setnFuels(fuels+2);
	omega.setnFuels(fuels+3);

	alfa.circleplanet.setPosition(100,100);
	alfa.circleplanet.setRadius(20);
	beta.circleplanet.setPosition(100,500);
	beta.circleplanet.setRadius(20);
	gamma.circleplanet.setPosition(500,100);
	gamma.circleplanet.setRadius(20);
	omega.circleplanet.setPosition(500,500);
	omega.circleplanet.setRadius(20);
}
void SolarSystem::setShip(Spaceship& s){
	ship = s;
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
				if(event.key.code == sf::Keyboard::P){
					return 2;
				}
			}
			ship.direction(event);
			ship.ifShooting(event);
		}
		rightorleft = ship.move(window);
		ship.shoot(bullets);
		window.clear();
		ship.draw(window);
		window.draw(alfa.circleplanet);
		window.draw(beta.circleplanet);
		window.draw(gamma.circleplanet);
		window.draw(omega.circleplanet);
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
		window.display();
	}
	return 0;
}
