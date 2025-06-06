#pragma once
#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
#include "zmienne.h"
#include "nakladka.h"
#include <deque>
using namespace std;
using namespace sf;
class akcja :public status_gry
{
	petla& p1;
	zmienne& z1;
	button g1;
	button g2;
	button g3;
	button g4;
	button g5;
	button g6;
	button g7;
	button g8;
	grafika o1;
	grafika o2;
	grafika o3;
	napisy t1;
	napisy t2;
	napisy t3;
	napisy t4;
	napisy t5;
	napisy t6;
	napisy t7;
	napisy t8;
	napisy t9;
	napisy t10;
	nakladka n1;
	przepis kajzerka;
	przepis chlebek;
	przepis rogalik;
	przepis precel;
	przepis chalka;
	skladnik maka;
	skladnik drozdze;
	skladnik mleko;
	skladnik jajka;
	skladnik woda;
	skladnik maslo;
	float dystans;
	deque<przepis*> przepisy_zbior = { &chlebek, &kajzerka, &rogalik};
	deque<skladnik*> skladniki_widoczne = { &maka, &woda, &drozdze};
public:
	akcja(petla& p1, zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void zmianastrony(Vector2i pozycjamyszy);
	void akcja_zdarzenia(Vector2i pozycjamyszy);
	void klienci(float& dystans, float dt);
	void guzikiZaznaczenie(Vector2i pozycjamyszy);
	void przewinPrzepisy(int przesuniecieY);
};

