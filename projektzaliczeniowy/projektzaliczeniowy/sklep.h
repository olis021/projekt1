#pragma once
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
class sklep :public status_gry
{
	petla& p1;
	grafika o1;
	button g1;
	zmienne& z1;
	button g2;
	napisy t1;

public:
	sklep(petla& p1, zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;

};
