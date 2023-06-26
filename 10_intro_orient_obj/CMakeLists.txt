cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_10)

# extrair comandos de compilação em arquivo json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# altere o nome do arquivo fonte principal e inclua fonte adicional
add_executable(tutorial_10 01_intro_classes.cpp)

# indica os diretórios para buscar os cabeçalhos (*.h) chamados nos códigos
include_directories(./include)

# definindo uso de C++ versão 17
target_compile_features(tutorial_10 PUBLIC cxx_std_17)
