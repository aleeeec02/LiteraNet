#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

#include "Lista.h"
#include "Usuario.h"

using namespace std;


auto getEdadValidada = []() -> int {
	int edad;

	while (true) {
		cout << "Ingresar edad: ";
		cin >> edad;

		if (cin.fail()) {
			cin.clear(); // borrar el búfer de entrada para restaurar cin a un estado utilizable
			cin.ignore(INT_MAX, '\n'); // ignorar la última entrada si cin.fail es true
			cout << "Por favor, ingrese un número válido para la edad." << endl;
		}
		else if (edad < 0 || edad > 120)
		{
			cout << "Por favor, ingrese una edad válida (0-120)." << endl;
		}
		else
		{
			cin.ignore();
			return edad; // good input J4EMCM6Z ESP003
		}
	}
	};

class GestorDeUsuarios {
private:
	Lista <Usuario*>* lst_usuario;
public:
	GestorDeUsuarios() {
		lst_usuario = new Lista<Usuario*>();
		cargarUsuariosDesdeArchivo();
	}
	~GestorDeUsuarios() {
		delete lst_usuario;
	}

	void cargarUsuariosDesdeArchivo() {
		ifstream archivoEntradaUsuarios("usuarios.txt");
		string linea;

		while (getline(archivoEntradaUsuarios, linea)) {

		}
	}
	void crearUsuario2(int num) {

		string nombre, apellido, correo, direccion;
		int edad, dni;

		cout << "------Registrar Usuario------" << endl;
		cout << "Ingresar nombre: ";
		cin >> nombre;
		cout << "Ingresar apellido: ";
		cin >> apellido;

		edad = getEdadValidada();
		cout << "Ingresar correo: ";
		cin >> correo;
		cout << "Ingresar DNI: ";
		cin >> dni;
		cout << "Ingresar direccion: ";
		cin >> direccion;
		Usuario* user = new Usuario(nombre, apellido, edad, dni, correo, direccion);
		lst_usuario->agregarPos(user, num);

		guardarUsuarioEnArchivo(user);
	}

	void crearUsuario2(int num, string nombre, string apellido, int edad, int dni, string correo, string direccion) {
		Usuario* user = new Usuario(nombre, apellido, edad, dni, correo, direccion);
		lst_usuario->agregarPos(user, num);
		guardarUsuarioEnArchivo(user);
	}

	void guardarUsuarioEnArchivo(Usuario* user) {
		ofstream archivoSalidaUsuarios("usuarios.txt", ios::app);
		if (archivoSalidaUsuarios.is_open()) {
			archivoSalidaUsuarios << user->getNombre() << "," << user->getApellido() << "," << user->getEdad() << "," << user->getEdad() << "," << user->getCorreo() << user->getDNI() << "," << user->getDireccion() << endl;
			archivoSalidaUsuarios.close();
		}
		else {
			cout << "No se pudo abrir el archivo para escribir.\n";
		}
	}

	void MostrarUsuarios() {
		for (int i = 0; i < lst_usuario->longitud(); i++) {
			cout << "Codigo de usuario: " << lst_usuario->obtenerPos(i)->getUserID() << endl;
		}
	}

};