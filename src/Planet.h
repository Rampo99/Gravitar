#ifndef PLANET_H_
#define PLANET_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "Bunker.h"
#include "Fuel.h"

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


class Planet {
public:
	Planet();
	void draw(sf::RenderWindow& w);
	void setnBunkers(int n);
	void setnFuels(int n);
	void terraforming(ptrlines Lines, sf::RenderWindow& w, int rightorleft);
	ptrlines Lines;
	sf::CircleShape circleplanet;
private:
	int bunkers;
	int fuels;
};

#endif
