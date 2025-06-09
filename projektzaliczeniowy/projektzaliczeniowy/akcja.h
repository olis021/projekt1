#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
#pragma once
#include "zmienne.h"
#include "nakladka.h"

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
	button g9;
	button wyjdz;
	button odmow;
	grafika o1;
	grafika o2;
	grafika o3;
	grafika chleb_e;
	grafika rogal_e;
	grafika kajzerka_e;
	grafika chalka_e;
	grafika precel_e;
	grafika chmurka;
	grafika zamowienie;
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
	napisy t11, t12, t13, t14;
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
	Music mruczenie;
	SoundBuffer buffer_meow;
	Sound meow;
	float dystans;
protected:

	int za = 1, ile = 1, n = 2;
	int numerkota = 0;
	int ostatnikot = 0;
	bool sprzedane = false;
	bool hop = false;
	int hopka = 0;
	bool losowanie = false;
	bool losowanie2 = false;
	bool odmowa = false;
	bool kotek_najwyzej = false;

public:
	akcja(petla& p1, zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void klienci(float& dystans, float dt);
	void guzikiZaznaczenie(Vector2i pozycjamyszy);
	virtual ~akcja() {};
};

