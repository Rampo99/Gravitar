#include <SFML/Graphics.hpp>
#include <list>
#include <math.h>
#include <iostream>
#include "Spaceship.h"


#define PI 3.14159265


using namespace std;
using namespace sf;


Spaceship::Spaceship()
{
	ship = ConvexShape(16);
	ship.setFillColor(Color::Green);
	ship.setPoint(0, Vector2f(0, 0));
	ship.setPoint(1, Vector2f(7, 14));
	ship.setPoint(2, Vector2f(0, 28));
	ship.setPoint(3, Vector2f(7, 42));
	ship.setPoint(4, Vector2f(0, 56));
	ship.setPoint(5, Vector2f(14, 49));
	ship.setPoint(6, Vector2f(28, 56));
	ship.setPoint(7, Vector2f(42, 49));
	ship.setPoint(8, Vector2f(56, 56));
	ship.setPoint(9, Vector2f(49, 42));
	ship.setPoint(10, Vector2f(56, 28));
	ship.setPoint(11, Vector2f(49, 14));
	ship.setPoint(12, Vector2f(56, 0));
	ship.setPoint(13, Vector2f(42, 7));
	ship.setPoint(14, Vector2f(28, 0));
	ship.setPoint(15, Vector2f(14, 7));
	ship.setOrigin(28, 28);
	ship.setPosition(100, 100);
	move_left = move_up = move_right = move_down = false;
	speed = 400;
}

void Spaceship::direction(Event event)
{
	switch (event.type) {
	case Event::KeyPressed:
		switch (event.key.code) {
		case Keyboard::A:
			move_left = true;
			if (Keyboard::isKeyPressed(Keyboard::Key::D))
				move_right = false;
			break;
		case Keyboard::W:
			move_up = true;
			if (Keyboard::isKeyPressed(Keyboard::Key::S))
				move_down = false;
			break;
		case Keyboard::D:
			move_right = true;
			if (Keyboard::isKeyPressed(Keyboard::Key::A))
				move_left = false;
			break;
		case Keyboard::S:
			move_down = true;
			if (Keyboard::isKeyPressed(Keyboard::Key::W))
				move_up = false;
			break;
		default:
			break;
		}
		break;
		case Event::KeyReleased:
			switch (event.key.code) {
			case Keyboard::A:
				move_left = false;
				if (Keyboard::isKeyPressed(Keyboard::Key::D))
					move_right = true;
				break;
			case Keyboard::W:
				move_up = false;
				if (Keyboard::isKeyPressed(Keyboard::Key::S))
					move_down = true;
				break;
			case Keyboard::D:
				move_right = false;
				if (Keyboard::isKeyPressed(Keyboard::Key::A))
					move_left = true;
				break;
			case Keyboard::S:
				move_down = false;
				if (Keyboard::isKeyPressed(Keyboard::Key::W))
					move_up = true;
				break;
			default:
				break;
			}
			break;
			default:
				break;
	}
}

void Spaceship::move()
{
	Time elapsed = clock.restart();
	double coeff = 1;
	if ((move_up || move_down) && (move_left || move_right))
		coeff = sin(45 * PI / 180);
	if (move_left)
		ship.setPosition(ship.getPosition().x - elapsed.asSeconds() * speed * coeff, ship.getPosition().y);
	if (move_up)
		ship.setPosition(ship.getPosition().x, ship.getPosition().y - elapsed.asSeconds() * speed * coeff);
	if (move_right)
		ship.setPosition(ship.getPosition().x + elapsed.asSeconds() * speed * coeff, ship.getPosition().y);
	if (move_down)
		ship.setPosition(ship.getPosition().x, ship.getPosition().y + elapsed.asSeconds() * speed * coeff);
}

void  Spaceship::draw(RenderWindow& window)
{
	window.draw(ship);
}

