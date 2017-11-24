cmake_minimum_required (VERSION 3.0.0)
project (autom)
#nazwa pliku wykonywalnego

add_executable(autom cell_autom.c flow_control.c)
#nazwa pliku wyk, potem nazwy zrodel
add_compile_options( -Wall -g)
