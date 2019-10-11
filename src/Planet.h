#ifndef PLANET_H_
#define PLANET_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

struct List{
	sf::VertexArray lines;
	List *next;
	List *prev;
};
typedef List* ptr;

class Planet {
public:
	Planet();
	virtual ~Planet();
	void draw(sf::RenderWindow& w);
	void terraforming(ptr Head);
	ptr Head;
};

#endif
