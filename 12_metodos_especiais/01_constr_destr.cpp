/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_constr_destr.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Construtores padrão (default)
  - Destrutores

Construtores padrão
-------------------
  Para uma classe em que o construtor não foi implementado, C++ implicitamente
  define um construtor padrão, inicializado sem argumentos. Ele pode ser usado
  declarando uma classe sem argumentos.

  classe_exemplo MeuExemplo;

  Contudo, quando se implementa qualquer forma de construtor em uma classe, C++
  desabilita o construtor padrão. Portanto, é preciso implementar o construtor
  padrão para usá-lo.

  classe exemplo {
      string data;
    public:
      exemplo () { }  // implementação do construtor padrão
      exemplo (const string& str) : data(str) { }
  };

Destrutores
-----------
  Os destrutores tem papel inverso aos construtores. De fato, eles são
  responsáveis pela desalocação e limpeza de memória quando o ciclo de vida da
  classe termina. Até o momento não tivemos que alocar nenhum recurso
  dinamicamente e, portanto, não foi necessário o uso de destrutores. Para tal,
  no caso de uma classe que aloca um dado membro em memória dinâmica os
  destrutores se tornam absolutamente úteis pois fornecem esse mecanismo para
  liberar a memória.

  Os destrutores tem sintaxe muito parecida com os construtores padrão, sem
  argumentos e sem retorno. Além disso, são identificados pela precedência de 
  tilde (~)

  classe exemplo {
      string* data;
    public:
      // construtor com alocação dinâmica
      exemplo () : data(new string) { } 
      exemplo (const string& str) : data(new string(str)) { }

      // destrutor para liberar a memória
      ~exemplo() { delete data; }    // destrutor
  };

  Os destrutores são executados sempre que o ciclo de vida de do objeto termina,
  usualmente com o fim da função main.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/classes2/

*/

#include <iostream>
#include <cstdlib>
#include <cmath>

class GeneralVector {
    int nSize;
    double* data;
  public:
    // construtores e destrutor
    GeneralVector(int, double*);
    GeneralVector(int, double);
    ~GeneralVector() { delete[] data; }

    // sobrecarregamento de operadores
    GeneralVector& operator=(const GeneralVector&);
    GeneralVector& operator+=(const GeneralVector&);
    GeneralVector& operator-=(const GeneralVector&);
    double& operator[](int i) const { return data[i]; }

    // métodos genéricos
    int size() { return nSize; }
    double maxnorm() const;    // norma máximos
    double twonorm() const;    // norma euclideana
};

// construtores
GeneralVector::GeneralVector(int n, double* vec) {
  
  // opção 1
  /* nSize = n; */
  /* data = new double[n]; */

  // opção 2
  /* data = new double[nSize = n]; */

  // opção 3
  this->data = new double[this->nSize = n];
  
  for (int i = 0; i < n; i++) {
  this->data[i] = vec[i];
  }
}

GeneralVector::GeneralVector(int n, double value) {
  this->data = new double[this->nSize = n];
  
  for (int i = 0; i < n; i++) {
    this->data[i] = value;
  }
}


// sobrecarregamento de operadores
GeneralVector& GeneralVector::operator=(const GeneralVector& vec) {
  if (this != &vec) {   // verificando se é o próprio vetor
    if(this->nSize != vec.nSize) {
      std::cerr << "Erro de tamanho na atribuição (=) de vetores."
                << std::endl;
      abort();
    }
    for (int i = 0; i < this->nSize; i++) {
      this->data[i] = vec[i];
    }
  }
  return *this;
}

GeneralVector& GeneralVector::operator+=(const GeneralVector& vec) {
  if(this->nSize != vec.nSize) {
    std::cerr << "Erro de tamanho na atribuição (+=) de vetores."
              << std::endl;
    abort();
  }
  for (int i = 0; i < this->nSize; i++) {
    this->data[i] += vec[i];
  }
  return *this;
}

GeneralVector& GeneralVector::operator-=(const GeneralVector& vec) {
  if(this->nSize != vec.nSize) {
    std::cerr << "Erro de tamanho na atribuição (-=) de vetores."
              << std::endl;
    abort();
  }
  for (int i = 0; i < this->nSize; i++) {
    this->data[i] -= vec[i];
  }
  return *this;
}

double GeneralVector::maxnorm() const {
  double norma = fabs(this->data[0]);
  for (int i = 1; i < this->nSize; i++) {
    norma += fabs(this->data[i]);
  }
  return norma;
}

double GeneralVector::twonorm() const {
  double norma = this->data[0]*this->data[0];
  for (int i = 1; i < this->nSize; i++) {
    norma += this->data[i]*this->data[i];
  }
  return sqrt(norma);
}

int main(int argc, char **argv) {
  
  int size = 500;
  double* v = new double[size];

  for (int i = 0; i < size; i++) {
    v[i] = sqrt(i)*cos(i);
  }

  // construção copiando elementos de v 
  GeneralVector vec1(size, v);

  // construção uniforme
  GeneralVector vec2(size, 3.0);

  std::cout << "Norma max de vec1 = " << vec1.maxnorm() << std::endl;

  // testando sobrecarregamento =
  vec2 = vec1;

  std::cout << "Norma max de vec2 = " << vec2.maxnorm() << std::endl;

  // para não ter vazamento de memória, precisamos liberar v
  delete[] v;

  // os objetos GeneralVector são liberados pelo destrutor
  return 0;
}
