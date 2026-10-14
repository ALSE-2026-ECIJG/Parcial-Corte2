#include "PanelSolar.h"
#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @brief Simula una granja de paneles solares.
 */
int main() {
    std::vector<PanelSolar> paneles;
    int cantidad = 0;

    std::cout << "==========================================\n";
    std::cout << " SISTEMA DE GESTIÓN DE PANELES SOLARES\n";
    std::cout << "==========================================\n";
    std::cout << "¿Cuántos paneles desea registrar? ";
    std::cin >> cantidad;

    if (std::cin.fail() || cantidad <= 0) {
        std::cerr << "Cantidad inválida. Saliendo...\n";
        return 1;
    }

    for (int i = 0; i < cantidad; ++i) {
        std::string id;
        float eficiencia;
        std::cout << "\n--- Panel #" << (i + 1) << " ---\n";
        std::cout << "ID del panel: ";
        std::cin >> id;
        std::cout << "Eficiencia (0-100): ";
        std::cin >> eficiencia;

        try {
            paneles.emplace_back(id, eficiencia);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what()
                      << " Se usará eficiencia 50 %.\n";
            paneles.emplace_back(id, 50.0f);
        }
    }

    std::cout << "\n=== REGISTRO DE GENERACIÓN ===\n";
    for (auto& p : paneles) {
        int lecturas;
        std::cout << "\n¿Cuántas lecturas para el panel "
                  << p.getId() << "? ";
        std::cin >> lecturas;
        for (int j = 0; j < lecturas; ++j) {
            float wh;
            std::cout << "  Lectura #" << (j + 1) << " (Wh): ";
            std::cin >> wh;
            p.registrarGeneracion(wh);
        }
    }

    std::cout << "\n\n========= REPORTE FINAL =========\n";
    float totalSistema = 0.0f;
    for (const auto& p : paneles) {
        p.mostrarInfo();
        totalSistema += p.energiaTotal();
    }
    std::cout << ">>> Energía total del sistema: "
              << totalSistema << " Wh\n";

    if (!paneles.empty()) {
        const PanelSolar* mejor = &paneles[0];
        for (const auto& p : paneles) {
            if (p.energiaTotal() > mejor->energiaTotal()) mejor = &p;
        }
        std::cout << ">>> Panel más productivo: "
                  << mejor->getId() << " ("
                  << mejor->energiaTotal() << " Wh)\n";
    }
    return 0;
}
