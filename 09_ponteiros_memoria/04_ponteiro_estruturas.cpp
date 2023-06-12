/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_ponteiro_estruturas.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Ampliando conceito sobre estruturas
  - Ponteiro para estruturas
  - Passagem de estruturas para subrotinas

Conceito e uso de estruturas
----------------------------
  Entender bem o conceito de estruturas é importante pois sua aplicação se
  assemelha muito com a programação orientada a objetos. Por isso, vamos
  formalizar melhor alguns pontos.

  Uma estrutura representa um grupo de elementos de dados (e ações) submetidos
  a um único nome. Os elementos de dados são dados membro da estrutura.

  struct lista_compras_t {
      string verduras;
      string acougue;
      string padaria;
      string papelaria;
      ....
  };

  A forma de acesso aos dados membro é pelo uso do operador ponto.

  lista_compras_t bazar;
  bazar.papelaria = "caneta";

  É possível usar array de estruturas, remetendo a ideia de um banco de dados
  centralizado.

  lista_compras_t mercado[3];


Ponteiros para estruturas
-------------------------
  É possível criar um ponteiro para referenciar o endereço de memória de
  estruturas. Isso é interessante para acesso a um array de estrutura ou para
  passagem de dados para funções. Vale notar que o acesso aos dados é
  diferente, de acordo com o formato usado.

  struct my_data_t {
      int a;
      int b;
  };

  my_data_t data;

  acesso:

    data.b  : dado membro b do objeto data
    data->b : dado membro b do objeto apontado para data [ (*data).b ]
    *data.b : valor apontado para o dado membro b do objeto data [ *(data.b) ]

  O operador deferência -> só pode ser usado para acesso de dados em ponteiros
  de estruturas. Sua operação é equivalente a (*estrut).dado_membro.

  - Passagem dos dados da estrutura para funções:
  Visto como passagem usual de variáveis, como valor ou referência.

  func1(t1.id);   // passagem por valor da variavel
  func1(&t1.id);  // passagem por referencia da variavel

  - Passagem da estrutura completa para funções (valor ou referencia):
  Para passagem por valor, alta perda de eficiência computacional para
  alocação dos campos da estrutura dentro da função. NÃO USEM!!!!

  Apenas passagem de ponteiro ao usar a referência da estrutura. Custo
  computacional reduzido! Nesta passagem, os campos são acessados dentro da
  função usando o operador -> .

Referências
-----------
  - https://cplusplus.com/doc/tutorial/structures/

 */

#include <cstdlib>
#include <iostream>
#include <unistd.h>

struct my_time {
  int horas;
  int minutos;
  int segundos;
};

// declaraco de prototypes
void display(my_time *t);
void update(my_time *t);

int main(int argc, char **argv) {

  int i;
  my_time systime;
  my_time *p;   // posso criar um ponteiro
  p = &systime; // e apontar para a estrutura

  // inicializando variaveis
  systime.horas = 0;
  systime.minutos = 0;
  systime.segundos = 0;

  for (i = 0; i < 70; i++) {
    update(&systime);
    display(p);
  }

  return (EXIT_SUCCESS);
}

// como foi passado o ponteiro, acesso aos dados com operador ->
void update(struct my_time *t) {

  t->segundos++;

  // checando se 60 seg conta 1 min
  if (t->segundos == 60) {
    t->segundos = 0;
    t->minutos++;
  }

  // checando se 60 min conta 1 hora
  if (t->minutos == 60) {
    t->minutos = 0;
    t->horas++;
  }

  // checando se 24 horas conta 1 dia completo
  if (t->horas == 24) {
    t->horas = 0;
  }
  // funcao para "dormir" (esperar) um segundo
  sleep(1);
}

void display(struct my_time *t) {
  std::cout << t->horas << ":" << t->minutos << ":" << t->segundos << '\n';
}
