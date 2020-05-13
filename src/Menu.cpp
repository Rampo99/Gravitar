#include "Menu.h"


Menu::Menu(void) {}


int Menu::Run(sf::RenderWindow &App)
{
	sf::Font Font;
	sf::Text title, Menu1, Menu2;
	int menu = 0;
	if (!Font.loadFromFile("font.ttf")) {
		std::cerr << "Error loading font" << std::endl;
		return(-1);
	}
	title.setFont(Font);
	title.setCharacterSize(80);
	title.setString("nongravitar");
	title.setColor(Color::Green);
	title.setPosition(620, 30);
	Menu1.setFont(Font);
	Menu1.setCharacterSize(40);
	Menu1.setString("new game");
	Menu1.setPosition(820, 400);
	Menu2.setFont(Font);
	Menu2.setCharacterSize(40);
	Menu2.setString("exit");
	Menu2.setPosition(820, 480 );
	while (App.isOpen()) {
		sf::Event Event;
		while (App.pollEvent(Event)) {
			if (Event.type == sf::Event::Closed)
				return (-1);
			if (Event.type == sf::Event::KeyPressed) {
				switch (Event.key.code) {
				case Keyboard::Escape:
					App.close();
					break;
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Enter:
					if (menu == 0) return 1;
					else App.close();
					break;
				default:
					break;
				}
			}
		}
		if (menu == 0) {
			Menu1.setColor(sf::Color::Red);
			Menu2.setColor(sf::Color::White);
		}
		else {
			Menu1.setColor(sf::Color::White);
			Menu2.setColor(sf::Color::Red);
		}
		App.clear();
		App.draw(title);
		App.draw(Menu1);
		App.draw(Menu2);
		App.display();
	}
	return(-1);
}
