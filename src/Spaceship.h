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
	void setposition(int x, int y);
	void direction(Event event);
	void ifShooting(Event event);
	void shoot(list<Bullet*>& bullets);
	int move(RenderWindow& window);
	void draw(RenderWindow& window);
	double getx();
	double gety();
};


#endif  // SPACESHIP_H

