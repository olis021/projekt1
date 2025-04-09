#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class status_gry
{
public:
	virtual void obsluga_zdarzen(Event& e, RenderWindow& okno) = 0;
	virtual void wyswietl(RenderWindow& okno) = 0;
	virtual ~status_gry() =default;
};
