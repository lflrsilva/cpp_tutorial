/** 

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_tipos_literais.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Criacao de macro usando define
  - Variaveis constantes (const)
  - Constantes literais
  - Detalhes de static, extern, volatile, auto

O que são constantes literais?
------------------------------
  Em uma declaração de identificador (variável), a constante literal é o valor
  que colocamos do lado direito da atribuição.
  
  int i = 5;

  5 representa uma constante literal do tipo inteiro. Para literais em
  ponto-flutuante ainda devemos nos preocupar com a representação da notação
  científica.

  3.14159    // 3.14159
  6.02e23    // 6.02 x 10^23
  1.6e-19    // 1.6 x 10^-19
  3.0        // 3.0

  É possível indicar sufixos aos literais para ser mais explícito no tipo
  desejado. Veja os casos abaixo:

  a. Literais inteiros

  u ou U : unsigned
  l ou L : long
  ll ou LL : long long

  75   : int
  75u  : unsigned int
  75l  : long
  75ul : unsigned long 
  75lu : unsigned long

  b. Literais em ponto-flutuante

  f ou F : float
  l ou L : long double

  3.14159L   : long double
  6.02e23f   : float

  c. Literais de caracteres (c-like)
  Tabela de caracteres especiais iniciados com \. Algumas das combinações já
  estão desabilitadas.

  \n  newline
  \r  carriage return
  \t  tab
  \v  vertical tab
  \b  backspace
  \f  form feed (page feed)
  \a  alert (beep)
  \'  single quote (')
  \"  double quote (")
  \?  question mark (?)
  \\  backslash (\)

  Referencias:
  - https://cplusplus.com/doc/tutorial/constants/
  - http://en.wikibooks.org/wiki/C_Programming/Variables#Data_type_modifiers

 */

#include <iostream>
#include <cstdlib>    // define EXIT_SUCCESS

// Definindo macros (sem ; no final da linha!)
// como a macro está definida antes do main, é tratada de modo global!
// Por isso, recomenda-se nomear usando caixa alta
#define PRECO_DO_OLEO 1000

#define MSG "Deu ruim"

#define IFTRUE if(true) 

int main(int argc, char** argv) {

    // usando literais
    // 3.14L é representado com 10 bytes, mas x só suporta 8 bytes de espaço
    // existe perda na precisão.
    double x = 3.14L;

    // declarando variaveis constantes
    const int i = 10u;

    // nao eh possivel alterar o valor da variavel
    //	 i = 11;

    const double pi = 3.1415926;
    const char newline = '\n';

    // Ao usar a macro, substitui-se sua representação em si
    std::cout << "O preço atual = USD " << PRECO_DO_OLEO << std::endl;
    std::cout << MSG << " para economia mundial." << std::endl;

    IFTRUE {
      std::cout << "Entrei no if" << std::endl;
    }

    // uso de caracteres especiais
    std::cout << "Verificando caracteres especiais" << newline;
    std::cout << "um\ndois\ntrês" << newline;
    std::cout << "um\tdois\ttrês" << newline;
    std::cout << "Estamos \"programando\" muito bem..." << newline;

    return (EXIT_SUCCESS);
}

