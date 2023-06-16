cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_08)

# altere o nome do arquivo fonte
# no arquivo principal 03, inclua tambem o arquivo fonte com as rotinas
add_executable(tutorial_08 03_outros_tipos.cpp)

# definindo uso de C++ versão 17
target_compile_features(tutorial_08 PUBLIC cxx_std_17)

