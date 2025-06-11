#pragma once
#include "petla.h"
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
class nowy_skladnik :public status_gry
///klasa pochodna od status_gry, w tym stanie gry jestes informowany o wonym odblokowanym skladniku///
{
	petla& p1;
	napisy t1;
	grafika o1;
	grafika o2;
	button g1; 
	zmienne& z1;

public:
	nowy_skladnik(petla& p1, zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	virtual ~nowy_skladnik() {}
};

