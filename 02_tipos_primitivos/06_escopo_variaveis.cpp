/**
  
  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   06_escopo_variaveis.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Escopo de variáveis globais e locais

  Obs.: Apesar de não trabalharmos tanto com o escopo das variáveis no programa
  principal, este conceito é muito importante em funções, subrotinas, classes
  etc. A principal ideia é entender quais variáveis são visíveis (ou acessáveis)
  em dada etapa do código.

  Referencias:
  - Yang, D. (livro)

 */

#include <iostream>

// Região de declaração de variáveis globais
int i = 10;

int main(int argc, char** argv) {

    // variável local ao main()
    int i = 30;
    int j = ::i;      // operador :: acessa a variável global

    // criando região de escopo restrito (escondido)
    {
        int k = i;    // i = 30, no escopo de main()
        int i = 100;  // cria-se i no escopo restrito e guarda-se i no 
                      // escopo de main
        int l = ::i;  // acesso à variável global
        l = i;        // i = 100, usando i no escopo restrito
    }
    // saindo do escopo restrito e voltamos ao escopo de main()
    // TODAS as variáveis no escopo restrito não podem mais ser acessadas e 
    // a memória reservada é liberada.

    int m = i;        // m = 30, no escopo de main()

    return (0);
}
