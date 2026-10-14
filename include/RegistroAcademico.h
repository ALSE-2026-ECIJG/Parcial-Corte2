#ifndef REGISTRO_ACADEMICO_H
#define REGISTRO_ACADEMICO_H

#include <string>
#include <vector>

/**
 * @class RegistroAcademico
 * @brief Clase que gestiona el registro académico de un estudiante.
 */
class RegistroAcademico {
private:
    std::string nombre;                  /**< Nombre del estudiante */
    int creditosAprobados;               /**< Cantidad total de créditos aprobados */
    float promedioPonderado;             /**< Promedio acumulado ponderado */
    std::vector<float> notas;            /**< Vector con las notas registradas */
    std::vector<int> creditosNotas;      /**< Vector con los créditos asociados a cada nota */

public:
    /**
     * @brief Constructor de la clase RegistroAcademico.
     * @param nombre Nombre del estudiante.
     */
    RegistroAcademico(const std::string& nombre);

    /**
     * @brief Registra una nota junto con sus créditos correspondientes.
     * @param nota Calificación obtenida (debe estar entre 0.0 y 5.0).
     * @param creditos Número de créditos de la asignatura.
     */
    void registrarNota(float nota, int creditos);

    /**
     * @brief Obtiene el promedio ponderado actual.
     * @return Promedio ponderado acumulado.
     */
    float obtenerPromedio() const;

    /**
     * @brief Verifica si los créditos aprobados cumplen con un requisito mínimo.
     * @param creditosRequeridos Cantidad mínima de créditos requerida.
     * @return true si cumple o supera los créditos; false en caso contrario.
     */
    bool cumpleRequisitos(int creditosRequeridos) const;

    /**
     * @brief Obtiene el nombre del estudiante.
     * @return Nombre del estudiante.
     */
    std::string obtenerNombre() const;

    /**
     * @brief Muestra el resumen del estado académico del estudiante.
     */
    void mostrarInformacion() const;
};

#endif // REGISTRO_ACADEMICO_H