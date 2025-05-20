#include <SFML/Graphics.hpp>
#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
#pragma once
//dzeidziczy po klasie wirtualnej (musi miec te same funkcje - dlatego override - zapewnic poprawne nadpisywanie funkcji wirtualnej)
class menu :public status_gry
{
	petla& p1;
	grafika o2;
	button g1;
	button g2;

public:
	menu(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
};
