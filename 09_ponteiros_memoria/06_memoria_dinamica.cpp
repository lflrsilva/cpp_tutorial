/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_memoria_dinamica.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Alocação de memória dinâmica
  - Cuidados com a memória dinâmica

Alocação de memória dinâmica
----------------------------
  Em todos os tutoriais anteriores, ao definir as variáveis no código, a
  memória necessária para a execução era determinada antes da execução. Mas
  existem situações em que a quantidade de memória só consegue ser determinada
  em tempo de execução. Nestes casos, o programador pode solicitar o alocamento
  dinâmico da memória.

  Em C++, a alocação dinâmica é realizada com o operador new sobre um ponteiro
  do tipo desejado.

  int *ptr;
  ptr = new int [10];

  A última operação aloca o espaço necessário para o tipo desejado (array,
  struct ou elementos mais complexos, como classes) e posiciona o ponteiro
  sobre o local de memória (por exemplo, o primeiro elemento para arrays).

  O comportamento da variável alocada dinamicamente é idêntico ao alocado de
  modo estático. O acesso aos elementos é o mesmo.

  ptr[i] ou *(ptr + i)

  É usual que as variáveis alocadas dinamicamente sejam necessárias apenas por
  um período de tempo. Quando não for mais necessária, pode ser desalocada para
  liberar recursos para uso pelo sistema operacional. Para isso, usa-se o
  operador delete

  delete ptr;      // para quando ptr é um único elemento
  delete[] ptr;    // para quando ptr é um array

  O operador delete sempre deve ser aplicado sobre ponteiros que apontam para
  um bloco de memória alocado dinamicamente.

Cuidados com a alocação dinâmica
--------------------------------
  Deve-se tomar certos cuidados com a alocação dinâmica de memória. Quando
  solicitado pelo programa, o sistema deve liberar a memória heap para
  alocação. Contudo, a memória é limitada e não existe garantia de que o
  sistema irá permitir a alocação. Por isso, cabe ao programador verificar se
  a alocação de memória teve sucesso.

  Existem duas formas de verificar a alocação. O uso de exceptions retorna
  tipos especiais que indicam algum comportamento estranho no código. Existe
  um tipo especial para erros de alocação de memória retornado pelo operador
  new. Os exceptions são a forma padrão de tratar erros de alocação, mas só
  vamos abordar esse tema mais a frente.

  Como segunda alternativa para checar se a alocação teve sucesso, é possível
  usar um objeto especial chamado notrhow, definido no cabeçalho <new>.

  ptr = new (nothrow) int [10];

  Se a alocação de memória falhar, nothrow retorna um ponteiro nulo.

  if ( ptr == nullptr ) {

    // erro na alocação!! Tomar as medidas necessárias.
  }

  Usar nothrow não é tão eficiente quanto exceptions, mas é bem simples e pode
  ser usado em um primeiro momento. Quando abordarmos exceptions, alteramos a
  metodologia.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/dynamic/

 */

#include <cmath>
#include <cstdlib> // define std::abort()
#include <iostream>
#include <new> // define std::nothrow

// exemplo com ponteiro duplo e alocação dinâmica
// multiplicação de matriz A[n][m] e vetor v[n] constantes
// a variável com o resultado será alocada dentro da função
// e retorna para o programa principal
double *multMatVec(double **Ar, double *vr, int n, int m) {

  // alocando espaço para armazenar o resultado
  double *tm = new (std::nothrow) double[n];
  if (tm == nullptr) {
    std::cout << "Erro ao alocar tm em multMatVec. Abortando." << std::endl;
    std::abort();
  }

  for (int i = 0; i < n; i++) {
    // zerando o valor em tm
    tm[i] = 0.0;
    for (int j = 0; j < m; j++) {
      // multiplicando os elementos nas colunas e somando-os
      tm[i] += Ar[i][j] * vr[j];
    }
  }
  return tm;
}

int main(int argc, char **argv) {

  const int nmax = 100; // no de linhas
  const int mmax = 200; // no de colunas

  // alocando espaço para matriz
  double **a = new (std::nothrow) double *[nmax];
  for (int i = 0; i < nmax; i++) {
    a[i] = new (std::nothrow) double[mmax];
  }
  // checando alocação
  if (a == nullptr) {
    std::cout << "Erro ao alocar a matriz. Abortando." << std::endl;
    std::abort();
  }

  // alocando um vetor
  double *b = new double[mmax];
  // checando alocação
  if (!b) {
    std::cout << "Erro ao alocar o vetor. Abortando." << std::endl;
    std::abort();
  }

  // colocando valores na matriz e no vetor
  for (int i = 0; i < nmax; i++) {
    for (int j = 0; j < mmax; j++) {
      a[i][j] = (double)(i * i + j);
      b[j] = (double)(3 * j + 5);
    }
  }
  // realizando a multiplicação
  double *c = multMatVec(a, b, nmax, mmax);
  // análise da norma da solução
  double norm = 0.0;
  for (int i = 0; i < nmax; i++) {
    norm += c[i] * c[i];
  }
  norm = sqrt(norm);
  std::cout << "Norma da solução = " << norm << std::endl;

  // vamos deletar toda a memória alocada
  for (int i = 0; i < nmax; i++) {
    delete[] a[i];
  }
  delete[] a;
  delete[] b;
  delete[] c;

  return (EXIT_SUCCESS);
}
