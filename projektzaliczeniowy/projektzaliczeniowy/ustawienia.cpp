#include "ustawienia.h"
#include "Na1.h"
#include "petla.h"
using namespace std;
using namespace sf;

ustawienia::ustawienia(petla& p1):o1(300, 50, "obraz1.png")
{

}
void ustawienia::obsluga_zdarzen(Event& e, RenderWindow& okno)
{

}
void ustawienia::wyswietl(RenderWindow& okno)
{
	okno.draw(o1.guzikson);
}