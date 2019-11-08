#include "Planet.h"
#include "Screen.h"
#include "Spaceship.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>

#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_

class SolarSystem : public Screen{
public:
	SolarSystem();
	virtual int Run(sf::RenderWindow &App);
	void setupPlanets();
	void setShip(Spaceship& s);
	Planet alfa;
	Planet beta;
	Planet gamma;
	Planet omega;
	Spaceship ship;
private:
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	int bunkers;
	int fuels;
	int rightorleft;
};

#endif
