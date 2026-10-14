/**
 * @file PanelSolar.h
 * @brief Definición de la clase PanelSolar para gestión de energía solar.
 * @author Samuel Lopez
 * @date 2025
 */

#ifndef PANELSOLAR_H
#define PANELSOLAR_H

#include <string>
#include <vector>
#include <iostream>

/**
 * @class PanelSolar
 * @brief Representa un panel solar que registra energía generada
 *        y calcula su eficiencia promedio.
 */
class PanelSolar {
private:
    std::string id;                          ///< Identificador del panel
    float eficiencia;                        ///< Eficiencia (0-100 %)
    float energiaGenerada = 0.0f;            ///< Energía total acumulada (Wh)
    std::vector<float> historialGeneracion;  ///< Historial de lecturas

public:
    /**
     * @brief Constructor.
     * @param i Identificador del panel.
     * @param e Eficiencia entre 0 y 100.
     * @throws std::invalid_argument si la eficiencia está fuera de rango.
     */
    PanelSolar(std::string i, float e);

    /**
     * @brief Registra una lectura de energía generada.
     * @param wattHora Energía en Watt-hora.
     */
    void registrarGeneracion(float wattHora);

    /// @brief Devuelve la energía total acumulada (Wh).
    float energiaTotal() const;

    /// @brief Devuelve el promedio de energía por lectura.
    float eficienciaPromedio() const;

    std::string getId() const;
    float getEficiencia() const;
    std::size_t getNumeroLecturas() const;

    /// @brief Muestra toda la información del panel.
    void mostrarInfo() const;
};

#endif // PANELSOLAR_H
