#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screens.h"
#include "Spaceship.h"
using namespace std;
using namespace sf;


int main()
{
	std::vector<Screen*> Screens;
	int screen = 0;
	ContextSettings settings;
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(900, 900), "Gravitar", Style::Default, settings);
	window.setKeyRepeatEnabled(false);
	Spaceship ship;
	ship.setposition(window.getSize().x / 2, window.getSize().y / 2);
	Menu menu;
	Screens.push_back(&menu);
	SolarSystem* solarsystem = new SolarSystem;
	solarsystem->setShip(ship);
	Screens.push_back(solarsystem);
	int bunkers = 2, fuels = 1;
	Game* game = new Game;
	game->setnBunkers(bunkers);
	game->setnFuels(fuels);
	game->setShip(ship);
	Screens.push_back(game);
	while (screen >= 0) {
		if (screen == 2)
			menu.setreturnint(screen);
		if(screen == 1)
			menu.setreturnint(screen);
		screen = Screens[screen]->Run(window);
		if (screen == 3) {
			bunkers++;
			fuels++;
			cout << "dioporco";
			delete game;
			game = NULL;
			game = new Game;
			cout << "ciao";
			game->setnBunkers(bunkers);
			game->setnFuels(fuels);
			game->setShip(ship);
			Screens[2] = game;
			if (solarsystem->check()) {
				delete solarsystem;
				solarsystem = NULL;
				solarsystem = new SolarSystem;
				solarsystem->setShip(ship);
				Screens[1] = solarsystem;
			}
			screen = 1;
		}
		if (screen == 4) {
			solarsystem->alfacheck = false;
			screen = 2;
		}
		if (screen == 5) {
			solarsystem->betacheck = false;
			screen = 2;
		}
		if (screen == 6) {
			solarsystem->omegacheck = false;
			screen = 2;
		}
		if (screen == 7) {
			solarsystem->gammacheck = false;
			screen = 2;
		}
	}
}
