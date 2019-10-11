#include "Planet.h"

using namespace std;
Planet::Planet() {
	Head = new List;
}

Planet::~Planet() {

}

void Planet::terraforming(ptr Head){
	int x = 0;
	int y = 400;
	Head->lines.setPrimitiveType(sf::Lines);
	int k = 0;
	srand(time(0));
	while(x<500){
		Head->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		k++;
		int r = (rand()%100)+1;
		if(x==480){
			x+=19;
		}else{
			x+=20;
		}
		if(r<30){
			if(y>30)y-=30;
		} else if(r>=30 && r<60) {
			if(y<470) y+=30;
		}
		Head->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		k++;
		if(x==499) x++;
		cout << x << endl;
		cout << k << endl;
	}
	// if back head->prev
	// if next head->next
	Head = Head->next;
}
void Planet::draw(sf::RenderWindow& w){
	w.draw(Head->lines);
}
