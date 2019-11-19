#include "Screen.h"
#include "Spaceship.h"
#include "Bullet.h"
#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>
#include "Bunker.h"
#include "Fuel.h"
#include <ctime>
#include <math.h>


#ifndef GAME_H
#define GAME_H


struct BunkerList {
	Bunker bunker;
	BunkerList *next;
	BunkerList *prev;
};


struct FuelList {
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
	bool isdraw = false;  // this is a bool check to prevent terraforming if it's already done
};


typedef LinesList *ptrlines;


class Game : public Screen{

public:
	Game();
	virtual int Run(sf::RenderWindow &App);
	Spaceship ship;
	void setShip(Spaceship& s); //Set ship from main
	void setnBunkers(int n); //set number of bunkers for current game
	void setnFuels(int n); //set number of fuels for current game
	void terraforming(sf::RenderWindow& w, int rightorleft); //creates terrain in run-time
	void draw(sf::RenderWindow& w);
	ptrlines Lines;
	unsigned int x = 0,y = 0;
	bool setup = true;

private:
	int bunkers;
	int fuels;

};


#endif
