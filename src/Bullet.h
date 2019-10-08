#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;


#ifndef BULLET_H
#define BULLET_H


class Bullet {

private:
	CircleShape bullet;
	bool move_left, move_up, move_right, move_down;
	double speed;
	Clock clock;

public:
	Bullet(double x, double y, bool left, bool up, bool right, bool down);
	void move();
	void draw(RenderWindow& window);
};


#endif /* BULLET_H_ */
