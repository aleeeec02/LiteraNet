#pragma once
#include <iostream>
#include <string>

using namespace std;

class Review {
private:
    string resumen;

public:
    Review(string resumen) : resumen(resumen) {}  // Inicializaci�n con lista de inicializadores
    Review() : resumen("") {}  // Constructor predeterminado

    string printReview() {
        return resumen;
    }

};
