/**
 * @file main.cpp
 * @brief Programa principal: simula la operación de dos clientes bancarios.
 */
#include "ClienteBancario.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

/**
 * @brief Lee un valor float desde la entrada estándar, repitiendo hasta que sea válido.
 * @param mensaje Texto que se muestra al usuario.
 * @return El valor leído.
 */
static float leerFloat(const std::string& mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada invalida, intente de nuevo.\n";
    }
}

/**
 * @brief Punto de entrada del programa.
 * @return 0 si finaliza correctamente.
 */
int main() {
    std::vector<ClienteBancario> clientes;
    std::string nombre, cedula;

    std::cout << "=== Registro de clientes bancarios ===\n\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "--- Cliente " << (i + 1) << " ---\n";
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "Cedula: ";
        std::getline(std::cin, cedula);
        clientes.emplace_back(nombre, cedula);
        std::cout << "\n";
    }

    for (auto& cliente : clientes) {
        std::cout << "--- Transacciones de " << cliente.obtenerNombre() << " ---\n";
        cliente.depositar(leerFloat("Valor a depositar: "));
        if (cliente.retirar(leerFloat("Valor a retirar: "))) {
            std::cout << "Retiro exitoso.\n";
        } else {
            std::cout << "Retiro rechazado (fondos insuficientes o valor invalido).\n";
        }
        std::cout << "\n";
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Resumen final ===\n";
    for (const auto& cliente : clientes) {
        std::cout << "Cliente: " << cliente.obtenerNombre() << "\n"
                  << "  Saldo actual: $" << cliente.obtenerSaldo() << "\n"
                  << "  Promedio de transacciones: $" << cliente.promedioTransacciones() << "\n\n";
    }
    return 0;
}
