#include <iostream>
#include <string>
using namespace std;

enum MetodoPago { Efectivo, Tarjeta };
enum Moneda { Soles, Dolares };

// Función para validar una tarjeta de crédito usando el algoritmo de Luhn (Algoritmo de Luhn)
bool validarTarjeta(string numero) {
    int n = numero.length();
    int suma = 0;
    bool alterna = false;

    for (int i = n - 1; i >= 0; i--) {
        int digito = numero[i] - '0';
        if (alterna) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
        alterna = !alterna;
    }

    return (suma % 10 == 0);
}

class Pago {
private:
    double monto;
    MetodoPago metodo;
    Moneda moneda;
    string numeroTarjeta;
public:
    Pago(double monto, MetodoPago metodo, Moneda moneda, string numeroTarjeta = "")
        : monto(monto), metodo(metodo), moneda(moneda), numeroTarjeta(numeroTarjeta) {}

    double getMonto() const {
        return monto;
    }

    MetodoPago getMetodo() const {
        return metodo;
    }

    bool procesarPago() {
        string monedaStr = (moneda == Soles) ? "soles" : "dólares";

        if (metodo == Efectivo) {
            cout << "Procesando pago en efectivo por " << monto << " " << monedaStr << "." << endl;
            return true;
        }
        else if (metodo == Tarjeta) {
            if (validarTarjeta(numeroTarjeta)) {
                cout << "Procesando pago con tarjeta válida por " << monto << " " << monedaStr << "." << endl;
                return true;
            }
            else {
                cout << "Tarjeta inválida. No se pudo procesar el pago." << endl;
                return false;
            }
        }
        return false;
    }
};

int main() {
    Pago pago1(50.0, Efectivo, Soles);
    Pago pago2(100.0, Tarjeta, Soles, "4539570161823386");  // Número de tarjeta válido para prueba
    Pago pago3(200.0, Tarjeta, Dolares, "1234567812345678");  // Número de tarjeta inválido para prueba

    pago1.procesarPago();
    pago2.procesarPago();
    pago3.procesarPago();

    return 0;
};