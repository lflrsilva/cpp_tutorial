/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_ponteiros_basico.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Conceitos de endereço e ponteiros
  - Aplicação dos ponteiros
  - Manipulação de dados com ponteiros
  - Ponteiros void e nulos

Ponteiros e Referências
-----------------------
  Ponteiros são um tipo de variável que não aloca valores em si, mas endereços
  de memória. Portanto, armazena o local de memória para onde dado ponteiro
  aponta.

  Um ponteiro aponta para dado local (endereço) na memória. Designamos um
  ponteiro com o operador deferência *. Se int* T, T aponta para o endereço de
  uma variável inteira.

  int* p; // eh o ponteiro de um inteiro

  __|__|__|__|__|__|__|__|__|__|
              ^*p

  A referência é o endereço na memória onde dada variável esta alocada. Se
  existe a declaração de int i, &i eh o endereço onde i está alocado.

  int i = 5;
              &i
  __|__|__|__|5_|__|__|__|__|__|
  ...18 19 20 21 22 23...        sendo exemplos de endereços

  em que o endereço de i é 21.

  foo = &i;      // foo = 21
  bar = i;       // bar = 5

  Pode-se apontar o ponteiro para o local de memória onde i está alocado.

  int i = 5;
  int j;
  int* p;
  p = &i;      // Ao indicar onde p aponta, não precisa de *
  j = *p + 1;  // Ao indicar o operador *, acessa-se o valor na memória

              &i       j
  __|__|__|__|5_|__|__|6_|__|__|
              *p

  Diferente de ponteiros, não se declara endereços de memória.

Ponteiros void
--------------
  Uma das grandes flexibilidades é usar ponteiros void. Lembre-se que void
  representa a ausência de um tipo definido. Portanto, pode apontar para
  variáveis de qualquer tipo. Contudo, ao derreferenciar (buscar o valor
  alocado), deve-se antes ajustar o espaço da da variável.

  Este é um tópico mais avançado e sugiro a leitura na referência citada.

Ponteiros inválidos (nulos)
---------------------------
  Ponteiros podem ser alocados em qualquer espaço de memória, inclusive em
  pontos que não referenciam nenhum elemento ou variável válida. Exemplo disso
  é um ponteiro não inicializado.

  int* q;

  C++ não impede que qualquer destes ponteiros apontem para qualquer local. O
  que pode causar um erro é acessar o valor (derreferenciar o ponteiro),
  causando um comportamento indefinido (erro de execução ou valores aleatórios).

  Em algumas situações, pode ser interessante alocar explicitamente o ponteiro
  em um ponto designado para descarte. Este é o ponto nulo (inteiro 0, nullptr
  ou NULL).

  int *p = 0;
  int *p = nullptr;
  int *p = NULL;

  *p aponta para o primeiro espaço de memria (0) do computador (no é usado
  pelo sistema). Pode-se usar testes condicionais para checar se o ponteiro
  é nulo ou não.

  if(p)    // true se p não for nulo

  if(!p)   // true se p for nulo

Referências
-----------
  - https://cplusplus.com/doc/tutorial/pointers/

 */

#include <iostream>

int main(int argc, char **argv) {

  // declaracao das variaveis
  int i = 5;    // i eh int, valor do objeto i é 5.
  int *pi = &i; // pi eh um ponteiro de um inteiro
                // e atribui o endereco de i a pi
  int j = *pi;  // valor da variavel apontada por pi
                // e atribuido a j, j = 5

  int *ptr = nullptr; // espaco null

  //    double* ii = &j;       // ILEGAL!! j eh int!

  double d1 = 2.7, d2 = 3.1;

  double *p = &d1; // p aponta para d1, *p = 2.7
  double a = *p;   // a = 2.7
  p = &d2;         // p aponta para d2, *p = 3.1
                   // Aqui p muda para onde aponta na memoria

  double b = *p; // b = 3.1
  *p = 5.5;      // o valor para qual p aponta eh 5.5
                 // Aqui o valor para o qual p aponta muda

  double c = *p; // c = 5.5
  double d = d2; // d = 5.5, ja que *p = 5.5

  // Apresentando em tela o endereco na memoria
  std::cout << "Endereco de d2: " << &d2 << "\n";
  std::cout << "Endereco de p: " << p << "\n";

  std::cout << "Alterando o endereco de p...\n";
  p = &d;
  std::cout << "Endereco de p: " << p << "\n";

  return (0);
}
