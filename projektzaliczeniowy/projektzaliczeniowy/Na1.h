#pragma once
#include "SFML/Graphics.hpp"
#include"petla.h"
#include "status_gry.h"
#include <iostream>
using namespace sf;
using namespace std;
//plik naglowkowy z klasa obiekt, napisy, grafika, button
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
	virtual ~obiekt() {};
};

class napisy : public obiekt
{
protected:
	string tresc;
	Font czcionka;
	Color kolor;
	int Size;
public:
	Text nap;
	napisy(float x, float y, string tresc, Color kolor, int Size);
	napisy() : obiekt(0, 0), tresc("napis"), Size(1) {}
	void rysujnapisInt(RenderWindow& okno, int& x);
	void zmienNapis(RenderWindow& okno, string nowyNapis);
	virtual ~napisy() {};
};

class grafika : public obiekt
{
protected:
	string nazwa;
	Texture tekstura;
public:
	Sprite obraz;
	grafika(float x, float y, string nazwa);
	grafika() : obiekt(0.f, 0.f), nazwa("grafika") {}
	void rysuj(RenderWindow& okno); //virtual?
	void zmienTeksture(string nowaTekstura);
	void zmienPolozenie(float x, float y);
	Vector2f zwrocPolozenie();
	virtual ~grafika() {};
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
	virtual ~button() {};
};


//
//class obiekt:public button
//{
//public:
//	obiekt(float x, float y, string nazwa);
//	bool czystoi();
//};
