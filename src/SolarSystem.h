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
	sf::CircleShape beta;
	sf::CircleShape gamma;
	sf::CircleShape omega;
	Spaceship ship;
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	int rightorleft;

};

#endif
