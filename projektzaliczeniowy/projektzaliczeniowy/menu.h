#pragma once
#include <SFML/Graphics.hpp>
#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
using namespace std;
using namespace sf;

class menu :public status_gry
{
	petla& p1;
	grafika o2;
	button g1;
	button g2;
	button g3;

public:
	menu(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
};
