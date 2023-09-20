#include <iostream>
#include "Libro.h"
#include "Lista.h"
#include "Cola.h"
#include "Review.h"
#include "Reserva.h"
#include <stdio.h>
#include <locale>

//Colecciones
Lista<Review*>* lst_review = new Lista<Review*>();
Cola<Reserva*>* cola_reserva = new Cola<Reserva*>();
Lista<Libro*>* lst_libro = new Lista<Libro*>();
Lista<Usuario*>* lst_usuario = new Lista<Usuario*>();
//Prospecto de Menu
void menu() {
	cout << "Ingrese una Opcion: " << endl;;
	cout << "Registrar Usuario" << endl;
	cout << "Registrar Libro" << endl;
}
//Busca un Usuario de la Lista por codigo
Usuario* buscarUsuario(string codigo) {
	for (int i = 0; i < lst_usuario->longitud(); i++) {
		if (lst_usuario->obtenerPos(i)->getCodigo() == codigo) {
			cout << "Se encontro el Usuario: " << endl;
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
			cout << "Se encontro el Libro: " << endl;
			cout << lst_libro->obtenerPos(i)->getCodigo() << endl;
			cout << lst_libro->obtenerPos(i)->getNombre() << endl;
			return lst_libro->obtenerPos(i);
		}
	}
	cout << "Error: Libro No Registrado";
}

int main()
{
	//Validación de tildes SPA
	locale loc("es_PE.UTF-8");


	Reserva* reserva; // guardara las reservas desencoladas;
	int opcion, countUser = 0, countLib = 0; // contadores para los registros
	string comment, codigo, nombre; // auxiliares input

	//******************* Registros *********************
	do {
		cout << "Ingrese Codigo Usuario: "; getline(cin, codigo);
		cout << "Ingrese Nombre Usuario: "; getline(cin, nombre);
		lst_usuario->agregaFinal(new Usuario(codigo, nombre));
		countUser++;
	} while (countUser < 5);
	do {
		cout << "Ingrese Codigo del Libro: "; getline(cin, codigo);
		cout << "Ingrese Nombre del Libro: "; getline(cin, nombre);
		lst_libro->agregaFinal(new Libro(codigo, nombre));
		countLib++;
	} while (countLib < 5);
	for (int i = 0; i < lst_usuario->longitud(); i++) {
		string auxCod = lst_usuario->obtenerPos(i)->getCodigo();
	}
	//*******************   RESERVA ******************

	//Busqueda de Usuario por Codigo 
	cout << "************* RESERVA *************" << endl;
	cout << "Ingrese su Codigo de Usuario: "; getline(cin, codigo);
	Usuario* usuarioExistente;
	usuarioExistente = buscarUsuario(codigo); //Devuelve un Objeto si el usuario esta registrado	


	if (libroExistente) {
		string comentarioUsuario;
		cout << "Por favor, ingrese su comentario sobre el libro: ";
		getline(cin, comentarioUsuario); // Obtener la línea completa del comentario del usuario

		// Agregar la reseña del usuario al libro encontrado
		libroExistente->agregarResena(comentarioUsuario, 5); // Aquí, estoy asumiendo 5 estrellas, puedes cambiarlo
	}

	//Busqueda de Libro por Codigo 
	cout << "Ingrese Codigo del Libro a Reservar: "; getline(cin, codigo);
	Libro* libroExistente;
	libroExistente = buscarLibro(codigo); //Devuelve un Objeto si el Libro esta registrado
	cola_reserva->encolar(new Reserva(usuarioExistente, libroExistente));
	reserva = cola_reserva->desencolar();
	reserva->mostrarDetallesReserva();







	//llenar Lista de Reseñas *Manual* FUNCIONA
	/*
	do {
		cout << "Ingrese Un comentario del Libro: "; getline(cin, comment);
		count++;
		lst_review->agregaFinal(new Review(comment));
	} while (count < 5);
	for (int i = 0; i < lst_review->longitud(); i++) {

		lst_review->obtenerPos(i)->getReview();
	}
	*/

}