#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <list>
#include "Spaceship.h"


#define PI 3.14159265


using namespace std;
using namespace sf;


void start_game();


Spaceship::Spaceship()
{
	ship = ConvexShape(16);
	ship.setFillColor(Color::Blue);
	ship.setOutlineColor(Color(0, 0, 100));
	ship.setOutlineThickness(2);
	ship.setPoint(0, Vector2f(0, 0));
	ship.setPoint(1, Vector2f(5, 10));
	ship.setPoint(2, Vector2f(0, 20));
	ship.setPoint(3, Vector2f(5, 30));
	ship.setPoint(4, Vector2f(0, 40));
	ship.setPoint(5, Vector2f(10, 35));
	ship.setPoint(6, Vector2f(20, 40));
	ship.setPoint(7, Vector2f(30, 35));
	ship.setPoint(8, Vector2f(40, 40));
	ship.setPoint(9, Vector2f(35, 30));
	ship.setPoint(10, Vector2f(40, 20));
	ship.setPoint(11, Vector2f(35, 10));
	ship.setPoint(12, Vector2f(40, 0));
	ship.setPoint(13, Vector2f(30, 5));
	ship.setPoint(14, Vector2f(20, 0));
	ship.setPoint(15, Vector2f(10, 5));
	ship.setOrigin(20, 20);
	health = 6;
	double l = 25;  // l lato quadrato cuore
	heart = ConvexShape(8);
	heart.setFillColor(Color::Blue);
	heart.setOutlineColor(Color(0, 0, 100));
	heart.setOutlineThickness(2);
	heart.setPoint(0, Vector2f((1.0 / 4) * l, 3));
	heart.setPoint(1, Vector2f(0, (1.0 / 3) * l));
	heart.setPoint(2, Vector2f(0, (1.0 / 2) * l));
	heart.setPoint(3, Vector2f((1.0 / 2) * l, l));
	heart.setPoint(4, Vector2f(l, (1.0 / 2) * l));
	heart.setPoint(5, Vector2f(l, (1.0 / 3) * l));
	heart.setPoint(6, Vector2f((3.0 / 4) * l, 3));
	heart.setPoint(7, Vector2f((1.0 / 2) * l, (1.0 / 3) * l));
	fuel_border = RectangleShape(Vector2f(305.0, 26.0));
	fuel_border.setFillColor(Color::Black);
	fuel_border.setOutlineColor(Color::Yellow);
	fuel_border.setOutlineThickness(2);
	fuel_border.setPosition(1593.5, 13);
	fuel_bar = RectangleShape(Vector2f(300.0, 21.0));
	fuel_bar.setFillColor(Color::Yellow);
	fuel_bar.setPosition(1596, 15.5);
	move_left = move_up = move_right = move_down = shooting = false;
	speed = 600;
	ratio = 1.0 / 2.0;
	for_shooting_time = seconds(ratio);
	fuel_bar_time = seconds(20);
	raggioon = false;
	raggio = RectangleShape(Vector2f(5, 300));
	raggio.setOrigin(2.5, 0);
	raggio.setFillColor(Color::Cyan);
	score = 0;
}


void Spaceship::reset()
{
	move_left = move_up = move_right = move_down = shooting = false;
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
	if (move_left || move_right || move_up || move_down)
		fuel_bar_time -= drain_fuel_clock.restart();
	else
		drain_fuel_clock.restart();
}


void Spaceship::ifShooting(Event event)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::L)
		shooting = true;
	if (event.type == Event::KeyReleased && event.key.code == Keyboard::L)
		shooting = false;
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::K)
		raggioon = true;
	if (event.type == Event::KeyReleased && event.key.code == Keyboard::K)
		raggioon = false;
}


void Spaceship::setposition(double x, double y)
{
	ship.setPosition(x, y);
}


double Spaceship::getx()
{
	return ship.getPosition().x;
}


double Spaceship::gety()
{
	return ship.getPosition().y;
}


void Spaceship::shoot()
{
	double x = ship.getPosition().x, y = ship.getPosition().y;
	for_shooting_time += canshoot_clock.restart();
	if (shooting && for_shooting_time.asSeconds() >= ratio) {
		Bullet *tmp;
		if (move_left)
			x -= 20;
		if (move_up)
			y -= 20;
		if (move_right)
			x += 20;
		if (move_down)
			y += 20;
		if (!(move_left || move_up || move_right || move_down))
			tmp = new Bullet(x, y + 20, false, false, false, true);
		else {
			tmp = new Bullet(x, y, move_left, move_up, move_right, move_down);
		}
		bullets.push_front(*tmp);
		for_shooting_time = canshoot_clock.restart();
	}
}


int Spaceship::move(RenderWindow& window)
{
	Time elapsed = move_clock.restart();
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

	if (gety() < 0)
		ship.setPosition(getx(), 0);
	else if(gety() > window.getSize().y)
		ship.setPosition(getx(), window.getSize().y);

	if (getx() < 0) {
		ship.setPosition(window.getSize().x, gety());
		return -1;  // spaceship is going over left-window border
	}
	else if (getx() > window.getSize().x) {
		ship.setPosition(0, gety());
		return 1;  // spaceship is going over right-window border
	}
	return 0;  // spaceship moving in-window bounds.
}


void Spaceship::draw(RenderWindow& window)
{
	sf::Font font1;
	sf::Text number;
	if (!font1.loadFromFile("Consolas.ttf")) {
		std::cerr << "Error loading font" << std::endl;
		exit(-1);
	}
	number.setFont(font1);
	number.setCharacterSize(40);
	number.setString(sf::String(std::to_string(score)));
	number.setColor(Color::White);
	number.setPosition(10, 35);
	window.draw(number);

	if(!isAlive()) {
		while (window.isOpen()) {
			sf::Event Event;
			while (window.pollEvent(Event)) {
				if (Event.type == sf::Event::Closed)
					window.close();
				if (Event.type == sf::Event::KeyPressed and Event.key.code == Keyboard::Escape)
					window.close();
				if (Event.type == sf::Event::KeyPressed and Event.key.code == Keyboard::Enter)
					start_game();
			}
			window.clear();
			sf::Font font2;
			sf::Text gameover;
			if (!font2.loadFromFile("font.ttf")) {
				std::cerr << "Error loading font" << std::endl;
				exit(-1);
			}
			gameover.setFont(font2);
			gameover.setCharacterSize(80);
			gameover.setString("game over\nscore ");
			gameover.setColor(Color::Red);
			gameover.setPosition(660, 350);
			number.setPosition(1060, 437);
			number.setColor(Color::Red);
			number.setCharacterSize(86);
			window.draw(gameover);
			window.draw(number);
			window.display();
		}
	}

	invulnerable_time -= invulnerable_clock.restart();
	if (isVulnerable()) {
		ship.setFillColor(Color::Blue);
		ship.setOutlineColor(Color(0, 0, 100));
	}
	else {
		ship.setFillColor(Color(0, 255, 255));
		ship.setOutlineColor(Color(0, 100, 100));
	}

	if (raggioon) {
		raggio.setPosition(ship.getPosition().x, ship.getPosition().y);
		window.draw(raggio);
	}

	list<Bullet>::iterator it;
	for(it = bullets.begin(); it != bullets.end(); ) {
		it->move();
		if (it->isAlive(window)) {
			it->draw(window);
			it++;
		}
		else
			it = bullets.erase(it);
	}

	window.draw(ship);

	for (int h = 0; h < health; h++) {
		heart.setPosition(h * 25 + 10 + 10 * h, 9);
		window.draw(heart);
	}

	window.draw(fuel_border);
	double x = 300 * (fuel_bar_time.asSeconds() / 20);
	x = x < 0 ? 0 : x;
	fuel_bar.setSize(Vector2f(x, fuel_bar.getSize().y));
	window.draw(fuel_bar);
}


void Spaceship::clearBullets()
{
	bullets.clear();
}


ConvexShape Spaceship::getShape()
{
	return ship;
}


void Spaceship::hit()
{
	if (isVulnerable())
		health--;
}


RectangleShape Spaceship::getRaggio()
{
	return raggio;
}


void Spaceship::addFuel(int type)
{
	if (type)
		fuel_bar_time += seconds(6.5);
	else  // type == 0
		fuel_bar_time += seconds(4.5);
	fuel_bar_time = fuel_bar_time.asSeconds() > 20.0 ? seconds(20.0) : fuel_bar_time;
}


void Spaceship::makeInvulnerable(double s)
{
	invulnerable_time = seconds(s);
}


bool Spaceship::isVulnerable()
{
	return invulnerable_time.asSeconds() <= 0;
}


void Spaceship::increaseScore(int a)
{
	score += a;
}


bool Spaceship::isAlive()
{
	return health > 0 and fuel_bar_time.asSeconds() > 0;
}
