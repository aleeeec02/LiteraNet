#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "Persona.h"
#include "Usuario.h"
#include "Autor.h"
#include "ListaNodo.h"

Lista<Usuario*>* lisUsuario = new Lista<Usuario*>;
Lista<Autor*>* lisAutor = new Lista<Autor*>;
void RegistrarUsuario(int num) {
	string nombre, apellido, correo, direccion;
	int edad, dni;
	cout << "------Registrar Usuario------" << endl;
	cout << "Ingresar nombre: ";
	cin >> nombre;
	cout << "Ingresar apellido: ";
	cin >> apellido;
	cout << "Ingresar edad: ";
	cin >> edad;
	cout << "Ingresar correo: ";
	cin >> correo;
	cout << "Ingresar DNI: ";
	cin >> dni;
	cout << "Ingresar direccion: ";
	cin >> direccion;
	Usuario* user = new Usuario(nombre, apellido, edad, dni, correo, direccion);
	lisUsuario->agregarPos(user, num);
}
void MostrarUsuarios() {
	for (int i = 0; i < lisUsuario->Can(); i++) {
		cout << "\nUsuario: " << i + 1 << endl;
		lisUsuario->obtenerPos(i)->Mostrar();
	}
}

void ArchivoAutor(vector<string>& datos) {
	ifstream archivo("Autores.txt", ios::in);
	if (!archivo.is_open())
		cout << "No se puede abrir el archivo." << endl;
	string linea;
	while (getline(archivo, linea)) {
		istringstream iss(linea);
		string dato;
		while (iss >> dato) {
			datos.push_back(dato);
		}
	}
	archivo.close();
}

void RegistrarAutor(vector<string>& datos) {
	string nombre, apellido, correo, alias;
	int edad, dni, numlib, cont;
	cont = 0;
	for (int i = 0; i < datos.size(); i=i+7) {
		nombre = datos.at(i);
		apellido = datos.at(i+1);
		edad = stoi(datos.at(i+2));
		dni = stoi(datos.at(i+3));
		correo = datos.at(i+4);
		numlib = stoi(datos.at(i+5));
		alias = datos.at(i+6);
		Autor* writher = new Autor(nombre, apellido, edad, dni, correo, numlib, alias);
		lisAutor->agregarPos(writher,cont++);
	}
}
void MostrarAutor() {
	for (int i = 0; i < lisAutor->Can(); i++) {
		cout << "\nAutore: " << i + 1 << endl;
		lisAutor->obtenerPos(i)->Mostrar();
	}
}
int Menu() {
	int op;
	cout << "\n";
	cout << "----------Menu----------" << endl;
	cout << "1. Registrar Usuario." << endl;
	cout << "2. Mostrar Usuarios." << endl;
	cout << "3. Mostrar autores." << endl;
	cout << "4. Salir." << endl;
	cout << "-Ingrese una opcion: ";
	do {
		cin >> op;
		if (op < 0 || op > 5)
			cout << "Ingrese una opcion valida.";
	} while (op < 0 || op>5);
	return op;
}
int main() {
	vector<string> datos;
	int num = 0;
	while (true) {
		int op = Menu();
		if (op == 5) {
			cout << "Adios." << endl;
			break;
		}
		switch (op) {
		case 1: RegistrarUsuario(num);
			num++;
			break;
		case 2: MostrarUsuarios();
			break;
		case 3: ArchivoAutor(datos);
			RegistrarAutor(datos);
			MostrarAutor();
			break;
		case 4: break;
		}
	}
	return 0;
}