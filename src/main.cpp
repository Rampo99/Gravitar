#include <SFML/Graphics.hpp>
#include "Screens.h"
#include "Spaceship.h"
#include "cstdlib"
#include <iostream>


using namespace std;
using namespace sf;


Spaceship ship;


int main()
{
	srand(time(0));
	std::vector<Screen*> Screens;
	int screen = 0;
	ContextSettings settings;
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(1920, 1080), "Gravitar", Style::Fullscreen, settings);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(500);
	window.setMouseCursorVisible(false);
	ship.setposition(window.getSize().x / 2, window.getSize().y / 2);
	Menu menu;
	Screens.push_back(&menu);
	SolarSystem* solarsystem = new SolarSystem;
	Screens.push_back(solarsystem);
	int bunkers = 2, fuels = 1;
	Game* game = new Game;
	game->setnBunkers(bunkers);
	game->setnFuels(fuels);
	Screens.push_back(game);
	while (screen >= 0) {
		if (screen == 2)
			menu.setreturnint(screen);
		if (screen == 1)
			menu.setreturnint(screen);
		screen = Screens[screen]->Run(window);
		if (screen == 3) {
			//ship.increasescore(20);
			bunkers++;
			fuels++;
			delete game;
			game = NULL;
			game = new Game;
			game->setnBunkers(bunkers);
			game->setnFuels(fuels);
			Screens[2] = game;
			if (solarsystem->check()) {
				//ship.addlife();
				//ship.increasescore(100);
				delete solarsystem;
				solarsystem = NULL;
				solarsystem = new SolarSystem;
				Screens[1] = solarsystem;
			}
			screen = 1;
		}
		if (screen == 4) {
			solarsystem->alfacheck = false;
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2 - 200);
			ship.clearBullets();
			screen = 2;
		}
		if (screen == 5) {
			solarsystem->betacheck = false;
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2;
		}
		if (screen == 6) {
			solarsystem->omegacheck = false;
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2;
		}
		if (screen == 7) {
			solarsystem->gammacheck = false;
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2;
		}
	}
}
