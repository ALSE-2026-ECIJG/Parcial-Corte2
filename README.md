# Registro Académico

Proyecto en C++17 que implementa la clase `RegistroAcademico`, la cual gestiona
las notas y créditos de un estudiante (escala 0.0 a 5.0, aprueba con 3.0 o más).

## Estructura
- `include/RegistroAcademico.h`: declaración de la clase (Doxygen)
- `src/RegistroAcademico.cpp`: implementación
- `src/main.cpp`: programa principal
- `docs/`: documentación HTML generada con Doxygen

## Compilación
```bash
mkdir build && cd build
cmake ..
cmake --build .
./registro        # En Windows: registro.exe
```

## Generar documentación
```bash
doxygen Doxyfile
```
Abra `docs/index.html` en el navegador.

## Ejemplo de ejecución
```
=== SISTEMA DE REGISTRO ACADEMICO ===
Cuantos estudiantes desea registrar (minimo 2)? 2

--- Estudiante 1 ---
Nombre: Ana
Cuantas materias va a registrar? 2
  Nota materia 1 (0.0 - 5.0): 4.5
  Creditos materia 1: 3
  Nota materia 2 (0.0 - 5.0): 2.5
  Creditos materia 2: 2

--- Estudiante 2 ---
Nombre: Luis
Cuantas materias va a registrar? 1
  Nota materia 1 (0.0 - 5.0): 3.0
  Creditos materia 1: 4

Creditos requeridos para cumplir el requisito: 4

=== RESULTADOS ===
Estudiante: Ana
  Materias registradas: 2
  Creditos aprobados:   3
  Promedio ponderado:   3.70
  Cumple requisitos:    NO

Estudiante: Luis
  Materias registradas: 1
  Creditos aprobados:   4
  Promedio ponderado:   3.00
  Cumple requisitos:    SI
```
##
autor nicolas huerfano ;-;