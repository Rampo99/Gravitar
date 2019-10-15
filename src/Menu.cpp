#include "Menu.h"

Menu::Menu(void){
	gioco = false;
}

int Menu::Run(sf::RenderWindow &App){
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	int menu = 0;
	if(!Font.loadFromFile("font.ttf"))
	{
		std::cerr << "Error loading font" << std::endl;
		return(-1);
	}
	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("gioca");
	Menu1.setPosition( 280, 160);

	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("esci");
	Menu2.setPosition( 280, 220 );

	while(App.isOpen()){
		sf::Event Event;
		while(App.pollEvent(Event)){
			if(Event.type == sf::Event::Closed){
				return (-1);
			}
			if(Event.type == sf::Event::KeyPressed){
				switch (Event.key.code){
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Enter:
					if (menu == 0){
						gioco = true;
						return (1);
					} else {
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}

		if(menu == 0){
			Menu1.setColor(sf::Color::Red);
			Menu2.setColor(sf::Color::White);
		} else {
			Menu1.setColor(sf::Color::White);
			Menu2.setColor(sf::Color::Red);
		}

		if(gioco){
			Menu1.setString("continua");
		}

		App.clear();
		App.draw(Menu1);
		App.draw(Menu2);
		App.display();
	}

	return(-1);
}

