#pragma once
#include <string.h>
class Jugador {
private:
	char nombre[20];
	int puntaje;
	int lineas;

public:
	Jugador(const char* n = "???", int p = 0,int l=0) {
		strcpy_s(nombre, n);
		puntaje = p;
		lineas = l;
	}
	void setPuntaje(int p) {
		puntaje = p;
	}
	int getPuntaje() {
		return puntaje;
	}
	void setLineas(int l) {
		lineas = l;
	}
	int getLineas() {
		return lineas;
	}
};