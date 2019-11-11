#include "SolarSystem.h"

SolarSystem::SolarSystem() {
	bunkers = 2;
	fuels = 1;
	rightorleft = 0;
	issetup = false;
}
void SolarSystem::setGame(Game& g){
	game = g;
}
void SolarSystem::setupPlanets(){
	if(!issetup){
		alfa.setnBunkers(bunkers);
		beta.setnBunkers(bunkers+1);
		gamma.setnBunkers(bunkers+2);
		omega.setnBunkers(bunkers+3);
		bunkers++;
		alfa.setnFuels(fuels);
		beta.setnFuels(fuels+1);
		gamma.setnFuels(fuels+2);
		omega.setnFuels(fuels+3);
		alfa.circleplanet.setOrigin(10,10);
		alfa.circleplanet.setPosition(100,100);
		alfa.circleplanet.setRadius(20);
		beta.circleplanet.setOrigin(10,10);
		beta.circleplanet.setPosition(100,500);
		beta.circleplanet.setRadius(20);
		gamma.circleplanet.setOrigin(10,10);
		gamma.circleplanet.setPosition(500,100);
		gamma.circleplanet.setRadius(20);
		omega.circleplanet.setOrigin(10,10);
		omega.circleplanet.setPosition(500,500);
		omega.circleplanet.setRadius(20);
		issetup = true;
	}
}
void SolarSystem::setShip(Spaceship& s){
	ship = s;
}
int SolarSystem::checkcollide(){
	if((ship.getx() >= alfa.circleplanet.getPosition().x - 30 && ship.getx() <= alfa.circleplanet.getPosition().x + 30) && (ship.gety() >= alfa.circleplanet.getPosition().y - 30 && ship.gety() <= alfa.circleplanet.getPosition().y + 30)){
		game.setplanet(alfa);
		return 2;
	}
	if((ship.getx() >= beta.circleplanet.getPosition().x - 30 && ship.getx() <= beta.circleplanet.getPosition().x + 30) && (ship.gety() >= beta.circleplanet.getPosition().y - 30 && ship.gety() <= beta.circleplanet.getPosition().y + 30)){
		game.setplanet(beta);
		return 2;
	}
	if((ship.getx() >= omega.circleplanet.getPosition().x - 30 && ship.getx() <= omega.circleplanet.getPosition().x + 30) && (ship.gety() >= omega.circleplanet.getPosition().y - 30 && ship.gety() <= omega.circleplanet.getPosition().y + 30)){
		game.setplanet(omega);
		return 2;
	}
	if((ship.getx() >= gamma.circleplanet.getPosition().x - 30 && ship.getx() <= gamma.circleplanet.getPosition().x + 30) && (ship.gety() >= gamma.circleplanet.getPosition().y - 30 && ship.gety() <= gamma.circleplanet.getPosition().y + 30)){
		game.setplanet(gamma);
		return 2;
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
		if(checkcollide() == 2)	return checkcollide();

		window.display();
	}
	return 0;
}
