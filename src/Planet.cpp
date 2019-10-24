#include "Planet.h"

using namespace std;

Planet::Planet() {
	Lines = new LinesList;
	Bunkers = new BunkerList;
	Fuels = new FuelList;
}

Planet::~Planet() {

}

void Planet::terraforming(ptrlines Lines, ptrbunkers Bunkers, ptrfuels Fuels, sf::RenderWindow& w){
	unsigned int x = 0;
	unsigned int y = w.getSize().y-100;
	ptrfuels f = Fuels;
	ptrbunkers b = Bunkers;
	Lines->lines.setPrimitiveType(sf::Lines);
	srand(time(0));
	while(x<w.getSize().x){
		Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
		int perclines = (rand()%100)+1;
		int percbunker = (rand()%100)+1;
		int percfuel = (rand()%100)+1;
		int fueltype = 1;
		int bunkertype = 1;
		if(x==w.getSize().x-20){
			x+=19;
		}else{
			x+=20;
		}
		if(y!=w.getSize().y-20){
			if(perclines<30){
				if(y>20) y-=20;
			} else if(perclines>=30 && perclines<60) {
				y+=20;
			}
		} else {
			y +=19;
		}
		if(percfuel < 5){
			f->fuel.settype(fueltype);
			if(fueltype == 2) fueltype --; else fueltype++;
			f->fuel.position(100,100);
			cout << "fuel spawn";
			f->next=new FuelList;
			f->next->prev = f;
			f = f->next;
		} else if(percbunker < 5){
			b->bunker.settype(bunkertype);
			if(bunkertype == 2) bunkertype --; else bunkertype++;
			b->bunker.position(200,200);
			b->bunker.drawing();
			cout << "bunker spawn";
			b->next=new BunkerList;
			b->next->prev = b;
			b = b->next;
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
	ptrfuels f = Fuels;
	ptrbunkers b = Bunkers;
	while (f->fuel.isdraw == true){
		f->fuel.draw(w);
		f = f->next;
	}
	while (b->bunker.isdraw == true){
			b->bunker.draw(w);
			b = b->next;
		}
	w.draw(Lines->lines);
}
