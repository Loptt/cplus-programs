cmake_minimum_required(VERSION 3.9)
project(Project2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project2 main.cpp Autor.h Fecha.h Materia.h Tema.h EjemploVideo.h)

configure_file(Autores.txt Autores.txt COPYONLY)
configure_file(EjemploVideo.txt EjemploVideo.txt COPYONLY)
configure_file(Temas.txt Temas.txt COPYONLY)
configure_file(Materias.txt Materias.txt COPYONLY)