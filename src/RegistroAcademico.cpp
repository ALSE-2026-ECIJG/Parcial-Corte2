#include "../include/RegistroAcademico.h"
#include <iostream>

// Constructor
RegistroAcademico::RegistroAcademico(const std::string& nombre)
    : nombre(nombre), creditosAprobados(0), promedioPonderado(0.0f) {}

// Método para registrar una nota con sus créditos
void RegistroAcademico::registrarNota(float nota, int creditos) {
    // Validaciones
    if (nota < 0.0f || nota > 5.0f) {
        std::cout << "Error: La nota debe estar entre 0.0 y 5.0.\n";
        return;
    }
    if (creditos <= 0) {
        std::cout << "Error: Los creditos deben ser mayores a cero.\n";
        return;
    }

    notas.push_back(nota);
    creditosNotas.push_back(creditos);

    // Si la nota es aprobatoria (>= 3.0), se suman los créditos aprobados
    if (nota >= 3.0f) {
        creditosAprobados += creditos;
    }

    // Recalcular promedio ponderado
    float sumaPonderada = 0.0f;
    int totalCreditos = 0;

    for (size_t i = 0; i < notas.size(); ++i) {
        sumaPonderada += notas[i] * creditosNotas[i];
        totalCreditos += creditosNotas[i];
    }

    if (totalCreditos > 0) {
        promedioPonderado = sumaPonderada / totalCreditos;
    }
}

// Retorna el promedio ponderado acumulado
float RegistroAcademico::obtenerPromedio() const {
    return promedioPonderado;
}

// Verifica si cumple con los créditos requeridos
bool RegistroAcademico::cumpleRequisitos(int creditosRequeridos) const {
    return creditosAprobados >= creditosRequeridos;
}

// Retorna el nombre del estudiante
std::string RegistroAcademico::obtenerNombre() const {
    return nombre;
}

// Muestra la información del registro académico
void RegistroAcademico::mostrarInformacion() const {
    std::cout << "\n----------------------------------------\n";
    std::cout << "Estudiante: " << nombre << "\n";
    std::cout << "Creditos Aprobados: " << creditosAprobados << "\n";
    std::cout << "Promedio Ponderado: " << promedioPonderado << "\n";
    std::cout << "Asignaturas registradas: " << notas.size() << "\n";
    std::cout << "----------------------------------------\n";
}