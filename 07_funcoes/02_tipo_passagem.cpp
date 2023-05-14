/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_tipo_passagem.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Passagem de dados para subrotina

  1) por valor      : o valor da variável de entrada á passado para dentro
                      da subrotina. Se existir manipulação do valor na
                      subrotina, este não é alterado no programa principal.

  2) por referência : o endereço de memória da variável é passado para a
                      subrotina. Ao alterar o valor na subrotina, este
                      também o será no programa principal.
                      PASSAGEM POR PONTEIRO !!

Passagem de argumentos
----------------------

  1) Passagem por valor
  ---------------------
  Até o momento, todas as funções que utilizamos passaram os valores de
  variáveis definidas no programa principal para dentro da subrotina.

  int x = 3, y = 2, z;     // programa principal
  z = adicao(x, y);        // chamada no programa principal

  Nesta situação, os valores de 3 e 2 são passados para a subrotina adicao
  e, de fato, são cópias dos valores de x e y. Perceba que cabe à subrotina
  inicializar as variáveis parâmetro e receber estes valores. Ou seja, existe
  uma duplicação de informação no fluxo de dados ao copiar os valores.

  int adicao(int a, int b)    // declaração da subrotina
                /\     /\
                |      |      3 e 2, respectivamente
  z = adicao(   x,     y);    // chamada no programa principal

  Note que, caso os valores de a e b sejam alterados dentro da subrotina, x
  e y não serão afetados quando a execução retornar ao nível anterior de
  chamada (programa principal, por exemplo).

  Como estamos, no momento, tratando de variáveis fundamentais, a passagem
  por valor não compromete a eficiência na execução do código.

  2) Passagem por referência
  --------------------------
  Agora imagine a situação em que os argumentos das subrotinas são estruturas
  de dados mais avançadas, como arrays, structs, enums ou mesmo classes. Para
  esses casos, a quantidade de dados e memória alocada é bem maior que para
  os tipos fundamentais. Com isso, a passagem por valor, ao fazer uma cópia
  dos dados dentro da função, afeta de forma drástica a eficiência
  computacional.

  Como solução, considere que é possível, ao invés de passar o valor da
  variável em si (realizando a cópia dentro da subrotina), passar o endereço
  de memória onde a variável está alocada no programa principal (ou no nível
  acima da chamada da função). Para isso, os parâmetros são recebidos na
  subrotina por referência (&), capturando o endereço de memória original
  da variável e, por consequência, o valor alocado neste endereço.

  int x = 1, y = 3, z = 7;       // programa principal
  duplicar(x, y, z);             // chamada no programa principal

  // declaração da função
  void duplicar (int& a, int& b, int& c) {

      a *= 2;
      b *= 2;
      c *= 2;
  }

  Repare que a subrotina recebe o endereço de memória dos argumentos e qualquer
  alteração nos valores das variáveis da subrotina que receberam o endereço de
  memória afeta as variáveis no programa principal. Afinal, ambas compartilham
  o mesmo espaço de memória e podem alterar o valor ali alocado.

  void duplicar (int& a, int& b, int& c)     // recebendo referência
                     /\      /\      /\
                     |       |       |       compartilhamento de memória
                    \/      \/      \/
      duplicar(     x,      y,      z  );    // passagem das variáveis

  Note ainda que não houve nenhuma cópia de valores de variáveis. Isso evitou
  duplicação de memória alocada e evitou perda de eficiência, caso estivéssemos
  manipulando estruturas de dados mais complexas. Vale citar ainda que, para
  estruturas de dados mais complexas, deve-se alinhar a referência com o
  mecanismo que C++ tem de acompanhar os dados, o chamado ponteiro. Vamos
  explorar os ponteiros mais a frente.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/functions/
  - https://en.cppreference.com/w/cpp/language/function
  - https://codescracker.com/cpp/cpp-function-calling.htm

 */

#include <iostream>
using namespace std;

// passagem por valor
int pass_val_value(int x) {
    x = x*x;
    return(x + 5);
}

// passagem por referência
int pass_val_refer(int& x) {
    x = x*x;
    return(x + 5);
}

int main(int argc, char** argv) {

    int i, j;

    i = 5;
    j = pass_val_value(i);
    cout << "por valor: i = " << i << " e j = " << j << endl;

    i = 5;
    j = pass_val_refer(i);
    cout << "por refer: i = " << i << " e j = " << j << endl;

    //Finalização
    return 0;
}

