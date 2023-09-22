#pragma once

#include <iostream>
#include <string>
#include "Review.h"

using namespace std;

struct Node {
    Review data;  // Objeto de la clase Review 
    Node* next = nullptr;   // puntero
};

class Libro {
protected:
    // inicializando
    string codigo = "";
    string nombre = "";
    double precio = 0.0;
    Node* head = nullptr;
    bool libroExistente = false;


    void setLibroExistente(bool existente) {
        libroExistente = existente;
    }

    bool getlibroExistente()const {
        return libroExistente;
    }

public:

    Libro(string codigo, string nombre, double precio) : codigo(codigo), nombre(nombre), precio(precio), head(nullptr) {}

    Libro() : codigo(""), nombre(""), precio(0.0), head(nullptr) {} // Constructor por defecto con inicializaciones


    string getCodigo() {
        return codigo;
    }
    string getNombre() {
        return nombre;
    }

    // Obtener precio del libro
    double getPrecio() const {
        return precio;
    }
    // Cambiar precio del libro
    void cambiarPrecio(double nuevoPrecio) {
        precio = nuevoPrecio;
    }

    // Agregar reseña al libro
    void agregarResena(string resumen) {
        Node* nuevoNodo = new Node();  // Crear nuevo nodo
        nuevoNodo->data = Review(resumen);  // Asignar datos al nuevo nodo
        nuevoNodo->next = head;  // Enlazar el nuevo nodo
        head = nuevoNodo;
    }

    // Obtener detalles del libro
    void obtenerDetalles() const {
        cout << "Código: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;
        cout << "Reseñas: " << endl;
        Node* temp = head;
        while (temp != nullptr) {
            temp->data.getReview();
            temp = temp->next;
        }
    }

    // Destructor de libro para liberar memoria
    ~Libro() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};