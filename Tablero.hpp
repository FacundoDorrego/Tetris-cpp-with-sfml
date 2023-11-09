
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <cstring>
#include "Piezas.hpp"
#include "Jugador.hpp"
#include "UI.hpp"

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
	float intervaloActualizacion = 1.0f;
	

	
public:
	//Constructor
	Tablero();
	//Actualizacion visual
	void actualizarTableroColor();
	bool actualizarTablero();
	void limpiarTablero();
	//colocacion de pieza
	bool colocarPieza();
	//setter
	void actualizarIntervalo(float i);
	//getter
	float getIntervaloActualizacion();
	//movimientos
	void izquierda();
	void derecha();
	void rotacion();
	//limpiar lineas
	int checkLinea();
	//Jugar
	void jugar();
	//Renderizado
	virtual void draw(RenderTarget&, RenderStates) const;
	
};