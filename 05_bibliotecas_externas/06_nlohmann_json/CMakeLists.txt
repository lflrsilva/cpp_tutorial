cmake_minimum_required(VERSION 3.25)

project(using_json)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(my_app main_json.cpp)

target_link_libraries(my_app PRIVATE nlohmann_json::nlohmann_json)
