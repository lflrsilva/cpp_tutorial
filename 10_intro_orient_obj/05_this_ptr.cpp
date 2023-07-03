/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_this_ptr.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - O ponteiro this nas classes

Ponteiro this
-------------
  Na abordagem OOP, os métodos membro são usadas para manipular os dados membro
  de modo individual e que altera a característica do objeto em si. É possível
  que, neste caso, o retorno do método seja o próprio objeto alterado. Então,
  como referenciar o próprio objeto manipulado pelo método?

  Este é o objetivo do ponteiro this que aponta para o objeto o qual o método
  está manipulando. Veja o exemplo abaixo:

  class Dummy {
    public:
      bool isitme (Dummy& param);      // recebe o endereço de um objeto Dummy
  };

  bool Dummy::isitme (Dummy& param)
  {
    if (&param == this) return true;   // verifica se objeto que é argumento
    else return false;                 // aponta para o mesmo objeto que está
  }                                    // usando o método

  int main () {
    Dummy a;
    Dummy* b = &a;                     // b aponta para a 
    if ( b->isitme(a) )                // de fato, a tem o mesmo endereço de b
      cout << "yes, &a is b\n";
    return 0;
  }

  Outro uso comum do ponteiro this ocorre quando um método retorna objeto por 
  referência.

  CVector& CVector::operator= (const CVector& param)
  {
    x=param.x;
    y=param.y;
    return *this;
  }

Referências
-----------
  - https://cplusplus.com/doc/tutorial/templates
  - https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

*/

#include <algorithm>
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

    AtomicSpecie operator+ (const AtomicSpecie&);

    void setSymbol(std::string sy) {symbol = sy; }

    void setAw(float aw) { Aw = aw; }

    std::string getSymbol() { return symbol; }

    float getAw() { return Aw; }
};

// usando this para referenciar o próprio objeto
AtomicSpecie& AtomicSpecie::operator=(const AtomicSpecie& rhs) {
  this->symbol = rhs.symbol;
  this->Aw = rhs.Aw;
  return *this;
}

// usando this para referenciar o próprio objeto
// dentro dos métodos, temos acesso os dados privados. Pode usar (.)
AtomicSpecie AtomicSpecie::operator+(const AtomicSpecie& rhs) {
  AtomicSpecie tmp;
  tmp.symbol = this->symbol + rhs.symbol;
  tmp.Aw = this->Aw + rhs.Aw;
  return tmp;
}

int main(int argc, char **argv) {

  AtomicSpecie carbon {"C", 6, 12.011};
  AtomicSpecie oxigen {"O", 16, 15.999};

  AtomicSpecie CarbonMonoxide;
  CarbonMonoxide = carbon + oxigen;

  std::cout << "A massa molecular de "
            << CarbonMonoxide.getSymbol() <<" eh: "
            << CarbonMonoxide.getAw()
            << " g/mol"
            << std::endl;

  return 0;
}
