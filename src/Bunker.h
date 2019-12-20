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

private:
	sf::ConvexShape bunker;
	int health = 100;
	list<Bullet*> bullets;
	Time for_shooting;
	Clock clock_canshoot;
	double ratio, rot;
	int type;
	double *directions, *bullets_speed;

};


#endif
