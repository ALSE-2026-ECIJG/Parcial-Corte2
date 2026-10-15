#include "Sensor.h"

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

Sensor::Sensor(int id, const std::string& nombre,
const std::string& tipo, double valor)
: id(id), nombre(nombre), tipo(tipo),
valor(valor), activo(true) {

if (id <= 0) {
throw std::invalid_argument(
"El ID debe ser positivo."
);
}

if (nombre.empty() || tipo.empty()) {
throw std::invalid_argument(
"El nombre y el tipo no pueden estar vacios."
);
}

if (!std::isfinite(valor)) {
throw std::invalid_argument(
"La medicion inicial debe ser un numero finito."
);
}
}

int Sensor::getId() const {
return id;
}

std::string Sensor::getNombre() const {
return nombre;
}

std::string Sensor::getTipo() const {
return tipo;
}

double Sensor::getValor() const {
return valor;
}

bool Sensor::estaActivo() const {
return activo;
}

bool Sensor::actualizarMedicion(double nuevoValor) {
if (!activo || !std::isfinite(nuevoValor)) {
return false;
}

valor = nuevoValor;
return true;
}

void Sensor::activar() {
activo = true;
}

void Sensor::desactivar() {
activo = false;
}

void Sensor::mostrarInformacion() const {
std::cout << std::fixed << std::setprecision(2);
std::cout << "ID: " << id << '\n';
std::cout << "Nombre: " << nombre << '\n';
std::cout << "Tipo: " << tipo << '\n';
std::cout << "Medicion: " << valor << '\n';
std::cout << "Estado: "
<< (activo ? "Activo" : "Inactivo") << '\n';
std::cout << "-------------------------\n";
}


