#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "status_gry.h"
#include <iostream>
#include <memory>
#include "zmienne.h"
using namespace std;
using namespace sf;
class petla
///p�tla gry///
{
protected:
	RenderWindow okno; //SFML: tworzenie okna z mo�liwo�ci� rysowania obiekt�w na ekranie
	unique_ptr<status_gry> obecnystan; //Memory: zmiany statusu gry, inteligentny wska�nik 
	//- �atwe zarz�dzanie dynamiczne pami�ci�, zapobiega wyciekom, zwalnia pami�� gdy wska�nik zostaje zniszczony
	Music muzyka; //SFML: muzyka lecaca w tle
public:
	zmienne k1;
	petla();
	void gra();
	void zmana_stanu(unique_ptr<status_gry> nowy);
};

