#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include <iterator>
#include "Spaceship.h"
#include "Bullet.h"


using namespace std;
using namespace sf;


int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(1600, 900), "Gravitar", Style::Default, settings);
	window.setKeyRepeatEnabled(false);
	Spaceship ship;
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			ship.direction(event);
			ship.ifShooting(event);
		}
		ship.move();
		ship.shoot(bullets);
		window.clear();
		ship.draw(window);
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
