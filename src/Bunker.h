#ifndef BUNKER_H_
#define BUNKER_H_

#include <SFML/Graphics.hpp>

class Bunker {
public:
	Bunker(int a);
	virtual ~Bunker();
	void draw(sf::RenderWindow& w);
private:
	sf::ConvexShape bunker;
	int health = 100, turrets;
	float firespeed;
};

#endif
