/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_rotinas.cpp
  Author: lflrsilva

  Rotinas auxiliares para definições em 03_ref_const.cpp.

 */

// Deve-se incluir o cabeçalho associado
#include "03_rotinas.h"

// Função fatorial
long fatorial(long a) {
    if (a > 1)
        return (a * fatorial (a-1));
    else
        return 1;
}
