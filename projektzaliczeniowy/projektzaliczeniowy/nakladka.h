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
	bool widoczny;
	napisy t1;
	button g1;
	button g2;
	void zmniejsz();
	skladnik(float x, float y, string nazwaObraz, string nazwaGuzik1, string nazwaGuzik2, bool widoczny);
	skladnik() : grafika(0, 0, "kajzerka.png"),
		g1(0 + 340, 0 + 160, "kajzerka.png", "kajzerka.png"), g2(0 + 589, 0 + 160, "kajzerka.png", "kajzerka.png"), 
		t1(0 + 495, 0 + 168, "0", Color::Black, 50), widoczny(false){
	}
	void rysujskladnik(RenderWindow& okno);
	void przyciskNacisnietySkladnik(zmienne& z1, Vector2i pozycjamyszy);
	void przenies(float y);
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
	string nazwaGuzik2, bool widoczny);
	przepis() : skladnik(0, 0, "kajzerka.png", "kajzerka.png", "kajzerka.png", false),
		t2(0 + 412, 0 + 9, "0", Color::Black, 50), t3(0 + 532, 0 + 9, "0", Color::Black, 50), t4(0 + 651, 0 + 9, "0", Color::Black, 50), 
		liczbas1(0), liczbas2(0), liczbas3(0), cena(1) {
	}
	void rysujprzepis(RenderWindow& okno);
	void przyciskNacisniety(Vector2i pozycjamyszy);
	bool moznaUpiec(skladnik& s1, skladnik& s2, skladnik& s3, zmienne& z1);
	void przeniesPrzepis(float y);
};

class nakladka : public grafika
{
public:
	button g1;
	button g2;
	bool nakladkaAktywna = false;
	bool nakladkaskladniki = false;
	bool nakladkaprzepisy = true;
	bool nakladkaekwipunek = false;
	nakladka(float x, float y, string nazwa);
	void ustawbool(bool przepisy, bool skladniki, bool ekwpipunek, bool wydajzamowienie, zmienne& z1);
};