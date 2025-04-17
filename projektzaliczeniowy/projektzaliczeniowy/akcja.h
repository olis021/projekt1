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
	obiekt o1;
	napisy t1;
	napisy t2;
	napisy t3;
	napisy t4;
	float dystans;

public:
	akcja(petla& p1,zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e) override;
	void wyswietl(RenderWindow& okno) override;
	void klienci(float& dystans,float dt);
};
