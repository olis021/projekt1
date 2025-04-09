#include "SFML/Graphics.hpp"
#include "status_gry.h"
#include <iostream>
#include <memory>
using namespace std;
using namespace sf;
#pragma once
class petla
{
protected:
	RenderWindow okno;
	unique_ptr<status_gry> obecnystan;
public:
	petla();
	void gra();
	void zmana_stanu(unique_ptr<status_gry> nowy);


};
