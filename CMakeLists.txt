cmake_minimum_required(VERSION 3.10)
project(ClienteBancarioApp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Librería con la lógica de ClienteBancario.
add_library(ClienteBancarioLib src/ClienteBancario.cpp)
target_include_directories(ClienteBancarioLib PUBLIC include)

# Ejecutable principal.
add_executable(ClienteBancarioApp src/main.cpp)
target_link_libraries(ClienteBancarioApp PRIVATE ClienteBancarioLib)

# Target opcional `doc` para generar documentación HTML con Doxygen
# (cmake --build . --target doc).
find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/docs")
    doxygen_add_docs(doc
        include/ClienteBancario.h
        src/ClienteBancario.cpp
        src/main.cpp
        COMMENT "Generando documentación Doxygen en docs/"
    )
endif()
