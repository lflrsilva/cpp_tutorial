/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_ponteiro_funcoes.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Ponteiro para funções

  C++ permite operações com ponteiros que apontam para funções. Isso permite
  que funções possam ser tratadas como argumento de outra função. A sintaxe
  para ponteiros de funções é a mesma para uma função regular, exceto

  - o nome da função deve estar entre parênteses,
  - o * deve estar antes do nome da função

Referências
-----------
  - https://cplusplus.com/doc/tutorial/pointers/

 */

#include <cstdlib>
#include <iostream>

// definindo função regular
inline int add(int a, int b) { return a + b; }

// definindo função regular
inline int sub(int a, int b) { return a - b; }

// definindo função regular com ponteiro de função como parâmetro
inline int operation(int x, int y, int (*fp)(int, int)) {
  int op = (*fp)(x, y);
  return op;
}

int main(int argc, char **argv) {

  int m, n;
  // criando ponteiro de função e apontando para sub
  int (*minus)(int, int) = sub;

  m = operation(7, 3, add);
  std::cout << m << std::endl;

  m = operation(7, 3, minus);
  std::cout << m << std::endl;

  // alterando ponteiro minus para a função add
  minus = add;
  m = operation(7, 3, minus);
  std::cout << m << std::endl;

  return (EXIT_SUCCESS);
}
