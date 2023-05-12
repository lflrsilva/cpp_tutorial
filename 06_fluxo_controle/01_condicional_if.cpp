/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   condicional_if.cpp
  Author: lflrsilva

  Topicos abordados:
  - Uso de condicionais
  - Aplicacao do condicional if
  - Condicional composto if-else
  - Condicional composto if-else if-else

  Sintaxe do condicional:

	if(boolean_expression)
	{
	    comando(s) executados SE a expressao booleana for true
	}
	else
	{
	    comando(s) executados SE a expressao booleana for false
	}

 */

#include <iostretam>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    int  n = 2, r;
    float x = 2.0;
    float y = 4.0;
    float Small;

    // Todos os comandos if serão avaliados
    if (n > 0) x *= 10;    // se n > 0, execute x *= 10

    if (n == 0) {         // se n seja igual a 0, execute x *= 5
        x *= 5;
    }

    if (n) y *= 7;        // se n != 0 (true), execute y *= 7

    // Cuidados com o uso de condicionais

     // Comparação de valores em ponto flutuante
    x = 0.3333;
    y = 1./3.;

    if(x == y)
    {
        cout << "Será q serei executado?\n";
    }

    Small = 1.e-4;
	  // fabs() retorna o valor absoluto do argumento (cmath)
    if(fabs(x-y) <= Small)
    {
        cout << "Beleza, entrei no condicional\n";
    }

    // Uso do IF-ELSE
    // x = 0.;
    if(x == 0)
    {
        cout << "Cuidado com divisao por zero\n";
    }
    else
    {
        y /= x;
    }

    /* IF-ELSE encadeado
     *
     *  if (condition1) statement1
     *  else if (condition2) statement2
     *  else if (condition3) statement3
     *  else statement4
     *
     *  A condicao seguinte so sera avaliada se a anterior for FALSA.
     */
    if (x > 0) {

        cout << "x é positivo!" << endl;

    } else if (x < 0) {

        cout << "x é negativo!" << endl;

    } else {

        cout << "x é 0" << endl;

    }

    return 0;
}

