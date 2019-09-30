#ifndef ALIEN_H_
#define ALIEN_H_

#include <SFML/Graphics.hpp>

class Alien {
public:
	Alien();
	virtual ~Alien();
	void draw(sf::RenderWindow& w);
private:
	sf::ConvexShape alien;
};

#endif
