/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_definicao_rotinas.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Conceitos sobre funções e subrotinas
  - Sintaxe e passagem de dados
  - Formas de passagem e retorno de dados
  - Argumentos com valores padrão
  - Funções inline

Sub-rotinas
-----------

  Estrutura modular no desenvolvimento do código, usando códigos auxiliares
  chamados funções ou sub-rotinas. As instruções sera executadas em uma
  estrutura independente do código principal ( main() ). Portanto, o
  código principal deve enviar informações para a sub-rotina. Por sua vez,
  ao finalizar suas operações a sub-rotina deve retornar o resultado para
  o código principal.

  A definição geral de subrotinas segue abaixo:

  tipo_retorno nome_funcao ( lista_parametros )
  {
      comandos dentro da sub-rotina
      ...

      return variavel_tipo_retorno
  }

  - tipo_retorno: a sub-rotina deve retornar um valor ao código principal.
    Define-se o tipo da variável a ser retornada. Caso não se deseje retornar
    nenhuma informação, utiliza-se void.

  - nome_funcao: auto-explicativo

  - lista_parametros: Valores no código principal não são conhecidos pela
    sub-rotina. Assim, deve-se passar as variáveis necessárias para executar
    os comandos dentro da sub-rotina.

  - comandos: auto-explicativo

  Obs.: Caso se implemente algo após o retorno da subrotina, ainda em seu escopo,
  os comandos nunca serão executados. Afinal, o escopo voltou ao nível anterior
  (programa principal, caso a função seja chamada em main()).

  Ex.: www.tutorialspoint.com

	// function returning the max between two numbers
	int max(int num1, int num2)
	{
	   // local variable declaration
	   int result;

	   if (num1 > num2)
	      result = num1;
	   else
	      result = num2;

	   return result;
	}

Declaração de subrotinas : prototypes
-------------------------------------

  As rotinas podem ser escritas diretamente no arquivo fonte do
  código principal ou em um arquivo em separado. Quando escritas
  em arquivo separado ou apos o main(), deve-se declará-las
  (prototype). A declaração de sub-rotinas deve conter:

  tipo_retorno nome_funcao ( lista_parametros );

  Ex.: www.tutorialspoint.com

  Pode-se declarar a funcao acima como:

  int max(int num1, int num2);

  Não é necessário explicitar o nome das variáveis, apenas o
  tipo das variáveis que serão passadas para a subrotina.

  int max(int, int );

  Mais exemplos de prototype:

  int square(int);             // recebe int, retorna int
  double sum(double,double);   // recebe 2 double, retorna 1 double
  int f();                     // não recebe nada, retorna int
  void g(double,double);       // recebe dois double, não retorna nada

Valor padrão de argumento
-------------------------

  Na declaração da subrotina, é possível indicar valores padrão para os
  argumentos. Nesse caso, se o programador não indicar um valor ao
  chamar a subrotina, o valor padrão será usado.

  int divisao(int a, int b = 2) {

      int r;
      r = a/b;

      return r;
  }

  No programa principal:

  divisao(12);     // apenas a é indicado, b = 2
  divisao(12, 3);  // a e b são indicados

Funções inline
--------------

  A chamada de subrotinas pode causar uma certa sobrecarga de processamento
  (organizar os argumentos, manipulação das chamadas etc). Para funções bem
  simples, seria muito mais eficiente simplesmente colocar os comandos onde
  a função seria chamada do que formalizar todo procedimento de chamada da
  subrotina em si.

  Nessa situação, o programador pode sugerir ao compilador que tente otimizar
  o código e apenas use uma expansão dos comandos nos locais de chamada da
  subrotina ao invés de alocar todo mecanismo convencional de chamada de
  subrotinas. Basta declarar a subrotina como inline.

  inline int soma(int a, int b) {
      return a + b;
  }

  Note que se trata de uma sugestão ao compilador! O compilador irá analisar
  se aplica a declaração inline ou não. Por que não coloco a declaração inline
  em todas as funções? Isso se aplica apenas para funções bem triviais e, caso
  faça isso em todas as funções, você vai aumentar o esforço de compilação.

  Obs.: inline deve ser colocado apenas na declaração da função. Caso a
  implementação da funções esteja em outro local do código, não se deve
  indicar inline novamente.

  Obs.: Mas o que seria uma função bem simples? O guia de recomendações para
  C++ da Google indica que são funções com 10 linhas ou menos. Deve-se tomar
  cuidado com as instruções que estão dentro da subrotina inline. No caso de
  repetições, existe um esforço associado em que não compensa o uso de inline.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/functions/
  - https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
  - https://google.github.io/styleguide/cppguide.html

 */

#include <iostream>
#include <cstdlib>

// *********************
// Declaração e implementação de subrotinas
inline int soma(int a = 20, int b = 10) {
    return a + b;
}

inline void msg(void) {
    std::cout << "Função eh um bagulho louco!" << std::endl;
}

// Declaração de prototype
// necessário para subrotinas implementadas em outra região do código
// Basta indicar os tipos dos argumento e retorno
inline int max(int, int);

// *********************

// ----------------------
// Início do programa principal
int main(int argc, char** argv) {

    // declaração das variáveis em main()
    int a = 100;
    int b = 200;
    int ret;

    // chamada da função soma
    std::cout << "Soma de " << a << " + " << b << " = "
              << soma(a, b) << std::endl;

    // usando argumento padrão
    std::cout << "Soma de 20 + 10 = " << soma() << std::endl;

    // chamada de função sem argumentos e retorno
    msg();

    // chamando a função para obter o valor máximo
    ret = max(a, b);

    std::cout << "Valor maximo eh : " << ret << "\n";

    return (EXIT_SUCCESS);
}
// Fim do programa principal
// ----------------------

// ***********************
// implementação da função int max(int, int)
// inline é colocado na declaração da função
int max(int num1, int num2)
{
    //variável local
    int result;

    if (num1 > num2) {
        result = num1;
    } else {
        result = num2;
    }

    return result;
}
