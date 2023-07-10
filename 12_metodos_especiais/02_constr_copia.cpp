/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_constr_copia.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Construtor por cópia
  - Deep e shallow copy
  - Cópia por atribuição

Construtores por cópia
----------------------
  Quando a construção de um objeto tem como argumento um outro objeto do mesmo
  tipo (da mesma classe), a construção deve ser feita por cópia. Neste caso, o
  único argumento deve ser a referência (&) à classe, com atributos const
  (para garantir que não haverá alteração nos dados da classe argumento).

  MinhaClasse::MinhaClasse(const MinhaClasse&);

  Caso a classe não tenha explicitamente um método de cópia ou movimento (já
  vamos ver isso), C++ define um construtor padrão de cópia.

  classe exemplo {
      int a, b;
      string data;
    public:
      // implementação do construtor padrão
      exemplo () { }
      // implementação do construtor com entrada do dado
      exemplo (int x, int y, const string& str) : a(x), b(y), data(str) { }
      // implementação do construtor por cópia
      exemplo (const exemplo& ex) : a(ex.a), b(ex.b), data(ex.data) { }

      const string& conteudo() const { return *data; }
  };

  Repare que no exemplo acima, existe a cópia dos dados membros da classe que
  serve de argumento do construtor. Isto é chamado de shallow copy e funciona
  bem para dados que tem tipos básicos. Mas e quando os dados membro são
  ponteiros que gerenciam a memória? Neste caso isso pode não funcionar como
  esperado.

Cópia shallow e deep
--------------------
  Considere a situação da construção por cópia em que a classe argumento possui
  um ponteiro entre seus dados membros. No caso de shallow copy, os dados
  membros do objeto argumento são copiados para o novo objeto. Para um ponteiro,
  ambos dados membro do tipo ponteiro vão apontar para o mesmo endereço de
  memória.

  exemplo ex1(ptr);  // construção usual
  exemplo ex2(ex1);  // construção por cópia shallow

  Isso implica que qualquer alteração no dado membro de um dos objetos afeta o
  outro. Quando os objetos forem destruídos, ambos vão tentar liberar o mesmo
  espaço de memória, provavelmente causando um erro de execução.

  Esta situação pode ser evitada pela construção usando deep copy que, na
  verdade, é um conceito bem simples. Ao invés de realizar a cópia do ponteiro
  em si, alocar um novo espaço de memória e copiar o conteúdo do dado membro.

  classe exemplo {
      string* data;
    public:
      // implementação do construtor padrão
      exemplo () { }
      // implementação do construtor com entrada do dado
      exemplo (const string& str) : data( new string(str) ) { }
      // implementação do construtor por cópia
      exemplo (const exemplo& ex) : data( new string (ex.conteudo()) ) { }

      const string& conteudo() const { return *data; }
  };

Cópia por atribuição
--------------------
  C++ tem um comportamento padrão para objetos não inicializados, mas com
  operador de atribuição. Neste caso, o operador se comporta como um construtor.
  Contudo, caso o objeto já tenha sido construído (e inicializado), o
  comportamento do operador é de atribuição simples.

  MinhaClasse ex1;
  MinhaClasse ex2(ex1);     // construtor por cópia
  MinhaClasse ex3 = ex1;    // inicialização do objeto: construtor por cópia
  ex1 = ex2;                // objeto já inicializado: atribuição simples

  Note que ex3 é declarado e inicializado com uma construção do objeto. É
  importante identificar que não se trata de uma atribuição, mas uma construção.
  Já na última linha, não se trata de uma declaração e, portanto, é um operador
  de atribuição sobre um objeto já existente.

  A sintaxe parte do sobrecarregamento do operador = tomando um valor ou
  referência da classe como parâmetro. O retorno usualmente se refere a *this.

  MinhaClasse& operator=(const MinhaClasse&);

  Por considerar os casos de construção de objetos, deve-se tomar os mesmos 
  cuidados sobre deep e shallow copy discutidos acima.

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
