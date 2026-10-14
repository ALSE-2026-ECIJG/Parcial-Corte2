#include "PanelSolar.h"
#include <stdexcept>
#include <numeric>

PanelSolar::PanelSolar(std::string i, float e)
    : id(std::move(i)), eficiencia(e) {
    if (eficiencia < 0.0f || eficiencia > 100.0f) {
        throw std::invalid_argument("La eficiencia debe estar entre 0 y 100.");
    }
}

void PanelSolar::registrarGeneracion(float wattHora) {
    if (wattHora < 0.0f) {
        std::cerr << "[ADVERTENCIA] No se permiten valores negativos.\n";
        return;
    }
    historialGeneracion.push_back(wattHora);
    energiaGenerada += wattHora;
}

float PanelSolar::energiaTotal() const { return energiaGenerada; }

float PanelSolar::eficienciaPromedio() const {
    if (historialGeneracion.empty()) return 0.0f;
    float suma = std::accumulate(historialGeneracion.begin(),
                                 historialGeneracion.end(), 0.0f);
    return suma / static_cast<float>(historialGeneracion.size());
}

std::string PanelSolar::getId() const { return id; }
float PanelSolar::getEficiencia() const { return eficiencia; }
std::size_t PanelSolar::getNumeroLecturas() const {
    return historialGeneracion.size();
}

void PanelSolar::mostrarInfo() const {
    std::cout << "========================================\n"
              << "Panel ID      : " << id << "\n"
              << "Eficiencia    : " << eficiencia << " %\n"
              << "Energía total : " << energiaGenerada << " Wh\n"
              << "N° lecturas   : " << historialGeneracion.size() << "\n"
              << "Promedio (Wh) : " << eficienciaPromedio() << "\n"
              << "========================================\n";
}
