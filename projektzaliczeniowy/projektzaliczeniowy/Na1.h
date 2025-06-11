#pragma once
#include "SFML/Graphics.hpp"
#include"petla.h"
#include "status_gry.h"
#include <iostream>
using namespace sf;
using namespace std;

/// <summary>
/// Podstawowe klasy takie jak obiekt, grafika, przycisk, napis u¿ywane w ca³ym projekcie
/// </summary>

class obiekt
///podstawowy obiekt, po którym bêd¹ dziedziczyæ klasy guzik, napis itd.///
{
protected:
	float x; //zmienne po³o¿enia
	float y;
	FloatRect hitbox; //SFML: okreslenie hitboxow i kolizji
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
	void rysujnapisInt(RenderWindow& okno, int& x); //wyswietl int w formie string
	void zmienNapis(RenderWindow& okno, string nowyNapis); //zmien tresc napisu
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
	void rysuj(RenderWindow& okno); //narusyj grafike
	void zmienTeksture(string nowaTekstura); //zmien teksture grafiki
	void zmienPolozenie(float x, float y); //zmien polozenie grafiki
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
	void wskaznikGuzik(Vector2i pozycjamyszy); //sprawdz czy naje¿d¿amy wskanzikiem na guzik i zmien jego teksture
	virtual ~button() {};
};
