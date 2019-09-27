/*
 * SpaceShip.h
 *
 *  Created on: 27 set 2019
 *      Author: loren
 */

#ifndef SPACESHIP_H_
#define SPACESHIP_H_

#include <SFML/Graphics.hpp>

class SpaceShip {

public:
	SpaceShip();
	SpaceShip(sf::RenderWindow&);
	virtual ~SpaceShip();

private:
	int x,y;

};

#endif /* SPACESHIP_H_ */
