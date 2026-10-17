# ClienteBancario

Proyecto final del parcial de C++. Simula cuentas de clientes bancarios
(depositos, retiros, saldo y promedio de transacciones) usando programacion
orientada a objetos, contenedores de la STL (`std::vector`), CMake y Doxygen.

## Estructura

```
Proyecto/
├── CMakeLists.txt
├── Doxyfile
├── include/ClienteBancario.h
├── src/ClienteBancario.cpp
├── src/main.cpp
└── docs/            (documentacion HTML generada por Doxygen)
```

## Compilacion

```bash
mkdir build && cd build
cmake ..
make
./banco
```

## Documentacion

Abrir `docs/html/index.html` en el navegador. Para regenerarla:

```bash
doxygen Doxyfile
```

## Ejemplo de ejecucion

```
=== Registro de clientes ===
Cliente 1 - Nombre: Ana
Cliente 1 - Cedula: 123
Cliente 2 - Nombre: Luis
Cliente 2 - Cedula: 456

--- MENU ---
1. Depositar
2. Retirar
3. Consultar saldo
4. Promedio de transacciones
5. Listar clientes
0. Salir
Opcion: 1
Cliente (1-2): 1
Monto a depositar: 5000
Deposito exitoso. Saldo: 5000

Opcion: 2
Cliente (1-2): 1
Monto a retirar: 1200
Retiro exitoso. Saldo: 3800

Opcion: 2
Cliente (1-2): 1
Monto a retirar: 9000
Retiro rechazado (monto invalido o saldo insuficiente).

Opcion: 4
Cliente (1-2): 1
Promedio de transacciones de Ana: 1900

Opcion: 5
Ana | CC 123 | Saldo: 3800 | Transacciones: 2
Luis | CC 456 | Saldo: 0 | Transacciones: 0
```

## Autor

Nicolas
