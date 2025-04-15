#include "petla.h"
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
#pragma once
class stats:public status_gry
{
	petla& p1;
	napisy t1;
	button g1;
	napisy t2;
	button g2;
	zmienne z1 = zmienne();

public:
	stats(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt) override;
	void wyswietl(RenderWindow& okno) override;

};
