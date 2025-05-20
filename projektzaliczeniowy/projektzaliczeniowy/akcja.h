#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
#pragma once
class akcja :public status_gry
{
	petla& p1;
	zmienne& z1;
	button g1;
	button g2;
	button g3;
	grafika o1;
	grafika o2;
	napisy t1;
	napisy t2;
	napisy t3;
	napisy t4;
	napisy t5;
	float dystans;

public:
	akcja(petla& p1,zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	/*void klientspecjalny(float& dystans,float dt);
	void klienci(float& dystans, float dt);*/
};
