#include "Na1.h"
using namespace std;
using namespace sf;
int main()
{
    RenderWindow okno(VideoMode(1200, 800), "GraKotPiekarz");
        if (!arial.loadFromFile("ArialCE.ttf"))
        {
            cout << "nie dziala";
        }
    button g1(450,300,"guzik.png");
    
    napisy n1(465, 250, "super gra o piekarzu");
    obiekt o1(300, 50, "obraz1.png");
    button g2(450, 600, "tbc.png");
    while (okno.isOpen()) {
        Event event;
        while (okno.pollEvent(event)) {
            if (event.type == Event::Closed)
                okno.close();

            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
            {
                Vector2i pozycjamyszy = Mouse::getPosition(okno);
                    g1.p1(pozycjamyszy);
                
            }
            
        }

            okno.clear(tlo);
        if(etap1)
        {
            okno.draw(n1.nap);
            okno.draw(g1.guzikson);
        }
        if (etap2)
        {
            okno.draw(o1.guzikson);
            okno.draw(g2.guzikson);
            
        }
            okno.display();
    }

    return 0;
}