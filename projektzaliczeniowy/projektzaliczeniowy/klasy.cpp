#include "Na1.h"
#include "petla.h"
#include "zmienne.h"
using namespace std;
using namespace sf;
//plik z definicjami klas z plików nag³ówkowych: Na1, petla, zmienne
//DODAC OBSLUGE BLEDOW PRZY OTWIERANIU PLIKOW

bool etap1 = true;
bool etap2 = false;

obiekt::obiekt(float x, float y)
{
	this->x = x;
	this->y = y;
}

napisy::napisy(float x, float y, string tresc, Color kolor, int Size) : obiekt(x, y), kolor(kolor),tresc(tresc), Size(Size)
{
	czcionka.loadFromFile("MegamaxJonathanToo-YqOq2.ttf");
	nap.setFont(czcionka);
	nap.setString(this->tresc);
	nap.setFillColor(kolor);
	nap.setCharacterSize(Size);
	nap.setPosition(this->x, this->y);
}

grafika::grafika(float x, float y, string nazwa) : obiekt(x, y)
{
	this->nazwa = nazwa;
	this->tekstura.loadFromFile(nazwa);
	this->obraz.setTexture(this->tekstura);
	this ->obraz.setPosition(this->x, this->y);
	hitbox = obraz.getGlobalBounds();
}

void grafika::zmienTeksture(string nowaTekstura)
{
	this->tekstura.loadFromFile(nowaTekstura);
	this->obraz.setTexture(tekstura);
}

void grafika::rysuj(RenderWindow&okno)
{
	okno.draw(obraz);
}

button::button(float x, float y, string nazwa, string nazwaWskaznik): grafika(x, y, nazwa) 
{
	this->nazwaWskaznika = nazwaWskaznik;
	this->teksturaWskaznika.loadFromFile(nazwaWskaznik);
}

bool button::p1(Vector2i pozycjamyszy)
{
	{
		if (this->hitbox.contains(Vector2f(pozycjamyszy)))
		{
			cout << "kliknieto guzik";
			return true;
		}
		else return false;
	}
}


void button::wskaznikGuzik(Vector2i pozycjamyszy)
{
	if (this->p1(pozycjamyszy))
	{
		this->obraz.setTexture(this->teksturaWskaznika);
	}
	else
	{
		this->obraz.setTexture(this->tekstura);
	}
}

vector<string> zam = { "dzien dobry,poprosze ","chleby", "kajzerki" };