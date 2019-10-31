#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screens.h"
using namespace std;
using namespace sf;


int main(){
	std::vector<Screen*> Screens;
	int screen = 0;
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(600, 600), "Gravitar", Style::Default, settings);
	window.setKeyRepeatEnabled(false);

	Menu menu;
	Screens.push_back(&menu);
	SolarSystem solarsystem;
	Screens.push_back(&solarsystem);
	Game game;
	game.setplanet(solarsystem.alfa);
	Screens.push_back(&game);

	while (screen >= 0){
		screen = Screens[screen]->Run(window);
	}

}

