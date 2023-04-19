/**
  
  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_tipos_fundamentais_limites.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Modificadores de tipo
  - Quantidade de memoria alocada
  - Limites dos valores das variaveis
  - Introducao a precisao numerica

Modificadores de tipo
---------------------
  - caractereres
  char (8 bits), char16_t (16 bits), char32_t (32 bits)
  wchar_t  : maior capacidade de armazenamento de conjunto de caracteres

  - inteiros
  signed ou unsigned : valores com ou sem sinal
  short, long  e long long : 16 bits, 32 bits e 64 bits

  - ponto-flutuante
  long double : precisão estendida (depende da arquitetura)

Bibliotecas
-----------
  - cstdlib: funções de uso geral, gerenciamento de memória, geração de número 
             randômico, conversão entre tipos, comunicação com sistema e 
             variáveis de ambiente
  - climits: definição de variáveis globais com os limites de tipos inteiros
             para o sistema e compilador utilizados
  - cfloat:  definição de variáveis globais com os limites de tipos
             ponto-flutuante para o sistema e compilador utilizados

  Obs.: valores dos limites escritos no codigo sao de sistemas 32 bits e
  podem variar entre diferentes SOs e compiladores.

  Referencias
  -----------
  - https://cplusplus.com/reference/climits/
  - https://en.cppreference.com/w/cpp/language/types
  - https://cplusplus.com/reference/cfloat/
  - http://www.tutorialspoint.com/c_standard_library/index.htm
  - http://en.wikibooks.org/wiki/C_Programming/C_Reference/limits.h

 */

#include <iostream>
#include <cstdlib>    // define EXIT_SUCCESS
#include <climits>    // valores limite de inteiros
#include <cfloat>     // valores limite de ponto flutuante

int main(int argc, char** argv) {

    // Variaveis inteiras
    int i;                // -32768 a 32767 (2 bytes)
                          // -2147483648 a 2147483647 (4 bytes)

    // restringe a variavel a valor positivo
    unsigned int j;       // 0 a 65535 (2 bytes)
                          // 0 a 4294967295 (4 bytes)

    // define a quantidade de bytes alocados
    // 2 bytes
    short int k;           // -32768 a 32767
    unsigned short int l;  // 0 a 65535

    // 4 bytes
    long int m;           // -2147483648 a 2147483647
    unsigned long int n;  // 0 a 4294967295

    // declaracao de variavel em ponto flutuante
    // precisao simples (4 bytes - ~ 6  casas decimais)
    float fpi;            // 1.2E-38 a 3.4E+38

    // precisao dupla   (8 bytes - ~ 15 casas decimais)
    double dpi;           // 2.3E-308 a 1.7E+308

    // precisao dupla estendida  (10 bytes - ~ 19 casas decimais)
    long double ldpi;     // 3.4E-4932 a 1.1E+4932

    // saida em tela de bytes armazenados na memoria
    // comando sizeof retorna o tamanho, em bytes, de tipos de variável
    std::cout << "Qtde de armazenada para int    (bytes) : "
              << sizeof(int) << std::endl;
    std::cout << "Qtde de armazenada para float  (bytes) : "
              << sizeof(float) << std::endl;
    std::cout << "Qtde de armazenada para double (bytes) : "
              << sizeof(long double) << std::endl;
    std::cout << "Qtde de armazenada para char   (bytes) : "
              << sizeof(char) << std::endl
              << std::endl;

    // saida em tela dos limites das variaveis inteiras
    // constantes macro definidas em climits
    std::cout << "Valor minimo para SHORT INT = " << SHRT_MIN << std::endl;
    std::cout << "Valor maximo para SHORT INT = " << SHRT_MAX << std::endl
              << std::endl;

    std::cout << "Valor minimo para INT = " << INT_MIN << std::endl;
    std::cout << "Valor maximo para INT = " << INT_MAX << std::endl
              << std::endl;

    std::cout << "Valor maximo para UNSIGNED LONG INT = " << ULONG_MAX
              << std::endl << std::endl;

    // saida em tela dos limites das variaveis em ponto flutuante
    // constantes macro definidas em cfloat
    std::cout << "Valor minimo para FLOAT = " << FLT_MIN << std::endl;
    std::cout << "Valor maximo para FLOAT = " << FLT_MAX << std::endl
              << std::endl;

    std::cout << "Valor minimo para DOUBLE = " << DBL_MIN << std::endl;
    std::cout << "Valor maximo para LONG DOUBLE = " << LDBL_MAX << std::endl;

    return (EXIT_SUCCESS);
}
