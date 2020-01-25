#ifndef BUNKER_H
#define BUNKER_H


#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <list>


class Bunker {

public:
	Bunker();
	void draw(sf::RenderWindow& w);
	void settype(int a);
	void position(int x, int y);
	bool isdraw;
	void drawing();
	void rotate(double x);
	bool isAlive();
	void hit();
	sf::ConvexShape getShape();
	list<Bullet> bullets;

private:
	sf::ConvexShape bunker;
	int health;
	Time for_shooting;
	Clock clock_canshoot;
	double ratio, rot;
	int type;
	double *directions, *bullets_speed;

};


#endif
