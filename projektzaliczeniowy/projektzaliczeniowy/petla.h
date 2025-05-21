#include "SFML/Graphics.hpp"
#include "status_gry.h"
#include <iostream>
#include <memory>
#include "zmienne.h"
using namespace std;
using namespace sf;
#pragma once
class petla
{
protected:
	RenderWindow okno;
	unique_ptr<status_gry> obecnystan;
	View widok = okno.getDefaultView();
	const float SKALA = 16.0f /9.0f;
public:
	zmienne k1;
	petla();
	void gra();
	void zmana_stanu(unique_ptr<status_gry> nowy);
};

