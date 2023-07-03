/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   08_class_template.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Templates em classes
  - Especialização com templates

Templates em classes
--------------------
  Os templates em classes seguem o mesmo uso e sintaxe como aplicado em funções.

  template <class T>
  class mypair {
      T values [2];
    public:
      mypair (T first, T second)
      {
        values[0]=first; values[1]=second;
      }
  };

  O identificador class (ou typename) T atua como um tipo dentro da classe,
  definindo o tipo do array values nos dados e métodos. Vale ressaltar a minha
  preferência particular por sempre usar typename em templates para evitar
  conflito com o conceito de classe. A declaração do objeto da classe mypair é:

  mypair<int> MeuObjeto1(10, 20);

  mypair<float> MeuObjeto2(10.0, 20.0);

  Caso a implementação do método não seja inline, a mesma deve estar em algum
  lugar do código fora da definição da classe.

  template <typename T>
  class mypair {
      T a, b;
    public:
      mypair (T first, T second) :
        a(first), b(second) { }
      T getmax ();
  };

  template <typename T>
  T mypair<T>::getmax ()
  {
    T retval;
    retval = a>b? a : b;
    return retval;
  }

  A implementação de um método fora da classe pode ter uma sintaxe um pouco mais
  complicada. Repare na declaração do método getmax:

  template <typename T>
  T mypair<T>::getmax ()

  A primeira linha indica o parâmetro do template T. Na segunda linha, temos o
  retorno T do método seguido do escopo da classe mypair<T> (afinal, ela tem um
  template).

Especialização de templates
---------------------------
  A especialização de templates é apenas uma implementação de uma classe
  template em que o argumento T já está definido. O intuito é particularizar
  um dado comportamento para um dado tipo T.

  Para implementar a especialização, deve-se ter antes a implementação da classe
  genérica com a definição do template.

  template <class T>
  class mycontainer {
      T element;
    public:
      mycontainer (T arg) {element=arg;}
      T increase () {return ++element;}
  };

  Em seguida, cria-se uma classe com o mesmo nome, mas com argumento vazio para
  o template. Contudo, o nome da classe já inclui o tipo do argumento a ser
  usado na especialização.

  template <>
  class mycontainer <char> {
      char element;
    public:
      mycontainer (char arg) {element=arg;}
      char uppercase ()
      {
        if ((element>='a')&&(element<='z'))
        element+='A'-'a';
        return element;
      }
  };

  Para o exemplo anterior, a classe genérica realmente não se aplicaria na 
  operação com caracteres. Portanto, a especialização mantém os métodos comuns
  entre a classe genérica e a especializada e permite a implementação de novas
  funcionalidades.

  No fim, o objetivo é particularizar a funcionalidade de uma classe dependendo
  de um argumento específico do template. Este conceito vai ser muito ampliado
  quando abordamos herança.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/templates

*/

#include <iostream>
using namespace std;

// Exemplo de template
template <typename T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <typename T>
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

// Especialização de template
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) { element=arg; }
    T increase () { return ++element; }
};

template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) { element=arg; }
    char uppercase ()
    {
      if ((element>='a')&&(element<='z')) {
        element+='A'-'a';
      }
      return element;
    }
};

int main(int argc, char **argv) {
  // Exemplo de template
  mypair<int> myobject (100, 75);
  cout << myobject.getmax() << endl;

  // Especialização 
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  cout << myint.increase() << endl;
  cout << mychar.uppercase() << endl;

  return 0;
}

