#pragma once
#include "Na1.h"
#include "zmienne.h"

using namespace std;
using namespace sf;


class skladnik : public grafika
{
public:
	int liczba_do_wypieczenia = 0;
	int liczba_w_ekwipunku = 0;
	napisy t1;
	button g1;
	button g2;
	void zmniejsz();
	skladnik(float x, float y, string nazwaObraz, string nazwaGuzik1, string nazwaGuzik2);
	skladnik() : grafika(0, 0, "kajzerka.png"),
		g1(0 + 340, 0 + 160, "kajzerka.png", "kajzerka.png"), g2(0 + 589, 0 + 160, "kajzerka.png", "kajzerka.png"), t1(0 + 495, 0 + 168, "0", Color::Black, 50) {
	}
	void rysujskladnik(RenderWindow& okno);
	void przyciskNacisnietySkladnik(zmienne& z1, Vector2i pozycjamyszy);
};

class przepis : public skladnik
{
public:
	bool warunek(skladnik& s1, skladnik& s2, skladnik& s3);
	void zrob();
	int liczbas1 = 0;
	int liczbas2 = 0;
	int liczbas3 = 0;
	float cena;
	napisy t2;
	napisy t3;
	napisy t4;
	przepis(float x, float y, int s1, int s2, int s3, float cena, string nazwaObraz, string nazwaGuzik1, 
	string nazwaGuzik2);
	przepis() : skladnik(0, 0, "kajzerka.png", "kajzerka.png", "kajzerka.png"),
		t2(0 + 412, 0 + 9, "0", Color::Black, 50), t3(0 + 532, 0 + 9, "0", Color::Black, 50), t4(0 + 651, 0 + 9, "0", Color::Black, 50), liczbas1(0), liczbas2(0), liczbas3(0), cena(1) {
	}
	void rysujprzepis(RenderWindow& okno);
	void przyciskNacisniety(Vector2i pozycjamyszy);
	bool moznaUpiec(skladnik& s1, skladnik& s2, skladnik& s3, zmienne& z1);
};

class suwak: public button
{
public:
	bool ciagnie = false;
	suwak(float x, float y, string nazwa, string nazwaZaznaczony);
	suwak() : button(0, 0, "suwak1", "suwak2") {}
	void podazaj(Vector2i pozycjamyszy, skladnik& o1);

};

class nakladka : public grafika
{
public:
	suwak s1;
	bool nakladkaAktywna = false;
	bool nakladkaskladniki = false;
	bool nakladkaprzepisy = true;
	bool nakladkaekwipunek = false;
	bool zmienstrone = false;
	nakladka(float x, float y, string nazwa);
	void ustawbool(bool przepisy, bool skladniki, bool ekwpipunek, bool wydajzamowienie, zmienne& z1);
	void zmianastrony();
};