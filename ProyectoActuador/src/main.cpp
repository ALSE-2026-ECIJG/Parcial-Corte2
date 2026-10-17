/**
 * @file main.cpp
 * @brief Programa principal: simulación de dos actuadores.
 * @author Juan José Olarte Barón
 */
#include "actuador.h"

#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

/** @brief Lee un nombre no vacío con getline. */
std::string leerNombre(const std::string& mensaje) {
    std::string texto;
    do {
        std::cout << mensaje;
        if (!std::getline(std::cin >> std::ws, texto)) {
            throw std::runtime_error("Fin de la entrada.");
        }
    } while (texto.empty());
    return texto;
}

/** @brief Lee un entero con cin; repite si la entrada no es válida. */
int leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) return valor;
        if (std::cin.eof()) throw std::runtime_error("Fin de la entrada.");
        std::cout << "Entrada invalida, escriba un numero entero.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

}  // namespace

int main() {
    try {
        std::vector<actuador> actuadores;  // contenedor de la STL

        std::cout << "=== Simulador de actuadores ===\n";
        actuadores.push_back(actuador(leerNombre("Nombre del actuador 1: ")));
        actuadores.push_back(actuador(leerNombre("Nombre del actuador 2: ")));

        std::cout << "\n--- Encendido y ajuste de potencia ---\n";
        for (auto& a : actuadores) {
            a.encender();
            std::cout << a.obtenerNombre() << ": " << a.obtenerEstado() << "\n";
            bool ok = false;
            while (!ok) {
                int nivel = leerEntero("Potencia para " + a.obtenerNombre() +
                                       " (0 a 100): ");
                ok = a.ajustarPotencia(nivel);
                if (!ok) std::cout << "Nivel invalido: debe estar entre 0 y 100.\n";
            }
        }

        std::cout << "\n--- Estado despues de ajustar ---\n";
        for (const auto& a : actuadores) a.mostrarResumen();

        std::cout << "\n--- Apagando " << actuadores[0].obtenerNombre() << " ---\n";
        actuadores[0].apagar();
        if (!actuadores[0].ajustarPotencia(50)) {
            std::cout << "Un actuador apagado no permite ajustar la potencia.\n";
        }

        std::cout << "\n=== Resultado final ===\n";
        for (const auto& a : actuadores) a.mostrarResumen();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
