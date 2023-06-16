cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_07)

# altere o nome do arquivo fonte
# no arquivo principal 03, inclua tambem o arquivo fonte com as rotinas
add_executable(tutorial_07 01_definicao_rotinas.cpp)

# indica os diretórios para buscar os cabeçalhos (*.h) chamados nos códigos
include_directories(./)

# definindo uso de C++ versão 17
target_compile_features(tutorial_07 PUBLIC cxx_std_17)

