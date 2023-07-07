/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_list_container.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Container list
  - Container forward_list

O que são lists?
----------------
  O container list difere do array e vector na forma de armazenar e gerenciar
  seus dados. De fato, os elementos não são mais alocados de forma sequencial
  na memória. Cada elemento tem a referência dos elementos vizinhos (anterior e
  posterior) através de ponteiros.

            |     |  ->  |     |  ->  |     |  ->
            | el1 |      | el2 |      | el3 |
            |     |  <-  |     |  <-  |     |  <-
                    ptrs

  Como o container list tem a referência dos dois elementos vizinhos, pode
  iterar tanto para frente quanto para trás. O container permite a inserção e
  remoção de elementos a qualquer momento e entre quaisquer par de elementos.

  A maior desvantagem de list é que não tem acesso direto a um elemento
  específico. Por exemplo, para acessar o terceiro elemento de uma lista, é
  preciso iterar todos os elementos anteriores (varredura para frente) ou
  posteiores (varredura para trás) até chegar ao elemento desejado. Portanto,
  existe um custo computacional nesta operação. Além disso, a indexação dos
  ponteiros dos elementos vizinhos também aumenta a quantidade de memória
  necessária.

  A diferença de list e forward_list é que a última só faz varredura para frente
  (parte do primeiro elemento).

Referências
-----------
  - https://cplusplus.com/reference/list/list/

*/

#include <iostream>
#include <list>
#include <iterator>


int main(int argc, char **argv) {

  // declaração de container
  std::list<int> myContainer;
  std::list<int>::iterator it;

  for (int i = 0; i < 5; i++) {
    myContainer.push_back(i + 1);    // 1 2 3 4 5
  }

  // vamos para o inicio da lista 
  it = myContainer.begin();    // 1 2 3 4 5
                               // ^
  it++;                        // 1 2 3 4 5
                               //   ^

  // neste ponto, vamos inserir mais um  valor
  myContainer.insert(it, 8);         // 1 8 2 3 4 5
                                     //     ^

  // vamos colocar 2 vezes o valor 9!
  myContainer.insert(it, 2, 9);     // 1 8 9 9 2 3 4 5
                                    //         ^

  it--;                             // 1 8 9 9 2 3 4 5
                                    //       ^
  it = myContainer.erase(it);       // 1 8 9 2 3 4 5
                                    //       ^


  for (auto i : myContainer) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
