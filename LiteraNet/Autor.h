#pragma once
//Esta clase sera con Archivos, sera la unica manera de agregar autores
#include "Persona.h"
#include "common-dependencies.h"

class Autor : public Persona {
public:
	Autor() :Persona() { this->NumLibros = 0; this->alias = ""; }
	Autor(string nom, string ape, int ed, int d, string cor, int numlib, string al) :Persona(nom, ape, ed, d, cor), NumLibros(numlib), alias(al) {}

	void setNumLibros(int nl) { this->NumLibros = nl; }
	void setAlias(int al) { this->alias = al; }

	int getNumLibros() { return this->NumLibros; }
	string getAlias() { return this->alias; }
private:
	int NumLibros;
	string alias;
};
