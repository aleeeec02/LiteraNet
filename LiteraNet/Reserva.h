#pragma once

#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class Reserva {
	Libro* libro;
	Usuario* usuario;

public:
	//Constructor con parametros
	Reserva(Usuario* user, Libro* lib):usuario(user), libro(lib) { 
	}

	Reserva() : usuario(nullptr), libro(nullptr){};

	void generarReserva(Usuario* user, Libro* lib) {
		this->usuario = user;
		this->libro = lib;
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
	}
};