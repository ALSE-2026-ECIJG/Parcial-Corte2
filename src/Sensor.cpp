#include "../include/Sensor.h"
#include <iostream>

using namespace std;

Sensor::Sensor(int id_sensor, string tipo_sensor, string ubicacion_sensor) {
    id = id_sensor;
    tipo = tipo_sensor;
    ubicacion = ubicacion_sensor;
    valorActual = 0.0;
}

void Sensor::registrarMedida(float nuevoValor) {
    valorActual = nuevoValor;
    cout << "- Sensor de " << tipo << " en " << ubicacion << " registró: " << valorActual << endl;
}

bool Sensor::detectarPeligro(float umbralMaximo) {
    return valorActual > umbralMaximo;
}