#include <iostream>
#include "Screen.h"

#include <SFML/Graphics.hpp>

#ifndef MENU_H_
#define MENU_H_

class Menu : public Screen{
public:
	Menu(void);
	virtual int Run(sf::RenderWindow &App);
private:
	bool gioco;

};

#endif
