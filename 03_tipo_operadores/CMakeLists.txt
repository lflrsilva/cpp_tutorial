cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_03)

# altere o nome do arquivo fonte
add_executable(tutorial_03 01_operadores_aritmeticos.cpp)

# definindo uso de C++ versão 17
target_compile_features(tutorial_03 PUBLIC cxx_std_17)

