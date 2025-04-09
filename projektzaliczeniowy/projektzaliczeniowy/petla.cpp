#include "petla.h"
#include "menu.h"
using namespace std; 
using namespace sf;
petla::petla():okno(VideoMode(1200,800),"gra o piekarzu")
{
	petla::zmana_stanu(make_unique<menu>(*this));

}
void petla::gra()
{
	while (okno.isOpen())
	{
		Event event;
		while (okno.pollEvent(event)) {
			if (event.type == Event::Closed)
				okno.close();
			obecnystan->obsluga_zdarzen(event,okno);

		}
		okno.clear();
		obecnystan->wyswietl(okno);
		okno.display();

	}
}
void petla::zmana_stanu(unique_ptr<status_gry> nowy)
{
	obecnystan = move(nowy);
}