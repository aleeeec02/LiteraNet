#pragma once
class Libro;


#include "Persona.h"
#include <fstream>
#include <sstream> // permite identificar la separaciones de strings (en este caso comas para identificar usernames; manipular y dividir strings)
#include <functional> //lambda

#include <random> // para poder implementar mt19937(generador de números aleatorios y útil para algoritmo de Twister de Mersenne)
#include <ctime> // para poder utilizar `time()`

using namespace std;



//Esta clase se creara de manera manual

class Libro;

class Usuario : public Persona {
private:
	string direccion;
	string userID;

	// Generación de un ID de usuario único
	void generarCodigoDeUsuario() {
		mt19937 motor(static_cast<unsigned int>(time(nullptr)));
		uniform_int_distribution<int> distribucion(0, 35);
		stringstream ss;
		const char alfanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		for (int i = 0; i < 8; ++i) {
			int indiceAleatorio = distribucion(motor);
			ss << alfanum[indiceAleatorio];
		}

		userID = ss.str();
	}

public:
	Usuario() :Persona() {
		this->direccion = " "; 
		generarCodigoDeUsuario(); // Automáticamente crea un userID cuando un nuevo usuario es creado
	}
	Usuario(std::string nom, std::string ape, int ed, int d, std::string cor, std::string direc)
		: Persona(nom, ape, ed, d, cor), direccion(direc) {
	}

	~Usuario(){}

	void setDireccion(string direc) { this->direccion = direc; }

	string getDireccion() {
		return this->direccion;
	}

	void setUserID(string ID) {
		userID = ID;
	}
	
	string getUserID() {
		return userID;
	}

	string getCodigo() {
		return userID;
	}
};
