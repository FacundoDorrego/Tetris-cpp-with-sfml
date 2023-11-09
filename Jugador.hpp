#pragma once
#include <string.h>
class Jugador {
private:
	char nombre[20];
	int puntaje;
	int lineas;

public:
	Jugador(const char	*n = "???", const int p = 0,const int l=0) {
		strcpy(nombre, n);
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
	void setNombre(char *n) {
		strcpy(nombre, n);
	}
	const char* getNombre() {
		return nombre;
	}
};

class ArchivoJugadores {
private:
	char nombre[20];
public:
	ArchivoJugadores(const char* n) {
		strcpy(nombre, n);
	}
	Jugador leerRegistro(int pos) {
		Jugador reg;
		
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) return reg;
		fseek(p, sizeof reg * pos, 0);
		fread(&reg, sizeof reg, 1, p);
		fclose(p);
		return reg;
	}
	int contarRegistros() {
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) return -1;
		fseek(p, 0, 2);
		int tam = ftell(p);
		fclose(p);
		return tam / sizeof(Jugador);
	}
	bool grabarRegistro(Jugador reg) {
		FILE* p;
		p = fopen(nombre, "ab");
		if (p == NULL) return false;
		int escribio = fwrite(&reg, sizeof reg, 1, p);
		fclose(p);
		return escribio;
	}

	void mostrarPuntajes() {
		system("cls");
		FILE* p;
		p = fopen(nombre, "rb");
		if (p == NULL) {
			cout << "No se pudo abrir el archivo." << endl;
			return;
		}

		Jugador reg;
		int numRegistros = contarRegistros();

		if (numRegistros <= 0) {
			cout << "No hay puntajes para mostrar." << endl;
			fclose(p);
			return;
		}

		for (int i = 0; i < numRegistros; i++) {
			fseek(p, sizeof(Jugador) * i, 0);
			fread(&reg, sizeof(Jugador), 1, p);
			cout << "----------------" << endl;
			cout << "Jugador " << i + 1 << ":" << endl;
			cout << "Nombre: " << reg.getNombre() << endl;
			cout << "Puntaje: " << reg.getPuntaje() << endl;
			cout << "Lineas: " << reg.getLineas() << endl;
			cout << "----------------" << endl;
		}

		fclose(p);
	}

	void borrarPuntajes() {
		FILE* p;
		p = fopen(nombre, "wb");
		if (p == NULL) {
			cout << "No se pudo abrir el archivo." << endl;
			return;
		}
		else {
			cout << "Puntajes borrados." << endl;
		}
		fclose(p);
	}

};