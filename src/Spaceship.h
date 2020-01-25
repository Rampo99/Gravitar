#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>


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
	int health;
	Clock clock_move, clock_canshoot, drain_fuel;
	Time for_shooting, fuel_bar_time;

public:
	list<Bullet> bullets;
	int score = 0;
	double fuellvl = 100;
	//void increasefuel();
	//void addlife();
	//void increasescore(int a);
	//void removelife();
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

};


extern Spaceship ship;


#endif  // SPACESHIP_H
