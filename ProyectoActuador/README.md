# ProyectoActuador

Proyecto final de C++ (POO, STL, CMake y Doxygen). Implementa la clase `actuador`,
un dispositivo con nombre, estado (encendido/apagado) y nivel de potencia de 0 a 100.
El programa principal guarda dos actuadores en un `std::vector`, pide datos con `cin`
y simula su encendido, ajuste de potencia y apagado.

## Estructura

```
ProyectoActuador/
├── CMakeLists.txt
├── Doxyfile
├── include/actuador.h
├── src/actuador.cpp
├── src/main.cpp
└── docs/            (HTML generado por Doxygen; abrir docs/index.html)
```

## Compilación

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Ejecución

```bash
./simulador
```

Ejemplo (el usuario escribe Ventilador, Bomba, 80, 150, 60):

```
Nombre del actuador 1: Ventilador
Nombre del actuador 2: Bomba

--- Encendido y ajuste de potencia ---
Ventilador: Encendido
Potencia para Ventilador (0 a 100): 80
Bomba: Encendido
Potencia para Bomba (0 a 100): 150
Nivel invalido: debe estar entre 0 y 100.
Potencia para Bomba (0 a 100): 60

--- Estado despues de ajustar ---
Actuador Ventilador | Estado: Encendido | Potencia: 80%
Actuador Bomba | Estado: Encendido | Potencia: 60%

--- Apagando Ventilador ---
Un actuador apagado no permite ajustar la potencia.

=== Resultado final ===
Actuador Ventilador | Estado: Apagado | Potencia: 0%
Actuador Bomba | Estado: Encendido | Potencia: 60%
```

## Documentación

```bash
doxygen Doxyfile
```
