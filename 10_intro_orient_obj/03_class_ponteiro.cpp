/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_class_ponteiro.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Ponteiro para classes

Ponteiro para classes
---------------------
  O principal objetivo no uso de ponteiros se refere a criar arrays de classes e
  na passagem de classes como parâmetros nas funções. Neste caso, é possível 
  usar alocação dinâmica também. Note que a funcionalidade no uso de ponteiros 
  e endereço já foi abordada em tutoriais anteriores.

  De qualquer modo, vale relembrar os operadores de acesso aos dados e objetos.

  *x     operador "apontando para" por x
  &x     operador endereço de x
  x.y    operador de acesso ao membro y do objeto x
  x->y   operador de acesso ao membro y do objeto apontado por x
  (*x).y operador de acesso ao membro y do objeto apontado por x
  x[0]   acesso ao primeiro objeto apontado por x
  x[n]   acesso ao (n+1) objeto apontado por x

Referências
-----------
  - https://cplusplus.com/doc/tutorial/classes/

*/

#include <iostream>
#include <cstdlib>   // abort()
#include <string>

class AtomicSpecie {

    std::string symbol;  // símbolo da especie atomica
    int index;           // indice da especie atomica
    float Aw;            // peso atomico (g/mol)

  public:

    // construtores
    AtomicSpecie(std::string sy, int id, float aw) : 
      symbol(sy),
      index(id),
      Aw(aw) { }

    void setSymbol(std::string, int);

    void setAw(float aw) { Aw = aw; }

    float getAw() { return Aw; }
};

int main(int argc, char **argv) {

  // exemplo de apontamento
  AtomicSpecie carbon {"C", 6, 12.011};
  AtomicSpecie* c_ptr;
  c_ptr = &carbon;

  // acesso de função membro pública usando .
  std::cout << "Acesso de dados via classe : " 
    << carbon.getAw() << std::endl;
  // acesso de função membro pública usando ->
  std::cout << "Acesso de dados via ponteiro : " 
    << c_ptr->getAw() << std::endl;


  // exemplo de array de classe
  AtomicSpecie * molecule;
  molecule = new AtomicSpecie[2] {
    {"H", 1, 1.008},    // hidrogenio
    {"O", 16, 15.999}   // oxigenio
  };
  if (molecule == nullptr) { 
    std::cerr<<"Erro de alocação em molecule!" << std::endl;
    std::abort();
  }

  // acesso via elemento do array
  std::cout << "A massa molecular de H2O eh: "
            << 2*molecule[0].getAw() + molecule[1].getAw()
            << " g/mol"
            << std::endl;

  // liberando a memória
  delete[] molecule;

  return 0;
}
