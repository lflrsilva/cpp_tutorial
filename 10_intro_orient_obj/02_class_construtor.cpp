/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_class_construtor.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Construtores de classes

Construtores básicos
--------------------
  O objetivo dos construtores é inicializar ou mesmo alocar o espaço dos dados
  da classe. Para isso, os construtores são funções membro especiais que
  possuem o mesmo nome da classe e não tem nenhum retorno (nem void).

  class AtomicSpecie {
      string symbol;
      int index;
      float Aw;

    public:

      // definição de construtor
      AtomicSpecie(string, int, float);

      float getAw() { return Aw; }
  };

  void AtomicSpecie::AtomicSpecie(string s, int id, float aw) {
    symbol = s;
    index = id;
    Aw = aw;
  }

  É importante frisar que construtores só podem ser usados uma única vez, i.e.
  no momento de criar o objeto. Caso seja necessário alterar valores dos dados
  membro ao longo do código, implemente funções membro com esse objetivo.

Sobrecarregamento de construtores
---------------------------------
  Assim como sobrecarregamento de funções (overload), é possível sobrecarregar
  os contrutores para criar classes de diferentes maneiras. Como em funções,
  tudo vai depender dos argumentos usados na construção.

  class AtomicSpecie {
      string symbol;
      int index;
      float Aw;

    public:

      // definição de construtores
      AtomicSpecie();                    // sem argumentos - dados membro
                                         // alocados, mas não inicializados

      AtomicSpecie(string, int, float);  // com argumentos - alocação e
                                         // inicialização dos dados membro

      float getAw() { return Aw; }
  };

  void AtomicSpecie::AtomicSpecie() {
    symbol = "H";
    index = 1;
    Aw = 1.008;
  }

  void AtomicSpecie::AtomicSpecie(string s, int id, float aw) {
    symbol = s;
    index = id;
    Aw = aw;
  }

  Por fim, toda classe define o construtor padrão, declarado sem parênteses nem
  argumentos. Este construtor sempre pode ser usado e tem o mesmo comportamento
  do construtor sem argumentos, a menos a inicialização dos dados membro.

Inicialização de dados membro
-----------------------------
  Por padrão, os construtores seguem uma forma de chamada funcional ao usar
  parênteses para receber os parâmetros que inicializam os dados membro.
  Contudo, existem outras possibilidades de inicialização da classe e dados.

  - Quando a classe possui um único dado para inicializar, é possível usar o
    operador de igualdade.

    nome_classe nome_obj = valor_inicializacao;

  - Em C++ moderno (acima da versão 17), a inicialização uniforme também é
    possível usando { } ao invés de ( ).

    nome_classe nome_obj {valor1, valor2, valor3, ...};

    ou incluindo =

    nome_classe nome_obj = {valor1, valor2, valor3, ...};

    A lista de valores é definida pelo template initializer_list<T>. Para mais
    detalhes, verifique a referência.

Construção com inicialização de dados membro
--------------------------------------------
  Uso de inicialização direta de dados membro no corpo da chamada do
  construtor usando o operador : .

  class Rectangle {
      int width,height;
    public:
      Rectangle(int,int);
      int area() {return width*height;}
  };

  A construção pode ser realizada por:

  Rectangle::Rectangle (int x, int y) { width=x; height=y; }

  ou

  Rectangle::Rectangle (int x, int y) : width(x) { height=y; }

  ou

  Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

Referências
-----------
  - https://cplusplus.com/doc/tutorial/classes/
  - https://cplusplus.com/reference/initializer_list/initializer_list/

*/

#include <iostream>
#include <string>

class AtomicSpecie {

    std::string symbol;  // símbolo da especie atomica
    int index;           // indice da especie atomica
    float Aw;            // peso atomico (g/mol)

  public:

    // construtores
    AtomicSpecie();     // construtor padrão

    AtomicSpecie(std::string sy, int id, float aw) : 
      symbol(sy),
      index(id),
      Aw(aw) { }

    void setSymbol(std::string, int);

    void setAw(float aw) { Aw = aw; }

    float getAw() { return Aw; }
};

AtomicSpecie::AtomicSpecie() {
  symbol = "C";
  index = 6;
}

int main(int argc, char **argv) {

  // declaração padrão
  AtomicSpecie hydrogen {"H", 1, 1.008};
  AtomicSpecie oxigen = {"O", 16, 15.999};
  AtomicSpecie carbon;

  // valor não inicializado na construção padrão.
  std::cout << "Peso atomico em construção não inicializada : " 
    << carbon.getAw() << std::endl;

  std::cout << "A massa molecular de H2O eh: "
            << 2*hydrogen.getAw() + oxigen.getAw()
            << " g/mol"
            << std::endl;

  return 0;
}
