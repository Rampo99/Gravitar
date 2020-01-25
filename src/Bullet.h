#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


#ifndef BULLET_H
#define BULLET_H


class Bullet {

private:
	CircleShape bullet;
	bool move_left = true, move_up = true, move_right = true, move_down = true, using_degrees;
	double speed, angolo = 0;
	Clock clock;

public:
	Bullet(double x, double y, bool left, bool up, bool right, bool down);
	Bullet(double x, double y, double ang, double sp);
	void move();
	bool isAlive(RenderWindow& window);
	void draw(RenderWindow& window);
	CircleShape getShape();

};


#endif  // BULLET_H

