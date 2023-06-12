/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_args_funcoes.cpp
  Author: lflrsilva

Passagem de arrays (vetores e matrizes)
---------------------------------------

  Para arrays como argumentos da sub-rotina, apenas o endereço é passado como
  parâmetro. No caso, sempre para o primeiro elemento do array. Neste caso, a
  passagem eh sempre por referencia e o usuário pode alterar o conteúdo do
  argumento passado para a sub-rotina. Pode-se evitar isso passando o argumento
  como uma variável constante.

 */

#include "display.h"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {

  int t[10], i;

  double a[] = {1., 2., 8., 20., -10., 30.};
  double sum, d5;

  for (i = 0; i < 10; i++) {
    t[i] = i;
  }

  display(t); // array aponta para primeiro elemento

  sum = h(a, 6); // Soma dos elementos de a
  d5 = a[5];     // d5 = 1000

  return (EXIT_SUCCESS);
}
