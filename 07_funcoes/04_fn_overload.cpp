/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_fn_overload.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Sobrecarregamento de funções : é possível usar o mesmo nome para a subrotina,
  mas com tipos de argumentos diferentes. A escolha de qual implementação é usada
  depende dos tipos dos argumentos.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/functions/
  - https://google.github.io/styleguide/cppguide.html

 */

#include <iostream>
#include <cstdlib>

int soma(int a, int b) {
    return a + b;
}

double soma(double a, double b) {
    return a + b;
}

int main(int argc, char** argv) {

    int xi = 2, yi = 3, resi;
    double xd = 2.5, yd = 3.5, resd;

    // chamada da função soma (int)
    resi = soma(xi, yi);
    std::cout << "Soma de " << xi << " + " << yi << " = "
              << resi << std::endl;

    // chamada da função soma (double)
    resd = soma(xd, yd);
    std::cout << "Soma de " << xd << " + " << yd << " = "
              << resd << std::endl;

    return (EXIT_SUCCESS);
}
