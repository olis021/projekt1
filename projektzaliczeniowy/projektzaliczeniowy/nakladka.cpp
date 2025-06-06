#include "nakladka.h"
extern int monetki = 10;

skladnik::skladnik(float x, float y, string nazwaObraz, string nazwaGuzik1,
	string nazwaGuzik2): grafika(x, y, nazwaObraz),
	g1(x + 340, y + 160, nazwaGuzik1, nazwaGuzik1), g2(x + 589, y + 160, nazwaGuzik2, nazwaGuzik2), t1(x + 495, y + 168, "0", Color::Black, 50) {
}

przepis::przepis(float x, float y, int s1, int s2, int s3, int cena, string nazwaObraz, string nazwaGuzik1,
	string nazwaGuzik2): skladnik(x, y, nazwaObraz, nazwaGuzik1, nazwaGuzik2), 
	t2(x + 412,y+9, "0", Color::Black,50), t3(x+532,y+ 9, "0", Color::Black, 50), t4(x + 651, y + 9, "0", Color::Black, 50), cena(cena), liczbas1(s1), liczbas2(s2), liczbas3(s3) {
}

void przepis::rysujprzepis(RenderWindow& okno)
{
	this->rysuj(okno);
	g1.rysuj(okno);
	g2.rysuj(okno);
	t1.rysujnapisInt(okno,this->liczba_do_wypieczenia);
	t2.rysujnapisInt(okno,this->liczbas1);
	t3.rysujnapisInt(okno,this->liczbas2);
	t4.rysujnapisInt(okno,this->liczbas3);
}

void skladnik::rysujskladnik(RenderWindow& okno)
{
	this->rysuj(okno);
	g1.rysuj(okno);
	g2.rysuj(okno);
	t1.rysujnapisInt(okno, this->liczba_do_wypieczenia);
}
void skladnik::zmniejsz()
{
	if (this->liczba_do_wypieczenia >= 1)
		this->liczba_do_wypieczenia--;
}
void przepis::przyciskNacisniety(Vector2i pozycjamyszy)
{
	if (this->g1.p1(pozycjamyszy))
	{
		this->liczba_do_wypieczenia++;
	}
	if (this->g2.p1(pozycjamyszy))
	{
		this->zmniejsz();
	}
}

void skladnik::przyciskNacisnietySkladnik(zmienne& z1, Vector2i pozycjamyszy)
{
	if (this-> g1.p1(pozycjamyszy))
	{
		this->liczba_do_wypieczenia++;
	}
	if (this->g2.p1(pozycjamyszy))
	{
		this->zmniejsz();
	}
}
void przepis::zrob()
{
	int koszt = liczba_do_wypieczenia * cena;
	monetki = monetki - koszt;
	liczba_w_ekwipunku += liczba_do_wypieczenia;
	liczba_do_wypieczenia = 0;
}

bool przepis::warunek(skladnik& s1, skladnik& s2, skladnik& s3)
{
	return(this->liczbas1 == s1.liczba_do_wypieczenia && this->liczbas2 == s2.liczba_do_wypieczenia && this->liczbas3 == s3.liczba_do_wypieczenia);
}
suwak::suwak(float x, float y, string nazwa, string nazwaZaznaczony) : button(x, y, nazwa, nazwaZaznaczony) {}

void suwak::podazaj(Vector2i pozycjamyszy, skladnik& o1)
{
	o1.zmienPolozenie(o1.zwrocPolozenie().x, o1.zwrocPolozenie().y + pozycjamyszy.y);
}
nakladka::nakladka(float x, float y, string nazwa) : grafika(x, y, nazwa), s1(741, 16, "suwak.png", "suwak_zaznaczony.png") {}


void nakladka::ustawbool(bool przepisy, bool skladnik, bool ekwpipunek, bool wydajzamowienie, zmienne& z1)
{
	this->nakladkaskladniki = skladnik;
	this->nakladkaprzepisy = przepisy;
	this->nakladkaekwipunek = ekwpipunek;
	z1.wydajzamowienie = wydajzamowienie;
}
void nakladka::zmianastrony()
{
	if (this->zmienstrone=false)
	{
		this->zmienstrone = true;
	}
	if (this->zmienstrone)
	{
		this->zmienstrone = false;
	}
}
bool przepis::moznaUpiec(skladnik& s1, skladnik& s2, skladnik& s3, zmienne& z1)
{
	return (s1.liczba_do_wypieczenia == this->liczbas1*this->liczba_do_wypieczenia &&
		s2.liczba_do_wypieczenia == this->liczbas2 * this->liczba_do_wypieczenia &&
		s3.liczba_do_wypieczenia == this->liczbas3 * this->liczba_do_wypieczenia);
}
