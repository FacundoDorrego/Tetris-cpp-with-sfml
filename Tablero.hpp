
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
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
	int tablero[20][10];
	RectangleShape tableroShapes[20][10];
	sf::Clock reloj;
	float segundosTranscurridos;
	float intervaloActualizacion = 0.5f;
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
	void actualizarIntervalo(float i);
	virtual void draw(RenderTarget&, RenderStates) const;
};