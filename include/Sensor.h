
/**
 * @file Sensor.h
 * @brief Definición de la clase Sensor para el sistema de prevención.
 */

#ifndef SENSOR_H
#define SENSOR_H
#include <string>

/**
 * @class Sensor
 * @brief Representa un sensor genérico que mide variables ambientales.
 */
class Sensor {
public:
    int id;                     /**< Identificador único del sensor */
    std::string tipo;           /**< Tipo de sensor (Humo, Gas, etc.) */
    std::string ubicacion;      /**< Lugar donde está instalado el sensor */
    float valorActual;          /**< Último valor registrado por el sensor */

    /**
     * @brief Constructor de la clase Sensor.
     * @param id_sensor ID del sensor.
     * @param tipo_sensor Tipo de variable que mide.
     * @param ubicacion_sensor Lugar de instalación.
     */
    Sensor(int id_sensor, std::string tipo_sensor, std::string ubicacion_sensor);
    
    /**
     * @brief Registra una nueva medición en el sensor.
     * @param nuevoValor El valor medido en tiempo real.
     */
    void registrarMedida(float nuevoValor);

    /**
     * @brief Evalúa si el valor actual supera el límite seguro.
     * @param umbralMaximo Valor máximo permitido antes de lanzar alerta.
     * @return true si hay peligro, false si los niveles son normales.
     */
    bool detectarPeligro(float umbralMaximo);
};

#endif