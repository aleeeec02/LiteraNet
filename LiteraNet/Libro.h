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
    string codigo = "";
    string nombre = "";
    double precio = 0.0;
    Node* head = nullptr;
    bool libroExistente = false;

    void setLibroExistente(bool existente) {
        libroExistente = existente;
    }

    bool getLibroExistente() const {
        return libroExistente;
    }

public:
    // Constructors
    Libro(string codigo, string nombre, double precio) : codigo(codigo), nombre(nombre), precio(precio), head(nullptr) {}

    Libro() : codigo(""), nombre(""), precio(0.0), head(nullptr) {} 

    // Getters and Setters
    string getCodigo() {
        return codigo;
    }

    string getNombre() {
        return nombre;
    }

    double getPrecio() const {
        return precio;
    }

    void cambiarPrecio(double nuevoPrecio) {
        precio = nuevoPrecio;
    }

    // Methods
    void agregarResena(string resumen) {
        Node* nuevoNodo = new Node();  
        nuevoNodo->data = Review(resumen);  
        nuevoNodo->next = head;  
        head = nuevoNodo;
    }

    void obtenerDetalles() const {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Precio: " << precio << endl;

        cout << "¿Desea comprar este libro? (y/n): ";


        if (head == nullptr) {
            cout << "No hay reseñas disponibles." << endl;
        }
        else {
            Node* temp = head;
            while (temp != nullptr) {
                temp->data.printReview();
                temp = temp->next;
            }
        }
    }



    void guardarLibro(const string& archivo) {
        ofstream outFile(archivo, ios::app);
        if (outFile.is_open()) {
            outFile << codigo << "," << nombre << "," << precio << ",";

            if (head == nullptr) {
                cout << "No hay reseñas disponibles." << endl;
            }
            else {
                Node* temp = head;
                while (temp != nullptr) {
                    temp->data.printReview();
                    temp = temp->next;
                }
            }

            outFile << endl;
            outFile.close();
        }
    }

    void cargarLibro(const string& archivo, const string& codigoLibro) {
        ifstream inFile(archivo);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                istringstream iss(line);
                string token;
                getline(iss, token, ',');
                if (token == codigoLibro) {
                    codigo = token;
                    getline(iss, nombre, ',');
                    getline(iss, token, ',');
                    precio = stod(token);

                    while (getline(iss, token, '|')) {
                        agregarResena(token);
                    }
                    break;
                }
            }
            inFile.close();
        }
    }

    string Serializar() const {
        stringstream ss;
        ss << nombre << "," << codigo << "," << precio;
        return ss.str();
    }

    static Libro Deserializar(const string& str) {
        stringstream ss(str);
        string nombre, codigo, temp, reviews_str;
        double precio;

        getline(ss, nombre, ',');
        getline(ss, codigo, ',');
        getline(ss, temp, ',');
        precio = stod(temp);
        getline(ss, reviews_str, ',');

        Libro libro(nombre, codigo, precio);

        stringstream reviews_ss(reviews_str);
        while (getline(reviews_ss, temp, '|')) {
            libro.agregarResena(temp);
        }

        return libro;
    }

    ~Libro() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
