#pragma once
#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
class kontrolki :public status_gry
///klasa pochodna po status_gry, która zawiera instrukcje gry///
{
	petla& p1;
	button g1;
	grafika o1;
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
public:
	kontrolki(petla& p1);
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	virtual ~kontrolki(){};
};
