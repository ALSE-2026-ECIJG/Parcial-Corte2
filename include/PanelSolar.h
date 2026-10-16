#ifndef PANELSOLAR_H
#define PANELSOLAR_H

#include <string>
#include <vector>

/**
 * @file PanelSolar.h
 * @brief Definición de la clase PanelSolar para la gestión y monitoreo de generación de energía fotovoltaica.
 */

class PanelSolar {
private:
    std::string id;
    float eficiencia;
    float energiaGenerada;
    std::vector<float> historialGeneracion;

public:
    PanelSolar(std::string id_val, float eficiencia_val);
    void registrarGeneracion(float wattHora);
    float energiaTotal() const;
    float eficienciaPromedio() const;
    std::string getId() const;
};

#endif // PANELSOLAR_H
