#pragma once
//Esta clase se creara de manera manual


class Usuario : public Persona {
public:
	Usuario() :Persona() { this->direccion = ""; }
	Usuario(string nom, string ape, int ed, int d, string cor, string direc):Persona(nom, ape, ed, d, cor), direccion(direc){}
	~Usuario(){}

	void setDireccion(string direc) { this->direccion = direc; }
	string getDireccion() { return this->direccion; }

private:
	string direccion;
};
