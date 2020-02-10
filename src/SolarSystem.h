#include "Screen.h"
#include "Spaceship.h"
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include "Game.h"


#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_


class SolarSystem : public Screen {

public:
	SolarSystem(int n);
	virtual int Run(sf::RenderWindow &App);
	void setupPlanets();  // setup solarsystem planets (solarsystem view)
	int checkcollide();  // checks if spaceship collides a planet
	bool check();  // checks if planets are already completed
	bool alfacheck = true;
	bool betacheck = true;
	bool gammacheck = true;
	bool omegacheck = true;

private:
	sf::CircleShape alfa;
	sf::CircleShape beta;
	sf::CircleShape gamma;
	sf::CircleShape omega;
	int what_s_s;
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;

};

#endif
