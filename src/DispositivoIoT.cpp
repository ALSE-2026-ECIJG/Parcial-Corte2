#include "DispositivoIoT.h"

DispositivoIoT::DispositivoIoT(int id_val) {
    id = id_val;
    conectado = false;
    consumoWattHora = 0.0f;
}

void DispositivoIoT::conectar() {
    conectado = true;
}

void DispositivoIoT::desconectar() {
    conectado = false;
}

void DispositivoIoT::registrarConsumo(float valor) {
    if (valor >= 0.0f) {
        registroConsumo.push_back(valor);
    }
}

float DispositivoIoT::consumoTotal() const {
    float total = 0.0f;
    for (float v : registroConsumo) {
        total += v;
    }
    return total;
}

int DispositivoIoT::getId() const {
    return id;
}
