#include "UI.hpp"
UI::UI() {
	if (!fuente.loadFromFile("ka1.tff")) {
		cout << "Error al cargar fuente" << endl;
	}
	textoTituloPuntaje.setFont(fuente);
	textoTituloPuntaje.setFillColor(Color::White);
	textoTituloPuntaje.setPosition(Vector2f(235, 25));
	textoTituloPuntaje.setString("Puntaje");

	textoTituloMaxPuntaje.setFont(fuente);
	textoTituloMaxPuntaje.setFillColor(Color::White);
	textoTituloMaxPuntaje.setPosition(Vector2f(225, 200));
	textoTituloMaxPuntaje.setString("Maximo puntaje");
	textoTituloMaxPuntaje.setCharacterSize(20);
	
	textoPuntaje.setFont(fuente);
	textoPuntaje.setFillColor(Color::White);
	textoPuntaje.setPosition(Vector2f(250, 70));

	textoPuntaje.setFont(fuente);
	textoPuntaje.setFillColor(Color::White);
	textoPuntaje.setPosition(Vector2f(265, 245));

	hechoPorTexto.setFont(fuente);
	hechoPorTexto.setFillColor(Color::White);
	hechoPorTexto.setPosition(Vector2f(260, 370));
	hechoPorTexto.setString("Hecho por Facundo Nehuen Dorrego");
	hechoPorTexto.setCharacterSize(16);

	perdisteTexto.setFont(fuente);
	perdisteTexto.setFillColor(Color::White);
	perdisteTexto.setPosition(Vector2f(8, 150));
	perdisteTexto.setString("Perdiste :c");
	perdisteTexto.setCharacterSize(16);

	textoNuevoPuntaje.setFont(fuente);
	textoNuevoPuntaje.setFillColor(Color::White);
	textoNuevoPuntaje.setPosition(Vector2f(8, 150));
	textoNuevoPuntaje.setString("Nuevo puntaje");
	textoNuevoPuntaje.setCharacterSize(25);

}
void UI::setPuntaje(int x) {
	if (x <= 0) {
		textoPuntaje.setString("000" + to_string(x));
	}
	else if (x <= 99)
	{
		textoPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 999)
	{
		textoPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 9999)
	{
		textoPuntaje.setString(to_string(x));
	}
	else {
		textoPuntaje.setString("9999");
	}
}
void UI::setMaxPuntaje(int x) {
	if (x <= 0) {
		textoMaxPuntaje.setString("000" + to_string(x));
	}
	else if (x <= 99)
	{
		textoMaxPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 999)
	{
		textoMaxPuntaje.setString("00" + to_string(x));
	}
	else if (x <= 9999)
	{
		textoMaxPuntaje.setString(to_string(x));
	}
	else {
		textoMaxPuntaje.setString("9999");
	}
}
void UI::Perder() {
	perder = true;
}
void UI::NuevoPuntaje() {
	nuevoPuntaje = true;
}

