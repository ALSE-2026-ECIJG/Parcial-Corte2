/**
 * @file main.cpp
 * @brief Simula el proceso de registro de notas de varios estudiantes.
 */
#include "RegistroAcademico.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

/** @brief Lee un entero hasta que el usuario ingrese uno válido (>= minimo). */
static int leerEntero(const std::string& mensaje, int minimo) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor && valor >= minimo) return valor;
        std::cout << "  Entrada invalida (minimo " << minimo << ").\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/** @brief Lee un float hasta que el usuario ingrese uno válido. */
static float leerFloat(const std::string& mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) return valor;
        std::cout << "  Entrada invalida.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::vector<RegistroAcademico> estudiantes;

    std::cout << "=== SISTEMA DE REGISTRO ACADEMICO ===\n";
    int cantidad = leerEntero("Cuantos estudiantes desea registrar (minimo 2)? ", 2);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < cantidad; ++i) {
        std::string nombre;
        std::cout << "\n--- Estudiante " << (i + 1) << " ---\n";
        while (true) {
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);
            try {
                estudiantes.emplace_back(nombre);
                break;
            } catch (const std::invalid_argument& e) {
                std::cout << "  Error: " << e.what() << "\n";
            }
        }

        int numMaterias = leerEntero("Cuantas materias va a registrar? ", 1);
        RegistroAcademico& actual = estudiantes.back();
        for (int m = 1; m <= numMaterias; ++m) {
            bool registrada = false;
            while (!registrada) {
                float nota = leerFloat("  Nota materia " + std::to_string(m) + " (0.0 - 5.0): ");
                int creditos = leerEntero("  Creditos materia " + std::to_string(m) + ": ", 1);
                try {
                    actual.registrarNota(nota, creditos);
                    registrada = true;
                } catch (const std::invalid_argument& e) {
                    std::cout << "  Error: " << e.what() << " Intente de nuevo.\n";
                }
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int requeridos = leerEntero("\nCreditos requeridos para cumplir el requisito: ", 1);

    std::cout << "\n=== RESULTADOS ===\n" << std::fixed << std::setprecision(2);
    for (const auto& est : estudiantes) {
        std::cout << "Estudiante: " << est.getNombre() << "\n"
                  << "  Materias registradas: " << est.getCantidadNotas() << "\n"
                  << "  Creditos aprobados:   " << est.getCreditosAprobados() << "\n"
                  << "  Promedio ponderado:   " << est.obtenerPromedio() << "\n"
                  << "  Cumple requisitos:    "
                  << (est.cumpleRequisitos(requeridos) ? "SI" : "NO") << "\n\n";
    }
    return 0;
}
