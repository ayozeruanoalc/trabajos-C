
## Trabajos Prácticos en lenguaje C

Este repositorio contiene los trabajos prácticos de los bloques dedicados a la programación de sistemas en GNU/Linux, incluyendo gestión de procesos, hilos y manipulación de archivos en C. 

[![My Skills](https://skillicons.dev/icons?i=c)](https://skillicons.dev)

Autores: **Ayoze Ruano Alcántara, Enrique Reina Hernández y Fabio Nesta Arteaga Cabrera**.

### Trabajo 1: Gestión de grupos en C
Implementación de una biblioteca para gestionar un grupo de alumnos.
- Uso de punteros, vectores, structs, funciones y memoria dinámica.
- Código modular: `grupo.c`, `grupo.h`, `test_grupo.c`, `Makefile`.
- Pruebas unitarias para cada función de la biblioteca.

### Trabajo 2: Mini-Shell en C
Implementación de un shell básico que ejecuta comandos introducidos por el usuario.
- Uso de llamadas al sistema: `fork`, `exec`, `wait`, `getpid`, `getppid`, `exit`.
- Funcionalidades opcionales:
  - Medición del tiempo de ejecución y uso de CPU (`times`, `getrusage`).
  - Comando `cd` implementado en el propio shell.
  - Ejecución asíncrona de comandos con `&`.

### Trabajo 3: Hilos y Archivos
- Programación concurrente con la biblioteca POSIX `pthreads`.
- Ejercicios de suma paralela y producto escalar de vectores con múltiples hilos.
- Sincronización mediante cerrojos y variables condición.
- Manipulación de archivos usando solo llamadas al sistema (`open`, `write`, `read`, etc.).





