#pragma once

#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

class Reserva {
	string fechaReserva;
	Libro* libro;
	Usuario* usuario;

public:
	//Constructor con parametros
	Reserva(Usuario* user, Libro* lib):usuario(user), libro(lib) { 
		this->fechaReserva = "01/10/23";
//		this->usuario = user; this->libro = lib; 
	}

	Reserva() : usuario(nullptr), libro(nullptr), fechaReserva("") {};

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
		cout << "Código de Usuario : " << this->usuario->getCodigo() << endl;
		cout << "Código de Libro: " << this->libro->getCodigo() << endl;
		cout << "Fecha de Reserva: " << this->fechaReserva << endl;
	}
};