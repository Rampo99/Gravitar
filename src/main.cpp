#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screens.h"
using namespace std;
using namespace sf;


int main()
{
	std::vector<Screen*> Screens;
	int screen = 0;

		//Window creation
		sf::RenderWindow App(sf::VideoMode(640, 480, 32), "SFML Demo 3");

		//Mouse cursor no more visible
		App.setMouseCursorVisible(false);

		//Screens preparations
		Menu menu;
		Screens.push_back(&menu);
		Game game;
		Screens.push_back(&game);

		//Main loop
		while (screen >= 0)
		{
			screen = Screens[screen]->Run(App);
		}

}

