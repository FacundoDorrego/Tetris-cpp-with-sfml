#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "rlutil.h"
using namespace std;
using namespace sf;

int main()
{
    Tablero tablero;
    Jugador jugador;
    UI ui;
    ArchivoJugadores archijug("puntajes.dat");
    int opcion;
    bool juego = true;

    while (juego) {
        ui.dibuCuad();
        gotoxy(55, 10);
        cout << "TETRIS" << endl;
        gotoxy(41, 13);
        cout << "1- JUGAR " << endl;
        gotoxy(41, 14);
        cout << "2- MOSTRAR PUNTAJES " << endl;
        gotoxy(41, 15);
        cout << "8- BORRAR PUNTAJES " << endl;
        gotoxy(41, 16);
        cout << "0- SALIR " << endl;
        gotoxy(41, 17);
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
        case 1:
            tablero.jugar();
            system("cls");
            break;
        case 2:
            archijug.mostrarPuntajes();
            system("pause");
            system("cls");

            break;
        case 8:
            archijug.borrarPuntajes();
            system("pause");
            system("cls");
            break;
        case 0:
            juego = false;
            break;
        default:
            cout << "OPCION INCORRECTA " << endl;
            break;
        }
    }

    return 0;
}
