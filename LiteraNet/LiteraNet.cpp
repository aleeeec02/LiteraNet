#pragma once
#include <iostream>
#include <stdio.h>

#include "Usuario.h"

#include "Review.h"


#include "Pago.h"
#include "Libro.h"
#include "Reserva.h"

#include "Lista.h"
#include "Cola.h"


#include <string>
#include <fstream>
#include <sstream>

#include <locale>


//Colecciones
Lista<Review*>* lst_review = new Lista<Review*>();
Cola<Reserva*>* cola_reserva = new Cola<Reserva*>();
Lista<Libro*>* lst_libro = new Lista<Libro*>();
Lista<Usuario*>* lst_usuario = new Lista<Usuario*>();

// ****************************************//
// VALIDACIONES NECESARIAS			       //
// para entradas de datos usando lambda    //
// ****************************************//


//Función para verificar si el username existe
auto usernameYaExistente = make_shared<function<bool(const  string)>>(
	[](const string& username) -> bool {

	ifstream archivoEntrada("usernames.txt");
	string linea;

	//Lee cada línea del archivo
	while (getline(archivoEntrada, linea)) {
		istringstream iss(linea); // Usar istringstream para dividir las líneas

		string usernameYaExistente;

		// Si no se puede leer el username del usuario, terminar ciclo
		if (!(iss >> usernameYaExistente)) { break; }

		if (usernameYaExistente == username) {
			return true;
		}
	}
	return false; // Retorna falso si el usuario no existe (bool)
	}
);

//Función para crear un nuevo usuario
auto crearUsuario = [](const string username, const string& codigoUsername) {
	//if (usernameYaExistente(username)) {
		cout << "El username ya está ocupado." << endl;
		return;
	//}
	ofstream archivoSalida("usernames.txt", ios::app); // 'append' mode (modo 'añadir')
	archivoSalida << username << "," << codigoUsername << "\n"; // Add a comma for easy parsing later (añadir una coma para facilitar el análisis más tarde)
};



//Prospecto de Menu
void menu() {
	cout << "Ingrese una Opción: " << endl;;
	cout << "Registrar Usuario" << endl;
	cout << "Registrar Libro" << endl;
}

//Busca un Usuario de la Lista por codigo
Usuario* buscarUsuario(string codigo) {
	for (int i = 0; i < lst_usuario->longitud(); i++) {
		if (lst_usuario->obtenerPos(i)->getCodigo() == codigo) {
			cout << "Se encontró el Usuario: " << endl;
			cout << lst_usuario->obtenerPos(i)->getCodigo() << endl;
			cout << lst_usuario->obtenerPos(i)->getNombre() << endl;
			return lst_usuario->obtenerPos(i);
		}
	}
	cout << "Error: Usuario No Registrado";
}

//Busca un Usuario de la Lista por codigo
Libro* buscarLibro(string codigo) {
	for (int i = 0; i < lst_libro->longitud(); i++) {
		if (lst_libro->obtenerPos(i)->getCodigo() == codigo) {
			cout << "Se encontró el Libro: " << endl;
			cout << lst_libro->obtenerPos(i)->getCodigo() << endl;
			cout << lst_libro->obtenerPos(i)->getNombre() << endl;
			return lst_libro->obtenerPos(i);
		}
	}
	cout << "Error: Libro No Registrado";
	return nullptr;
}


int main()
{
	//Validación de tildes SPA
	locale loc("es_PE.UTF-8");

	cout << "Hola gente :v toco hacer el Menu";

}