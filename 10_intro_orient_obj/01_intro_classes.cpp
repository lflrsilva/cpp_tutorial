/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_intro_classes.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Introdução à orientação a objetos
  - Introdução à classes

Orientação a objetos
--------------------
  A programação orientada a objetos é um modelo que estrutura o planejamento do
  software em torno dos dados (objetos) e os procedimentos que alteram ou usam
  estes dados (métodos). O princípio é usado para representar entidades do
  mundo real e desmembrando-as em partes menores (menos complexas). Com isso,
  é possível, em um primeiro momento, implementar elementos simples e
  aprimorá-los depois. Para tal, conceitos como abstração, encapsulamento,
  herança e polimorfismo podem ser usados.

  Uma proposta é analisar o problema físico, decompô-lo em elementos menores e,
  a partir do menor elemento, construir a estrutura de objetos que compõe o 
  problema. Por exemplo, para analisar reações químicas simples no âmbito
  industrial, talvez o menor elemento seja a representação da espécie atômica
  ou molecular. Mas para um problema de reações mais complexas, a nuvem
  eletrônica e a transferência de elétrons seja o mais apropriado... Tudo
  depende do problema e da complexidade necessária.

Introdução à classes
--------------------
  A definição de classes é a base na idealização dos objetos e a composição dos
  dados e métodos. Tanto dados quanto métodos são chamados de membros da classe.

  class minhaClasse {
    
    especificador_acesso:
    // dados da classe;
    tipo dado1;
    tipo dado2;
    ...

    especificador_acesso:
    // métodos para manipular os dados da classe
    tipo metodo1();
    tipo metodo2();
    ...
    
  };

  Repare que a declaração e funcionalidade de classes é idêntica à de estruturas
  (structs). Contudo, as classes fornecem uma proteção aos dados e métodos que
  as estruturas não tem. Na verdade, estruturas (structs) são classes em que
  todos os dados e métodos são de acesso público (podem ser alteradas em 
  qualquer local do código). A definição do acesso aos membros da classe é dada
  pelos especificadores de acesso, que podem ser:

    - private   : os membros privados só podem ser acessados por outros membros
                  da classe. Por exemplo, a manipulação de dados privados fica
                  restrita à própria classe em si, protegendo-os de alteração
                  indevida por outras classes ou no código principal.

    - protected : os membros protegidos podem ser acessados por outros membros
                  da própria classe ou de classes derivadas dela.

    - public    : os membros públicos podem ser acessados de qualquer local do
                  código em que a classe esteja visível (tenha escopo).

  O padrão para classes é definir os membros como private.

  class AtomicSpecie {
                    // todos os membros são privados por padrão
    string symbol;  // símbolo da especie atomica
    int index;      // indice da especie atomica
    float Aw;       // peso atomico (g/mol)

    public:         // definindo como público, estes membros podem ser acessados
                    // de qualquer lugar e manipular os dados da classe

      // Pode colocar prototypes ou já implementar as funções membro!
      void setSymbol(string, int);

      void setAw(float aw) {
        Aw = aw;
      }

      float getAw() {
        return Aw;
      }
  };

  Membros em que se define apenas o prototype devem ter sua implementação em
  outro local do código. Com isso, deve-se indicar que o membro está 
  implementado no escopo (::) da classe.

  void AtomicSpecie::setSymbol(string s, int id) {
    symbol = s;
    index = id;
  }

  Não existe diferença em declarar o prototype ou já declarar e implementar a
  função membro, a menos que no último caso, a função é automaticamente
  candidata para otimização inline.

  No programa principal, todos os membros públicos podem ser acessados usando
  o operador de acesso (.), assim como structs [1].

  [1] Vale notar que o acesso a ponteiros e endereços de classes segue a mesma
  notação de tutoriais passados, usando *, & e acesso a membros com (.) e (->).

Referências
-----------
  - https://cplusplus.com/doc/tutorial/classes/

*/

#include <iostream>
#include <string>

class AtomicSpecie {

  std::string symbol;  // símbolo da especie atomica
  int index;           // indice da especie atomica
  float Aw;            // peso atomico (g/mol)

  public:

    void setSymbol(std::string, int);

    void setAw(float aw) {
      Aw = aw;
    }

    float getAw() {
      return Aw;
    }
};

// implementação de função membro
void AtomicSpecie::setSymbol(std::string s, int id) {
  symbol = s;
  index = id;
}

int main(int argc, char **argv) {

  // declaração padrão
  AtomicSpecie hydrogen, oxigen;

  // definindo hidrogênio
  hydrogen.setSymbol("H", 1);
  hydrogen.setAw(1.008);

  // definindo oxigênio
  oxigen.setSymbol("O", 16);
  oxigen.setAw(15.999);

  std::cout << "A massa molecular de H2O eh: "
            << 2*hydrogen.getAw() + oxigen.getAw()
            << " g/mol"
            << std::endl;

  return 0;
}
