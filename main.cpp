#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.hpp"
using namespace std;
using namespace sf;
int main()
{
    Tablero tablero;
    RenderWindow window(VideoMode(400, 400), "Tetris");
    window.setFramerateLimit(60);
    int derecha=0, izquierda = 0;
    tablero.colocarPieza();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            tablero.actualizarIntervalo(0.1f);
        }
        else {
            tablero.actualizarIntervalo(0.5f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && !derecha) {
            tablero.derecha();
            derecha = 1;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Right)) {
            derecha = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right) && derecha) {
            derecha++;
            if (derecha == 7) {
                derecha = 0;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) && !izquierda) {
            tablero.izquierda();
            izquierda = 1;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Left)) {
            izquierda = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left) && izquierda) {
            izquierda++;
            if (izquierda == 7) {
                izquierda = 0;
            }
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
