/** 

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_operadores_aritmeticos.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Treinamento de depuracao
  - Operacoes basicas (+ - * / %)
  - Operacoes com inteiros
  - Operacoes de ponto flutuante
  - Precedencia de operacao
  - Uso de parenteses
  - Biblioteca matemática

Operadores bitwise
------------------
Não vamos explorar os operadores bitwise neste curso, mas vamos discutir um
pouco sobre o assunto. Os operadores bitwise operam individualmente sobre os
bits (0 ou 1) representando uma string, um número, arrays etc. Por exemplo,
uma operação NOT (negação) sobre a representação do decimal 7 em bits:

NOT 0111  (decimal 7)
  = 1000  (decimal 8)

Existem lógicas e algoritmos baseados em operações bitwise que são muito
eficientes e, de modo geral, vale o conhecimento. Contudo, no âmbito de
computação científica, é melhor explorarmos outros assuntos.

Referencias
-----------
  - https://cplusplus.com/doc/tutorial/operators/
  - https://en.cppreference.com/w/cpp/language/operators
  - https://en.wikipedia.org/wiki/Bitwise_operation

 */

#include <iostream>
#include <cmath>

int main(int argc, char** argv) {

    // declaracao de variaveis
    double d = 3.14;
    int n = 2;

    // operacoes entre tipos de variaveis
    int m = d + n;      // m = ?, conversao implicita entre tipos
    double c = d + n;   // c = ?, conversao implicita entre tipos

    // operacao combinada com atribuicao
    double w = 2.0 + (d = 2.0);

    // atribuicao multipla
    c = w = 1.0;

    // atribuição com operador ,
    // as expressões são executadas e apenas a última é atribuída à variável
    double e = (c = 3.0, c + 2.0);

    // operacoes entre inteiros
    double a = 13/4;    // a = ?
    double x = 3/4;     // x = ?
	
	// conversao de tipos de variaveis
    double y = 3.0/4;   // y = 0.75
    double z = 3/4.0;   // z = 0.75
	
	// uso de remainder (%)
    int t = 13%4;       // t = 1, resto de 13/4 eh 1
                        // 12/4 = 3, resta 1
	
	// operacoes compostas
	// execucao da expressao da esquerda para direita
	// precedencia: * ou / e + ou -
	n = 2 + 3*4 - 4/2;
	n = (2 + 3)*4 - 4/2;
	n = 2 + 3*(4 - 4)/2;
	n = 2 + (3*(4 -4)/2);

  // acesso a comandos da biblioteca matemática
  std::cout << "Raiz quadrada de dois = "  << sqrt(2.0) << std::endl;
  std::cout << "Cosseno de menos um   = "  << cos(-1.0) << std::endl;
  std::cout << "Log neperiano de dois = "  << log(2.0) << std::endl;
  std::cout << "Log na base 10 de dois = " << log10(2.0) << std::endl;

    return (0);
}
