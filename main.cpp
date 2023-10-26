#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.hpp"
#include "Jugador.hpp"
using namespace std;
using namespace sf;
int main()
{
    Tablero tablero;
    Jugador jugador;
    RenderWindow window(VideoMode(400, 400), "Tetris");
    window.setFramerateLimit(60);
    int derecha = 0, izquierda = 0, arriba = 0, nuevoPuntaje = 0, lineas = 0;
    bool lineasBorradas = false;
    tablero.colocarPieza();
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
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
            if (derecha == 6) {
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
            if (izquierda == 6) {
                izquierda = 0;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && !arriba) {
            tablero.rotacion();

            arriba = 1;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Up)) {
            arriba = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            tablero.actualizarIntervalo(0.1f);  
        } else {
            tablero.actualizarIntervalo(1.0f);  
        }

        
        if (tablero.actualizarTablero()) {
            int cantLineasBorradas = tablero.checkLinea();
            if (cantLineasBorradas > 0) {
                lineasBorradas = true;
                lineas += cantLineasBorradas;
                nuevoPuntaje += cantLineasBorradas * 5;
                jugador.setLineas(lineas);
                jugador.setPuntaje(nuevoPuntaje);
            }
            
            if (!tablero.colocarPieza()) {
                cout << "Perdiste" << endl;
                window.close();
            }
            
        }
      
        tablero.actualizarTableroColor();
       
        cout <<"Puntaje jugador: "<< jugador.getPuntaje() << endl;
        cout << "Lineas jugador: " << jugador.getLineas() << endl;
        
        

       
        
        window.clear(Color(30, 30, 30));
        window.draw(tablero);
        window.display();
    }

    return 0;
}
