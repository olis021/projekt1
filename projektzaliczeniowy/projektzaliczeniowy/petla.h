#pragma once
#include "SFML/Graphics.hpp"
#include "status_gry.h"
#include <iostream>
#include <memory>
#include "zmienne.h"
using namespace std;
using namespace sf;
class petla
{
protected:
	RenderWindow okno;
	unique_ptr<status_gry> obecnystan;
public:
	zmienne k1;
	petla();
	void gra();
	void zmana_stanu(unique_ptr<status_gry> nowy);
};

