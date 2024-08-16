[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/Z4l11-L-)
# AyED / AYP2 - TP3 1c2024

<p align="center">
   <img src="Banner.jpg" alt="TP3: Quality of Life"><br>
</p>

### Estudiante: MOYANO, ANDRÉS - 110017

El proyecto se puede compilar manualmente por terminal con la siguiente línea:

>g++ main.cpp -I include src/combate_multiple.cpp src/combate.cpp src/armamento_artefactos.cpp src/artefacto.cpp src/menu.cpp src/administrador_artefactos.cpp src/administrador_combate.cpp src/transformador_texto.cpp -Wall -Werror -Wconversion -o main

O, alternativamente, con CMake, utilizando el archivo **CMakeLists.txt** presente en el directorio raíz.

Para distribuciones de Linux, se pueden utilizar los scripts presentes en el directorio raíz para compilar y ejecutar
la suite de tests. Requiere:

1. [g++](https://gcc.gnu.org/)
2. [CMake](https://cmake.org/)
3. [Valgrind](https://valgrind.org/)

Que se pueden instalar por terminal:

> sudo apt-get install // PROGRAMA //

# Aclaraciones adicionales:

// Muy buenos días corrector. Agregue un meta comentario siguiendo la premiza de
que el Honkai Star Rail no se ha lanzado haciendo un "menu debug". Esto se debe
a que no tengo mucho tiempo para pulir más este TP, tengo que hacer un 
vector dinamico en ASSEMBLY para otra materia y aún no lo empece. Si tengo
un poco de tiempo quizas continue un poco este TP, sobretodo las pre y post
que son escuetas, me hubiera gustado hacer un menu visualmente lindo como
el del TP 2 pero por ahora es imposible...//