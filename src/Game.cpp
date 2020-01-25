#include "Game.h"


using namespace std;
using namespace sf;


Game::Game()
{
	Lines = new LinesList;
	Lines->next = NULL;
	Lines->prev = NULL;
	Lines->Bunkers = new BunkerList;
	Lines->Fuels = new FuelList;
	bunkers = 0;
	fuels = 0;
	sxpointer = Lines;
	dxpointer = Lines;
	fullview = false;
	nothingtodraw = false;
	singlescreen = false;
}


void Game::setnBunkers(int n)
{
	bunkers = n;
}


void Game::setnFuels(int n)
{
	fuels = n;
}


int Game::Run(sf::RenderWindow &window)
{
	// 3 is the int value of planet-completed
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape)
					window.close();
				if (event.key.code == Keyboard::K) {
					ship.setposition(window.getSize().x / 2, window.getSize().y / 2);
					ship.clearBullets();
					return 3;
				}
			}
			ship.direction(event);
			ship.ifShooting(event);
		}
		int rightorleft = ship.move(window);
		ship.shoot();
		window.clear();
		ship.draw(window);
		terraforming(window, rightorleft);
		draw(window);
		window.display();
		checkCollisions();
	}
	return 0;
}


void Game::terraforming(sf::RenderWindow& w, int rightorleft) {
	/* rightorleft is
	 * 1 if ship goes over right-window border
	 * -1 if ship goes over left-window border
	 * (check spaceship::move function) */
	if (fuels == 0 and bunkers == 0 and !fullview) {
		if (Lines->next == NULL) {
			Lines->next = sxpointer;
			sxpointer->prev = Lines;
		}
		else {
			Lines->prev = dxpointer;
			dxpointer->next = Lines;
		}
		fullview = true;
	}
	if (rightorleft == 1) {
		if (!singlescreen)
			ship.clearBullets();
		if (Lines->next == NULL) {
			Lines->next = new LinesList;
			Lines->next->prev = Lines;
			Lines->next->Bunkers = new BunkerList;
			Lines->next->Fuels = new FuelList;
			Lines->next->next = NULL;
		}
		Lines = Lines->next;
		if (fuels != 0 or bunkers != 0)
			dxpointer = Lines;
	}
	else if (rightorleft == -1) {
		if (!singlescreen)
			ship.clearBullets();
		if (Lines->prev == NULL) {
			Lines->prev = new LinesList;
			Lines->prev->next = Lines;
			Lines->prev->Bunkers = new BunkerList;
			Lines->prev->Fuels = new FuelList;
			Lines->prev->prev = NULL;
		}
		Lines = Lines->prev;
		if (fuels != 0 or bunkers != 0)
			sxpointer = Lines;
	}

	if (Lines->isdraw == false) {
		int p = 0;
		Lines->isdraw = true;
		x = 0;
		if (setup) {
			y = w.getSize().y - 100;
			setup = false;
		}
		unsigned int y2;
		int finaly;
		bool lastlinecheck = true;
		ptrfuels f = Lines->Fuels;
		ptrbunkers b = Lines->Bunkers;
		Lines->lines.setPrimitiveType(sf::Lines);
		while (x < w.getSize().x) {
			Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Green));
			int perclines = (rand() % 100) + 1;
			int percbunker = (rand() % 100);
			int percfuel = (rand() % 100);
			int fueltype = 1;
			int bunkertype = rand() % 2 + 2;
			y2 = y;
			if (x == w.getSize().x - 40) {
				x += 39;
				if (Lines->next != NULL)
					Lines->lines.append(sf::Vertex(sf::Vector2f(x,Lines->next->lines[0].position.y), sf::Color::Green));
				if (nothingtodraw) {
					lastlinecheck = false;
					if (Lines->next == NULL)
						Lines->lines.append(sf::Vertex(sf::Vector2f(x,sxpointer->lines[0].position.y), sf::Color::Green));
					else
						Lines->lines[0].position.y = dxpointer->lines[14].position.y;
				}
			}
			else
				x += 40;
			if (y != w.getSize().y - 20) {
				if (perclines < 30) {
					if (y > 20)
						y -= 20;
				}
				else if (perclines >= 30 && perclines < 60)
					y += 20;
			}
			else
				y -= 20;
			if (lastlinecheck)
				Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Green));
			if (y - y2 < 0)
				finaly = y2 - y;
			else
				finaly = y - y2;
			if (x > 40 and x <= w.getSize().x - 40) {
				if (p == 0) {
					if (percfuel < 14) {
						if (fuels > 0) {
							f->fuel.settype(fueltype);
							if (fueltype == 2)
								fueltype --;
							else
								fueltype++;
							f->fuel.position(x - 20, y - finaly / 2.0);
							if (y != y2) {
								if (y < y2)
									f->fuel.rotation(atan2(10,finaly) * 180 / 3.141592 + 180);
								else
									f->fuel.rotation(atan2(10,finaly) * 180 / 3.141592);
							}
							f->next = new FuelList;
							f->next->prev = f;
							f = f->next;
							fuels--;
						}
					}
					else if (percbunker < 14) {
						if (bunkers > 0) {
							b->bunker.settype(bunkertype);
							if (bunkertype == 2)
								bunkertype--;
							else
								bunkertype++;
							b->bunker.position(x - 20, y - finaly / 2);
							if (y != y2) {
								if (y < y2)
									b->bunker.rotate(atan2(10,finaly) * 180 / 3.141592 + 180);
								else
									b->bunker.rotate(atan2(10,finaly) * 180 / 3.141592);
							}
							b->bunker.drawing();
							b->next = new BunkerList;
							b->next->prev = b;
							b = b->next;
							bunkers--;
						}
					}
					p++;
				}
				else
					p--;
			}
			if (bunkers == 0 and fuels == 0) {
				nothingtodraw = true;
				if (Lines->prev == NULL and Lines->next == NULL)
					singlescreen = true;
			}
			if (x == w.getSize().x - 1)
				x++;
			if (y == w.getSize().y - 1)
				y++;
		}
	}
}


void Game::draw(sf::RenderWindow& w)
{
	ptrfuels f = Lines->Fuels;
	ptrbunkers b = Lines->Bunkers;
	while (f->fuel.isdraw) {
		f->fuel.draw(w);
		f = f->next;
	}
	while (b->bunker.isdraw) {
		b->bunker.draw(w);
		b = b->next;
	}
	w.draw(Lines->lines);
}


void Game::checkCollisions()
{
	ptrbunkers b = Lines->Bunkers;
	list<Bullet>::iterator it;

	// ship colpisce bunker
	for(it = ship.bullets.begin(); it != ship.bullets.end(); ) {
		b = Lines->Bunkers;
		while (b->bunker.isdraw) {
			if (b->bunker.isAlive()) {
				if (b->bunker.getShape().getGlobalBounds().contains(it->getShape().getPosition())) {
					b->bunker.hit();
					it = ship.bullets.erase(it);
				}
			}
			b = b->next;
		}
		it++;
	}

	// ship viene colpita
	b = Lines->Bunkers;
	while (b->bunker.isdraw) {
		for(it = b->bunker.bullets.begin(); it != b->bunker.bullets.end(); ) {
			if (ship.getShape().getGlobalBounds().contains(it->getShape().getPosition())) {
				ship.hit();
				it = b->bunker.bullets.erase(it);
			}
			else
				it++;
		}
		b = b->next;
	}

	for (unsigned int i = 0; i < Lines->lines.getVertexCount() - 1; i++) {
		for (it = ship.bullets.begin(); it != ship.bullets.end(); it++) {
			if ((it->getShape().getPosition().x >= Lines->lines[i].position.x) and (it->getShape().getPosition().x <= Lines->lines[i + 1].position.x)) {
				VertexArray tmpline(sf::Lines, 2);
				tmpline[0].position = Lines->lines[i].position;
				tmpline[1].position = Lines->lines[i + 1].position;
				if (tmpline.getBounds().contains(it->getShape().getPosition()))
					it = ship.bullets.erase(it);
			}
			else
				it++;
		}
	}

}








