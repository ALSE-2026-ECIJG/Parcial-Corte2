#include "PanelSolar.h"
#include <stdexcept>
#include <numeric>

PanelSolar::PanelSolar(std::string id_val, float eficiencia_val) {
    if (eficiencia_val < 0.0f) {
        throw std::invalid_argument("La eficiencia no puede ser negativa.");
    }
    id = id_val;
    eficiencia = eficiencia_val;
    energiaGenerada = 0.0f;
}

void PanelSolar::registrarGeneracion(float wattHora) {
    if (wattHora < 0.0f) {
        throw std::invalid_argument("La energía generada no puede ser negativa.");
    }
    historialGeneracion.push_back(wattHora);
    energiaGenerada += wattHora;
}

float PanelSolar::energiaTotal() const {
    float total = 0.0f;
    for (float energia : historialGeneracion) {
        total += energia;
    }
    return total;
}

float PanelSolar::eficienciaPromedio() const {
    return eficiencia;
}

std::string PanelSolar::getId() const {
    return id;
}
