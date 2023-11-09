#include "Tablero.hpp"
#include "Piezas.hpp"
#include "rlutil.h"
Tablero::Tablero():segundosTranscurridos(0.0f) {
	reloj.restart();
	memset(tablero, 0, sizeof(tablero));
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			tableroShapes[i][j] = RectangleShape(Vector2f(20, 20));
			tableroShapes[i][j].setPosition(j * 20, i * 20);
			tableroShapes[i][j].setFillColor(Color(50, 50, 50));
			tableroShapes[i][j].setOutlineThickness(2);
			tableroShapes[i][j].setOutlineColor(Color(0, 0, 0));

		}
	}
}

bool Tablero::colocarPieza() {
    srand(time(NULL));
    indNuevaPieza = rand() % 7;
    vector<vector<bool>> pieza = piezas.ConsultPieza(indNuevaPieza);
    int sz = (int)pieza.size();
    
    indY = 0;
    indX = 5 - sz / 2;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (pieza[i][j]) {
                if (tablero[i][j+indX]>0) {
                    return false;
                }
                tablero[i][j+indX] = -1;
            }
        }
    }
    int color = 1 + rand() % 7;
    indColorNuevaPieza = color;
    switch (color)
    {
    case 0:
        nuevaPiezaColor=Color(Color(50, 50, 50));
        break;
    case 1:
        nuevaPiezaColor = Color(Color(255, 166, 0));
        break;
    case 2:
        nuevaPiezaColor = Color(Color(245, 152, 245));
        break;
    case 3:
        nuevaPiezaColor = Color(Color(51, 204, 153));
        break;
    case 4:
        nuevaPiezaColor = Color(Color(255, 110, 100));
        break;
    case 5:
        nuevaPiezaColor = Color(Color(255, 204, 77));
        break;
    case 6:
        nuevaPiezaColor = Color(Color(166, 166, 255));
        break;
    case 7:
        nuevaPiezaColor = Color(Color(138, 194, 247));
        break;
    }
    
    return true;
}

bool Tablero::actualizarTablero() {
    bool limite = false;
   
    int aux;
    segundosTranscurridos += reloj.restart().asSeconds();
    if (segundosTranscurridos >= intervaloActualizacion) {
        aux = 0;
        for (int i = 18; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                if (tablero[i][j] == -1) {
                    if (tablero[i + 1][j] <= 0) {
                        aux++;
                    }
                }
            }
        }
        if (aux == 4) {
            for (int i = 18; i >= 0; i--) {
                for (int j = 0; j < 10; j++) {
                    if (tablero[i][j] == -1) {
                        tablero[i][j] = 0;
                        tablero[i + 1][j] = -1;
                    }
                }
            }
        }
        else {
            aux = 0;
            for (int i = 18; i >= 0; i--) {
                for (int j = 0; j < 10; j++) {
                    if (tablero[i][j] == -1) {
                        if (tablero[i + 1][j] <= 0) {
                            aux++;
                        }
                    }
                }
            }
            if (aux != 4) {
                for (int i = 19; i >= 0; i--) {
                    for (int j = 0; j < 10; j++) {
                        if (tablero[i][j] == -1) {
                            tablero[i][j] = indColorNuevaPieza;
                        }
                    }
                }
                limite = true;
            }
        }
        segundosTranscurridos = 0.0f;
        
        
    }

    return limite;
}

void Tablero::actualizarTableroColor(){
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			switch (tablero[i][j])
			{
			
			case 0: 
				tableroShapes[i][j].setFillColor(Color(50, 50, 50));
				break;
			case 1:
				tableroShapes[i][j].setFillColor(Color(255, 166, 0));
				break;
			case 2:
				tableroShapes[i][j].setFillColor(Color(245, 152, 245));
				break;
			case 3:
				tableroShapes[i][j].setFillColor(Color(51, 204, 153));
				break;
			case 4:
				tableroShapes[i][j].setFillColor(Color(255, 110, 100));
				break;
			case 5:
				tableroShapes[i][j].setFillColor(Color(255, 204, 77));
				break;
			case 6:
				tableroShapes[i][j].setFillColor(Color(166, 166, 255));
				break;
			case 7:
				tableroShapes[i][j].setFillColor(Color(138, 194, 247));
				break;

			default:
				tableroShapes[i][j].setFillColor(nuevaPiezaColor);
				break;
			}
		}
	}
}

void Tablero::actualizarIntervalo(float i) {
    intervaloActualizacion = i;
}

float Tablero::getIntervaloActualizacion() {
    return intervaloActualizacion;
}

void Tablero::izquierda() {
    int aux = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 1; j < 10; j++) {
            if (tablero[i][j] == -1) {
                if (tablero[i][j - 1] <= 0) {
                    aux++;
                }
            }
        }
    }
    if (aux == 4) {
        indX--;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (tablero[i][j] == -1) {
                    tablero[i][j] = 0;
                    tablero[i][j - 1] = -1;
                }
            }
        }
    }
}

void Tablero::derecha() {
    int aux = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 9; j++) {
            if (tablero[i][j] == -1) {
                if (tablero[i][j + 1] <= 0) {
                    aux++;
                }
            }
        }
    }
    if (aux == 4) {
        indX++;
        for (int i = 0; i < 20; i++) {
            for (int j = 9; j >= 0; j--) {
                if (tablero[i][j] == -1) {
                    tablero[i][j] = 0;
                    tablero[i][j + 1] = -1;
                }
            }
        }
    }
}

void Tablero::rotacion() {
    int piezaX = indX;
    int piezaY = indY;
    piezas.rotarPieza(indNuevaPieza);
    vector<vector<bool>> pieza = piezas.ConsultPieza(indNuevaPieza);
    int sz = (int)pieza.size();
    bool seRealizoRotacion = false;
    int originalY = indY;

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (pieza[i][j]) {
                int nuevaY = indY + i;
                int nuevaX = indX + j;

                if (nuevaY < 0 || nuevaY >= 20 || nuevaX >= 10 || nuevaX < 0 || tablero[nuevaY][nuevaX] > 0) {
                    piezas.desRrotarPieza(indNuevaPieza);
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if (tablero[i][j] == -1) {
                tablero[i][j] = 0;
            }
        }
    }

    
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (pieza[i][j]) {
                seRealizoRotacion = true;
                tablero[indY + i][indX + j] = -1;  
            }
        }
    }

   
    if (seRealizoRotacion) {
        indY = originalY; 
    }

    
    if (seRealizoRotacion) {
        if (indY < 19) {
            indY++;
        }
    }
}



int Tablero::checkLinea() {
    int lineasBorradas = 0;

    for (int i = 19; i >= 0; ) {
        bool lineaCompleta = true;

        for (int j = 0; j < 10; j++) {
            if (tablero[i][j] == 0) {
                lineaCompleta = false;
                break;
            }
        }

        if (lineaCompleta) {
            for (int k = i; k > 0; k--) {
                for (int j = 0; j < 10; j++) {
                    tablero[k][j] = tablero[k - 1][j];
                }
            }

            for (int j = 0; j < 10; j++) {
                tablero[0][j] = 0;
            }

            lineasBorradas++;
        }
        else {
            i--;
        }
    }

    return lineasBorradas;
}


void Tablero::limpiarTablero() {
    memset(tablero,0, sizeof(tablero));
}

void Tablero::jugar() {
    Tablero tablero;
    Jugador jugador;
    UI ui;
    ArchivoJugadores archijug("puntajes.dat");
    char nombre[20];
    int derecha = 0, izquierda = 0, arriba = 0, nuevoPuntaje = 0, lineas = 0, puntaje = 0, contLineas = 0;;
    bool lineasBorradas = false, vivo = true, aumentoDificultad = false;
    float velocidadOriginal = tablero.getIntervaloActualizacion();
    ui.setLineas(lineas);
    ui.setPuntaje(puntaje);
    system("cls");
    ui.dibuCuad();
    gotoxy(55, 10);
    cout << "TETRIS" << endl;
    gotoxy(41, 13);
    cout << "Nombre del jugador: " << endl;
    gotoxy(41, 14);
    cin >> nombre;
    system("cls");
    jugador.setNombre(nombre);
    RenderWindow window(VideoMode(500, 400), "Tetris");
    window.setFramerateLimit(60);
    gotoxy(55, 10);
    cout << "LANZANDO JUEGO..." << endl;
    while (window.isOpen()) {
        Event event;
        int contLineas = 0;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (vivo) {
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
            }
            else {
                tablero.actualizarIntervalo(velocidadOriginal); 
            }
            if (tablero.actualizarTablero()) {
                int cantLineasBorradas = tablero.checkLinea();
                if (cantLineasBorradas > 0) {
                    lineasBorradas = true;
                    lineas += cantLineasBorradas;
                    nuevoPuntaje += cantLineasBorradas * 5;
                    jugador.setLineas(lineas);
                    jugador.setPuntaje(nuevoPuntaje);
                    ui.setPuntaje(nuevoPuntaje);
                    ui.setLineas(lineas);
                    contLineas = lineas;
                }
                

                if (lineas % 10 == 0 && contLineas != 0 && velocidadOriginal > 0.08f) {
                    aumentoDificultad = true;
                    float nuevaVelocidad = velocidadOriginal -= 0.1f;
                    tablero.actualizarIntervalo(nuevaVelocidad);
                    contLineas = 0;
                }
                if (!tablero.colocarPieza()) {
                    system("cls");
                    ui.dibuCuad();
                    vivo = false;
                    ui.Perder();
                    tablero.limpiarTablero();
                    gotoxy(55, 10);
                    cout << "TETRIS" << endl;
                    gotoxy(50, 13);
                    cout << "----Perdiste----" << endl;
                    gotoxy(50, 14);
                    cout << "Jugador: " << jugador.getNombre() << endl;
                    gotoxy(50, 15);
                    cout << "Lineas: " << jugador.getLineas() << endl;
                    gotoxy(50, 16);
                    cout << "Puntaje: " << jugador.getPuntaje() << endl;
                    gotoxy(50, 17);
                    cout << "----------------" << endl;
                    archijug.grabarRegistro(jugador);
                }

            }

            tablero.actualizarTableroColor();
        }
        window.clear(Color(30, 30, 30));
        window.draw(tablero);
        window.draw(ui);
        window.display();
    }

}




void Tablero::draw(RenderTarget&rt, RenderStates rs) const{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			rt.draw(tableroShapes[i][j], rs);
		}
	}
}
