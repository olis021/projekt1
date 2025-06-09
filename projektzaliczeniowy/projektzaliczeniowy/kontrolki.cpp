#include "kontrolki.h"
#include "menu.h"
using namespace std;
using namespace sf;

kontrolki::kontrolki(petla& p1) :p1(p1), o1(0,0, "how_to_play_tlo.png"), t1(100, 243, "1. Left click the buttons to use them.", Color::White, 50),
t2(100, 323, "2. Push ESC on your keyboard to close the game.", Color::White, 50), t3(100, 403, "3. Purchase at least 5 of each ingredient at the", Color::White, 50),
t4(100,483, "   beginning of the game.", Color::White, 50),t5(100, 563, "4. When baking, remember the recipe of a ", Color::White, 50),
t6(100, 643, "   baked good and then pick the right number", Color::White, 50), t7(100,723,"   of each ingredient to bake it.", Color::White, 50),
g1(1471, 867,"go_back.png","go_back_zaznaczony.png") {}

void kontrolki::logika(float dt, Event& e, RenderWindow& okno)
{
	Vector2i pozycjamyszy = Mouse::getPosition(okno);
	g1.wskaznikGuzik(pozycjamyszy);
}

void kontrolki::obsluga_zdarzen(Event& e, RenderWindow& okno)
{
	Vector2i pozycjamyszy = Mouse::getPosition(okno);
	if (e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
	{
		if (g1.p1(pozycjamyszy))
			p1.zmana_stanu(make_unique<menu>(p1));
	}
}

void kontrolki::wyswietl(RenderWindow& okno)
{
	o1.rysuj(okno);
	g1.rysuj(okno);
	okno.draw(t1.nap);
	okno.draw(t2.nap);
	okno.draw(t3.nap);
	okno.draw(t4.nap);
	okno.draw(t5.nap);
	okno.draw(t6.nap);
	okno.draw(t7.nap);
}

