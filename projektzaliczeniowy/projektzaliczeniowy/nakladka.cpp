#include "nakladka.h"
extern int monetki = 10;
przepis::przepis(float x, float y, float a, float b, float c, float d, float m, float n, int cena, string nazwaObraz, string nazwaGuzik1, string nazwaGuzikZaznaczony1,
	string nazwaGuzik2, string nazwaGuzikZaznaczony2): grafika(x, y, nazwaObraz),
	g1(x + a, y + b, nazwaGuzik1, nazwaGuzikZaznaczony1), g2(x + c, y + d, nazwaGuzik2, nazwaGuzikZaznaczony2), t1(m,n, "0", Color::Black, 30), cena(cena) {
}
void przepis::rysujprzepis(RenderWindow& okno)
{
	this->rysuj(okno);
	g1.rysuj(okno);
	g2.rysuj(okno);
	t1.nap.setString(to_string(this->liczba_do_wypieczenia));
	okno.draw(t1.nap);
}

void przepis::zrob()
{//dodac obecne monety
	int koszt = liczba_do_wypieczenia * cena;
	monetki = monetki - koszt;
	liczba_w_ekwipunku += liczba_do_wypieczenia;
	liczba_do_wypieczenia = 0;
}
void przepis::ilosc()
{

}

void przepis::skladnik()
{

}

suwak::suwak(float x, float y, string nazwa, string nazwaZaznaczony) : button(x, y, nazwa, nazwaZaznaczony) {}

void suwak::podazaj(Vector2i pozycjamyszy)
{
	this->zmienPolozenie(this->x, this-> y + pozycjamyszy.y);
}
nakladka::nakladka(float x, float y, string nazwa) : grafika(x, y, nazwa) {}

