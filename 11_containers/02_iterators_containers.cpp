/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_iterators_containers.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Iteradores de containers

O que são iteradores?
---------------------
  Os iteradores (iterators) são métodos de containers que são específicos para
  varredura dos elementos. Na prática, os iteradores são objetos que apontam
  para um elemento dentro da faixa de dados contida por um container.

Categorias de iteradores
------------------------
  Os iteradores tem 5 categorias diferentes que dependem da funcionalidade de
  cada container.

          -------------------------------------------------
          |                 RANDOM ACCESS                 |
          |   -----------------------------------------   |
          |   |             BIDIRECTIONAL             |   |
          |   |   ---------------------------------   |   |
          |   |   |            FORWARD            |   |   |
          |   |   |   ---------       ----------  |   |   |
          |   |   |   | INPUT |       | OUTPUT |  |   |   |
          |   |   |   ---------       ----------  |   |   |
          |   |   ---------------------------------   |   |
          |   -----------------------------------------   |
          -------------------------------------------------

  Os iteradores input e output são os mais básicos e também os mais restritos.
  Ambos são usados em operações sequenciais de entrada (input - leitura do dado)
  ou saída (output - escrita do dado) em que o iterador é incrementado e segue
  para o próximo elemento. Ou seja, estes iteradores executam um único passo
  sobre um elemento.

  Os iteradores forward tem as mesmas que input e output, com capacidade de
  leitura e escrita de dados. O iterador bidirectional adiciona a capacidade
  de varredura sequencial nos sentidos para o fim ou início do container. Por
  fim, o iterador random access inclui ainda a possibilidade de acesso em uma
  posição arbitrária, assim como um ponteiro.

  Cada containers usa uma categoria de iterador para acesso aos elementos,
  fornecendo funcionalidades específicas. Tanto o array quanto o vector tem 
  iteradores random access.

  Os cabeçalhos dos containers já acessam os iteradores, mas para uso apenas 
  destes, inclua o cabeçalho <iterator>.

Referências
-----------
  - https://cplusplus.com/reference/array/array/
  - https://cplusplus.com/reference/vector/vector/
  - https://cplusplus.com/reference/iterator/

*/

#include <complex>
#include <iostream>
#include <array>
#include <vector>
#include <iterator>


int main(int argc, char **argv) {

  // declaração de array
  std::array<int, 10> arr1;

  // iterador simples usando offset []
  for (int i = 0; i < arr1.size(); i++) {
    arr1[i] = i + 1;
  }

  // vamos usar um iterator de array
  for (std::array<int, 10>::iterator i = arr1.begin();
      i != arr1.end();
      i++) 
  {
    std::cout << i << "\t";          // o iterador retorna os endereços 
  }                                  // por onde o ponteiro do iterador passa
  std::cout << "\n";

  // vamos aprimorar a escrita do laço usando auto 
  for (auto i = arr1.begin(); i != arr1.end(); i++) 
  {
    std::cout << *i << "\t";          // *i = valor no local de memória
  }
  std::cout << "\n";

  // C++ fornece outra forma de criar os laços com iteradores
  for (auto i : arr1) {
    std::cout << i << "\t";
  }
  std::cout << "\n";

  // legal, vamos fazer mais um teste alterando o valor do iterador!
  for (auto i : arr1) {
    i = i + 2;
    std::cout << i << "\t";
  }
  std::cout << "\n";

  // vamos confirmar se os valores do array foram alterados?
  for (int i = 0; i < arr1.size(); i++) {
    std::cout << arr1[i]  << "\t";
  }
  std::cout << "\n";

  // O que houve? O container não foi alterado. E se usarmos o endereço do 
  // container?
  for (auto& i : arr1) {
    i = i + 2;
  }

  for (int i = 0; i < arr1.size(); i++) {
    std::cout << arr1[i]  << "\t";
  }
  std::cout << "\n";

  return 0;
}
