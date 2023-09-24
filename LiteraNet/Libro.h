#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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
    void guardarLibro(const string& archivo) {
        ofstream outFile(archivo, ios::app); // Abrir archivo en modo append (añadir al final)
        if (outFile.is_open()) {
            outFile << codigo << "," << nombre << "," << precio << ",";

            Node* temp = head;
            while (temp != nullptr) {
                outFile << temp->next;
                if (temp != nullptr) {
                    outFile << "|"; // separador
                }
            }
            outFile << endl;
            outFile.close();
        }
    }

    void cargarLibro(const string& archivo, const string& codigoLibro) {
        ifstream inFile(archivo); // Abrir archivo en modo lectura
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                string token;
                getline(iss, token, ',');
                if (token == codigoLibro) {
                    // llenar los datos del libro
                    codigo = token;
                    getline(iss, nombre, ',');
                    getline(iss, token, ',');
                    precio = stod(token);

                    // llenar las reseñas
                    while (getline(iss, token, '|')) {
                        agregarResena(token);
                    }
                    break;
                }
            }
            inFile.close();
        }
    }


    //Serializacion
    string Serializar() const {
        stringstream ss;
        ss << nombre << "," << codigo << "," << precio;
        return ss.str();
    }

    //Deserializacion
    static Libro Deserializar(const string& str) {
        stringstream ss(str);
        string nombre, genero, codigo, temp;
        double precio;
        getline(ss, nombre, ',');
        getline(ss, codigo, ',');
        getline(ss, temp, ',');
        precio = stod(temp);
        getline(ss, temp, ',');

        return Libro(nombre, codigo, precio);
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