#ifndef BUNKER_H_
#define BUNKER_H_

#include <SFML/Graphics.hpp>

class Bunker {
public:
	Bunker();
	void draw(sf::RenderWindow& w);
	void settype(int a);
	void position(int x, int y);
	bool isdraw;
	void drawing();
	void rotation(int x);
private:
	sf::ConvexShape bunker;
	int health = 100, turrets;
	float firespeed;
};

#endif
