#include"status_gry.h"
#include "petla.h"
#include "Na1.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
#pragma once
class ustawienia :public status_gry
{
	petla& p1;
	grafika o1;
	button g1;
	zmienne& z1;
public:
	ustawienia(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
};
