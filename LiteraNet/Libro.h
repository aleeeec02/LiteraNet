#include <string>
using namespace std;

class Libro {
protected:
	string codigo;
	string nombre;
public:
	Libro(string codigo, string nombre) { this->codigo = codigo; this->nombre = nombre; }
	Libro() {}
	string getCodigo() {
		return codigo;
	}
	string getNombre() {
		return nombre;
	}
};