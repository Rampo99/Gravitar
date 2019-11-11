#include "Screen.h"
#include "Spaceship.h"
#include "Bullet.h"
#include <list>
#include <SFML/Graphics.hpp>
#include "Bunker.h"
#include "Fuel.h"
#include <ctime>
#include <math.h>

#ifndef GAME_H_
#define GAME_H_

struct BunkerList{
	Bunker bunker;
	BunkerList *next;
	BunkerList *prev;
};
struct FuelList{
	Fuel fuel;
	FuelList *next;
	FuelList *prev;
};

typedef BunkerList *ptrbunkers;
typedef FuelList *ptrfuels;

struct LinesList{
	sf::VertexArray lines;
	ptrbunkers Bunkers;
	ptrfuels Fuels;
	LinesList *next;
	LinesList *prev;
	bool isdraw = false;
};
typedef LinesList *ptrlines;

class Game : public Screen{
public:
	Game();
	virtual int Run(sf::RenderWindow &App);
	Spaceship ship;
	void setShip(Spaceship& s);
	void setnBunkers(int n);
	void setnFuels(int n);
	void terraforming(sf::RenderWindow& w, int rightorleft);
	void draw(sf::RenderWindow& w);
	ptrlines Lines;
private:
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	bool doterraform = true;
	int bunkers;
	int fuels;
};

#endif
