#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;
#pragma once
static Color tlo = Color::Black;
static Font arial;
class napisy
{
protected:
	float x;
	float y;
	string tresc;
public:
	Text nap;
	napisy(float x, float y,string tresc):x(x),y(y),tresc(tresc){
		nap.setFont(arial);
		nap.setString(tresc);
		nap.setFillColor(Color::White);
		nap.setCharacterSize(30);
		nap.setPosition(x, y);
	}
};
class button//klasa co tworzy guziki ,jest jeszcze zdecydowanie nie dopracowana podajesz jej pozycje na x i y ,nazwe pliku co potem siê otwiera jako graficzka
{
protected:
	float x;
	float y;
	string nazwa;
public:
	Sprite guzikson;
	Texture tekstura;
	FloatRect hitbox;
	button( float x, float y, string nazwa);
	button() : x(0), y(0), nazwa("guzi") {};
	bool p1(Vector2i pozycjamyszy)
	{
		if (hitbox.contains(Vector2f(pozycjamyszy)))
		{
			
			if (tlo == Color::Green)
			{
				tlo = Color::Black;
			}
			else tlo = Color::Green;;
			return true;
		}
		else return false;
	}

};