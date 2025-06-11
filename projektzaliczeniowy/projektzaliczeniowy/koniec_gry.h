#pragma once
#include "Na1.h"
#include "zmienne.h"
#include "status_gry.h"
#include "SFML/Audio.hpp"
using namespace std;
using namespace sf;
class koniec :public status_gry
///klasa pochodna od status_gry, w tym stanie gry jestes informowany o przegranej///
{
	petla& p1;
	zmienne& z1;
	grafika o1;
	button g1;
	napisy t1;
	SoundBuffer buffer_cry;
	Sound cry;

public:
	koniec(petla& p1,zmienne& z1);
	void obsluga_zdarzen(Event& e, RenderWindow& okno) override;
	void logika(float dt, Event& e, RenderWindow& okno) override;
	void wyswietl(RenderWindow& okno) override;
	virtual ~koniec() {};

};
