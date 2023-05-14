/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_ref_const.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Organização do projeto (cabeçalhos e fonte associado)
  - Modificador const para passagem por referência
  - Funções recursivas

Organização do projeto
----------------------

  Em dado momento, o arquivo principal passa a ter muita informação, seja de
  declarações, implementações de funções etc, e pode ficar confuso. Nesse caso,
  podemos organizar melhor o código implementando cabeçalhos e/ou arquivos fonte
  adicionais.

  Existem várias recomendações sobre como organizar os arquivos em um projeto C++.
  De modo geral, é senso comum que todo arquivo de cabeçalho, *.h, deve ser
  associado a um arquivo fonte, *.cpp, de mesmo nome. Cada arquivo tem um objetivo
  específico:

    - Arquivos de cabeçalho, *.h : declaram-se todos os cabeçalhos necessários para
    execução das funções. Neste arquivo, declaram-se os prototypes das funções.

    - Arquivos fonte, *.cpp      : deve-se necessariamente chamar o cabeçalho
    associado, onde todos os prototypes já estão declarados. Por isso, o arquivo
    fonte contém as implementações das funções.

Modificador const
-----------------

  A passagem por referência evita a operação cópia dos dados aumentando a
  eficiência na execução e gerenciamento de memória. Contudo, os dados
  passados por referência podem passar um indicativo de que a subrotina
  deve mudar os valores dos argumentos. E, de fato, seria mesmo um dos
  intuitos da função, mas nem sempre isso se aplica.

  A solução para isso é usar o modificador const sobre os tipos dos
  argumentos na declaração da subrotina.

  string concatenate (const string& str1, const string& str2);

  Nesse caso, a subrotina não pode alterar os dados dos argumentos mas
  pode acessá-los por referência, com a vantagem de evitar as cópias.
  Esse é um recurso muito popular para passagem de argumentos de tipos
  avançados de dados.

  IMPORTANTE: Para tipos de dados fundamentais, o uso de const não é
  recomendado. É possível, inclusive, diminuir a eficiência! Nos
  exemplos abaixo, tipos fundamentais são usados apenas para ilustrar
  sua aplicação.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/functions/
  - https://google.github.io/styleguide/cppguide.html

 */

#include <iostream>
#include <string>
#include "03_rotinas.h"     // inclusão do cabeçalho próprio
using namespace std;

// Toda declaração e implementação está no cabeçalho próprio
// string concatenate(const string&, string&);
// long fatorial(long);

int main(int argc, char** argv) {

    // criando strings com construção e atribuição (lembram??)
    string str1("Seu");
    string str2 = "Madruga";

    cout << "Antes da função concatenate" << endl;
    cout << str1 << " " << str2 << endl;
    string str3( concatenate(str1, str2) );
    cout << "Depois da função concatenate" << endl;
    cout << str1 << " " << str2 << endl;

    // uso da função fatorial
    long n = 9;
    cout << n << "! = " << fatorial(n) << endl;

    //Finalização
    return 0;
}

