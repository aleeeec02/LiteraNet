#include <string>
#include "Libro.h"
#include "Usuario.h"

using namespace std;

class Reserva : public Libro, Usuario {
	string fechaReserva;
	Libro* libro;
	Usuario* usuario;
public:
	Reserva(Usuario* user, Libro* lib) { this->fechaReserva = "01/10/23"; this->usuario = user; this->libro = lib; }
	Reserva() {};
	void generarReserva(Usuario* user, Libro* lib) {
		this->usuario = user;
		this->libro = lib;
	}
	void getReserva() {
		cout << fechaReserva;
	}
	void addLibro(Libro *lib) {
		this->libro = lib;
	}
	void addUsuario(Usuario *user) {
		this->usuario = user;
	}
	void mostrarLibro() {
		cout << this->libro->getCodigo() << endl;
		cout << this->libro->getNombre() << endl;
	}	
	void mostrarUsuario() {
		cout << this->usuario->getCodigo() << endl;
		cout << this->usuario->getNombre() << endl;
	}
	void mostrarDetallesReserva() {
		cout << "*************** DETALLES DE RESERVA ******************"<<endl;
		cout << "Libro: "<< this->libro->getNombre() << endl;
		cout << "Reservado por : " << this->usuario->getNombre() << endl;
		cout << "Codigo de Usuario : " << this->usuario->getCodigo() << endl;
		cout << "Codigo de Libro: " << this->libro->getCodigo() << endl;
		cout << "Fecha de Reserva: " << this->fechaReserva << endl;
	}
};