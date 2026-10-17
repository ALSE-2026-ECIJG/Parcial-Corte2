/**
 * @file actuador.cpp
 * @brief Implementación de la clase actuador.
 * @author Juan José Olarte Barón
 */
#include "actuador.h"

#include <iostream>
#include <stdexcept>

actuador::actuador(const std::string& nom)
    : nombre(nom), estado(false), nivelPotencia(0) {
    if (nom.empty()) {
        throw std::invalid_argument("El nombre del actuador no puede estar vacio.");
    }
}

void actuador::encender() { estado = true; }

void actuador::apagar() {
    estado = false;
    nivelPotencia = 0;
}

bool actuador::ajustarPotencia(int nuevoNivel) {
    if (!estado) return false;
    if (nuevoNivel < 0 || nuevoNivel > 100) return false;
    nivelPotencia = nuevoNivel;
    return true;
}

std::string actuador::obtenerEstado() const {
    return estado ? "Encendido" : "Apagado";
}

std::string actuador::obtenerNombre() const { return nombre; }

int actuador::obtenerNivelPotencia() const { return nivelPotencia; }

void actuador::mostrarResumen() const {
    std::cout << "Actuador " << nombre << " | Estado: " << obtenerEstado()
              << " | Potencia: " << nivelPotencia << "%\n";
}
