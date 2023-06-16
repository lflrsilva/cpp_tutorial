cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_09)

# altere o nome do arquivo fonte principal e inclua fonte adicional
add_executable(tutorial_09 01_ponteiros_basico.cpp)

# indica os diretórios para buscar os cabeçalhos (*.h) chamados nos códigos
include_directories(./include)

# definindo uso de C++ versão 17
target_compile_features(tutorial_09 PUBLIC cxx_std_17)

