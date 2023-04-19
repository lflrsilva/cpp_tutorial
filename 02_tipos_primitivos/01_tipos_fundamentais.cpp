/**
  
  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_tipos_fundamentais.cpp
  Author: lflrsilva

Tipos de variáveis (identificadores)
------------------------------------

  - Caracteres: 
  Conjunto básico de caracteres da tabela ASCII. Sua forma mais básica, char,
  representa um único caractere, como 'L'ou '^'. Pode ser estendido com tipos
  char modificados.
  
  - Inteira:
  Armazenam valores numéricos completos sem casas decimais, como 4 ou 2048.
  Podem ser modificados para ter diferentes tamanhos em memória (valores
  maiores) e com ou sem representação de sinais (suporte a valores negativos).
  
  - Ponto flutuante:
  Armazenam valores numéricos reais completos com casas decimais, como 3.14 ou
  0.05. São caracterizados por sua precisão numérica (simples ou dupla) e podem
  ser modificados para precisão estendida. A precisão depende da arquitetura do
  processador.
  
  - Booleana:
  Representação de dois estados, true ou false, para análises de comparação.
  Em C, não existem variáveis booleanas, sendo usado inteiro 0 para falso e
  qualquer outro valor para verdadeiro. Essa regra se mantém em C++.
  
  - Tipo void:
  Representação sem propósito específico.

Regras obrigatórias para nome de variáveis
------------------------------------------

  - Devem necessariamente começar com uma letra ou caractere "_" (underscore)
  - Apenas os primeiros 31 caracteres do nome da variável são relevantes
  - As linguagens C/C++ são sensíveis à caixa. Ou seja, para um mesmo 
    caractere, maiúsculo é diferente de minúsculo.
  - Existem palavras reservadas para a sintaxe do código e não podem ser usadas.
    As palavras padrão estão colocadas abaixo:

  alignas, alignof, and, and_eq, asm, auto, bitand, bitor, bool, break, case,
  catch, char, char16_t, char32_t, class, compl, const, constexpr, const_cast,
  continue, decltype, default, delete, do, double, dynamic_cast, else, enum,
  explicit, export, extern, false, float, for, friend, goto, if, inline, int,
  long, mutable, namespace, new, noexcept, not, not_eq, nullptr, operator, or,
  or_eq, private, protected, public, register, reinterpret_cast, return, short,
  signed, sizeof, static, static_assert, static_cast, struct, switch, template,
  this, thread_local, throw, true, try, typedef, typeid, typename, union,
  unsigned, using, virtual, void, volatile, wchar_t, while, xor, xor_eq

Boas práticas para nome de variáveis
------------------------------------

  - Use caixa baixa para variáveis locais
  - Use CAIXA ALTA para variáveis globais
  - Use um nome que represente o seu interesse para a variável, com um
    sentido físico, que sejam pronunciáveis e fáceis de buscar. Evite acentos
    ou caracteres fora da língua inglesa (encode US).

  Referências
  -----------
  - https://cplusplus.com/doc/tutorial/variables/
  - Yang, D. C++ and Object-Oriented Numeric Computing for Scientists and
      Engineers, Springer, 2001.
  - Martin, R. C., The clean code - A Handbook of Agile Software Craftmanship,
      Pearson Education, 2012.
  - http://en.wikibooks.org/wiki/C_Programming/Variables#Data_type_modifiers

 */

#include <iostream>
#include <cstdlib>    // define EXIT_SUCCESS

int main(int argc, char** argv) {

    /*
    * ANÁLISE DOS TIPOS MAIS BÁSICOS
    */

    // declaração de variável caractere
    char name;            // (pelo menos 1 byte ou 8 bits)

    // declaração de variável inteira
    int i;                // (pelo menos 2 bytes ou 16 bits)

    // declaração de variável em ponto flutuante
    // precisão simples (pelo menos 4 bytes ou 32 bits)
    float fpi;            // ~ 6  casas decimais

    // precisão dupla   (pelo menos 8 bytes ou 64 bits)
    double dpi;           // ~ 15 casas decimais

    // booleano
    bool state = true;

    // forma de declaração e inicialização (c-like)
    double dpi1 = 25.4;
    double dpi2 = 2e1;
    double dpi3 = 3.5e-2;

    // outras formas de declarar e inicializar (c++-like)
    // tipo idendificador(valor_inicial) - construtor
    int j(3);

    // tipo identificador {valor_inicial} - inicialização uniforme
    float fli{5.5};

    // operação de atribuição após inicialização
    // atribuindo valores a variáveis
    fpi  = 10.0;
    i    = 2;
    name = 'c';    

    // saída de dados em tela
    std::cout<< "Valor de i    = "<< i << std::endl;
    std::cout<< "Valor de fpi  = "<< fpi << std::endl;
    std::cout<< "Valor de name = "<< name << std::endl;

    // entrada de dados em tela
    std::cout<< "Entre com o novo valor de fpi: ";
    std::cin >> fpi;
    std::cout<< "Este foi o valor digitado? " << fpi << std::endl;

    // teste simples de condição da variável booleana
    if (state) {
        std::cout<<"Se isso aparece na tela, state é true!"<<std::endl;
    }

    return (EXIT_SUCCESS);
}
