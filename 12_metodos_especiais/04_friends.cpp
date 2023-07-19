/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_friends.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Métodos e classes friends

Métodos friends
---------------
  Um dos princípios de encapsulamento é não permitir que dados ou métodos
  privados ou protegidos sejam acessados fora da classe onde são definidos.
  Contudo, é possível fugir a essa regra com métodos friends.

  Os métodos friends se comportam como funções não-membro (mesmo estando
  definidas dentro da classe), mas que conseguem acessar membros privados ou 
  protegidos. Para tal, seu argumento deve ser um objeto da classe em si.

  class Rectangle {
      int width, height;
    public:
      Rectangle() {}
      Rectangle (int x, int y) : width(x), height(y) {}
      int area() {return width * height;}
      friend Rectangle duplicate (const Rectangle&);
  };

  Rectangle duplicate (const Rectangle& param)
  {
    Rectangle res;
    res.width = param.width*2;
    res.height = param.height*2;
    return res;
  }

  Repare que o método duplicate é declarado como friend dentro da classe
  Rectangle. A declaração friend faz com que o método se comporte como
  não-membro, sendo possível sua chamada direta no programa principal.

  int main () {
    Rectangle foo;
    Rectangle bar (2,3);
    foo = duplicate (bar);
    cout << foo.area() << '\n';
    return 0;
  }

Classes friends
---------------
  Segue o mesmo princípio de métodos friends. Neste caso, a classe friend tem 
  acesso aos membros privados e protegidos da classe em que está declarada.

  class Square;

  class Rectangle {
      int width, height;
    public:
      int area ()
        {return (width * height);}
      void convert (Square a);
  };

  class Square {
    friend class Rectangle;
    private:
      int side;
    public:
      Square (int a) : side(a) {}
  };

  void Rectangle::convert (Square a) {
    width = a.side;
    height = a.side;
  }

  Neste exemplo, a classe Rectangle é friend de Square e, portanto, pode acessar 
  seus dados membros privados. Repare como isso ocorre na função convert.

  Note ainda que, na sintaxe de C++, é preciso declarar a classe Square antes
  de usá-la no método convert em Rectangle.

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
    GeneralVector(const GeneralVector&& gv);
    ~GeneralVector() { delete[] data; }

    // sobrecarregamento de operadores
    GeneralVector& operator=(const GeneralVector&);
    GeneralVector& operator=(const GeneralVector&&);
    GeneralVector& operator+=(const GeneralVector&);
    GeneralVector& operator-=(const GeneralVector&);
    double& operator[](int i) const { return data[i]; }

    // métodos genéricos
    int size() { return nSize; }
    double& content() const { return *data; }  // acesso ao ponteiro data
    double maxnorm() const;    // norma máximos
    double twonorm() const;    // norma euclideana
    
    friend GeneralVector multiply(const GeneralVector&, const GeneralVector&);

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

// método friend é implementado como uma função simples, sem 
// indexação com a classe (GeneralVector:: )
GeneralVector multiply(GeneralVector& ls, GeneralVector& rs) {
  GeneralVector tmp(ls.size(), 0.0);
  for (int i =0; i < ls.size(); i++) {
    tmp[i] = ls[i]*rs[i];
  }
  return tmp;
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

  GeneralVector vec3 = multiply(vec1, vec2);

  std::cout << "Norma max de vec3 = " << vec3.maxnorm() << std::endl;

  // para não ter vazamento de memória, precisamos liberar v
  delete[] v;

  return 0;
}
