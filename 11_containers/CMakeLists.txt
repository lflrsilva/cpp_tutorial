cmake_minimum_required(VERSION 3.20)

# nome do projeto (igual ao executavel a ser criado)
project(tutorial_11)

# extrair comandos de compilação em arquivo json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# altere o nome do arquivo fonte principal e inclua fonte adicional
add_executable(tutorial_11 02_iterators_containers.cpp)

# indica os diretórios para buscar os cabeçalhos (*.h) chamados nos códigos
include_directories(./include)

# definindo uso de C++ versão 17
target_compile_features(tutorial_11 PUBLIC cxx_std_17)
