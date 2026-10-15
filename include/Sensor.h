#ifndef SENSOR_H
#define SENSOR_H

#include <string>

/**
* @brief Representa un sensor de medicion.
*
* Almacena la identificacion, el nombre, el tipo,
* la ultima medicion y el estado del sensor.
*/
class Sensor {
private:
int id;
std::string nombre;
std::string tipo;
double valor;
bool activo;

public:
/**
* @brief Construye un sensor.
* @param id Identificador unico y positivo.
* @param nombre Nombre del sensor.
* @param tipo Tipo de sensor.
* @param valor Medicion inicial.
*/
Sensor(int id, const std::string& nombre,
const std::string& tipo, double valor);

/** @brief Devuelve el identificador del sensor. */
int getId() const;

/** @brief Devuelve el nombre del sensor. */
std::string getNombre() const;

/** @brief Devuelve el tipo de sensor. */
std::string getTipo() const;

/** @brief Devuelve la ultima medicion. */
double getValor() const;

/** @brief Indica si el sensor esta activo. */
bool estaActivo() const;

/**
* @brief Actualiza la medicion del sensor.
* @param nuevoValor Nueva medicion.
* @return true si se actualizo correctamente.
*/
bool actualizarMedicion(double nuevoValor);

/** @brief Activa el sensor. */
void activar();

/** @brief Desactiva el sensor. */
void desactivar();

/** @brief Muestra toda la informacion del sensor. */
void mostrarInformacion() const;
};

#endif
