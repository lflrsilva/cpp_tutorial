/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_usando_namespaces.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Namespaces

Definição
---------
  Os namespaces são unidades lógicas que coletam declarações e definições em
  C++. Com a programação modular é possível dividir e separar um código com
  muitos comandos em partes menores e com objetivo comum. Outro objetivo de
  namespaces é evitar conflito de nomes em grandes projetos de desenvolvimento.

  Por exemplo, imagine grandes códigos para solução de sistemas lineares com
  matrizes. O programador pode definir namespaces para o tratamento de matrizes
  densas (cheias) e para o tratamento de matrizes esparsas (muitos zeros), ambas
  definidas com o mesmo nome de variável e solução.

  namespace dense {
      matrix(....);
      solve(...);
  }

  namespace sparse {
      matrix(....);
      solve(...);
  }

  Nesse momento, vamos aprender a declarar namespaces para acesso do seu
  conteúdo e criar namespaces simples. Vamos voltar a esse assunto e ampliar
  sua aplicação.

  IMPORTANTE: Ao incluir o namespace std, pode-se notar um aumento no tempo de
  compilação do projeto. Todos os comandos em std serão analisados pelo
  compilador, aumentado o tempo de construção do aplicativo.

Referências
-----------
   - https://en.cppreference.com/w/cpp/language/namespace
   - https://cplusplus.com/doc/tutorial/namespaces/

 */

#include <iostream>

// declarando o namespace padrão std
using namespace std;

// pode-se usar apenas alguns dos comandos do namespace
// using std::cout;
// using std::endl;

namespace my_variables {
  int a;
  int i;
}

int main(int argc, char** argv) {

    // declaracao de variaveis
    int i = 11;

    // variáveis no contexto do namespace my_variables
    // seus tipos já estão declarados dentro do namespace
    my_variables::a = 0;
    my_variables::i = 1;

    // Configurando saída formatada de inteiros (basefield)
    cout.setf(ios_base::hex, ios_base::basefield);
    cout <<"Hexadecimal, i : " << i << endl;
    cout.setf(ios_base::dec, ios_base::basefield);
    cout <<"Decimal,  i    : " << i << endl;
    cout << i << endl;

    cout << my_variables::i << endl;

    return 0;
}
