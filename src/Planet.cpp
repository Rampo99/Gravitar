#include "Planet.h"

using namespace std;

Planet::Planet() {
	Head = new List;
}

Planet::~Planet() {

}

void Planet::terraforming(ptr Head,sf::RenderWindow& w){
	int x = 0;
	int y = w.getSize().y-100;
	Head->lines.setPrimitiveType(sf::Lines);
	srand(time(0));
	while(x<w.getSize().x){
		Head->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		int r = (rand()%100)+1;

		if(x==w.getSize().x-20){
			x+=19;
		}else{
			x+=20;
		}
		if(y!=w.getSize().y-30){
			if(r<30){
				if(y>30) y-=30;
			} else if(r>=30 && r<60) {
				y+=30;
			}
		} else {
			y +=29;
		}
		Head->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		if(x==w.getSize().x-1) x++;
		if(y==w.getSize().y-1) y++;
	}
	// if back head->prev
	// if next head->next
	Head = Head->next;
}
void Planet::draw(sf::RenderWindow& w){
	w.draw(Head->lines);
}
