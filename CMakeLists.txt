cmake_minimum_required(VERSION 3.10)
project(ProyectoSensores)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(app_sensores src/main.cpp src/Sensor.cpp)