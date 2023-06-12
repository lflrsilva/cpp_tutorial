/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_arrays_display.cpp
  Author: lflrsilva

  Diferentes formas de declaracao do prototype para subrotina display

*/

#include "display.h"
#include <iostream>

/*
 * C++ converte num para um ponteiro de inteiros, pois nenhum parametro pode
 * receber um array
 */
// void display(int num[10]) {
//   for (int i = 0; i < 10; i++) {
//     std::cout << num[i] << "\n";
//   }
// }

/*
 * O argumento num tem tamanho desconhecido! C/C++ não verifica os limites
 * de arrays
 */
// void display(int num[]) {
//   for (int i = 0; i < 10; i++) {
//     std::cout << num[i] << "\n";
//   }
// }

/*
 * Qualquer array pode ser indexado usando operadores offset []
 */
void display(int *num) {
  for (int i = 0; i < 10; i++) {
    std::cout << num[i] << "\n";
  }
}
