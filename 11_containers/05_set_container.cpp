/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_set_container.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Container set e unordered_set
  - Container multiset 

O que são sets?
----------------
  O container set tem uma abordagem associativa para armazenar seus elementos. 
  Neste caso, a posição do elemento no container depende do seu valor. Ou seja,
  a ordem de inserção não importa para determinar a posição. Outra
  característica importante é que os elementos devem ser únicos. Por fim, uma 
  vez inseridos no set, os elementos não podem ser modificados (mas podem ser 
  removidos). 

  A diferença entre set e unordered_set é que o primeiro ordena os elementos de 
  acordo com seu valor e o segundo segue a ordem de inserção. Ambos tem 
  abordagem bidirecional de busca de dados.

Container multiset
------------------
  O container multiset segue a mesma ideia de set, mas permite a inserção de 
  itens repetidos.

Referências
-----------
  - https://cplusplus.com/reference/set/

*/

#include <iostream>
#include <set>

int main(int argc, char **argv) {

  // declaração de container
  std::set<int> myContainer;

  for (int i = 0; i < 3; i++) {
    myContainer.insert(i + 1);
    myContainer.insert(i - 1);
  }

  // ordem de inserção 
  // 1 -1 2 0 1 3 2 
  // Qual o conteúdo real do container?

  // o identificador do set é o valor do elemento
  myContainer.erase(-1);

  for (auto i : myContainer) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
