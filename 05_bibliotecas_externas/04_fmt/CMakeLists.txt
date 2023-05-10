cmake_minimum_required(VERSION 3.25)

project(using_fmt)

set(CMAKE_CXX_STANDARD 20)

find_package(fmt CONFIG REQUIRED)

add_executable(my_app main_fmt.cpp)

target_link_libraries(my_app PRIVATE fmt::fmt)

