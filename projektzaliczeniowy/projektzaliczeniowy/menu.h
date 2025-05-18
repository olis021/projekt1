#include <SFML/Graphics.hpp>
#include "petla.h"
#include "Na1.h"
#include "status_gry.h"
using namespace std;
using namespace sf;
#pragma once
class menu :public status_gry
{
	petla& p1;
	obiekt o2;
	button g1;


public:
	menu(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	void logika(float dt, Event& e) override;
};
