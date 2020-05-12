#include <SFML/Graphics.hpp>
#include "Screens.h"
#include "Spaceship.h"
#include "cstdlib"
#include <iostream>


using namespace std;
using namespace sf;


Spaceship ship;
RenderWindow window	(VideoMode(1920, 1080), "nonGravitar", Style::Fullscreen);
void start_game();


int main()
{
	srand(time(0));
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(500);
	window.setMouseCursorVisible(false);
	start_game();

}


void start_game()
{
	ship = Spaceship();
	int n = 0;  // numero solar system
	std::vector<Screen*> Screens;
	int screen = 0;
	ship.setposition(window.getSize().x / 2, window.getSize().y / 2);
	Menu menu;
	Screens.push_back(&menu);
	SolarSystem* solarsystem = new SolarSystem(n);
	Screens.push_back(solarsystem);
	int bunkers = 2, fuels = 1;
	Game* game = new Game;
	game->setnBunkers(bunkers);
	game->setnFuels(fuels);
	Screens.push_back(game);
	//looping screens -- (menu screen = 0, solarsystem screen=1, game screen=2)
	while (screen >= 0) {
		screen = Screens[screen]->Run(window);
		//player completed planet -- deleting game screen
		if (screen == 3) {
			ship.increaseScore(50);
			bunkers++;
			fuels++;
			delete game;
			game = NULL;
			game = new Game;
			game->setnBunkers(bunkers);
			game->setnFuels(fuels);
			Screens[2] = game;
			//player completed entire solar -- creating new solarsystem
			if (solarsystem->check()) {
				ship.increaseScore(200);
				n++;
				delete solarsystem;
				solarsystem = NULL;
				solarsystem = new SolarSystem(n);
				Screens[1] = solarsystem;
			}
			screen = 1; //send player to solar system
		}
		//player enters alfa
		if (screen == 4) {
			solarsystem->alfacheck = false; //stop drawing alfa from solarsystem
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2 - 200);
			ship.clearBullets();
			screen = 2; //send player to game screen
		}
		//player enters beta
		if (screen == 5) {
			solarsystem->betacheck = false; //stop drawing beta from solarsystem
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2; //send player to game screen
		}
		//player enters omega
		if (screen == 6) {
			solarsystem->omegacheck = false; //stop drawing omega from solarsystem
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2; //send player to game screen
		}
		//player enters gamma
		if (screen == 7) {
			solarsystem->gammacheck = false; //stop drawing gamma from solarsystem
			ship.setposition(window.getSize().x / 2, window.getSize().y / 2  - 200);
			ship.clearBullets();
			screen = 2; //send player to game screen
		}
	}
}

