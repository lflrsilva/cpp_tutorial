cmake_minimum_required(VERSION 3.25)

# ajuste o nome do projeto
project(using_fmt)

# vamos colocar o padrão C++ 20 pois
# o fmt tem algumas comandos bem atualizados
set(CMAKE_CXX_STANDARD 20)

# colocar o nome do pacote
find_package(fmt CONFIG REQUIRED)

# colocar o nome do executável e o arquivo fonte
add_executable(my_app main_fmt.cpp)

# colocar o nome do executável e as bibliotecas para linkar
target_link_libraries(my_app PRIVATE fmt::fmt)

