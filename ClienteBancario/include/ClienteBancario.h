#ifndef CLIENTE_BANCARIO_H
#define CLIENTE_BANCARIO_H

#include <string>
#include <vector>

/**
 * @brief Representa un cliente bancario con sus datos personales,
 *        saldo y transacciones.
 */
class ClienteBancario {
private:
    std::string nombre;               ///< Nombre del cliente
    std::string cedula;               ///< Cedula del cliente
    std::vector<float> transacciones; ///< Depositos (+) y retiros (-)
    float saldo;                      ///< Saldo actual

public:
    /**
     * @brief Constructor.
     * @param _nombre Nombre del cliente.
     * @param _cedula Cedula del cliente.
     */
    ClienteBancario(const std::string& _nombre, const std::string& _cedula);

    /**
     * @brief Deposita dinero en la cuenta.
     * @param valor Monto a depositar (debe ser mayor que 0).
     */
    void depositar(float valor);

    /**
     * @brief Retira dinero de la cuenta.
     * @param valor Monto a retirar (mayor que 0 y no superior al saldo).
     * @return true si el retiro se realizo, false en caso contrario.
     */
    bool retirar(float valor);

    /** @brief Devuelve el saldo actual. */
    float obtenerSaldo() const;

    /**
     * @brief Calcula el promedio de todas las transacciones.
     * @return Promedio, o 0 si no hay transacciones.
     */
    float promedioTransacciones() const;

    /** @brief Devuelve el nombre del cliente. */
    std::string obtenerNombre() const;

    /** @brief Devuelve la cedula del cliente. */
    std::string obtenerCedula() const;

    /** @brief Devuelve la cantidad de transacciones realizadas. */
    int cantidadTransacciones() const;
};

#endif
