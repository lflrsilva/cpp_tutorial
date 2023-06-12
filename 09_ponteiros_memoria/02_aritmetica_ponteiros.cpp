/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_aritmetica_ponteiros.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Conceitos sobre aritmética de ponteiros
  - Ponteiros para arrays
  - Aplicações com ponteiros
  - Teoria sobre operações relacionais com ponteiros

Aritmética de ponteiros
-----------------------
  Ponteiros indicam a informação de posição (endereço) na memória. O endereço
  na memória é um valor (em formato hex), que referência a sua posição. Sendo
  assim, é possível realizar operações simples com ponteiros: ++, --, + e -

  int *m;     // 4 bytes para inteiros

  Assumindo que m aponta para o local de memoria 1000:

  m++;

  O local de memória sera atualizado de onde m aponta para 1004: 1000 + 4 bytes.

Ponteiros para arrays
---------------------
  Arrays são ponteiros constantes que apontam para o primeiro elemento da lista.
  Portanto, ao atribuir um array a um ponteiro, este ira apontar para o primeiro
  elemento do array.

  double m[25];
  double *ptr;

  ptr = m;     // arrays são ponteiros constantes em m[0]

  m   [0] [1] [2] [3] ... [23] [24]
  ___|___|___|___|___|___|___|___|___|___|
      ^*ptr

  Portanto, é possível acessar todos os elementos do array usando apenas
  aritmética de ponteiros.

  for(i = 0; i < 25; i++) {
      cout << "*(ptr + " << i << ") : " << *(ptr + i) << endl;
  }

  Em arrays, os colchetes [] são chamados de operadores de deferência offset
  (deslocamento) em relação ao primeiro elemento do array.

  my_array[5] = 0;      // a[offset de 5] = 0
  *(my_array +5) = 0;   // apontando para (a + 5) = 0

Referências
-----------
  - https://cplusplus.com/doc/tutorial/pointers/

 */

#include <iostream>

#define NMAX 3

int main(int argc, char **argv) {

  int var[] = {10, 100, 300};
  int i, *ptr;

  ptr = var;
  for (i = 0; i < NMAX; i++) {

    std::cout << "Endereco de var[" << i << "] = " << ptr << std::endl;
    std::cout << "Valor de var[" << i << "] = " << *ptr << std::endl;

    // movendo a posição de ptr na memória
    ptr++;
  }

  // array com 5 elementos
  int ns[5];
  int *p;

  p = ns;  // apontando p em ns[0]
  *p = 10; // atribuindo 10 em ns[0]

  p++; // incremento na posição
  *p = 20;

  p = &ns[2]; // apontando para endereço de ns[2]
  *p = 30;

  p = ns + 3; // offset em 3 elementos
  *p = 40;

  p = ns; // apontando p em ns[0]
  *(p + 4) = 50;

  for (p = ns; p < (ns + 5); p++) {
    std::cout << *p << ", ";
  }
  p = nullptr;

  return 0;
}
