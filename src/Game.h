#include "Screen.h"
#include "Spaceship.h"
#include "Bullet.h"
#include <list>
#include <SFML/Graphics.hpp>
#include "Planet.h"

#ifndef GAME_H_
#define GAME_H_

class Game : public Screen{
public:
	Game();
	virtual int Run(sf::RenderWindow &App);
	void setplanet(Planet& pl);
	Spaceship ship;
	Planet planet;
	void setShip(Spaceship& s);
private:
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	bool doterraform = true;
};

#endif
