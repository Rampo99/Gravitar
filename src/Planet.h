#ifndef PLANET_H_
#define PLANET_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bunker.h"
#include "Fuel.h"

struct LinesList{
	sf::VertexArray lines;
	LinesList *next;
	LinesList *prev;
};
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
typedef LinesList *ptrlines;
typedef BunkerList *ptrbunkers;
typedef FuelList *ptrfuels;

class Planet {
public:
	Planet();
	virtual ~Planet();
	void draw(sf::RenderWindow& w);
	void terraforming(ptrlines Lines, ptrbunkers Bunkers, ptrfuels Fuels, sf::RenderWindow& w);
	ptrlines Lines;
	ptrbunkers Bunkers;
	ptrfuels Fuels;
};

#endif
