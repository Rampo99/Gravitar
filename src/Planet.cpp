#include "Planet.h"

using namespace std;

Planet::Planet() {
	Lines = new LinesList;
	Lines->Bunkers = new BunkerList;
	Lines->Fuels = new FuelList;
	bunkers = 0;
	fuels = 0;
}

void Planet::setnBunkers(int n){
	bunkers = n;
}
void Planet::setnFuels(int n){
	fuels = n;
}
void Planet::terraforming(ptrlines Lines, sf::RenderWindow& w, int rightorleft){
	if(Lines->isdraw == false){
		unsigned int x = 0;
		unsigned int y = w.getSize().y-100;
		unsigned int y2;
		int finaly;
		ptrfuels f = Lines->Fuels;
		ptrbunkers b = Lines->Bunkers;
		Lines->lines.setPrimitiveType(sf::Lines);
		srand(time(0));
		while(x<w.getSize().x){
			Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
			int perclines = (rand()%100)+1;
			int percbunker = (rand()%100)+1;
			int percfuel = (rand()%100)+1;
			int fueltype = 1;
			int bunkertype = 1;
			y2 = y;
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
				y-=20;
			}
			Lines->lines.append(sf::Vertex(sf::Vector2f(x,y), sf::Color::Cyan));
			if(y-y2 < 0) finaly = -(y-y2); else finaly = y-y2;
			if(percfuel < 2){
				if(fuels > 0){
					f->fuel.settype(fueltype);
					if(fueltype == 2) fueltype --; else fueltype++;
					f->fuel.position(x-10,y-finaly/2);
					if(y!= y2){
						if(y<y2) f->fuel.rotation(atan2(20,finaly)*180 / 3.141592 + 180);
						else f->fuel.rotation(atan2(20,finaly)*180 / 3.141592);
					}
					f->next=new FuelList;
					f->next->prev = f;
					f = f->next;
					fuels--;
				}
			} else if(percbunker < 2){
				if(bunkers > 0){
					b->bunker.settype(bunkertype);
					if(bunkertype == 2) bunkertype --; else bunkertype++;
					b->bunker.position(x-10,y-finaly/2);
					if(y!= y2){
						if(y<y2) b->bunker.rotation(atan2(20,finaly)*180 / 3.141592 +180);
						else b->bunker.rotation(atan2(20,finaly)*180 / 3.141592);
					}
					b->bunker.drawing();
					b->next=new BunkerList;
					b->next->prev = b;
					b = b->next;
					bunkers--;
				}
			}

			if(x==w.getSize().x-1) x++;
			if(y==w.getSize().y-1) y++;
		}
		if(rightorleft){
			Lines->next= new LinesList;
			Lines->next->prev = Lines;
		} else {
			Lines->prev = new LinesList;
			Lines->prev->next = Lines;
		}
	}
	if(rightorleft==1)	Lines = Lines->next;
	if(rightorleft==-1) Lines = Lines->prev;
}
void Planet::draw(sf::RenderWindow& w){
	ptrfuels f = Lines->Fuels;
	ptrbunkers b = Lines->Bunkers;
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
