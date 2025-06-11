#include "petla.h"
#include "menu.h"
using namespace std; 
using namespace sf;


petla::petla():okno(VideoMode(1920,1080), "Mr. Soft Paws' Bakery", Style::Titlebar | Style::Close)
///tworzy okno 1920x1080 z paskiem tytu�u z mo�liwo�ci� zamkni�cia okna///
///SFML: VideoMode okre�la rozmiary okna///
{
	//ustawienie muzyki w tle
	if(!muzyka.openFromFile("muzyka_tlo.ogg")) cerr << "Nie udalo sie zaladowac muzyki!" << endl;;
	muzyka.setLoop(true); 
	muzyka.setVolume(60);
	muzyka.play();
	petla::zmana_stanu(make_unique<menu>(*this)); //rozpoczecie gry od menu, utworzenie obiektu stanu stanu gry na stercie, poprzedni stan zostaje usuni�ty
}

void petla::gra()
{
Clock czas; //SFML: pomiar czasu mi�dzy klatkami dt
Vector2i poprzedniaPozycjaMyszy = Mouse::getPosition(okno);
	while (okno.isOpen()) //p�tla gry
	{
		Event event;
		while (okno.pollEvent(event)) {
			if (event.type == Event::Closed)
				okno.close(); //zamkniecie okna przyciskiem x w pasku tytulu
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
					okno.close();//zamkniecie aplikacji za pomoca ESC
			}
			obecnystan->obsluga_zdarzen(event,okno);
		}
		float dt = czas.restart().asSeconds(); // zwraca czas jaki minal od poprzedniego restartu
		obecnystan->logika(dt,event, okno);
		okno.clear(); //SFML: wyczy�� ekran
		obecnystan->wyswietl(okno);
		okno.display(); //SFML: wy�wietl wyrenderowane elementy
	}
}
void petla::zmana_stanu(unique_ptr<status_gry> nowy)
///zmie� stan gry///
{
	obecnystan = move(nowy);
}