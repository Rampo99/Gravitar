#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>

using namespace std;
using namespace sf;


#ifndef SPACESHIP_H
#define SPACESHIP_H


class Spaceship {

private:
	ConvexShape ship;
	bool move_left, move_up, move_right, move_down, shooting;
	double speed, ratio;
	Clock clock_move, clock_canshoot;
	Time for_shooting;

public:
	Spaceship();
	void direction(Event event);
	void ifShooting(Event event);
	void shoot(list<Bullet*>& bullets);
	void move();
	void draw(RenderWindow& window);
};


#endif  // SPACESHIP_H

