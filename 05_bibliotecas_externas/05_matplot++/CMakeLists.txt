cmake_minimum_required(VERSION 3.25)

project(using_matplot)

set(CMAKE_CXX_STANDARD 20)

find_package(matplot++ CONFIG REQUIRED)

add_executable(my_app main_matplot++.cpp)

target_link_libraries(my_app PRIVATE Matplot++::matplot)
