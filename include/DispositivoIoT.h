#ifndef DISPOSITIVO_IOT_H
#define DISPOSITIVO_IOT_H

#include <vector>

/**
 * @brief Clase que representa un dispositivo IoT con control de consumo energético.
 */
class DispositivoIoT {
private:
    int id;
    bool conectado;
    float consumoWattHora;
    std::vector<float> registroConsumo;

public:
    /**
     * @brief Constructor que inicializa el dispositivo con un identificador.
     * @param id_val Identificador único del dispositivo.
     */
    DispositivoIoT(int id_val);

    /**
     * @brief Conecta el dispositivo IoT.
     */
    void conectar();

    /**
     * @brief Desconecta el dispositivo IoT.
     */
    void desconectar();

    /**
     * @brief Registra un valor de consumo energético.
     * @param valor Cantidad en Watt-hora.
     */
    void registrarConsumo(float valor);

    /**
     * @brief Calcula el consumo total acumulado.
     * @return Suma de todos los consumos registrados.
     */
    float consumoTotal() const;

    /**
     * @brief Obtiene el identificador del dispositivo.
     * @return Entero con el ID.
     */
    int getId() const;
};

#endif
