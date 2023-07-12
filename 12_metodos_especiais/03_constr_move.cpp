/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_constr_move.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Construtor por transferência (move) de objetos

Construtores por transferência
------------------------------
  Os contrutores por transferência (move) são semelhantes a construção por
  cópia. A diferença é que a transferência, de fato, transfere o conteúdo de
  um objeto (fonte) para outro (destino). Com isso, a fonte perde
  complementamente o acesso ao objeto, que agora pertence ao destino. Esta
  condição se aplica quando a fonte é um objeto não nomeado.

  Mas o que é um objeto não nomeado? Bem, são objetos temporários que não estão
  associados a nada. Um exemplo de objeto não nomeado é o retorno de uma função.

  Digamos que existe uma função que retorne o objeto minhaClasse.

  minhaClasse fn();

  Portanto, o retorno é apenas um objeto temporário e, para ser armazenado, deve
  ser usado em uma construção ou atribuição. Este é o sentido do contrutor por
  transferência.

  minhaClasse ex1;          // construtor default
  minhaClasse ex2 = ex1;    // construtor por cópia
  minhaClasse ex3 = fn();   // construtor move

  ex1 = ex2;                // atribuição por cópia
  ex3 = minhaClasse();      // atribuição por move

  As duas operações acima que usam move partem de objetos são temporários não
  nomeados. Justamente por isso, a cópia não faz sentido e a transferência
  (move) se aplica de forma mais eficiente.

  A sintaxe de contrução e atribuição move usa como parâmetro a referência
  rvalue da própria classe.

  minhaClasse( minhaClasse&& );                // construção move
  minhaClasse& operator= ( minhaClasse&& );    // atribuição move

  Nos comandos acima, && se refere à referência a um rvalue (discutimos esse
  assunto em aulas anteriores).

  O conceito de transferência (move) se aplica melhor ainda em casos que usam
  o operador new e delete. A memória alocada pelo operador new também é não
  nomeada e, portanto, a trasferência para um objeto destino seria viável.

  A maioria dos compiladores mais modernos conseguem otimizar a operação de 
  retorno não nomeado. Nestes casos, a construção move nem seria usada.

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
    GeneralVector(const GeneralVector& gv);
    GeneralVector(const GeneralVector&& gv);           // move 
    ~GeneralVector() { delete[] data; }

    // sobrecarregamento de operadores
    GeneralVector& operator=(const GeneralVector&);
    GeneralVector& operator=(const GeneralVector&&);  // move
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

// Deep copy
GeneralVector::GeneralVector(const GeneralVector& gv) {
  this->data = new double[this->nSize = gv.nSize];

  for (int i = 0; i < gv.nSize; i++) {
    this->data[i] = gv.data[i];
  }
}

// Move
GeneralVector::GeneralVector(const GeneralVector&& gv) {
  this->nSize = gv.nSize;
  this->data = gv.data;
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

// atribuição move 
GeneralVector& GeneralVector::operator=(const GeneralVector&& vec) {
  this->nSize = vec.nSize;
  this->data = vec.data;
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

  // construção por move
  GeneralVector vec2 = GeneralVector(vec1);

  std::cout << "Norma max de vec1 = " << vec1.maxnorm() << std::endl;

  std::cout << "Norma max de vec2 = " << vec2.maxnorm() << std::endl;

  // para não ter vazamento de memória, precisamos liberar v
  delete[] v;

  return 0;
}
