#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class status_gry
///klasa abstrakcyjna statusu gry///
{
public:
	virtual void obsluga_zdarzen(Event& e, RenderWindow& okno) = 0; //obsluga zdarzen takich jak klikniecia myszki
	virtual void logika(float dt, Event& e, RenderWindow& okno) = 0; //logika stanu gry - animacje, podswietlane guziki itd
	virtual void wyswietl(RenderWindow& okno) = 0; //renderowanie wszystkiego na ekranie
	virtual ~status_gry() =default;
};
