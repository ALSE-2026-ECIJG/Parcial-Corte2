#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definición de la clase Sensor
class Sensor {
public:
    int id;
    string tipo;
    string ubicacion;
    float valorActual;

    // Constructor
    Sensor(int id_sensor, string tipo_sensor, string ubicacion_sensor) {
        id = id_sensor;
        tipo = tipo_sensor;
        ubicacion = ubicacion_sensor;
        valorActual = 0.0;
    }

    // Método para simular la lectura de datos
    void registrarMedida(float nuevoValor) {
        valorActual = nuevoValor;
        cout << "- Sensor de " << tipo << " en " << ubicacion << " registró: " << valorActual << endl;
    }

    // Método para evaluar si hay una emergencia
    bool detectarPeligro(float umbralMaximo) {
        return valorActual > umbralMaximo;
    }
};

int main() {
    // Uso de la librería STL (vector) exigida en el proyecto
    vector<Sensor> listaSensores;

    // Registramos 5 sensores enfocados en el modelo de prevención de desastres
    listaSensores.push_back(Sensor(1, "Humo", "Cocina"));
    listaSensores.push_back(Sensor(2, "Gas GLP", "Sótano"));
    listaSensores.push_back(Sensor(3, "Temperatura", "Sala Principal"));
    listaSensores.push_back(Sensor(4, "Fuego (Infrarrojo)", "Habitaciones"));
    listaSensores.push_back(Sensor(5, "Humedad", "Techo"));

    cout << "=== SISTEMA DE PREVENCION DE DESASTRES INICIADO ===" << endl;
    cout << "Total de sensores registrados en la casa: " << listaSensores.size() << endl << endl;

    // Simulamos la lectura de valores del entorno
    listaSensores[0].registrarMedida(45.5); // Sensor de humo
    listaSensores[2].registrarMedida(24.0); // Sensor de temperatura normal
    listaSensores[1].registrarMedida(80.2); // Fuga de gas detectada
    cout << endl;

    // Evaluamos si algún sensor supera los umbrales seguros
    if (listaSensores[0].detectarPeligro(40.0)) {
        cout << "¡ALERTA ROJA! Niveles altos de humo detectados." << endl;
        // Aquí iría la lógica para enviar la señal de abrir las puertas automáticas
    }
    
    if (listaSensores[1].detectarPeligro(50.0)) {
        cout << "¡ALERTA ROJA! Fuga de gas inminente. Activando alarmas y ventilación." << endl;
    }

    return 0;
}
