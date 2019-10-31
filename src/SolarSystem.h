#include "Planet.h"
#include "Screen.h"

#ifndef SOLARSYSTEM_H_
#define SOLARSYSTEM_H_

class SolarSystem : public Screen{
public:
	SolarSystem();
	virtual int Run(sf::RenderWindow &App);
	void setupPlanets();
	Planet alfa;
	Planet beta;
	Planet gamma;
	Planet omega;
private:
	int bunkers;
	int fuels;
};

#endif
