/**
 * @file actuador.h
 * @brief Declaración de la clase actuador.
 * @author Juan José Olarte Barón
 */
#ifndef ACTUADOR_H
#define ACTUADOR_H

#include <string>

/**
 * @class actuador
 * @brief Dispositivo que se puede encender, apagar y ajustar en potencia (0 a 100).
 * @author Juan José Olarte Barón
 */
class actuador {
private:
    std::string nombre;  ///< Nombre del actuador.
    bool estado;         ///< true = encendido, false = apagado.
    int nivelPotencia;   ///< Nivel de potencia entre 0 y 100.

public:
    /**
     * @brief Constructor. El actuador inicia apagado y con potencia 0.
     * @param nom Nombre del actuador (no puede estar vacío).
     * @throws std::invalid_argument si el nombre está vacío.
     */
    actuador(const std::string& nom);

    /** @brief Enciende el actuador. */
    void encender();

    /** @brief Apaga el actuador y deja la potencia en 0. */
    void apagar();

    /**
     * @brief Ajusta el nivel de potencia.
     * @param nuevoNivel Valor entre 0 y 100.
     * @return true si se ajustó; false si el actuador está apagado o el valor
     *         está fuera del rango [0, 100].
     */
    bool ajustarPotencia(int nuevoNivel);

    /** @brief Devuelve "Encendido" o "Apagado" según el estado. */
    std::string obtenerEstado() const;

    /** @brief Devuelve el nombre del actuador. */
    std::string obtenerNombre() const;

    /** @brief Devuelve el nivel de potencia actual. */
    int obtenerNivelPotencia() const;

    /** @brief Muestra por consola el nombre, estado y potencia. */
    void mostrarResumen() const;
};

#endif // ACTUADOR_H
