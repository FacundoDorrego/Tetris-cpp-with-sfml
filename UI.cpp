#include "UI.hpp"
#include "rlutil.h"
UI::UI() {
	if (!fuente.loadFromFile("ka1.ttf")) {
		cout << "Error al cargar fuente" << endl;
	}
	textoTituloPuntaje.setFont(fuente);
	textoTituloPuntaje.setFillColor(Color::White);
	textoTituloPuntaje.setPosition(Vector2f(250, 25));
	textoTituloPuntaje.setString("Puntaje");

	
	
	textoTituloLineas.setFont(fuente);
	textoTituloLineas.setFillColor(Color::White);
	textoTituloLineas.setPosition(Vector2f(265, 200));
	textoTituloLineas.setString("Lineas");
	
	textoPuntaje.setFont(fuente);
	textoPuntaje.setFillColor(Color::White);
	textoPuntaje.setPosition(Vector2f(295, 70));

	

	textoLineas.setFont(fuente);
	textoLineas.setFillColor(Color::White);
	textoLineas.setPosition(Vector2f(295, 245));

	hechoPorTexto.setFont(fuente);
	hechoPorTexto.setFillColor(Color::White);
	hechoPorTexto.setPosition(Vector2f(215, 370));
	hechoPorTexto.setString("Hecho por Facundo Dorrego");
	hechoPorTexto.setCharacterSize(14);

	perdisteTexto.setFont(fuente);
	perdisteTexto.setFillColor(Color::White);
	perdisteTexto.setPosition(Vector2f(24, 150));
	perdisteTexto.setString("Perdiste");
	perdisteTexto.setCharacterSize(24);



}
void UI::setPuntaje(int x) {
	if (x <= 0) {
		textoPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 99)
	{
		textoPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 999)
	{
		textoPuntaje.setString("0" + to_string(x));
	}
	else if (x <= 9999)
	{
		textoPuntaje.setString(to_string(x));
	}
	else {
		textoPuntaje.setString("9999");
	}
}

void UI::setLineas(int x) {
	if (x <= 0) {
		textoLineas.setString("00" + to_string(x));
	}
	else if (x <= 99)
	{
		textoLineas.setString("00" + to_string(x));
	}
	else if (x <= 999)
	{
		textoLineas.setString("0" + to_string(x));
	}
	else if (x <= 9999)
	{
		textoLineas.setString(to_string(x));
	}
	else {
		textoLineas.setString("9999");
	}
}

void UI::Perder() {
	perder = true;
}



void UI::dibuCuad() {
	for (int i = 0; i < 11; i++) {
		rlutil::CursorHider hider;
		rlutil::msleep(5);
		gotoxy(30, (9 + i));
		cout << "|";
		gotoxy(90, (9 + i));
		cout << "|";
	}
	for (int i = 0; i < 61; i++) {
		rlutil::CursorHider hider;
		rlutil::msleep(5);
		gotoxy((30 + i), 8);
		cout << "-";
		gotoxy((30 + i), 20);
		cout << "-";
	}
}

void UI::draw(RenderTarget& rt, RenderStates rs) const {
	rt.draw(textoTituloPuntaje, rs);
	rt.draw(textoPuntaje, rs);
	rt.draw(textoLineas, rs);
	rt.draw(textoTituloLineas, rs);
	rt.draw(hechoPorTexto, rs);
	if (perder) {
		rt.draw(perdisteTexto, rs);
	}

}