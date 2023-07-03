/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   06_membros_static.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Dados e métodos estáticos (static)

Compartilhando informações
--------------------------
  Dados estáticos que fazem parte da classe compartilham o mesmo valor para 
  diferentes instâncias da classe. Ou seja, para uma classe

  class A {
      static int i;
    public:
      void aumentaI() { i++; }
      int checarI() { return i; }
  };

  int A::i = 0;     // por ter dados compartilhados, sua inicialização não 
                    // ocorre na classe

  Todas as variáveis do tipo classe A, tem o mesmo valor de i. Ou seja, o 
  comportamento é semelhante a variáveis globais, mas apenas dentro do escopo 
  da classe.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/templates
  - https://www.geeksforgeeks.org/static-keyword-cpp/
  - https://www.studytonight.com/cpp/static-keyword.php

*/

#include <iostream>

class exemplo {
    static int i;
  public:
    void increaseI() { i++; }
    int getI() { return i; }
};

int exemplo::i = 0;

int main(int argc, char **argv) {

  exemplo A;      // i = 0
  A.increaseI();  // i = 1
  A.increaseI();  // i = 2 

  exemplo B;
  std::cout << "Valor de i = " << B.getI() << std::endl;

  return 0;
}
