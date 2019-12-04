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
}


void Game::setnBunkers(int n)
{
	bunkers = n;
}

Spaceship Game::returnship(){
	return ship;
}

void Game::setnFuels(int n)
{
	fuels = n;
}


void Game::setShip(Spaceship& s)
{
	ship = s;
}


int Game::Run(sf::RenderWindow &window)
{
	// 3 is the int value of planet-completed
	cout << "bunkers: " << bunkers << "  Fuels: " << fuels;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Escape)
					return 0;
				if (event.key.code == Keyboard::K)
					return 3;
			}
			ship.direction(event);
			ship.ifShooting(event);
		}
		int rightorleft = ship.move(window);
		ship.shoot();
		window.clear();
		ship.draw(window);
		ship.drawBullets(window);
		terraforming(window, rightorleft);
		draw(window);
		window.display();
	}
	return 0;
}


void Game::terraforming(sf::RenderWindow& w, int rightorleft){
	/* rightorleft is
	 * 1 if ship goes over right-window border
	 * -1 if ship goes over left-window border
	 * (check spaceship::move function) */
	if(fuels == 0 and bunkers == 0 and !fullview){
		if (Lines->next == NULL){
			Lines->next = sxpointer;
			sxpointer->prev = Lines;
		} else {
			Lines->prev = dxpointer;
			dxpointer->next = Lines;
		}
		fullview = true;
	}
	if (rightorleft == 1) {
		if (Lines->next == NULL) {
			Lines->next = new LinesList;
			Lines->next->prev = Lines;
			Lines->next->Bunkers = new BunkerList;
			Lines->next->Fuels = new FuelList;
			Lines->next->next = NULL;
		}
		Lines = Lines->next;
		if(fuels != 0 or bunkers != 0) dxpointer = Lines;
	} else if (rightorleft == -1) {
		if (Lines->prev == NULL) {
			Lines->prev = new LinesList;
			Lines->prev->next = Lines;
			Lines->prev->Bunkers = new BunkerList;
			Lines->prev->Fuels = new FuelList;
			Lines->prev->prev = NULL;
		}
		Lines = Lines->prev;
		if(fuels != 0 or bunkers != 0) sxpointer = Lines;
	}

	if (Lines->isdraw == false) {
		Lines->isdraw = true;
		x = 0;
		if (setup) {
			y = w.getSize().y - 100;
			setup = false;
		}
		unsigned int y2;
		int finaly;
		ptrfuels f = Lines->Fuels;
		ptrbunkers b = Lines->Bunkers;
		Lines->lines.setPrimitiveType(sf::Lines);
		srand(time(0));
		while (x < w.getSize().x) {
			Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
			int perclines = (rand() % 100) + 1;
			int percbunker = (rand() % 100) + 1;
			int percfuel = (rand() % 100) + 1;
			int fueltype = 1;
			int bunkertype = 1;
			y2 = y;
			if (x == w.getSize().x - 40)
				x += 39;
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
			Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
			if (y-y2 < 0)
				finaly = -(y-y2);
			else
				finaly = y-y2;
			if (percfuel < 10) {
				if (fuels > 0) {
					f->fuel.settype(fueltype);
					if (fueltype == 2)
						fueltype --;
					else
						fueltype++;
					f->fuel.position(x-20,y-finaly/2);
					if (y != y2) {
						if (y<y2)
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
			else if (percbunker < 10) {
				if (bunkers > 0) {
					b->bunker.settype(bunkertype);
					if (bunkertype == 2)
						bunkertype--;
					else
						bunkertype++;
					b->bunker.position(x - 20, y - finaly / 2);
					if (y != y2) {
						if (y < y2)
							b->bunker.rotation(atan2(10,finaly)*180 / 3.141592 +180);
						else
							b->bunker.rotation(atan2(10,finaly)*180 / 3.141592);
					}
					b->bunker.drawing();
					b->next = new BunkerList;
					b->next->prev = b;
					b = b->next;
					bunkers--;
				}
			}
			if (x == w.getSize().x - 1)
				x++;
			if(y == w.getSize().y - 1)
				y++;
		}
	}
}


void Game::draw(sf::RenderWindow& w)
{
	ptrfuels f = Lines->Fuels;
	ptrbunkers b = Lines->Bunkers;
	while (f->fuel.isdraw == true) {
		f->fuel.draw(w);
		f = f->next;
	}
	while (b->bunker.isdraw == true) {
		b->bunker.draw(w);
		b = b->next;
	}
	w.draw(Lines->lines);
}
