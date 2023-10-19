#ifndef PIEZAS_HPP
#define PIEZAS_HPP

#include <iostream>
#include <vector>

using namespace std;

class Piezas {
private:
	vector < vector < vector<bool>>> piezas;
public:
	Piezas();
	vector<vector<bool>> ConsultPieza(int ind);
	void rotarPieza(int ind);
	void desRotarPieza(int ind);
};

#endif // PIEZAS_HPP