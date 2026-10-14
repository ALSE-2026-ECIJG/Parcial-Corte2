cmake_minimum_required(VERSION 3.10)
project(RegistroAcademicoProyecto)

# Configurar el estandar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorio de cabeceras
include_directories(${CMAKE_SOURCE_DIR}/include)

# Archivos fuente del proyecto
set(SOURCES
    src/main.cpp
    src/RegistroAcademico.cpp
)

# Ejecutable final
add_executable(RegistroAcademicoProyecto ${SOURCES})