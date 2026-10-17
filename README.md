# ClienteBancario

Proyecto en C++ que implementa la clase `ClienteBancario` (depósitos, retiros,
saldo y promedio de transacciones), organizado con CMake y documentado con Doxygen.

## Estructura

- `include/ClienteBancario.h`: declaración de la clase (Doxygen).
- `src/ClienteBancario.cpp`: implementación de los métodos.
- `src/main.cpp`: programa principal (`cin`/`cout`, dos clientes en un `std::vector`).
- `CMakeLists.txt`: configuración de compilación.
- `Doxyfile`: configuración de Doxygen. La documentación HTML se genera en `docs/`.

## Compilación

```bash
mkdir build && cd build
cmake ..
make
./ClienteBancarioApp
```

## Documentación

```bash
doxygen Doxyfile      # genera docs/html/index.html
```

## Ejemplo de ejecución

```
Cliente: Ana Torres
  Saldo actual: $350000.00
  Promedio de transacciones: $175000.00

Cliente: Luis Gomez
  Saldo actual: $200000.00
  Promedio de transacciones: $200000.00
```
