#include "Menu.h"

Menu::Menu(void)
{
	a = 3 * 255;
	b = 3;
	gioco = false;
}

int Menu::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Sprite Sprite;
	int k = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	int menu = 0;

	Sprite.setColor(sf::Color(255, 255, 255, k));
	/*if (!Font.loadFromFile("verdanab.ttf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	} */
	Menu1.setFont(Font);
	Menu1.setCharacterSize(20);
	Menu1.setString("Gioca");
	Menu1.setPosition({ 280.f, 160.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(20);
	Menu2.setString("Esci");
	Menu2.setPosition({ 280.f, 220.f });

	if (gioco)
	{
		k = a;
	}

	while (Running)
	{
		while (App.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Enter:
					if (menu == 0)
					{
						//Let's get play !
						gioco = true;
						return (1);
					}
					else
					{
						//Let's get work...
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (k<a)
		{
			k++;
		}
		Sprite.setColor(sf::Color(255, 255, 255, k / b));
		if (menu == 0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
		}
		else
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(Sprite);
		if (k == a)
		{
			if (gioco)
			{
				Menu1.setString("Continua");
			}

			App.draw(Menu1);
			App.draw(Menu2);
		}
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

