# Proyecto Final - Dispositivo IoT en C++

## Descripción
Aplicación robusta en C++ desarrollada bajo los principios de la Programación Orientada a Objetos para gestionar dispositivos IoT, controlar su estado de conexión y registrar su consumo energético utilizando contenedores de la STL.

## Tecnologías y Herramientas
- C++ (Estándar C++17)
- Contenedores de la STL (`std::vector`)
- CMake (Gestión y compilación de proyectos)
- Doxygen (Generación de documentación técnica)
- Git y GitHub (Control de versiones colaborativo)

## Instrucciones de Compilación y Ejecución
Para compilar y ejecutar el proyecto utilizando CMake en tu entorno local, ejecuta los siguientes comandos en la terminal desde la raíz del proyecto:

```bash
# Configurar el proyecto
cmake -S . -B build

# Compilar el proyecto
cmake --build build

# Ejecutar el programa resultante (Linux/macOS)
./build/ProyectoIoT

# O en Windows (dependiendo del generador):
# .\build\Debug\ProyectoIoT.exe
