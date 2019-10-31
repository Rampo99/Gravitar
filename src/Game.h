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
	void setplanet(Planet pl);
private:
	Spaceship ship;
	list<Bullet*> bullets;
	list<Bullet*>::iterator it;
	Planet planet;
	bool doterraform = true;
};

#endif
