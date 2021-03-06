#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>
#include <string>


using namespace std;
using namespace sf;


#ifndef SPACESHIP_H
#define SPACESHIP_H


class Spaceship {

private:
	ConvexShape ship, heart;
	RectangleShape fuel_border, fuel_bar, raggio;
	bool move_left, move_up, move_right, move_down, shooting, raggioon;
	double speed, ratio;
	int health, score;
	Clock move_clock, canshoot_clock, drain_fuel_clock, invulnerable_clock;
	Time for_shooting_time, fuel_bar_time, invulnerable_time;

public:
	list<Bullet> bullets;
	double fuellvl = 100;
	void increaseScore(int a);
	Spaceship();
	void setposition(double x, double y);
	void direction(Event event);
	void ifShooting(Event event);
	void reset(); //reset spaceship movements to prevent run-time bugs.
	void shoot();
	int move(RenderWindow& window);
	void draw(RenderWindow& window);
	double getx();
	double gety();
	void clearBullets();
	ConvexShape getShape();
	void hit();
	RectangleShape getRaggio();
	void addFuel(int type);
	void makeInvulnerable(double s);
	bool isVulnerable();
	bool isAlive();

};


extern Spaceship ship;


#endif  // SPACESHIP_H
