#pragma once
#include "Usuario.h"


class Administrador : public Usuario {
public:
    void agregarLibro() {}
    void mostrarUsuarios() {}
    void verAdministradoresActuales() {}
    void verReportes() {}
    void verAdministradoresActuales() {}

    int adminMenu() {
        int op;
        cout << "\n";
        cout << "----------Menu Administrador----------" << endl;
        cout << "1. Agregar Libro." << endl;
        cout << "2. Mostrar Usuarios." << endl;
        cout << "3. Ver Reportes de Ventas." << endl;
        cout << "4. Ver Administradores Actuales." << endl;
        cout << "5. Salir al Menu Principal." << endl;

        cout << "Ingrese una opcion: ";
        do {
            cin >> op;
            if (cin.fail() || op < 1 || op > 5) {
                cout << "Opción no válida. Por favor, ingrese una opción válida (1-5): ";
                cin.clear();
                cin.ignore();
            }
        } while (cin.fail() || op < 1 || op > 5);
        return op;
    }

    void ejecutarAccion(int op) {
        switch (op) {
        case 1:
            agregarLibro();
            break;
        case 2:
            mostrarUsuarios();
            break;
        case 3:
            verReportes();
            break;
        case 4:
            verAdministradoresActuales();
            break;
        default:
            break;
        }

    }
};