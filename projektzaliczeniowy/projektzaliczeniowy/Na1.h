#include "SFML/Graphics.hpp"
#include"petla.h"
#include "status_gry.h"
#include <iostream>
using namespace sf;
using namespace std;
//plik naglowkowy z klasa obiekt, napisy, grafika, button
#pragma once
static Color tlo = Color::Black;
static Font arial;

class obiekt
	//podstawowy obiekt, po którym bêd¹ dziedziczyæ klasy guzik, napis itd.
{
protected:
	float x; //zmienne po³o¿enia
	float y;
	FloatRect hitbox;
public:
	obiekt(float x, float y);
};

class napisy: public obiekt
{
protected:
	string tresc;
	Font czcionka;
	Text nap;
public:
	napisy(float x, float y, string tresc);
};

class grafika : public obiekt
{
protected:
	string nazwa;
	Texture tekstura;
	Sprite obraz;
public:
	grafika(float x, float y, string nazwa);
	grafika() : obiekt(x, y), nazwa("grafika)") {}
	void rysuj(RenderWindow& okno); //virtual?
};
class button: public grafika
{
protected:
	string nazwaWskaznika;
	Texture teksturaWskaznika;
public:
	button( float x, float y, string nazwa, string nazwaWskaznika);
	button() : grafika(0,0,"guzik"){}
	bool p1(Vector2i pozycjamyszy);
	void wskaznikGuzik(Vector2i pozycjamyszy);
};


//class obiekt:public button
//{
//public:
//	obiekt(float x, float y, string nazwa);
//	bool czystoi();
//};
