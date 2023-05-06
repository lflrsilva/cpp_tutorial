/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_saida_dados_formatada.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Saída formatada de dados
  - Formatacao de inteiros (ios_base::basefield)

Saída formatada de dados
------------------------
  Comandos de formatação <ios>:<ios_base> :

  - cout.width() para retorno do número de caracteres que compõe a espessura de
    página. Padrão 0, adaptando a saída de dados conforme a necessidade.
  - cout.width(unsigned int) para definir o número de caracteres para espessura
    de página.
  - Manipuladores left, right e internal para alinhamento de texto.
  - Função fill(char) para preencher os espaços restantes na linha.
  - Função setf(format flags) para definir o ajuste de texto (adjustfield),
    sistemas numéricos (basefield) e formato de ponto-flutuante (floatfield).

Formatação de inteiros
----------------------
  A saída de inteiros pode ser formatada no sistema decimal, octal e
  hexadecimal.

  - Base 10 (decimal)     : representa qualquer número usando 10 dígitos [0-9]
  - Base 2 (binário)      : representa qualquer número usando 2 dígitos [0-1]
  - Base 8 (octal)        : representa qualquer número usando 8 dígitos [0-7]
  - Base 16 (hexadecimal) : representa qualquer número usando 10 dígitos e
                            6 caracteres [0-9, A, B, C, D, E, F]

  Os dois últimos sistemas estão ligados ao modo com que o processador lida com
  os dados em memória. Contudo, para nossa prática, o sistema decimal é o mais
  usado.

 Referências
 -----------
   - https://cplusplus.com/reference/ios/
   - https://cplusplus.com/reference/ios/ios_base/setf/
   - https://x-engineer.org/numbers-representation-systems-decimal-binary-octal-hexadecimal/
   - https://medium.com/coderscorner/number-systems-decimal-binary-octal-and-hexadecimal-5e567e55ab28

 */

#include <iostream>

int main(int argc, char** argv) {

    // declaracao de variaveis
    int i = 1711;
    long int imax = 2147483644;
    float f = 3.7182;
    double d = 3.1415926535;

    // Formatação simples
    std::cout << std::cout.width() << '\n';
    std::cout << 100 << '\n';
    std::cout.width(10);
    std::cout << 100 << '\n';
    std::cout.fill('x');
    std::cout.width(15);
    std::cout << std::left << 100 << '\n';

    // Configurando saída formatada de inteiros (basefield)
    std::cout.setf(std::ios_base::dec, std::ios_base::basefield);    // decimal
    std::cout << i << std::endl;
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);    // hex
    std::cout << i << std::endl;

    std::cout.setf(0, std::ios_base::basefield);   // volta ao padrão
    std::cout.width(5);
    std::cout << imax << std::endl;

    return 0;
}
