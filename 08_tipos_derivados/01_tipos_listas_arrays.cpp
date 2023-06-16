/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_tipos_listas_arrays.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - fundamentos de alocacao de arrays
  - sintaxe no uso de arrays
  - arrays 1d
  - arrays 2d

Arrays: vetores e matrizes
--------------------------

  Sendo T uma variável declarada, T[n] é um array ou lista
  unidimensional (vetor) de n elementos com o mesmo tipo de T.

  Os elementos são indexados a partir de 0 ate n-1 e são armazenados
  em sequência na memória (stack).

  int T[5];     alocacao 5 x ( 4 bytes ) = 20 bytes

  |___|___|___|___|___|
    0   1   2   3   4

  Para lista bidimensional, T[n][m] aloca uma matriz com n linhas e m
  colunas, com elementos do mesmo tipo de T.

  int T[3][2];  alocacao 3 x 2 x (4 bytes) = 24 bytes

  n
   0 |___|___|
       0   1   m

   1 |___|___|
       0   1   m

   2 |___|___|
       0   1   m

  Contudo, um array bidimensional eh armazenado sequencialmente na memoria,
  na ordem de linhas e colunas

   n =   0       1       2
         |___|___|___|___|___|___|
   m =     0   1   0   1   0   1

  De modo geral, armazenamento sequencial na memoria

Memória RAM
-----------

  int v[n];  // sequencial
  ____|____|____|____|____|______|
   v[0] v[1] v[2]    ...    v[n-1]

  int v[n][m];  // sequencial por linha
  _______|_______|_______|_________|_______|_______|_______|_________|
  v[0][0] v[0][1]   ...   v[0][m-1] v[1][0] v[1][1]   ...   v[1][m-1] ...

  Qual o uso eficiente do acesso a memoria em arrays 2D?? Lembre-se
  que a informacao passa para a memoria cache!

  IMPORTANTE: Os campo com o número de elementos do array dentro de [] deve
  ser necessariamente uma expressão ou valor constante. Afinal, arrays são
  blocos de memória estática (stack) e a quantidade de memória deve ser
  determinada em tempo de compilação, antes mesmo da execução.

Notas finais
------------
  - É possível criar arrays multidimensionais, como

        char segs_no_seculo[100][365][24][60][60];

  Contudo, a quantidade de memória requerida aumenta de forma exponencial para
  cada dimensão!

  - Sempre é possível usar uma técnica de composição de índices para evitar
  arrays multidimensionais.

  - A passagem de arrays para funções **sempre** é por referência! Vamos
  explorar esse assunto mais a frente.

  - Existem bibliotecas STL com diferentes estruturas de dados, inclusive
  arrays. A funcionalidade destas bibliotecas amplia bastante a manipulação
  de arrays. Vamos explorar esse tópico em containers de dados.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/arrays/

 */

#include <iostream>
#include <array>
#include <cmath>

// definindo macros para o tamanho dos arrays
#define Nmax 30
#define WIDTH 5
#define HEIGHT 3

// declaração e implementação da função
inline void printarray1d(float arg[], int length) {
    // arg[] indica que qualquer a função aceita 
    // arrays 1D de qualquer tamanho
    for (int n=0; n<length; ++n) {
    std::cout << arg[n] << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char** argv) {

    int i,j;
    float vec[3];     // array 1D com 3 floats; vec[0], vec[1], vec[2]
    int st[Nmax];     // array 1D com 30 ints; st[0], ... st[29]

    double mt[2][5];  // array 2D c/ 2 linhas e 5 colunas

    // Declaracao com inicializacao
    int v[] = {1, 2, 3, 4};      // inicializacao com atribuicao
    int a[3] = {2, 4, 5};         // inicializacao universal
    int u[][3] = { {1, 2, 3} , {4, 5, 8} };
    char filename[30] = "output";   // array de caracteres

    /* Erro se declarado E inicializado assim:
     * int v[4];
     * v = {2, 4, 5, 9}; // Erro!! Não dá para ser assim.
     */

    vec[0] = 1.0;
    vec[1] = 2.0;
    vec[2] =-2.0;

    for(i = 0; i < 30; i++) {
        st[i] = i*i + 7;
    }

    j = st[29];

    mt[0][0] = 5.0;
    mt[1][4] = 5.0;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 5; j++) {

            mt[i][j] = i + j;  // conversao implicita de tipos
        }
    }

    // passagem de array para função
    // E se trocar 3 por 4 no comando abaixo? O que acontece? 
    printarray1d(vec, 3);

    // representacao 1d vs 2d
    int dados_1d [HEIGHT * WIDTH];
    int dados_2d [HEIGHT][WIDTH];

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {

            // acesso dados 1d
            dados_1d[i*WIDTH + j] = (i+1)*(j+1);

            // acesso dados 2d
            dados_2d[i][j] = (i+1)*(j+1);

            std::cout << dados_1d[i*WIDTH + j] << "\t"
                      << dados_2d[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // As operacoes NAO podem ser realizadas diretamente com arrays
    // apenas com os COMPONENTES do array.

    j = st[0] * st[29];

    mt[0][0] = mt[1][1] + mt[0][4] * pow(mt[1][3], 2.5);

    // Array STL

    // declaração de array STL
    std::array<int, 3> meu_array = {10, 20, 30};

    // acesso por índices dos elementos do array
    for (int i=0; i < meu_array.size(); ++i) {
        ++meu_array[i];
    }

    // acesso dos elementos do array com iteradores especiais
    for (int elem : meu_array) {
        std::cout << elem << "\n";
    }

    return (0);
}
