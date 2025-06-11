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
///pêtla gry///
{
protected:
	RenderWindow okno; //SFML: tworzenie okna z mo¿liwoœci¹ rysowania obiektów na ekranie
	unique_ptr<status_gry> obecnystan; //Memory: zmiany statusu gry, inteligentny wskaŸnik 
	//- ³atwe zarz¹dzanie dynamiczne pamiêci¹, zapobiega wyciekom, zwalnia pamiêæ gdy wskaŸnik zostaje zniszczony
	Music muzyka; //SFML: muzyka lecaca w tle
public:
	zmienne k1;
	petla();
	void gra();
	void zmana_stanu(unique_ptr<status_gry> nowy);
};

