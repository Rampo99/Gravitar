#ifndef PLANET_H_
#define PLANET_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bunker.h"
#include "Fuel.h"
struct LinesList{
	sf::VertexArray lines;
	LinesList *next;
	LinesList *prev;
};

typedef LinesList *ptrlines;

class Planet {
public:
	Planet();
	virtual ~Planet();
	void draw(sf::RenderWindow& w);
	void terraforming(ptrlines Lines,sf::RenderWindow& w);
	ptrlines Lines;
};

#endif
