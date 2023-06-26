/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_sobrecarreg_operadores.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Sobrecarregamento de operadores sobre classes
  - Conceitos, definição e uso
  - Sobrecarregamento como função membro e não-membro

Conceito de sobrecarregamento
-----------------------------
  Na abordagem OOP, também é possível indicar o comportamento de determinados
  operadores conforme o tipo de objetos em operação. Por exemplo, sabe-se que

  int i = 1, j = 2, k;
  k = i  +  j;
     /\ /\ /\
        |      C++ define como adição aritmética das variáveis int

  Mas se for preciso representar objetos mais complexos? O símbolo + pode não
  ser capaz de trazer significado. Por isso, C++ permite redefinir
  (sobrecarregar) alguns símbolos para representar operações customizadas. Os
  símbolos que podem ser sobrecarregados são:

    +   -   *     /      %       ^
    &   |    ~    !      ,       =
    <   >    <=   >=     ++      --
    <<  >>   ==   !=     &&      ||
    +=  -=   /=   %=     ^=      &=
    |=  *=   <<=  >>=    []      ()
    ->  ->*  new  new[]  delete  delete[]

  Existem poucos símbolos que o sobrecarregamento não é permitido.

    ::    .*    .    ?:

Definindo operadores sobrecarregados
------------------------------------
  O sobrecarregamento se dá por funções chamadas operator seguidas do símbolo a
  ser sobrecarregado.

  tipo_retorno operator simbolo (parametros) {  corpo_da_funcao }

  Considere o exemplo:

  class CVector {
    public:
      int x,y;
      CVector () {};                            // construtor padrão (vazio)
      CVector (int a,int b) : x(a), y(b) {}     // construtor
      CVector operator + (const CVector&);      // sobrecarregamento
  };

  CVector CVector::operator+ (const CVector& param) {
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
  }

  Obs.: Como o operator tem o mesmo comportamento de uma função, ele usa como
  parâmetro o endereço do objeto para evitar passagem por cópia. Além disso,
  para não ter risco de alterar os valores do argumento param, define-se const.

Uso de operadores sobrecarregados
---------------------------------
  Note que o uso do operador sobrecarregado pode ser de forma implícita ou
  explícita.

  c = a + b;                // implícita
  c = a.operator+ (b);      // explícita

  Repare como a variável em que o operador se aplica sempre está do lado
  esquerdo (left hand side - lhs) e a variável argumento no lado direito (right
  hand side - rhs).

Implementação como função membro ou não-membro
----------------------------------------------
  Todos os símbolos tem suporte a implementação de sobrecarregamento como
  função membro da classe. Nesse caso, a implementação ocorre como apresentado
  acima.

  Contudo, alguns dos símbolos permite a implementação como funções comuns, ou
  seja, funções que não são membro da classe. O intuito é ampliar as
  possibilidades de implementação em diferentes notações. Considere as situações
  abaixo em que @ é o operador, a e b são os objetos das classes A e B, 
  argumentos da função operator como função não membro. Por fim, estão os 
  símbolos que permitem a funcionalidade.

    @a    - operator@(A)     + - * & ! ~ ++ --
    a@    - operator@(int)   ++ --
    a@b   - operator@(A, B)  + - * / % ^ & | < > == != <= >= << >> && ||

  Veja o exemplo abaixo para a implementação com função não membro.

  class CVector {
    public:
      int x,y;
      CVector () {}
      CVector (int a, int b) : x(a), y(b) {}
  };

  CVector operator+ (const CVector& lhs, const CVector& rhs) {
    CVector temp;
    temp.x = lhs.x + rhs.x;
    temp.y = lhs.y + rhs.y;
    return temp;
  }

Referências
-----------
  - https://cplusplus.com/doc/tutorial/templates
  - https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

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
    AtomicSpecie() { }

    AtomicSpecie(std::string sy, int id, float aw) : 
      symbol(sy),
      index(id),
      Aw(aw) { }

    AtomicSpecie operator+ (const AtomicSpecie&);

    void setSymbol(std::string sy) {symbol = sy; }

    void setAw(float aw) { Aw = aw; }

    std::string getSymbol() { return symbol; }

    float getAw() { return Aw; }
};

AtomicSpecie AtomicSpecie::operator+(const AtomicSpecie& sps) {
  AtomicSpecie tmp;
  tmp.setSymbol(symbol + sps.symbol);
  tmp.setAw(Aw + sps.Aw);
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
