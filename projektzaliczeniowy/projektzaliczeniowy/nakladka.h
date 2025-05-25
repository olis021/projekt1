#pragma once
#include "Na1.h"
#include "zmienne.h"

using namespace std;
using namespace sf;

class suwak : public button
{
protected:
	bool ciagnie = false;
public:
	suwak(float x, float y, string nazwa, string nazwaZaznaczony);
	suwak() : button(0, 0, "suwak1", "suwak2") {}
	void podazaj(Vector2i pozycjamyszy);
};

class przepis : public grafika
{
public:
	void zrob();
	void ilosc();
	void skladnik();
	int liczba_do_wypieczenia = 0;
	int liczba_w_ekwipunku = 0;
	int cena = 0;
	napisy t1;
	button g1;
	button g2;
	przepis(float x, float y, float a, float b, float c, float d, float m, float n, int cena, string nazwaObraz, string nazwaGuzik1, 
	string nazwaGuzikZaznaczony1, string nazwaGuzik2, string nazwaGuzikZaznaczony2);
	void rysujprzepis(RenderWindow& okno);
};

class nakladka : public grafika //UWAGA NAKLADKA MA OSOBNA FUNCKJE RYSUJ MOZE ZROBIC JAKAS WIRTUALNA DLA GRAFIK JAK TO RYSUJ JEST WSZEDZIE
{
public:
	bool nakladkaAktywna = false;
	bool nakladkaskladniki = false;
	bool nakladkaprzepisy = true;
	bool nakladkaekwipunek = false;
	nakladka(float x, float y, string nazwa);
};