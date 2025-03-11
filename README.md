# Homework1\_Sandri

## Enunciado

### Parte 1a

Crear una función que, dado un valor entero `n` (positivo y mayor a uno), devuelva una matriz cuadrada con valores organizados secuencialmente. Por ejemplo:

Para `n = 2`:

```
M2 = [1 2]
     [3 4]
```

Para `n = 3`:

```
M3 = [1 2 3]
     [4 5 6]
     [7 8 9]
```

### Parte 1b

Proveer un código que imprima el contenido de la matriz utilizando un único ciclo `for`, recorriéndola desde el mayor valor hasta el menor. Es decir, para `M2` la salida debe ser:

```
M[1][1] = 4
M[1][0] = 3
M[0][1] = 2
M[0][0] = 1
```

**Nota:** Se deben imprimir los índices de la matriz.

---

## Comandos para compilar y ejecutar el código en C++

1. Cambiar el directorio:
   ```sh
   cd Ejercicio_1
   ```

2. Compilar el código:
   ```sh
   g++ main.cpp -o programa
   ```
2. Ejecutar el programa:
   ```sh
   ./programa
   ```

---

### Parte 2-a

En muchos sistemas, es importante registrar eventos relevantes. Cada evento tiene un nivel de severidad, como:
- DEBUG
- INFO
- WARNING
- ERROR
- CRITICAL

#### Objetivo:
Implementar una función `logMessage` que agregue entradas a un archivo de log con el siguiente formato:
```
[ERROR] <Mensaje>
[INFO] <Mensaje>
```
Debe verificarse el funcionamiento con al menos una entrada de cada tipo.

---

## Comandos para compilar y ejecutar el código en C++

1. Cambiar el directorio
   ```sh
   cd Ejercicio_2
   ```

2. Compilar el código:
   ```sh
   g++ main.cpp -o programa
   ```
3. Ejecutar el programa:
   ```sh
   ./programa
   ```

### Parte 2b - Extensión del Sistema de Registro

Se requiere agregar funcionalidades adicionales al sistema de log:

1. **Registro de errores con archivo y línea:**
   ```cpp
   logMessage("Mensaje de error", "archivo.cpp", 42);
   ```
   Esto generará un log con el siguiente formato:
   ```
   [ERROR] Mensaje de error (Archivo: archivo.cpp, Línea: 42)
   ```

2. **Registro de eventos de seguridad:**
   ```cpp
   logMessage("Access Granted", "usuario123");
   logMessage("Access Denied", "invitado");
   ```
   Esto generará logs con el formato:
   ```
   [SECURITY] Access Granted (Usuario: usuario123)
   [SECURITY] Access Denied (Usuario: invitado)
   ```

3. **Captura de errores en tiempo de ejecución:**
   - Si se produce una excepción en tiempo de ejecución, el programa deberá capturarla, registrarla en el log e interrumpir su ejecución con `return 1`.

---

## Comandos para compilar y ejecutar el código en C++


1. Compilar el código:
   ```sh
   g++ log_system_v2.cpp -o log_program
   ```
3. Ejecutar el programa:
   ```sh
   ./log_program
   ```

### Parte 3

Se requiere implementar una lista enlazada utilizando std::unique_ptr. La lista debe contar con las siguientes funciones:

- create_node(): Crea y devuelve un nodo.
- push_front(int value): Inserta un nodo al frente de la lista.
- push_back(int value): Inserta un nodo al final de la lista.
- insert(int value, int position): Inserta un nodo en la posición indicada. Si la posición es mayor que el largo de la lista, debe insertarse al final y mostrar un mensaje informativo.
- erase(int position): Elimina el nodo en la posición indicada. Si la posición es mayor que el largo de la lista, debe eliminar el último nodo y mostrar un mensaje informativo.
- print_list(): Imprime la lista enlazada en el formato
```
1 -> 2 -> 3 -> nullptr
```

---

## Comandos para compilar y ejecutar el código en C++

1. Cambiar el directorio
   ```sh
   cd Ejercicio_3
   ```

2. Compilar el código:
   ```sh
   g++ linked_list.cpp -o linked_list
   ```
3. Ejecutar el programa:
   ```sh
   ./linked_list
   ```
   