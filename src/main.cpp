#include <iostream>
#include <vector>
#include "DispositivoIoT.h"

using namespace std;

int main() {
    vector<DispositivoIoT> redDispositivos;

    cout << "=== SIMULADOR DE DISPOSITIVOS IOT ===" << endl;
    
    int id1, id2;
    cout << "Ingrese el ID para el Dispositivo 1: ";
    cin >> id1;
    DispositivoIoT dev1(id1);

    cout << "Ingrese el ID para el Dispositivo 2: ";
    cin >> id2;
    DispositivoIoT dev2(id2);

    redDispositivos.push_back(dev1);
    redDispositivos.push_back(dev2);

    cout << "\nOperando con Dispositivo " << dev1.getId() << "..." << endl;
    redDispositivos[0].conectar();
    
    float consumo1, consumo2;
    cout << "Ingrese el consumo (Wh) a registrar para el Dispositivo 1: ";
    cin >> consumo1;
    redDispositivos[0].registrarConsumo(consumo1);

    cout << "Ingrese un segundo consumo (Wh) para el Dispositivo 1: ";
    cin >> consumo2;
    redDispositivos[0].registrarConsumo(consumo2);

    cout << "\n--- RESULTADOS ---" << endl;
    cout << "Consumo total acumulado del Dispositivo " << redDispositivos[0].getId() 
         << ": " << redDispositivos[0].consumoTotal() << " Wh" << endl;

    redDispositivos[0].desconectar();
    cout << "Dispositivo desconectado correctamente." << endl;

    return 0;
}
