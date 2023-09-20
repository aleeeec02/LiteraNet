#pragma once
//Por el momento la clase Persona en realidad no necesita template
//Revisar el constructor y destructor

class Persona {
public:
	Persona();
	Persona(string nom, string ape, int ed, int d, string cor);
	~Persona();

	void Mostrar();

	void setNombre(string nom);
	void setApellido(string apel);
	void setEdad(int ed);
	void setDNI(int d);
	void setCorreo(string cor);

	string getNombre();
	string getApellido();
	string getCorreo();
	int getEdad();
	int getDNI();

private:
	string nombre, apellido;
	int edad, dni;
	string correo;
};


Persona::Persona() {
	nombre = "";
	apellido = "";
	edad = 0;
	dni = 0;
	correo = "";
}
Persona::Persona(string nom, string ape, int ed, int d, string cor) {
	this->nombre = nom;
	this->apellido = ape;
	this->edad = ed;
	this->dni = d;
	this->correo = cor;
}
Persona::~Persona() {
}

void Persona::Mostrar() {
	cout << "Nombre: " << this->nombre << endl;
	cout << "Apellido: " << this->apellido << endl;
	cout << "Edad: " << this->edad << endl;
	cout << "DNI: " << this->dni << endl;
	cout << "Correo: " << this->correo << endl;
}

void Persona::setNombre(string nom) {
	nombre = nom;
}
void Persona::setApellido(string apel) {
	apellido = apel;
}
void Persona::setEdad(int ed) {
	edad = ed;
}
void Persona::setDNI(int d) {
	dni = d;
}
void Persona::setCorreo(string cor) {
	correo = cor;
}

string Persona::getNombre() {
	return nombre;
}
string Persona::getApellido() {
	return apellido;
}
string Persona::getCorreo() {
	return correo;
}
int Persona::getEdad() {
	return edad;
}
int Persona::getDNI() {
	return dni;
}