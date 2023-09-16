#include <iostream>
#include "Lista.h"

Lista <int>* coleccion = new Lista<int>();

int main()
{
	int count = 0;
	int elem, elementos;
	do {
		cout << "Ingrese un elemento: "; cin >> elem;
		coleccion->agregarFinal(elem);
		count++;
	} while (count < 5);
	for (int i = 0; i < 5; i++) {
		elementos = coleccion->obtenerPos(i);
		cout << elementos << endl;
	}
}