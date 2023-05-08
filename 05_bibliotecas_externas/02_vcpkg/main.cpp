/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   main.cpp
  Author: lflrsilva

  Arquivo teste para uso do vcpkg e CMake

*/

#include <sqlite3.h>
#include <iostream>

int main()
{
    std::cout << sqlite3_libversion() << std::endl;
    return 0;
}
