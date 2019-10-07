#include <SFML/Graphics.hpp>
#include <list>


using namespace std;
using namespace sf;


#ifndef SPACESHIP_H
#define SPACESHIP_H


class Spaceship {

private:
	ConvexShape ship;
	bool move_left, move_up, move_right, move_down;
	double speed;
	Clock clock;

public:
	Spaceship();
	void direction(Event event);
	void move();
	void draw(RenderWindow& window);
};

#endif  // SPACESHIP_H

