#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class UI : public Drawable {
private:
	Font fuente;
	Text textoPuntaje;
	Text textoTituloPuntaje;
	Text textoMaxPuntaje;
	Text textoTituloMaxPuntaje;
	Text hechoPorTexto;
	Text perdisteTexto;
	Text textoNuevoPuntaje;
	bool perder = false;
	bool nuevoPuntaje = false;
public:
	UI();
	void setPuntaje(int);
	void setMaxPuntaje(int);
	void Perder();
	void NuevoPuntaje();
	

};