#include <string>
using namespace std;

class Usuario {
protected:
	string codigo;
	string nombre;
public:
	Usuario(){}
	Usuario(string codigo, string nombre ){ this->codigo = codigo; this->nombre = nombre; }
	string getCodigo() {
		return codigo;
	}
	string getNombre() {
		return nombre;
	}
};