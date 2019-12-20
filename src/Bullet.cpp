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
	speed = 1000;
	bullet.setPosition(x, y);
	using_degrees = false;
}


Bullet::Bullet(double x, double y, double ang, double sp)
{
	bullet = CircleShape(5);
	bullet.setFillColor(Color(200, 0, 255));
	bullet.setOrigin(5, 5);
	bullet.setPosition(x, y);
	using_degrees = true;
	angolo = ang;
	speed = sp;
}

void Bullet::move()
{
	Time elapsed = clock.restart();
	if (!using_degrees) {
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
	else
		bullet.move(cos(angolo) * speed * elapsed.asSeconds(), sin(angolo) * speed * elapsed.asSeconds());
}


bool Bullet::isAlive(RenderWindow& window)
{
	return bullet.getPosition().x >= 0 - 5 &&
			bullet.getPosition().x <= window.getSize().x + 5 &&
			bullet.getPosition().y >= 0 - 5 &&
			bullet.getPosition().y <= window.getSize().y + 5;
}


void Bullet::draw(RenderWindow& window)
{
	window.draw(bullet);
}
