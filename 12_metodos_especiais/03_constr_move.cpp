/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_constr_move.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Construtor por transferência de objetos

Construtores por transferência 
------------------------------

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
    // construtor por cópia deep ou shallow (ver abaixo)
    GeneralVector(const GeneralVector& gv);
    ~GeneralVector() { delete[] data; }

    // sobrecarregamento de operadores
    GeneralVector& operator=(const GeneralVector&);
    GeneralVector& operator+=(const GeneralVector&);
    GeneralVector& operator-=(const GeneralVector&);
    double& operator[](int i) const { return data[i]; }

    // métodos genéricos
    int size() { return nSize; }
    double& content() const { return *data; }  // acesso ao ponteiro data
    double maxnorm() const;    // norma máximos
    double twonorm() const;    // norma euclideana
};

// construtores
GeneralVector::GeneralVector(int n, double* vec) {
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

// Shallow copy

GeneralVector::GeneralVector(const GeneralVector& gv) {
  this->nSize = gv.nSize;
  this->data = gv.data;
}

// Deep copy
/*
GeneralVector::GeneralVector(const GeneralVector& gv) {
  this->data = new double[this->nSize = gv.nSize];

  for (int i = 0; i < gv.nSize; i++) {
    this->data[i] = gv.data[i];
  }
}
*/

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
    v[i] = sqrt(i)*cos(2*i);
  }

  // construção copiando elementos de v 
  GeneralVector vec1(size, v);

  // construção por cópia
  GeneralVector vec2(vec1);

  std::cout << "Norma max de vec1 = " << vec1.maxnorm() << std::endl;

  // testando sobrecarregamento =
  // vec2 = vec1;

  std::cout << "Norma max de vec2 = " << vec2.maxnorm() << std::endl;

  // para não ter vazamento de memória, precisamos liberar v
  delete[] v;

  return 0;
}
