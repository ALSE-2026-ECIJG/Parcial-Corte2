Proyecto Sensores
Descripción

Aplicación desarrollada en C++ para administrar sensores y registrar sus mediciones. El programa permite crear sensores, consultar su información, actualizar mediciones y activar o desactivar sensores.
Funcionalidades

    Crear y almacenar dos sensores.
    Registrar nuevas mediciones ingresadas por el usuario.
    Validar identificadores, nombres, tipos y valores numéricos.
    Actualizar mediciones únicamente cuando el sensor está activo.
    Consultar la información y el estado de cada sensor.
    Mostrar los resultados por consola.

Tecnologías utilizadas

    C++
    STL (std::vector)
    CMake
    Doxygen
    Git y GitHub

Estructura del proyecto

Proyecto_Sensores/
├── include/
│   └── Sensor.h
├── src/
│   ├── Sensor.cpp
│   └── main.cpp
├── docs/
│   └── html/
│       └── index.html
├── CMakeLists.txt
├── Doxyfile
└── README.md

Requisitos

    Compilador de C++ compatible.
    CMake.
    Doxygen para regenerar la documentación.

Compilación

Desde la carpeta raíz del proyecto, ejecutar:

cmake -S . -B build
cmake --build build

Ejecución

En Ubuntu, ejecutar:

./build/ProyectoSensores

El programa solicitará una nueva medición para cada sensor y mostrará la información actualizada al finalizar.
Ejemplo de uso

=== SISTEMA DE REGISTRO DE SENSORES ===
Se han creado dos sensores.

Sensor: Sensor de temperatura
Ingrese la nueva medicion: 23
Medicion actualizada correctamente.

Sensor: Sensor de humedad
Ingrese la nueva medicion: 12
Medicion actualizada correctamente.

=== INFORMACION FINAL ===
ID: 1
Nombre: Sensor de temperatura
Tipo: Temperatura
Medicion: 23.00
Estado: Activo

Las mediciones mostradas son un ejemplo; los resultados dependen de los valores ingresados.
Documentación

La documentación del código se genera con Doxygen utilizando:

doxygen Doxyfile

El archivo HTML principal se encuentra en docs/html/index.html.
Autor

JulianAGF
