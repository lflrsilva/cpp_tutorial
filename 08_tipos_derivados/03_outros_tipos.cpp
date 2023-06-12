/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_outros_tipos.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - fundamentos e sintaxe de enumeracao
  - fundamentos e sintaxe de union

Estrutura enum
--------------
  Estrutura de variaveis do tipo constantes inteiras para tornar melhor a
  leitura do codigo. Seguindo o mesmo formato de C, a estrutura inicia em 0,
  por padrao. Caso contrario, deve-se especificar o primeiro valor.

  // definicao
  enum nome_enumer {
      lista_de_enumeracao   // itens separados por virgula
  } en_objs;

  em que en_objs é opcional.

  // declaracao de var como enum
  enum nome_enumer var;

  // exemplo     0      1     2      3
  enum colors_t {preto, azul, verde, vermelho};

  colors_t mcor;
  mcor = azul;     // 1

  Em C++, a estrutura enum possui um tipo próprio, ao invés de ter os dados
  convertidos para inteiros. Para tal, usa-se o identificador class (ou struct).

  // exemplo
  enum class Colors {preto, azul, verde, vermelho};

  Colors mcor;
  mcor = Colors::azul

  if (mcor == Colors::preto) { mcor = Colors::vermelho; }

Estrutura union
---------------
  Estrutura de variaveis com tipos diferentes e compartilham o mesmo espaco
  de memoria.

  union nome_union {
      tipo1 var1;
      tipo2 var2;
  } union_objs;

  O termo union_objs é opcional. Caso seja usado, o union é identificado por
  este último.

  Ao declarar um union, o compilador aloca um espaco grande
  o bastante para armazenar o maior tipo. As variaveis sao alocadas
  no mesmo espaco de memoria. Utilizado para evitar fragmentacao de
  dados e conversoes nao usuais entre tipos. Por exemplo, uma conversao
  nao usual do arredondamento de um double.

  Uma aplicação do union é dividir um dado tipo de variável em espaços menores.

  union mix_t {
    int l;        // 4 bytes
    struct {
      short hi;   // 2 bytes
      short lo;   // 2 bytes
    } s;
    char c[4];    // 1 byte * 4
  } mix;

Referências
-----------
  - https://cplusplus.com/doc/tutorial/other_data_types/

 */

#include <iostream>

int main(int argc, char** argv) {

    // uso de enum
    enum class dia_semana {
        domingo, segunda, terca, quarta, quinta, sexta, sabado
    };

    // declaracao de variaveis
    enum dia_semana feira, aniversario;

    feira = dia_semana::quarta;

    aniversario = dia_semana::sabado;

    // ERRO! Não existe definição para saída em tela de enum class
    // std::cout << feira << "\n"; // saida em tela como inteiro OK

    // uso de union
    union pw {
        char ch[4];   // 1 byte * 4
        int  i;       // 4 bytes
    };

    // declaracao de variaveis
    union pw word;
    word.i = 1;

    std::cout << word.i << std::endl;
    // não é possível ser definido para saída em tela
    for (int j = 0; j < 4; j++) {
        std::cout << word.ch[j] << "\t";
    }
    std::cout << "\n";

    // alterando a variável ch[0]. A variável que ocupa o mesmo espaço que i
    // também é alterada!!
    word.ch[0] = 'a';

    std::cout << word.i << std::endl;
    // não é possível ser definido para saída em tela
    for (int j = 0; j < 4; j++) {
        std::cout << word.ch[j] << "\t";
    }
    std::cout << "\n";

    return 0;
}

