#include"status_gry.h"
#include "petla.h"
#include "Na1.h"
using namespace std;
using namespace sf;
#pragma once
class ustawienia :public status_gry
{
	obiekt o1;
public:
	ustawienia(petla& p1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
};
