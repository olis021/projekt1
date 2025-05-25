#pragma once
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
class end :public status_gry
{
	petla& p1;
	grafika o1;
	button g1;
	napisy t1;

public:
	end(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;

};
