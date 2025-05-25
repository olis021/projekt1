#pragma once
#include "petla.h"
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
class stats:public status_gry
{
	petla& p1;
	napisy t1;
	grafika o1;
	button g1;
	button g3;
	button g4;
	napisy t2;
	button g2;
	napisy t3;
	napisy t4;
	napisy t5;
	zmienne& z1;

public:
	stats(petla& p1,zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;

};
