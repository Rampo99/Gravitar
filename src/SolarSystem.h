#include "Screen.h"
#include "Spaceship.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include "Game.h"
#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_

class SolarSystem : public Screen{
public:
	SolarSystem();
	virtual int Run(sf::RenderWindow &App);
	void setupPlanets();
	void setShip(Spaceship& s);
	int checkcollide();

private:
	sf::CircleShape alfa;
	bool alfacheck;
	sf::CircleShape beta;
	bool betacheck;
	sf::CircleShape gamma;
	bool gammacheck;
	sf::CircleShape omega;
	bool omegacheck;
	Spaceship ship;
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
};

#endif
