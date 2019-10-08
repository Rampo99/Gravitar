#include <SFML/Graphics.hpp>
#include <math.h>
#include "Bullet.h"


#define PI 3.14159265


using namespace std;
using namespace sf;


Bullet::Bullet(double x, double y, bool left, bool up, bool right, bool down)
{
	bullet = CircleShape(5);
	bullet.setFillColor(Color::Red);
	bullet.setOrigin(5, 5);
	move_left = left;
	move_up = up;
	move_right = right;
	move_down = down;
	speed = 800;
	bullet.setPosition(x, y);
}


void Bullet::move()
{
	Time elapsed = clock.restart();
	double coeff = 1;
	if ((move_up || move_down) && (move_left || move_right))
		coeff = sin(45.0 * PI / 180.0);
	if (move_left)
		bullet.setPosition(bullet.getPosition().x - elapsed.asSeconds() * speed * coeff, bullet.getPosition().y);
	if (move_up)
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y - elapsed.asSeconds() * speed * coeff);
	if (move_right)
		bullet.setPosition(bullet.getPosition().x + elapsed.asSeconds() * speed * coeff, bullet.getPosition().y);
	if (move_down)
		bullet.setPosition(bullet.getPosition().x, bullet.getPosition().y + elapsed.asSeconds() * speed * coeff);
}


void Bullet::draw(RenderWindow& window)
{
	window.draw(bullet);
}

