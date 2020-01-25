#include <iostream>
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Spaceship.h"


#ifndef MENU_H
#define MENU_H


class Menu : public Screen {

public:
	Menu(void);
	virtual int Run(sf::RenderWindow &App);
	void setreturnint(int a);

private:
	int returnint;

};


#endif
