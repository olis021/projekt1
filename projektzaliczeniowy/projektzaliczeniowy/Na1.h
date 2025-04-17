#include "SFML/Graphics.hpp"
#include"petla.h"
#include "status_gry.h"
#include <iostream>
using namespace sf;
using namespace std;
#pragma once
static Color tlo = Color::Black;
static Font arial;
class obiekt;
class napisy
{
protected:
	float x;
	float y;
	string tresc;
public:
	Text nap;
	napisy(float x, float y,string tresc):x(x),y(y),tresc(tresc){
		arial.loadFromFile("ArialCE.ttf");
		nap.setFont(arial);
		nap.setString(tresc);
		nap.setFillColor(Color::White);
		nap.setCharacterSize(30);
		nap.setPosition(x, y);
	}
};
class button//klasa co tworzy guziki ,jest jeszcze zdecydowanie nie dopracowana podajesz jej pozycje na x i y ,nazwe pliku co potem siê otwiera jako graficzka
{
	friend obiekt;
protected:
	string nazwa;
	Texture tekstura;
	FloatRect hitbox;

public:
	float x;
	float y;
	Sprite guzikson;
	button( float x, float y, string nazwa);
	button() : x(0), y(0), nazwa("guzi") {};
	bool p1(Vector2i pozycjamyszy);


};
class obiekt:public button
{
public:
	obiekt(float x, float y, string nazwa);
	bool czystoi();
};