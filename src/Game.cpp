#include "Game.h"
using namespace std;
using namespace sf;

Game::Game() {
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	Planet planet;
	rightorleft = 0;
}
void Game::setplanet(Planet pl){
	planet = pl;
}
void Game::setShip(Spaceship& s){
	ship = s;
}
int Game::Run(sf::RenderWindow &window){
	if (doterraform) planet.terraforming(planet.Lines,window,rightorleft);
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if(event.type == Event::KeyPressed){
				if(event.key.code == Keyboard::Escape){
					doterraform = false;
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
		planet.draw(window);
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

