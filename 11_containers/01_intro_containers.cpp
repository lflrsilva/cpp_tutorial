/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_intro_containers.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Introdução à containers
  - Containers to tipo array e vector

O que são containers?
--------------------_
  Todos os problemas computacionais compartilham uma mesma situação: todos tem
  que tratar dados. Os dados podem ser de diferentes valores e tipos, mas qual
  a melhor forma de armazenar e buscar os dados na memória?

  Existem várias abordagens no armazenamento e busca de dados na memória. A
  escolha da melhor abordagem sempre vai depender dos dados em si e suas
  particularidades. Até o momento, vimos as formas mais básicas no tratamento
  dos dados, com arrays e estruturas, e busca de informação pelos ponteiros.

  Em C++, a STL (Standard Template Library) fornece os chamados containers de
  dados. Os containers tem diferentes metodologias de armazenamento de dados e
  formas de acesso. Cada um dos containers tem vantagens e desvantagens
  dependendo do problema analisado. Todos os containers usam a técnica de
  templating e fazem parte das bibliotecas padrão de C++ (std).

  Além disso, os containers possuem métodos que facilitam a programação, como o
  gerenciamento automático de memória (alocação e desalocação), a capacidade de
  armazenamento (número de elementos dentro do container), acesso aos elementos,
  iteradores (varredura dos dados), modificadores de valores, entre outras
  funcionalidades. Em resumo, a vida do programador fica bem mais fácil com
  containers.

Containers array e vector
-------------------------
  Os containers array e vector tem comportamento semelhante a arrays simples,
  garantindo que os elementos estão em alinhamento contíguo na memória e acesso
  aos elementos pelo operador offset [].

    |-------região alocada------|
    |___|___|___|___|___|___|___|___|___|___|
    [0]  [1]   ...          [n-1]

  Contudo, arrays simples não tem a capacidade de identificar o número de
  elementos ou uma metodologia própria de varredura dos elementos (cabe ao
  desenvolvedor implementar).

  Neste contexto, os containers array e vector se destacam. A diferença entre
  os dois é que o primeiro só permite um tamanho fixo de elementos enquanto que
  o segundo permite a inserção ou remoção dinâmica de elementos. Ou seja, o
  container array se comporta como um array simples de memória estática enquanto
  que o vector se comporta como um array simples de memória dinâmica.

  Obs.: Para containers, é muito importante que você acesse as referências e
  veja as opções de comando para construção, acesso, inclusão ou exclusão de
  dados e outras funcionalidades.

  - Container array
  Por terem a mesma característica de um array simples em memória estática,
  possuem a mesma eficiência em armazenamento e acesso de dados. Note, portanto,
  que seu tamanho é calculado em tempo de compilação. Para usá-los deve-se
  incluir o cabeçalho <array>.

  #include <array>

  A declaração do array segue a sintaxe de templates com dois argumentos.

  std::array<tipo, num_elem> nome_variavel;

  Pode ser inicializado como um array simples ou atribuindo valores ao acessar
  cada elemento individual.

  std::array<int, 5> meu_array = { 1, 2, 6, 24, 120 };

  Para containers, a inicialização acima é tratada como um template de lista de
  inicialização (initializer_list). Ou seja, diferente de arrays simples,
  existe um tratamento especial para esta inicialização.

  O acesso aos dados usa o operador offset [].

  meu_array[0] = 720;
  std::cout << meu_array[2];

  - Container vector
  Possui características de um array simples em memória dinâmica, com eficiência
  semelhante. Sua sintaxe e uso são bem parecidos com array, a menos seu
  identificador. Para usá-lo deve-se incluir o cabeçalho <vector>.

  #include <vector>

  std::vector<int> prim;                // vector vazio de ints
  std::vector<int> seg  (4,100);        // 4 ints com valor 100
  std::vector<int> terc (seg);          // uma cópia de seg

  É possível realizar a inicialização dos elementos com initializer_list.

  Como arrays, a alocação em vector é realizada de forma contígua, mas usando
  memória dinâmica. Isso é feito de forma a permitir a inserção ou remoção de
  elementos a qualquer momento. Contudo, isso traz um problema pois o bloco
  de memória livre pode se esgotar ao inserir mais elementos. Neste caso, um
  novo bloco com memória disponível deve ser encontrado e todos os dados serão
  copiados para este último mantendo a estrutura contígua. Essa operação pode 
  aumentar muito o custo computacional se executada muitas vezes.

  Para ver os métodos de array e vector, acessem os links nas referências.

Referências
-----------
  - https://cplusplus.com/reference/array/array/
  - https://cplusplus.com/reference/vector/vector/

*/

#include <iostream>
#include <array>
#include <vector>


int main(int argc, char **argv) {

  // USANDO ARRAY ------
  // declaração de array
  std::array<int, 10> arr1;

  // Podemos usá-lo como um array simples
  // acesso ao número de elementos: size() ou max_size()
  for (int i = 0; i < arr1.size(); i++) {
    arr1[i] = i + 1;                      // acesso com []
  }

  for (int i = 0; i < arr1.size(); i++) {
    std::cout << arr1.at(i) << "\t";      // acesso com .at()
  }
  std::cout << "\n";

  // acesso aos extremos
  std::cout << "Primeiro elemento : " << arr1.front() << "\n";
  std::cout << "Último elemento   : " << arr1.back() << "\n";

  // USANDO VECTOR ------
  // declaração de vector
  std::vector<int> vec1(10, 0.0);

  // Podemos usá-lo como um array simples
  // acesso ao número de elementos: size() ou max_size()
  for (int i = 0; i < vec1.size(); i++) {
    vec1[i] = i + 1;                      // acesso com []
  }

  for (int i = 0; i < vec1.size(); i++) {
    std::cout << vec1.at(i)<< "\t";      // acesso com .at()
  }
  std::cout << "\n";

  // acesso aos extremos
  std::cout << "Primeiro elemento : " << vec1.front() << "\n";
  std::cout << "Último elemento   : " << vec1.back() << "\n";
  std::cout << "Tamanho máximo que o container suporta : " 
            << vec1.max_size() << "\n";
  
  // vamos alterar o tamanho do vetor 
  int oldSize = vec1.size();
  int newSize = 15;
  vec1.resize(newSize);
  std::cout << "Tamanho do vector : " << vec1.size() << "\n";

  // vamos colocar mais 5 elementos ao fim do vector 
  for (int i = oldSize; i < newSize + 5; i++) {
    if (i < newSize) {
      vec1[i] = i + 1;
    } else {
      vec1.push_back(i + 2);   // inserindo mais elementos
    }
  }

  for (int i = 0; i < vec1.size(); i++) {
    std::cout << vec1.at(i)<< "\t";
  }
  std::cout << "\n";

  return 0;
}
