#include "akcja.h"

void akcja::guzikiZaznaczenie(Vector2i pozycjamyszy)
{
	g4.wskaznikGuzik(pozycjamyszy);
	g5.wskaznikGuzik(pozycjamyszy);
	g6.wskaznikGuzik(pozycjamyszy);
	g7.wskaznikGuzik(pozycjamyszy);
	g8.wskaznikGuzik(pozycjamyszy);
	g2.wskaznikGuzik(pozycjamyszy);
	wyjdz.wskaznikGuzik(pozycjamyszy);
	maka.g1.wskaznikGuzik(pozycjamyszy);
	maka.g2.wskaznikGuzik(pozycjamyszy);
	drozdze.g1.wskaznikGuzik(pozycjamyszy);
	drozdze.g2.wskaznikGuzik(pozycjamyszy);
	woda.g2.wskaznikGuzik(pozycjamyszy);
	woda.g1.wskaznikGuzik(pozycjamyszy);
	chlebek.g1.wskaznikGuzik(pozycjamyszy);
	chlebek.g2.wskaznikGuzik(pozycjamyszy);
	kajzerka.g2.wskaznikGuzik(pozycjamyszy);
	kajzerka.g1.wskaznikGuzik(pozycjamyszy);
	if (z1.dzien > 1)
	{
		mleko.g1.wskaznikGuzik(pozycjamyszy);
		mleko.g2.wskaznikGuzik(pozycjamyszy);
		precel.g1.wskaznikGuzik(pozycjamyszy);
		precel.g2.wskaznikGuzik(pozycjamyszy);
	}
	if (z1.dzien > 3)
	{
		jajka.g1.wskaznikGuzik(pozycjamyszy);
		jajka.g2.wskaznikGuzik(pozycjamyszy);
		rogalik.g1.wskaznikGuzik(pozycjamyszy);
		rogalik.g2.wskaznikGuzik(pozycjamyszy);
	}
	if (z1.dzien > 6)
	{
		maslo.g1.wskaznikGuzik(pozycjamyszy);
		maslo.g2.wskaznikGuzik(pozycjamyszy);
		chalka.g1.wskaznikGuzik(pozycjamyszy);
		chalka.g2.wskaznikGuzik(pozycjamyszy);
	}
}