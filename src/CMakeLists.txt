cmake_minimum_required (VERSION 3.0.0)
project (autom)

add_executable(autom cell_autom.c flow_control.c rules.c)
add_compile_options( -Wall -g)
