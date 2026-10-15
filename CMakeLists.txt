cmake_minimum_required(VERSION 3.16)

project(ProyectoSensores VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(ProyectoSensores
src/main.cpp
src/Sensor.cpp
)

target_compile_options(ProyectoSensores PRIVATE
-Wall
-Wextra
-Wpedantic
)
