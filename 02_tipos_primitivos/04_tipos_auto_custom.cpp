/**
  
  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_tipos_auto_custom.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Dedução de tipos: auto e decltype (desde c++11)
  - Tipos customizados: using alias (desde c++11)

  Obs.: O comando typedef é usado para criar tipos customizados em C. Em termos
  gerais, o comando alias amplia a capacidade de typedef e, portanto, seu 
  uso é preferível.

  typedef scalar float;

  Referencias:
  - https://cplusplus.com/doc/tutorial/variables/

 */

#include <iostream>

// definindo um tipo customizado
// caso queira mudar a precisão, basta mudar para double
using scalar = float;

int main(int argc, char** argv) {

    // dedução do tipo pela inicialização
    auto x = 10.8L;   // long double
    auto i = 108;     // int
    auto iu = 10u;    // unsigned int

    // declara variável usando o mesmo tipo de outra variável
    int foo = 0;
    decltype(foo) bu;     // int bu;

    decltype(iu) au;      // cria au como unsigned int

    // declarando um tipo customizado
    scalar velocity = 10.0;
    scalar acceleration = 1.0;
    scalar position = 13.0;

    scalar time = position/velocity;

    return (0);
}

