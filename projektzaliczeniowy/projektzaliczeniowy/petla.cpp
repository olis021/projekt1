#include "petla.h"
#include "menu.h"
using namespace std; 
using namespace sf;


petla::petla():okno(VideoMode(1920,1080), "Mr. Soft Paws' Bakery", Style::Titlebar | Style::Close)
{
	petla::zmana_stanu(make_unique<menu>(*this)); //zmiana sceny
}

void petla::gra()
{
Clock czas;
	while (okno.isOpen())
	{
		Event event;
		while (okno.pollEvent(event)) {
			if (event.type == Event::Closed)
				okno.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
					okno.close();
			}
			obecnystan->obsluga_zdarzen(event,okno);
		}
		float dt = czas.restart().asSeconds();
		obecnystan->logika(dt,event, okno);
		okno.clear();
		obecnystan->wyswietl(okno);
		okno.display();
	}
}
void petla::zmana_stanu(unique_ptr<status_gry> nowy)
{
	obecnystan = move(nowy);
}