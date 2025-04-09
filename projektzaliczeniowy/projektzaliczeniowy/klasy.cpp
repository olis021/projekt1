#include "Na1.h"

using namespace std;
using namespace sf;
bool etap1 = true;
bool etap2 = false;
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
obiekt::obiekt(float x, float y, string nazwa)
{
	this->x = x;
	this->y = y;
	this->nazwa = nazwa;
	this->tekstura.loadFromFile(nazwa);
	this->guzikson.setTexture(this->tekstura);
	guzikson.setPosition(this->x, this->y);
	hitbox = guzikson.getGlobalBounds();
}
bool button::p1(Vector2i pozycjamyszy)
{
	{
		if (this->hitbox.contains(Vector2f(pozycjamyszy))&& etap1==true)
		{
			etap1 = false;
			etap2 = true; 
			cout << "kliknieto gozik";
			

		}
		else return false;
	}
}