#include "Na1.h"

using namespace std;
using namespace sf;

button::button( float x, float y, string nazwa)
{
	
	this->x = x;
	this->y = y;
	this->nazwa = nazwa;
	this->tekstura.loadFromFile(nazwa);
	this->guzikson.setTexture(this->tekstura);
	guzikson.setPosition(this->x, this->y);
	hitbox = guzikson.getGlobalBounds();

}