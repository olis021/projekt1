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
	grafika o1;
	grafika o2;
	grafika o3;
	napisy t1;
	napisy t2;
	napisy t3;
	napisy tdu;
	napisy t4;
	napisy t5;
	napisy t6;
	napisy t7;
	nakladka n1;
	przepis kajzerka;
	przepis maka;
	przepis chlebek;
	przepis drozdze;
	przepis mleko;
	float dystans;

public:
	akcja(petla& p1, zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void akcja_zdarzenia(Vector2i pozycjamyszy);
	void klienci(float& dystans, float dt);
};

