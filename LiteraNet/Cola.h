#include "Nodo_Cola.h"
#include <iostream>
using namespace std;
template <class T>
class Cola
{
private:
	Nodo_Cola<T>* inicio;
	Nodo_Cola<T>* fin;
public:
	Cola()
	{
		this->inicio = NULL;
		this->fin = NULL;
	}
	void encolar(T v);
	T desencolar();
	bool esVacia();
};

//IMPLEMENTACIÓN

template <class T>
bool Cola<T>::esVacia()
{
	return (inicio == NULL);
}

template <class T>
void Cola<T>::encolar(T v)
{
	Nodo_Cola<T>* nodo = new Nodo_Cola<T>(v);
	if (esVacia())
	{
		inicio = nodo;
		fin = inicio;
	}
	else
	{
		fin->siguiente = nodo;
		fin = nodo;
	}

	nodo = NULL;
}

template <class T>
T Cola<T>::desencolar()
{
	if (esVacia()) { // en caso que el usuario no haya agregado nada a la cola aka esté vacía
		cout << "Por favor haga una reserva de los libros que desea primero";
		return T();
	}

	T dato = inicio->dato;
	if (inicio == fin)
	{
		inicio = NULL;
		fin = NULL;
	}
	else
	{
		inicio = inicio->siguiente;
	}
	return dato;
}
