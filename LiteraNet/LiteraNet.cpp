#pragma once
#include <iostream>
#include <stdio.h>

#include "Usuario.h"
#include "Autor.h"
#include "Review.h"

#include "Pago.h"
#include "Libro.h"
#include "Reserva.h"

#include "Lista.h"
#include "Cola.h"

#include <conio.h> // para utilizar getch
#include <vector>

#include <string>
#include <fstream>
#include <sstream>

#include <locale>
#include <Windows.h>


using namespace std;


//Colecciones
Lista<Review*>* lst_review = new Lista<Review*>();
Cola<Reserva*>* cola_reserva = new Cola<Reserva*>();
Lista<Libro*>* lst_libro = new Lista<Libro*>();
Lista<Usuario*>* lst_usuario = new Lista<Usuario*>();
Lista<Autor*>* lst_autor = new Lista<Autor*>();

// ****************************************//
// VALIDACIONES NECESARIAS			       //
// para entradas de datos usando lambda    //
// ****************************************//

void initializeLocale() {
	setlocale(LC_ALL, "es_ES.UTF-8");  // aplicar tildes a todo el c�digo
}

//Funci�n para verificar si el username existe
auto usernameYaExistente = make_shared<function<bool(const  string)>>(
	[](const string& username) -> bool {

	ifstream archivoEntrada("usernames.txt");
	string linea;

	//Lee cada l�nea del archivo
	while (getline(archivoEntrada, linea)) {
		istringstream iss(linea); // Usar istringstream para dividir las l�neas

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

//Funci�n para crear un nuevo usuario
auto crearUsuario = [](const string username, const string& codigoUsername) {
	//if (usernameYaExistente(username)) {
		cout << "El username ya est� ocupado." << endl;
		return;
	//}
	ofstream archivoSalida("usernames.txt", ios::app); // 'append' mode (modo 'a�adir')
	archivoSalida << username << "," << codigoUsername << "\n"; // Add a comma for easy parsing later (a�adir una coma para facilitar el an�lisis m�s tarde)
};

auto getEdadValidada = []() -> int {
	int edad;

	while (true) {
		cout << "Ingresar edad: ";
		cin >> edad;

		if (cin.fail()) {
			cin.clear(); // borrar el b�fer de entrada para restaurar cin a un estado utilizable
			cin.ignore(INT_MAX, '\n'); // ignorar la �ltima entrada si cin.fail es true
			cout << "Por favor, ingrese un n�mero v�lido para la edad." << endl;
		}
		else if (edad < 0 || edad > 120)
		{
			cout << "Por favor, ingrese una edad v�lida (0-120)." << endl;
		}
		else 
		{
			cin.ignore();
			return edad; // good input J4EMCM6Z ESP003
		}
	}
};


void crearUsuario2(int num) {
	initializeLocale();

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
}

void MostrarUsuarios() {
	for (int i = 0; i < lst_usuario->longitud(); i++) {
		cout << "Codigo del usuario: " << lst_usuario->obtenerPos(i)->getUserID();
		cout << "\nUsuario: " << i + 1 << endl;
		lst_usuario->obtenerPos(i)->Mostrar();
	}
}
void leerArchivoAutor(vector<string>& datos) {

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
	for (int i = 0; i < datos.size(); i = i + 7) {
		nombre = datos.at(i);
		apellido = datos.at(i + 1);
		edad = stoi(datos.at(i + 2));
		dni = stoi(datos.at(i + 3));
		correo = datos.at(i + 4);
		numlib = stoi(datos.at(i + 5));
		alias = datos.at(i + 6);
		Autor* writher = new Autor(nombre, apellido, edad, dni, correo, numlib, alias);
		lst_autor->agregarPos(writher, cont++);
	}
}


// Funci�n para guardar libros en un archivo
void GuardarLibroEnArchivo() {
	ofstream outFile("libros.txt");
	for (int i = 0; i < lst_libro->longitud(); i++) {
		outFile << lst_libro->obtenerPos(i)->Serializar() << endl;
	}
	outFile.close();

}


// Funci�n para cargar libros desde un archivo

void CargarLibrosDesdeArchivo() {
	initializeLocale();

	ifstream inFile("libros.txt"); // especificamente aqu� ".\LiteraNet\LiteraNet\libros.txt"
	string line;

	while (getline(inFile, line)) {
		Libro libro = Libro::Deserializar(line);
		// Add this libro object to your list
		// Assuming lst_libro is your list of Libros
		lst_libro->agregar(&libro);  
		lst_libro->agregaFinal(&libro);  
	}

	inFile.close();
}


void MostrarAutor() {
	for (int i = 0; i < lst_autor->longitud(); i++) {
		cout << "\n-----Autor: " << i + 1 << "-----" << endl;
		cout << "\nAlias: " << lst_autor->obtenerPos(i)->getAlias() << endl;
		lst_autor->obtenerPos(i)->Mostrar();
	}
}


// Funci�n para agregar colores al texo desde Windows.h
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//Prospecto de Menu
int menu() {

	// est�tica del men�

	const int Blue = 9;
	const int Default = 7;

	// men� opciones
	//Prospecto de Menu
	initializeLocale();

	int op;
	cout << "\n";
	cout << "----------Menu----------" << endl;
	cout << "1. Registrar Usuario." << endl;
	cout << "2. Mostrar Usuario." << endl;
	cout << "3. Buscar Usuario." << endl;
	cout << "4. Mostrar autores." << endl;
	cout << "5. Buscar Libro." << endl;
	cout << "6. Agregar Libro." << endl;
	cout << "7. Mostrar Libros." << endl;
	cout << "8. Comprar Libros." << endl;
	cout << "9. Reservar Libro." << endl;  //exit
	cout << "10. Agregar Review." << endl;  //exit
	cout << "11. Salir." << endl;  //exit
	setColor(Blue);
	cout << "Ingrese una opcion: ";
	setColor(Default);


	do {
		cin >> op;
		if (cin.fail() || op < 1 || op > 11) {
			cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida (1-11): ";
			cin.clear();

			cin.ignore();
		}
	} while (cin.fail() || op < 1 || op > 11);
	return op;

}

//Busca un Usuario de la Lista por codigo
Usuario* buscarUsuario(string codigo) {
	for (int i = 0; i < lst_usuario->longitud(); i++) {
		if (lst_usuario->obtenerPos(i)->getCodigo() == codigo) {
			cout << "Se encontr� el Usuario: " << endl;
			cout << lst_usuario->obtenerPos(i)->getCodigo() << endl;
			cout << lst_usuario->obtenerPos(i)->getNombre() << endl;
			return lst_usuario->obtenerPos(i);
		}
	}
	cout << "Error: Usuario No Registrado";
}

Libro buscarLibro(string codigo) {
	ifstream inFile("libros.txt"); // Recibe datos de libros.txt
	string line;
	bool found = false;
	while (getline(inFile, line)) {
		Libro libro = Libro::Deserializar(line);
		if (libro.getCodigo() == codigo) {
			found = true;
			return libro;
		}
	}

	inFile.close();
	if (!found) {
		cout << "Libro no encontrado." << endl;
	}
}


void buscarLibroPorCodigo(string codigoli) {
	initializeLocale();

	string codigo;
	cout << "Ingrese el codigo del libro que desea buscar: ";
	cin >> codigo;

	CargarLibrosDesdeArchivo();

	// Buscar el libro en la lista
	bool encontrado = false;
	for (int i = 0; i < lst_libro->longitud(); i++) {
		if (lst_libro->obtenerPos(i)->getCodigo() == codigo) {
			encontrado = true;
			cout << "Detalles del Libro:" << endl;
			lst_libro->obtenerPos(i)->obtenerDetalles();
			break; // Detener la b�squeda una vez encontrado
		}
	}

	if (!encontrado) {
		cout << "Libro no encontrado." << endl;
	}
}


auto operacionComprarLibros = []() {
	string codigo;
	cout << "Ingrese el codigo del libro que desea comprar: ";
	cin >> codigo;

	// Buscar libro por código
	ifstream inFile("libros.txt");
	string line;
	bool found = false;

	while (getline(inFile, line)) {
		Libro libro = Libro::Deserializar(line);
		if (libro.getCodigo() == codigo) {
			found = true;

			// Mostrar detalles del libro
			libro.obtenerDetalles();

			// Confirmar compra
			cout << "¿Desea comprar este libro? (y/n): ";
			char confirm;

			cin >> confirm;

			if (tolower(confirm) == 'y') {
				// Realizar el pago aquí usando la clase Pago
				Pago pago(libro.getPrecio(), Efectivo, Soles);

				if (pago.procesarPago()) {
					cout << "Compra exitosa. Gracias por comprar con nosotros." << endl;
				}
				else {
					cout << "Compra fallida. Por favor, intente de nuevo más tarde." << endl;
				}
			}
			else {
				cout << "Compra cancelada." << endl;
			}

			break;
		}
	}

	inFile.close();

	if (!found) {
		cout << "Libro no encontrado." << endl;
	}
};


int main()
{

	//Apariencia: validaci�n de tildes y colores
	initializeLocale();
	const int Blue = 9; // Color Azul
	const int Default = 7; // Color predeterminado

	initializeLocale();
	vector<string> datos;
	string codigous, codigoli;
	int num = 0, op;

	auto operacionRegistrarUsuario = [&num]() {
		crearUsuario2(num);
		num++;
		};

	auto operacionMostrarUsuarios = []() {
		MostrarUsuarios();
		_getch();
		};

	auto operacionBuscarUsuario = [&codigous]() { // Usando codigous
		cout << "Ingrese el c�digo del usuario: ";
		cin >> codigous;
		buscarUsuario(codigous);
		_getch();
		};

	auto operacionMostrarAutor = [&datos]() { // Usando datos
		leerArchivoAutor(datos);
		RegistrarAutor(datos);
		MostrarAutor();
		_getch();
		};
	auto operacionAgregarLibro = []() {
		string codigo, nombre;
		double precio;

		cout << "Ingrese el c�digo del libro: ";
		cin >> codigo;
		cout << "Ingrese el nombre del libro: ";
		cin >> nombre;

		// Validaci�n del precio para que no sea bucle infinito
		while (true) {
			cout << "Ingrese el precio del libro: ";
			if (cin >> precio) {
				break;
			}
			else {
				cout << "Precio no v�lido. Por favor, ingrese un valor num�rico v�lido." << endl;
				cin.clear(); // Restaura el estado del flujo de entrada
				cin.ignore(); // Limpia el buffer de entrada
			}
		}


		// Crear nuevo objeto Libro
		Libro* newLibro = new Libro(codigo, nombre, precio);

		// Guardar el nuevo libro en libros.txt
		ofstream outFile("libros.txt", ios::app); // Abrir el archivo en modo append
		if (outFile.is_open()) {
			outFile << newLibro->Serializar() << endl;
			outFile.close();
			cout << "Libro agregado exitosamente a libros.txt." << endl;
			_getch();

		}
		else {
			cout << "Error al abrir libros.txt. El libro no se pudo agregar." << endl;
			_getch();

		}

		};

	auto operacionMostrarLibros = []() {
		cout << "Listado de Libros:" << endl;
		// Leer libros desde libros.txt y mostrarlos
		ifstream inFile("libros.txt");
		string line;

		while (getline(inFile, line)) {
			Libro libro = Libro::Deserializar(line);
			cout << "Codigo del libro: " << libro.getCodigo() << endl;
			cout << "Nombre del libro: " << libro.getNombre() << endl;
			cout << "Precio del libro: " << libro.getPrecio() << endl;
			cout << "--------------------" << endl;
		}

		inFile.close();
		};

	auto operacionBuscarLibro = []() {
		initializeLocale();
		string codigoli;
		cout << "Ingrese el codigo del libro que desea buscar: ";
		cin >> codigoli;

		ifstream inFile("libros.txt"); // Recibe datos de libros.txt
		string line;
		bool found = false;

		while (getline(inFile, line)) {
			Libro libro = Libro::Deserializar(line);
			if (libro.getCodigo() == codigoli) {
				cout << "Detalles del Libro:" << endl;
				libro.obtenerDetalles();
				found = true;
				break;
			}
		}

		inFile.close();

		if (!found) {
			cout << "Libro no encontrado." << endl;
		}
		};

	auto reservarLibro = []() {
		initializeLocale();
		Usuario* usuarioExistente;
		Libro libroExistente;
		string codUser, codLibro;
		Reserva reserva;
		cout << "Ingrese su codigo de usuario: "; cin >> codUser;
		cout << "Ingrese codigo del libro: "; cin >> codLibro;
		usuarioExistente = buscarUsuario(codUser);
		libroExistente = buscarLibro(codLibro);
		reserva.generarReserva(usuarioExistente, &libroExistente);
		reserva.mostrarDetallesReserva();
	};
	//6EEN6148
	do {
		system("cls");
		op = menu();

		switch (op) {
		case 1:
			operacionRegistrarUsuario();
			break;
		case 2:
			operacionMostrarUsuarios();
			break;
		case 3:
			operacionBuscarUsuario();
			break;
		case 4:
			operacionMostrarAutor();
			break;
		case 5:
			operacionBuscarLibro();
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;
		case 6:
			operacionAgregarLibro();
			cout << "Presiona cualquier tecla para continuar...";
			break;
		case 7:
			operacionMostrarLibros();
			cout << "Presiona cualquier tecla para continuar...";
			_getch(); // esperar a que el usuario presione tecla
			break;
		case 8:
			operacionMostrarLibros();
			operacionComprarLibros();
			cout << "Presiona cualquier tecla para continuar...";
			_getch();
			break;

		case 9: // Reservar Libro
			reservarLibro();
			break;
		case 10: // Agregar REserña
			cout << " Agregar Review.";
		case 11: // Exit Option
			cout << "Hasta luego, gracias por usar nuestro servicio.";
			_getch();
			exit(0);
		default:
			cout << "Opcion no válida. Por favor, intente de nuevo.\n";
			break;
		}
	} while (op != 0);


	return 0;
}