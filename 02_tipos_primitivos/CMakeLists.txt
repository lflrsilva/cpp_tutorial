cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_02)

# altere o nome do arquivo fonte
add_executable(tutorial_02 01_tipos_fundamentais.cpp)

# definindo uso de C++ versão 17
target_compile_features(tutorial_02 PUBLIC cxx_std_17)

