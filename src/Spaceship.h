#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>


using namespace std;
using namespace sf;


#ifndef SPACESHIP_H
#define SPACESHIP_H


class Spaceship {

private:
	ConvexShape ship, hearts[5];
	bool move_left, move_up, move_right, move_down, shooting;
	double speed, ratio;
	int health;
	list<Bullet*> bullets;
	Clock clock_move, clock_canshoot;
	Time for_shooting;

public:
	int score = 0;
	int lifes = 3;
	double fuellvl = 100;
	void increasefuel();
	void addlife();
	void increasescore(int a);
	void removelife();
	Spaceship();
	void setposition(int x, int y);
	void direction(Event event);
	void ifShooting(Event event);
	void reset(); //reset spaceship movements to prevent run-time bugs.
	void shoot();
	void drawBullets(RenderWindow& window);
	int move(RenderWindow& window);
	void draw(RenderWindow& window);
	double getx();
	double gety();

};


#endif  // SPACESHIP_H
