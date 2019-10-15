#include "Planet.h"

using namespace std;

Planet::Planet() {
	Lines = new LinesList;
}

Planet::~Planet() {

}

void Planet::terraforming(ptrlines Lines,sf::RenderWindow& w){
	int x = 0;
	int y = w.getSize().y-100;
	Lines->lines.setPrimitiveType(sf::Lines);
	srand(time(0));
	while(x<w.getSize().x){
		Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		int perclines = (rand()%100)+1;
		int percbunker = (rand()%100)+1;
		int percfuel = (rand()%100)+1;
		if(x==w.getSize().x-20){
			x+=19;
		}else{
			x+=20;
		}
		if(y!=w.getSize().y-30){
			if(perclines<30){
				if(y>30) y-=30;
			} else if(perclines>=30 && perclines<60) {
				y+=30;
			}
		} else {
			y +=29;
		}
		Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		if(x==w.getSize().x-1) x++;
		if(y==w.getSize().y-1) y++;
	}
	// if back head->prev
	// if next head->next
	Lines->next= new LinesList;
	Lines->next->prev=Lines;
	Lines = Lines->next;
}
void Planet::draw(sf::RenderWindow& w){
	w.draw(Lines->lines);
}
