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
	RenderWindow window(VideoMode(700, 700), "Gravitar", Style::Default, settings);
	window.setKeyRepeatEnabled(false);

	Menu menu;
	Screens.push_back(&menu);
	Game game;
	Screens.push_back(&game);

	while (screen >= 0){
		screen = Screens[screen]->Run(window);
	}

}

