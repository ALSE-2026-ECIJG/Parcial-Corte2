/**
 * @file RegistroAcademico.h
 * @brief Declaración de la clase RegistroAcademico.
 */
#ifndef REGISTRO_ACADEMICO_H
#define REGISTRO_ACADEMICO_H

#include <string>
#include <vector>

/**
 * @class RegistroAcademico
 * @brief Gestiona las notas y créditos de un estudiante.
 *
 * Usa la escala colombiana de 0.0 a 5.0. Una materia se aprueba
 * con nota mayor o igual a 3.0.
 */
class RegistroAcademico {
private:
    std::string nombre;                  ///< Nombre del estudiante
    int creditosAprobados;               ///< Créditos de materias aprobadas
    float promedioPonderado;             ///< Promedio ponderado por créditos
    std::vector<float> notas;            ///< Notas registradas
    std::vector<int> creditosNotas;      ///< Créditos de cada nota

    /** @brief Recalcula el promedio ponderado con todas las notas. */
    void recalcularPromedio();

public:
    static constexpr float NOTA_MIN = 0.0f;         ///< Nota mínima válida
    static constexpr float NOTA_MAX = 5.0f;         ///< Nota máxima válida
    static constexpr float NOTA_APROBATORIA = 3.0f; ///< Nota mínima para aprobar

    /**
     * @brief Constructor.
     * @param nombre Nombre del estudiante (no puede estar vacío).
     * @throw std::invalid_argument si el nombre está vacío.
     */
    explicit RegistroAcademico(const std::string& nombre);

    /**
     * @brief Registra una nota con sus créditos y actualiza el promedio.
     * @param nota Nota obtenida (entre 0.0 y 5.0).
     * @param creditos Créditos de la materia (mayor que 0).
     * @throw std::invalid_argument si la nota o los créditos son inválidos.
     */
    void registrarNota(float nota, int creditos);

    /**
     * @brief Obtiene el promedio ponderado actual.
     * @return Promedio ponderado (0.0 si no hay notas).
     */
    float obtenerPromedio() const;

    /**
     * @brief Verifica si el estudiante alcanzó los créditos requeridos.
     * @param creditosRequeridos Créditos mínimos exigidos.
     * @return true si creditosAprobados >= creditosRequeridos.
     */
    bool cumpleRequisitos(int creditosRequeridos) const;

    /** @brief Devuelve el nombre del estudiante. */
    std::string getNombre() const;

    /** @brief Devuelve los créditos aprobados. */
    int getCreditosAprobados() const;

    /** @brief Devuelve la cantidad de notas registradas. */
    std::size_t getCantidadNotas() const;
};

#endif // REGISTRO_ACADEMICO_H
