cmake_minimum_required(VERSION 3.12)
project(Pila C)

set(CMAKE_C_STANDARD 99)

add_executable(Pila main.c pila.c pila.h testing.c testing.h pruebas_alumno.c stack.c)