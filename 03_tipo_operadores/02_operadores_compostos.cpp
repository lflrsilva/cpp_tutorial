/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_operadores_compostos.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Treinamento de depuracao
  - Operadores de incremento
  - Avaliacao de operacoes de incremento
  - Operadores compostos

Obs.: Também existem operações bitwise ( >>=, <<=, &=, ^=, |=) em operações
de atribuição composta. Não vamos explorar esse assunto pois está fora do
escopo do tutorial.

Referencias
-----------
  - https://cplusplus.com/doc/tutorial/operators/
  - https://en.cppreference.com/w/cpp/language/operators
  - https://en.wikipedia.org/wiki/Bitwise_operation

*/

#include <iostream>

int main(int argc, char **argv) {

  // declaracao de variaveis
  int i = 4, j = 4;
  int valor;

  // Incremento e decremento
  i++; //  i = i + 1. Assim i = 5
  ++j; //  j = j + 1. Assim j = 5

  // Avaliando incremento
  int m = i++; //  m = i
               //  i = i + 1
               // Assim, m = 5, i = 6

  int n = ++j; // j = j + 1
               // n = j
               // Assim n = 6, j = 6

  // Avaliando decremento
  m = --i; // m = ?, i = ?
  n = j--; // n = ?, j = ?

  j = (i--) + (++i); // resultado imprevisivel

  // imprimindo em tela
  valor = 1;
  std::cout << "Usando depois da variavel : " << valor++ << std::endl;
  std::cout << "Valor apos incremento: " << valor << std::endl;

  valor = 1;
  std::cout << "Usando depois da variavel : " << ++valor << std::endl;
  std::cout << "Valor apos incremento: " << valor << std::endl;

  // atribuições compostas
  m += 2; // m = m + 2 = 5 + 2 = 7
  m -= 2; // m = m - 2 = 7 - 2 = 5
  m *= 2; // m = 10

  /*  Recomendacoes de uso
      my_very_long_variable = my_very_long_variable - 5 // messy
      my_very_long_variable -= 5                        // better
  */

  return (EXIT_SUCCESS);
}
