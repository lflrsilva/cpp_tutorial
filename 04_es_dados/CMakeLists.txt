cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_04)

# altere o nome do arquivo fonte
add_executable(tutorial_04 01_entrada_saida_basico.cpp)

# definindo uso de C++ versão 17
target_compile_features(tutorial_04 PUBLIC cxx_std_17)

