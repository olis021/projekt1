#include "Na1.h"
#include "petla.h"

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
		if (this->hitbox.contains(Vector2f(pozycjamyszy)))
		{

			cout << "kliknieto gozik";
			return true;

		}
		else return false;
	}
}
bool obiekt::czystoi()
{
	return false;
}