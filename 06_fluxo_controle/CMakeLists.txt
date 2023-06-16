cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_06)

# altere o nome do arquivo fonte
add_executable(tutorial_06 01_condicional_if.cpp)

# definindo uso de C++ versão 17
target_compile_features(tutorial_06 PUBLIC cxx_std_17)

