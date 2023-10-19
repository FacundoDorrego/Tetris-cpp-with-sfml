#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.hpp"
using namespace std;
using namespace sf;
int main()
{
    Tablero tablero;
    RenderWindow window(VideoMode(400, 400), "Tetris");
    window.setFramerateLimit(5);
    tablero.colocarPieza();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            tablero.actualizarLimiteTemp(18);
        }
        else {
            tablero.actualizarLimiteTemp(60);
        }
        if (tablero.actualizarTablero()) {
            if (!tablero.colocarPieza()) {
                cout << "Perdiste" << endl;
                window.close();
            }
        }
        tablero.actualizarTablero();
        tablero.actualizarTableroColor();
        window.clear(Color(30, 30, 30));
        window.draw(tablero);
        window.display();
      
    }

    return 0;
}
