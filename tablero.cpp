#include "Tablero.hpp"
#include "Piezas.hpp"
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
        } else {
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
        indX++;
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

void Tablero::rotacion(){
    piezas.rotarPieza(indNuevaPieza);
    vector<vector<bool>> pieza = piezas.ConsultPieza(indNuevaPieza);
    int sz = (int)pieza.size();
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if (pieza[i][j]) {
                if (indY+i<0||indY+i>=20||indX+j>=10||tablero[indY+i][indX+j] > 0) {
                    piezas.desRotarPieza(indNuevaPieza);
                    return;
                }
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++){
            if (tablero[i][j] == -1) {
                tablero[i][j] = 0;
            }
        }
    }

    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if (pieza[i][j]) {
                tablero[indY+i][indX+j] = -1;
            }
        }
    }
}

void Tablero::draw(RenderTarget&rt, RenderStates rs) const{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			rt.draw(tableroShapes[i][j], rs);
		}
	}
}
