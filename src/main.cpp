#include "Sensor.h"

#include <iostream>
#include <limits>
#include <vector>

int main() {
std::vector<Sensor> sensores;

try {
sensores.emplace_back(1, "Sensor de temperatura",
"Temperatura", 25.0);
sensores.emplace_back(2, "Sensor de humedad",
"Humedad", 60.0);
} catch (const std::exception& e) {
std::cerr << "Error al crear sensores: "
<< e.what() << '\n';
return 1;
}

std::cout << "=== SISTEMA DE REGISTRO DE SENSORES ===\n";
std::cout << "Se han creado dos sensores.\n\n";

for (Sensor& sensor : sensores) {
std::cout << "Sensor: " << sensor.getNombre() << '\n';
std::cout << "Ingrese la nueva medicion: ";

double medicion;

if (!(std::cin >> medicion)) {
std::cerr << "Error: debe ingresar un numero.\n";
return 1;
}

if (!sensor.actualizarMedicion(medicion)) {
std::cout << "No se pudo actualizar la medicion.\n";
} else {
std::cout << "Medicion actualizada correctamente.\n";
}

std::cout << '\n';
}

std::cout << "\n=== INFORMACION FINAL ===\n";

for (const Sensor& sensor : sensores) {
sensor.mostrarInformacion();
}

std::cout << "Total de sensores: " << sensores.size() << '\n';

return 0;
}
