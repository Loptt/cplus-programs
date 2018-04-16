cmake_minimum_required(VERSION 3.9)
project(Project3)

set(CMAKE_CXX_STANDARD 11)

add_executable(Project3 main.cpp Fecha.h Material.h Libro.h Disco.h Software.h Reserva.h)
configure_file(test.txt test.txt COPYONLY)