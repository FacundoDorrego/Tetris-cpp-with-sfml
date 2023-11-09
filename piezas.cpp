#include "Piezas.hpp"

Piezas::Piezas() {
	piezas ={ 
		{{1,1},
		 {1,1}},

		{{0,0,0,0,0},
		 {0,0,1,0,0},
		 {0,0,1,1,0},
		 {0,0,0,1,0},
		 {0,0,0,0,0}},

		{{0,0,0,0,0},
		 {0,0,0,1,0},
		 {0,0,1,1,0},
		 {0,0,1,0,0},
		 {0,0,0,0,0}},

		{{0,0,0,0,0},
		 {0,0,1,1,0},
		 {0,0,1,0,0},
		 {0,0,1,0,0},
		 {0,0,0,0,0}},

		{{0,0,0,0,0},
		 {0,1,1,0,0},
		 {0,0,1,0,0},
		 {0,0,1,0,0},
		 {0,0,0,0,0}},

		{{0,0,0,0,0},
		 {0,0,1,0,0},
		 {0,0,1,1,0},
		 {0,0,1,0,0},
		 {0,0,0,0,0}},

		{{0,0,1,0},
		 {0,0,1,0},
		 {0,0,1,0},
		 {0,0,1,0}},
	};
}

vector<vector<bool>> Piezas::ConsultPieza(int ind) {
	return piezas[ind];
}

void Piezas::rotarPieza(int ind) {
	vector<vector<bool>> vAux = piezas[ind];
	int indI = 0, indJ = 0;
	int sz = (int)piezas[ind].size();
	for (int i = 0; i < sz; i++) {
		for (int j = sz - 1; j >= 0; j--) {
			piezas[ind][indI][indJ] = vAux[j][i];
			indJ++;

		}
		indI++;
		indJ = 0;
	}
}



void Piezas::desRrotarPieza(int ind){
	vector<vector<bool>> vAux = piezas[ind];
	int indI = 0, indJ = 0;
	int sz = (int)piezas[ind].size();
	for (int i = sz-1; i >=0; i--) {
		for (int j = 0; j < sz; j++) {
			piezas[ind][indI][indJ] = vAux[j][i];
			indJ++;
		}
		indI++;
		indJ = 0;
	}
}