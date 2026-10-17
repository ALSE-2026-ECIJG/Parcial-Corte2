#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "ClienteBancario.h"

using namespace std;

int main() {
    vector<ClienteBancario> clientes;  // contenedor STL

    cout << "=== Registro de clientes ===\n";
    for (int i = 1; i <= 2; i++) {
        string nombre, cedula;
        cout << "Cliente " << i << " - Nombre: ";
        getline(cin, nombre);
        cout << "Cliente " << i << " - Cedula: ";
        getline(cin, cedula);
        clientes.push_back(ClienteBancario(nombre, cedula));
    }

    int opcion = -1;
    while (opcion != 0) {
        cout << "\n--- MENU ---\n"
             << "1. Depositar\n2. Retirar\n3. Consultar saldo\n"
             << "4. Promedio de transacciones\n5. Listar clientes\n0. Salir\n"
             << "Opcion: ";
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida.\n";
            opcion = -1;
            continue;
        }

        if (opcion >= 1 && opcion <= 4) {
            int idx;
            cout << "Cliente (1-" << clientes.size() << "): ";
            if (!(cin >> idx) || idx < 1 || idx > (int)clientes.size()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Cliente no valido.\n";
                continue;
            }
            ClienteBancario& c = clientes[idx - 1];
            float valor;

            if (opcion == 1) {
                cout << "Monto a depositar: ";
                cin >> valor;
                if (valor > 0) {
                    c.depositar(valor);
                    cout << "Deposito exitoso. Saldo: " << c.obtenerSaldo() << "\n";
                } else {
                    cout << "El monto debe ser positivo.\n";
                }
            } else if (opcion == 2) {
                cout << "Monto a retirar: ";
                cin >> valor;
                if (c.retirar(valor))
                    cout << "Retiro exitoso. Saldo: " << c.obtenerSaldo() << "\n";
                else
                    cout << "Retiro rechazado (monto invalido o saldo insuficiente).\n";
            } else if (opcion == 3) {
                cout << c.obtenerNombre() << " tiene un saldo de "
                     << c.obtenerSaldo() << "\n";
            } else {
                cout << "Promedio de transacciones de " << c.obtenerNombre()
                     << ": " << c.promedioTransacciones() << "\n";
            }
        } else if (opcion == 5) {
            for (const auto& c : clientes) {
                cout << c.obtenerNombre() << " | CC " << c.obtenerCedula()
                     << " | Saldo: " << c.obtenerSaldo()
                     << " | Transacciones: " << c.cantidadTransacciones() << "\n";
            }
        } else if (opcion != 0) {
            cout << "Opcion no valida.\n";
        }
    }
    cout << "Hasta luego.\n";
    return 0;
}
