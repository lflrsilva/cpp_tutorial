/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_deque_container.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Container deque

O que são deque?
----------------
  O container deque (double ended queue) tenta aliar as vantagens de arrays e
  vector em uma abordagem única. Como vectors, a alocação dinâmica permite a
  inserção de novos elementos, que são alocados de forma sequencial na memória.
  Mas nesse caso, quando o espaço acaba no bloco atual de memória, um novo bloco
  é usado para continuar a alocação dos novos elementos. Com isso, evita-se
  a desalocação e cópia de dados para um novo bloco de memória, como feito pelo
  container vector.

  Para acompanhar os elementos, o início de cada bloco de memória tem a
  indexação por um ponteiro. Com isso, são muito eficientes em inserir dados no
  início e no fim da cadeia de elementos. Apesar de serem mais complexos
  internamente, se tornam mais eficientes no aumento de elementos em
  determinadas condições, em especial em sequencias muito longas em que a
  desalocação de um vector seria muito custosa.

  Os métodos de deque são muito semelhantes a vector.

Referências
-----------
  - https://cplusplus.com/reference/list/list/

*/

#include <iostream>
#include <deque>

int main(int argc, char **argv) {

  // declaração de container
  std::deque<int> myContainer;

  for (int i = 0; i < 5; i++) {
    myContainer.push_back(i + 1);    // 1 2 3 4 5
  }

  myContainer.pop_front();          // deleta primeiro elemento 
  myContainer.push_front(10);       // insere no primeiro elemento

  for (auto i : myContainer) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
