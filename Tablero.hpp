
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>
#include "Piezas.hpp"
#include <time.h>
using namespace sf;

class Tablero : public Drawable {
private:
	Piezas piezas;
	int indNuevaPieza, indColorNuevaPieza;
	Color nuevaPiezaColor;
	int indX, indY;
	int temporizador = 0;
	int limiteTemporizador = 40;
	int tablero[20][10];
	RectangleShape tableroShapes[20][10];
public:
	//Constructor
	Tablero();
	//Actualizacion visual
	void actualizarTableroColor();
	bool actualizarTablero();
	//colocacion de pieza
	bool colocarPieza();
	//Renderizado
	void actualizarLimiteTemp(int l);
	virtual void draw(RenderTarget&, RenderStates) const;
};