/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_repeticoes_while.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Aplicacao do comando while
  - Aplicacao do comando do-while
  - Interrupcao de laco com break
  - Continuacao do laco com continue

  Sintaxe basica do comando while:

  while ( condition )
  {
      statement1;
      statement2;
      ...
  }

  Etapas:
  - Avalia a condicao de execucao do laco. Executa comandos se true
  - Ao fim da execucao de uma repeticao:
     - avalia condicao
     - Caso condicao seja true, realiza uma repeticao
     - Caso false, executa comando logo apos o laco

  Cuidados:
  - Caso a condicao nao seja alterada dentro dos comandos do laco, obtem-se um laco infinito!

  Sintaxe basica do comando do-while
  do
  {
      statement1;
      statement2;
      ...
  } while ( condition )

  Etapas:
  - Executa os comandos dentro do laco
  - Ao fim da execucao de uma repeticao:
     - avalia condicao de execucao do laco
     - Caso condicao seja true, realiza uma repeticao
     - Caso false, executa comando logo apos o laco

  Cuidados:
  - Os comandos sao executados pelo menos uma vez, mesmo se a condicao for false
  - No caso de um while, os comandos podem nao ser executados nunca
  - Comandos break e continue sao validos!

 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int i, j;

    i = 0;                   // inicializacao de i = 0
    while (i <= 20)          // avalia condicao para entrar no laco
    {
        cout << i << endl;   // executa comandos
        i++;                 // boa programacao: altere o parametro de condicao!
    }

    // O laço abaixo sera executado?
    i = 10;
    while (i > 100) {
        cout << i << endl;
        i++;
    }

    // O laço abaixo sera executado?
    i = 10;
    do
    {
        cout << i << endl;
        i++;
    } while (i > 100);


    return 0;
}
