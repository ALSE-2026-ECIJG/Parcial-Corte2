#include <iostream>
#include <vector>
#include "PanelSolar.h"

int main() {
    std::vector<PanelSolar> granjaSolar;

    granjaSolar.push_back(PanelSolar("PS-001", 18.5f));
    granjaSolar.push_back(PanelSolar("PS-002", 20.1f));

    int opcion = 0;
    do {
        std::cout << "\n========================================\n";
        std::cout << "   SISTEMA DE MONITOREO DE PANALES SOLARES\n";
        std::cout << "========================================\n";
        std::cout << "1. Registrar generacion de energia en un panel\n";
        std::cout << "2. Mostrar reporte y energia total generada\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string idBuscado;
            float energia;
            std::cout << "Ingrese el ID del panel (ej. PS-001, PS-002): ";
            std::cin >> idBuscado;
            std::cout << "Ingrese los Wh generados: ";
            std::cin >> energia;

            bool encontrado = false;
            for (auto& panel : granjaSolar) {
                if (panel.getId() == idBuscado) {
                    try {
                        panel.registrarGeneracion(energia);
                        std::cout << ">> ¡Generacion registrada con exito!\n";
                    } catch (const std::exception& e) {
                        std::cout << ">> Error: " << e.what() << "\n";
                    }
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                std::cout << ">> Error: Panel no encontrado en el sistema.\n";
            }

        } else if (opcion == 2) {
            std::cout << "\n--- REPORTE GENERAL DE LA GRANJA SOLAR ---\n";
            for (const auto& panel : granjaSolar) {
                std::cout << "Panel ID: " << panel.getId() << "\n"
                          << "  - Eficiencia: " << panel.eficienciaPromedio() << "%\n"
                          << "  - Energia Total Generada: " << panel.energiaTotal() << " Wh\n";
            }
        }
    } while (opcion != 3);

    std::cout << "Saliendo del sistema de monitoreo...\n";
    return 0;
}
