/** 

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   operadores_avancados.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Operadores de conversão de tipo
  - Operador condicional ternário
  - Uso de operadores relacionais e logicos
  - Introducao aos condicionais
  - Avaliacao de operacoes avancadas

Operador de conversão de tipo
-----------------------------
  As conversões entre tipos numéricos é bastante trivial.

  double x = 15.495;

  // conversão c-like
  int j = (int)x;          // as casas decimais são eliminadas
  
  double y = (double)j;    // 15.0 ..
  
  // conversão function-like
  double y = double(j);    // 15.0 ..

  Existe a conversão implícita entre tipos (automática), mas a decisão cabe ao
  compilador. Independente da conversão, sempre é possível perder informação.
  Ainda existem quatro tipos de operadores de conversão que vamos abordar
  depois: static_cast, dynamic_cast, const_cast e reinterpret_cast.

Operador condicional ternário
-----------------------------
  Esse operador analisa uma expressão condicional e pode retornar um ou outro 
  resultado caso a expressão seja true ou false.

  x = (condicao) ? expr_true : expr_false

  A lógica com operadoradores ternários se assemelha muito aos condicionais
  if-else. A escolha entre usar uma ou outra forma de condicional deve priorizar
  a legibilidade e manutenção do código, não por performance.

Referências
-----------
  - https://www.geeksforgeeks.org/type-conversion-in-c/
  - 

 */

#include <iostream>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int x = 5;
    int i = 2, j = 2;

    // conversão de tipo
    float m = 2.14;
    i = (int)m;     // as casas decimais são perdidas

    // condicional SE
	// conteudo do condicional so eh
	// executado SE condicao for verdadeira
    if (x < 6)  // argumento true
    {
        // Executa codigo entre chaves
        std::cout << "Entrei no condicional?" << std::endl;
        x = 7;
    }

    if (x == 0)  // argumento false
    {
        // Executa codigo entre chaves
        std::cout << "Entrei no condicional?" << std::endl;
        x = 0;
    }

    if (0) x = 17;   // Inteiro 0 é interpretado como false

    if (1) x = 20;   // Qualquer valor diferente de 0 é true (padrão 1)

    x = 7;
    if(3 < x < 9)    // true ou false????
    {
        // executa codigo dentro do condicional???
        std::cout << "Ola!" << std::endl;
    }

    x = 20;
    if(3 < x < 9)    // true ou false????
    {
        // executa codigo dentro do condicional???
        std::cout << "Oi!" << std::endl;
    }

    if( (i = 0) && (j = 3) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        std::cout << "Eita!" << std::endl;
    }

    if( (i = 4) || (j = 5) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        std::cout << "Loucura!" << std::endl;
    }

    if( (i = 0) || (j = 6) )    // true ou false????
    {
        // executa codigo dentro do condicional???
        std::cout << "Que viagem!" << std::endl;
    }

    return 0;
}
