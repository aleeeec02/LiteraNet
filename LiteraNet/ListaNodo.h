#pragma once
template <typename T>
class Nodo {
public:
	Nodo() { sig = nullptr; }
	Nodo(T nuelem) { elem = nuelem; sig = nullptr; }
	void setElem(T nuelem) { elem = nuelem; }
	void setSig(Nodo* nusig) { sig = nusig; }
	T getElem() { return elem; }
	Nodo* getSig() { return sig; }
	bool vacio() { return sig == NULL; }

private:
	T elem;
	Nodo* sig;
};

template<typename T>
class Lista {
public:
	Lista() :ini(nullptr), cantidad(0) { nodo = new Nodo<T>(); }
	Lista(Nodo<T>* newNodo) { nodo = newNodo; }
	~Lista();
	int Can();
	void agregarIni(T elem);
	void agregarPos(T elem, int pos);
	T obtenerIni();
	T obtenerPos(int pos);
private:
	Nodo<T>* nodo;
	Nodo<T>* ini;
	int cantidad;
	//typedef functional<int(T,T)> Comp;
};
template <typename T>
Lista<T>::~Lista() {
	Nodo* aux = ini;
	while (aux != nullptr) {
		aux = ini;
		ini = ini->sig;
		delete aux;
	}
}
template<typename T>
int Lista<T>::Can() {
	return cantidad;
}
template <typename T>
void Lista<T>::agregarIni(T elem) {
	Nodo<T>* nuevo = new Nodo<T>(elem);
	if (nuevo != nullptr) {
		ini = nuevo;
		cantidad++;
	}
}
template <typename T>
void Lista<T>::agregarPos(T elem, int pos) {
	if (pos > cantidad)return;
	if (pos == 0) {
		agregarIni(elem);
	}
	else {
		Nodo<T>* aux = ini;
		for (int i = 1; i < pos; i++) {
			aux = aux->getSig();
		}
		Nodo<T>* nuevo = new Nodo<T>(elem);
		nuevo->setSig(aux->getSig());
		if (nuevo != nullptr) {
			aux->setSig(nuevo);
			cantidad++;
		}
	}
}

template<typename T>
T Lista<T>::obtenerIni() {
	return obtenerPos(0);
}

template<typename T>
T Lista<T>::obtenerPos(int pos) {
	if (pos >= 0 && pos < cantidad) {
		Nodo<T>* aux = ini;
		for (int i = 0; i < pos; i++) {
			aux = aux->getSig();
		}
		return aux->getElem();
	}
	else {
		return NULL;
	}
}