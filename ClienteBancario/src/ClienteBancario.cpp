#include "ClienteBancario.h"

ClienteBancario::ClienteBancario(const std::string& _nombre,
                                 const std::string& _cedula) {
    nombre = _nombre;
    cedula = _cedula;
    saldo = 0.0f;
}

void ClienteBancario::depositar(float valor) {
    if (valor > 0) {
        saldo += valor;
        transacciones.push_back(valor);
    }
}

bool ClienteBancario::retirar(float valor) {
    if (valor > 0 && saldo >= valor) {
        saldo -= valor;
        transacciones.push_back(-valor);
        return true;
    }
    return false;
}

float ClienteBancario::obtenerSaldo() const {
    return saldo;
}

float ClienteBancario::promedioTransacciones() const {
    if (transacciones.empty()) {
        return 0.0f;
    }
    float suma = 0.0f;
    for (float t : transacciones) {
        suma += t;
    }
    return suma / transacciones.size();
}

std::string ClienteBancario::obtenerNombre() const { return nombre; }
std::string ClienteBancario::obtenerCedula() const { return cedula; }
int ClienteBancario::cantidadTransacciones() const { return transacciones.size(); }
