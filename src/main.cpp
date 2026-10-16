#include <iostream>
#include <vector>
#include "../include/Sensor.h"

using namespace std;

int main() {
    vector<Sensor> listaSensores;

    listaSensores.push_back(Sensor(1, "Humo", "Cocina"));
    listaSensores.push_back(Sensor(2, "Gas GLP", "Sótano"));
    listaSensores.push_back(Sensor(3, "Temperatura", "Sala Principal"));
    listaSensores.push_back(Sensor(4, "Fuego", "Habitaciones"));
    listaSensores.push_back(Sensor(5, "Humedad", "Techo"));

    cout << "=== SISTEMA DE PREVENCION INICIADO ===" << endl;
    cout << "Sensores registrados: " << listaSensores.size() << endl << endl;

    listaSensores[0].registrarMedida(45.5);
    listaSensores[2].registrarMedida(24.0);
    listaSensores[1].registrarMedida(80.2);
    cout << endl;

    if (listaSensores[0].detectarPeligro(40.0)) {
        cout << "¡ALERTA ROJA! Niveles altos de humo." << endl;
    }
    if (listaSensores[1].detectarPeligro(50.0)) {
        cout << "¡ALERTA ROJA! Fuga de gas inminente." << endl;
    }

    return 0;
}