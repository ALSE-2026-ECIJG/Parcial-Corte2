/**
 * @file RegistroAcademico.cpp
 * @brief Implementación de la clase RegistroAcademico.
 */
#include "RegistroAcademico.h"
#include <stdexcept>

RegistroAcademico::RegistroAcademico(const std::string& nombre)
    : nombre(nombre), creditosAprobados(0), promedioPonderado(0.0f) {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacio.");
    }
}

void RegistroAcademico::registrarNota(float nota, int creditos) {
    if (nota < NOTA_MIN || nota > NOTA_MAX) {
        throw std::invalid_argument("La nota debe estar entre 0.0 y 5.0.");
    }
    if (creditos <= 0) {
        throw std::invalid_argument("Los creditos deben ser mayores que 0.");
    }
    notas.push_back(nota);
    creditosNotas.push_back(creditos);
    if (nota >= NOTA_APROBATORIA) {
        creditosAprobados += creditos;
    }
    recalcularPromedio();
}

void RegistroAcademico::recalcularPromedio() {
    float sumaPonderada = 0.0f;
    int totalCreditos = 0;
    for (std::size_t i = 0; i < notas.size(); ++i) {
        sumaPonderada += notas[i] * creditosNotas[i];
        totalCreditos += creditosNotas[i];
    }
    promedioPonderado = (totalCreditos > 0) ? sumaPonderada / totalCreditos : 0.0f;
}

float RegistroAcademico::obtenerPromedio() const {
    return promedioPonderado;
}

bool RegistroAcademico::cumpleRequisitos(int creditosRequeridos) const {
    return creditosAprobados >= creditosRequeridos;
}

std::string RegistroAcademico::getNombre() const { return nombre; }

int RegistroAcademico::getCreditosAprobados() const { return creditosAprobados; }

std::size_t RegistroAcademico::getCantidadNotas() const { return notas.size(); }
