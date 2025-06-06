#include "nakladka.h"
extern float monetki = 10;

skladnik::skladnik(float x, float y, string nazwaObraz, string nazwaGuzik1,
	string nazwaGuzik2, bool widoczny): grafika(x, y, nazwaObraz),
	g1(x + 340, y + 160, nazwaGuzik1, nazwaGuzik1), g2(x + 589, y + 160, nazwaGuzik2, nazwaGuzik2), t1(x + 495, y + 168, "0", Color::Black, 50), widoczny(widoczny) {
}

przepis::przepis(float x, float y, int s1, int s2, int s3, float cena, string nazwaObraz, string nazwaGuzik1,
	string nazwaGuzik2, bool widoczny): skladnik(x, y, nazwaObraz, nazwaGuzik1, nazwaGuzik2, widoczny), 
	t2(x + 412,y+9, "0", Color::Black,50), t3(x+532,y+ 9, "0", Color::Black, 50), t4(x + 651, y + 9, "0", Color::Black, 50), cena(cena), liczbas1(s1), liczbas2(s1), liczbas3(s3) {
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
void skladnik::przenies(float y)
{
	zmienPolozenie(this->x,y);
	this->g1.zmienPolozenie(this->x + 340, y + 160);
	this->g2.zmienPolozenie(this->x + 589, y + 160);
	this->t1.nap.move(this->x + 495, y + 168);
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
		if(this->liczba_do_wypieczenia >= 1)
		this->liczba_do_wypieczenia--;
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
	float koszt = liczba_do_wypieczenia * cena;
	monetki = monetki - koszt;
	liczba_w_ekwipunku += liczba_do_wypieczenia;
	liczba_do_wypieczenia = 0;
}

bool przepis::warunek(skladnik& s1, skladnik& s2, skladnik& s3)
{
	return(this->liczbas1 == s1.liczba_do_wypieczenia && this->liczbas2 == s2.liczba_do_wypieczenia && this->liczbas3 == s3.liczba_do_wypieczenia);
}

void przepis::przeniesPrzepis(float y)
{
	this->zmienPolozenie(this->x, this->y + y);
    float baseX = this->x;
    float baseY = this->y;

    this->t1.zmienPolozenie(baseX + 495, baseY + 168);
    this->t2.zmienPolozenie(baseX + 412, baseY + 9);
    this->t3.zmienPolozenie(baseX + 532, baseY + 9);
    this->t4.zmienPolozenie(baseX + 651, baseY + 9);
    this->g1.zmienPolozenie(baseX + 340, baseY + 160);
    this->g2.zmienPolozenie(baseX + 589, baseY + 160);
}

nakladka::nakladka(float x, float y, string nazwa) : grafika(x, y, nazwa), g1(741, 16, "przycisk_gora.png", "przycisk_gora.png"), g2(741, 939, "przycik_dol.png", "przycik_dol.png") {}

void nakladka::ustawbool(bool przepisy, bool skladnik, bool ekwpipunek, bool wydajzamowienie, zmienne& z1)
{
	this->nakladkaskladniki = skladnik;
	this->nakladkaprzepisy = przepisy;
	this->nakladkaekwipunek = ekwpipunek;
	z1.wydajzamowienie = wydajzamowienie;
}

bool przepis::moznaUpiec(skladnik& s1, skladnik& s2, skladnik& s3, zmienne& z1)
{
	return (s1.liczba_do_wypieczenia == this->liczbas1*this->liczba_do_wypieczenia &&
		s2.liczba_do_wypieczenia == this->liczbas2 * this->liczba_do_wypieczenia &&
		s3.liczba_do_wypieczenia == this->liczbas3 * this->liczba_do_wypieczenia);
}
