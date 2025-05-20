#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
//klasa wirtualna - blueprint dla petli menu, petli piekarni itd
class status_gry
{
public:
	virtual void obsluga_zdarzen(Event& e, RenderWindow& okno) = 0; //co zrobic z danym zdarzeniem
	virtual void logika(float dt, Event& e, RenderWindow& okno) = 0; //opisanie mechaniki zdarzenia
	virtual void wyswietl(RenderWindow& okno) = 0; //wyswietl
	virtual ~status_gry() =default; //destruktor wirtualny - usuwa i wskaznik i klase wywolana za pomoca wskaznika
};
