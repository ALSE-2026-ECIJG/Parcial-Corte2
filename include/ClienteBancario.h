#ifndef CLIENTE_BANCARIO_H
#define CLIENTE_BANCARIO_H

#include <string>
#include <vector>

/**
 * @class ClienteBancario
 * @brief Representa un cliente de un banco, con su información básica
 *        y el historial de transacciones realizadas sobre su cuenta.
 */
class ClienteBancario {
private:
    std::string nombre;               ///< Nombre completo del cliente.
    std::string cedula;               ///< Número de cédula del cliente.
    std::vector<float> transacciones; ///< Historial de montos transaccionados (depósitos y retiros).
    float saldo;                      ///< Saldo actual disponible en la cuenta.

public:
    /**
     * @brief Construye un ClienteBancario con nombre y cédula dados.
     * @param nombre Nombre completo del cliente.
     * @param cedula Número de cédula del cliente.
     *
     * El saldo inicial se establece en 0.0 y el historial de
     * transacciones queda vacío.
     */
    ClienteBancario(const std::string& nombre, const std::string& cedula);

    /**
     * @brief Deposita un valor en la cuenta del cliente.
     * @param valor Monto a depositar. Debe ser positivo; si no, se ignora.
     */
    void depositar(float valor);

    /**
     * @brief Retira un valor de la cuenta del cliente, si hay saldo suficiente.
     * @param valor Monto a retirar. Debe ser positivo.
     * @return true si el retiro fue exitoso; false si el valor no es positivo
     *         o el saldo es insuficiente.
     */
    bool retirar(float valor);

    /**
     * @brief Obtiene el saldo actual del cliente.
     * @return El saldo disponible en la cuenta.
     */
    float obtenerSaldo() const;

    /**
     * @brief Obtiene el nombre del cliente.
     * @return El nombre completo del cliente.
     */
    std::string obtenerNombre() const;

    /**
     * @brief Calcula el promedio de los montos transaccionados.
     * @return El promedio de las transacciones (depósitos positivos, retiros
     *         negativos); 0.0 si no hay transacciones registradas.
     */
    float promedioTransacciones() const;
};

#endif // CLIENTE_BANCARIO_H
