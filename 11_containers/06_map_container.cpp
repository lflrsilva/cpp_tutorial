/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_map_container.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Container map e unordered_map
  - Container multimap

O que são map?
----------------
  O container map usa a abordagem associativa para armazenar seus elementos,
  vinculando uma chave (key) ao valor mapeado (armazenado)). Com isso, este
  container amplia o contexto de set usando a chave que identifica o valor. Da
  forma similar a set (não permite valores repetidos), map não permite chaves
  (keys) repetidas dentro do container.

  O par chave e valor, que reprensentam o elemento do container, ficam agrupados
  em um método template chamado pair.

  pair<key, T>

  O acesso da chave e do valor são pelos dados membros first e second de pair.

  chave : pair.first
  valor : pair.second

  O armazenamento segue a ordem das chaves (key). Por fim, os elementos podem
  ser acessados pelo operador offset [].

  A diferença entre map e unordered_map é que o primeiro ordena os elementos de
  acordo com as chaves e o segundo segue a ordem de inserção. Ambos tem
  abordagem bidirecional de busca de dados.

Container multimap
------------------
  O container multimap segue a mesma ideia de map, mas permite a inserção de
  chaves repetidas.

Referências
-----------
  - https://cplusplus.com/reference/map/

*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

int main(int argc, char **argv) {

  // declaração de container
  std::map<std::string, int> myContainer;

  myContainer["a"] = 1;
  myContainer["b"] = 3;
  myContainer["c"] = 5;

  // para inserir novos elementos 
  myContainer.insert( std::pair<std::string, int>("d", 7) );

  for (auto it = myContainer.begin(); it != myContainer.end(); it++) {
    std::cout << "Chave[" << it->first <<"] = " << it->second << std::endl;
  }

  // busca de uma chave específica
  auto it = myContainer.find("b");
 
  // apagando a chave se não for a última no container
  // não é permitido apagar o último elemento em map
  if (it != myContainer.end()) {
    myContainer.erase(it);
  }

  for (auto it = myContainer.begin(); it != myContainer.end(); it++) {
    std::cout << "Chave[" << it->first <<"] = " << it->second << std::endl;
  }
  return 0;
}
