/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   07_membros_const.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Dados e métodos constantes

Como retirar a permissão em alterar os dados?
---------------------------------------------
  Em tipos primitivos, usamos o identificador const para garantir que o valor
  de determinada variável não seja alterada. O mesmo princípio vale para
  classes também.

  const ClassType meuObjeto;

  A menos o construtor (que inicializa os dados membro), todos os dados da
  classe tem o comportamento const. Mesmo se for um dado público, o programa
  não permite alterar o valor ao acessá-los fora da classe (no programa
  principal).

  meuObjeto.x = 20;      // erro!!

Afeta as funções membro?
------------------------
  Ao usar const em uma classe, o acesso aos métodos (funções membro) também
  se altera. De fato, apenas métodos também identificados com const podem ser
  usados para um objeto const (uma classe const). A declaração do método como
  constante em uma classe segue a sintaxe:

  int nome_metodo() const { ... }

  Repare que o identificador const fica após o nome do método. Ainda é possível
  especificar o retorno do método como const.

  int nome_metodo() const { ... }          // método const
  const int& nome_metodo() { ... }         // retorno const&
  const int& nome_metodo() const { ... }   // método const e retorno const&

  Repare ainda que, como os métodos const só podem ser chamados por objetos que
  foram declarados como const, também é possível sobrecarregá-los considerando
  a opção sem const. Na situação acima, os métodos possuem a mesma assinatura,
  permitindo seu uso em qualquer situação (const ou não const).

  Obs.: Como muitas das variáveis, em especial objetos como classes, são
  passados por ponteiros para funções, os dados na memória ficam acessíveis
  para serem alterados. Isso pode ser uma falha de segurança dos dados. Por
  isso, o uso de const é muito importante e absolutamente usado na programação
  OOP em C++. Este é um tópico que vale um estudo mais dedicado #ficaadica

Referências
-----------
  - https://cplusplus.com/doc/tutorial/templates

*/

#include <iostream>
#include <string>

class AtomicSpecie {

    std::string symbol;  // símbolo da especie atomica
    int index;           // indice da especie atomica
    float Aw;            // peso atomico (g/mol)

  public:

    // construtores
    AtomicSpecie() { }

    AtomicSpecie(std::string sy, int id, float aw) : 
      symbol(sy),
      index(id),
      Aw(aw) { }

    AtomicSpecie& operator= (const AtomicSpecie&);

    std::string getSymbol() { return symbol; }

    // o exemplo é para mostrar possível falha de segurança de dados caso se 
    // retorne endereços ao invés de cópia da variável. O retorno const garante
    // que mesmo em acesso ao endereço, o valor deve ser constante.
    const float& getAw() const { return Aw; }
    float& getAw() { return Aw; }
};

AtomicSpecie& AtomicSpecie::operator=(const AtomicSpecie& rhs) {
  this->symbol = rhs.symbol;
  this->Aw = rhs.Aw;
  return *this;
}

int main(int argc, char **argv) {

  const AtomicSpecie carbon {"C", 6, 12.011};
  AtomicSpecie oxigen {"O", 16, 15.999};

  oxigen.getAw() = 2;      // funciona pois o retorno é sobre o endereço (ln 85)
   // carbon.getAw() = 2;      // Erro! define-se const, usando método const

  std::cout << oxigen.getAw() << std::endl;
  std::cout << carbon.getAw() << std::endl;

  return 0;
}
