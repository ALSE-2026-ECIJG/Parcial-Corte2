#include "ClienteBancario.h"
#include <numeric>

ClienteBancario::ClienteBancario(const std::string& nombre, const std::string& cedula)
    : nombre(nombre), cedula(cedula), saldo(0.0f) {}

void ClienteBancario::depositar(float valor) {
    if (valor <= 0.0f) {
        return;
    }
    saldo += valor;
    transacciones.push_back(valor);
}

bool ClienteBancario::retirar(float valor) {
    if (valor <= 0.0f || valor > saldo) {
        return false;
    }
    saldo -= valor;
    transacciones.push_back(-valor);
    return true;
}

float ClienteBancario::obtenerSaldo() const {
    return saldo;
}

std::string ClienteBancario::obtenerNombre() const {
    return nombre;
}

float ClienteBancario::promedioTransacciones() const {
    if (transacciones.empty()) {
        return 0.0f;
    }
    float suma = std::accumulate(transacciones.begin(), transacciones.end(), 0.0f);
    return suma / static_cast<float>(transacciones.size());
}
