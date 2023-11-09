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
	Text hechoPorTexto;
	Text perdisteTexto;
	Text textoTituloLineas;
	Text textoLineas;
	bool perder = false;
	
public:
	UI();
	void setPuntaje(int);
	void Perder();
	void setLineas(int x);
	void dibuCuad();
	virtual void draw(RenderTarget&, RenderStates) const;

};