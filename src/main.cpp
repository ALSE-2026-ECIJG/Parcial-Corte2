#include <iostream>
#include <vector>
#include <string>
#include "../include/RegistroAcademico.h"

int main() {
    // Contenedor de la STL para almacenar múltiples registros académicos de estudiantes
    std::vector<RegistroAcademico> estudiantes;

    int opcion = 0;
    
    do {
        std::cout << "\n========================================\n";
        std::cout << "   SISTEMA DE GESTION ACADEMICA (PARCIAL)\n";
        std::cout << "========================================\n";
        std::cout << "1. Registrar nuevo estudiante\n";
        std::cout << "2. Agregar nota a un estudiante\n";
        std::cout << "3. Ver informacion y promedio de estudiantes\n";
        std::cout << "4. Verificar requisitos de grado\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string nombreEstudiante;
            std::cout << "Ingrese el nombre del estudiante: ";
            std::cin >> nombreEstudiante;

            // Crear objeto y almacenarlo en el vector STL
            estudiantes.emplace_back(nombreEstudiante);
            std::cout << "¡Estudiante registrado con exito!\n";

        } else if (opcion == 2) {
            if (estudiantes.empty()) {
                std::cout << "No hay estudiantes registrados todavia.\n";
                continue;
            }

            std::cout << "\nEstudiantes disponibles:\n";
            for (size_t i = 0; i < estudiantes.size(); ++i) {
                std::cout << i + 1 << ". " << estudiantes[i].obtenerNombre() << "\n";
            }

            int indice = 0;
            std::cout << "Seleccione el numero del estudiante: ";
            std::cin >> indice;

            if (indice < 1 || indice > static_cast<int>(estudiantes.size())) {
                std::cout << "Indice invalido.\n";
                continue;
            }

            float nota;
            int creditos;
            std::cout << "Ingrese la nota (0.0 a 5.0): ";
            std::cin >> nota;
            std::cout << "Ingrese los creditos de la asignatura: ";
            std::cin >> creditos;

            // Invocación del método de la clase
            estudiantes[indice - 1].registrarNota(nota, creditos);

        } else if (opcion == 3) {
            if (estudiantes.empty()) {
                std::cout << "No hay estudiantes registrados.\n";
                continue;
            }

            for (const auto& est : estudiantes) {
                est.mostrarInformacion();
            }

        } else if (opcion == 4) {
            if (estudiantes.empty()) {
                std::cout << "No hay estudiantes registrados.\n";
                continue;
            }

            int indice = 0;
            std::cout << "Seleccione el numero del estudiante: ";
            std::cin >> indice;

            if (indice < 1 || indice > static_cast<int>(estudiantes.size())) {
                std::cout << "Indice invalido.\n";
                continue;
            }

            int creditosReq;
            std::cout << "Ingrese los creditos requeridos: ";
            std::cin >> creditosReq;

            if (estudiantes[indice - 1].cumpleRequisitos(creditosReq)) {
                std::cout << "¡El estudiante CUMPLE con los requisitos de creditos!\n";
            } else {
                std::cout << "El estudiante NO cumple con los creditos requeridos.\n";
            }

        } else if (opcion == 5) {
            std::cout << "Saliendo del sistema...\n";
        } else {
            std::cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 5);

    return 0;
}