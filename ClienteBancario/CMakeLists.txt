cmake_minimum_required(VERSION 3.10)
project(ClienteBancario VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(banco
    src/main.cpp
    src/ClienteBancario.cpp
)
