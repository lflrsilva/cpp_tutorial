/** 

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   operadores_relacionais.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Treinamento de depuracao
  - Operadores relacionais:
    - Igual a          : ==
    - Maior que        : >
    - Menor que        : <
    - Maior ou igual a : >=
    - Menor ou igual a : <=
    - Nao igual a      : !=
  - Avaliacao de operacoes relacionais

  - Operadores logicos:
    - E   : &&  (o pessimista)
    - OU  : ||  (o otimista)
    - NAO : !
  - Avaliacao de operacoes logicas

  Obs.: Operadores relacionais tem maior precedência em relação aos operadores
  logicos.

 Referencias
 -----------
   - https://cplusplus.com/doc/tutorial/operators/
   - https://en.cppreference.com/w/cpp/language/operators

 */

#include <iostream>

int main(int argc, char** argv) {

		// declaracao de variaveis
		int  a = 10, b = 20;
		bool t1 = true, f1 = false;
		bool t2 = true, f2 = false;

		// operacoes relacionais
		// resultado: true (1) ou false (0)
		int res1  = ( a == b );   // res1 = ?
		bool res2 = ( a > b  );   // res2 = ?
		int res3  = ( a < b  );   // res3 = ?
		bool res4 = ( a >= b );   // res4 = ?
		int res5  = ( a <= b );   // res5 = ?
		bool res6 = ( a != b );   // res6 = ?

		// operacoes logicas
		// resultado: true (1) ou false (0)
		int loc1  = (t1 && t2);   // loc1 = ?
		int loc2  = (t1 && f1);   // loc2 = ?
		bool loc3 = (f1 && f2);   // loc3 = ?

		int loc4  = (t1 || t2);   // loc4 = ?
		int loc5  = (t1 || f1);   // loc5 = ?
		bool loc6 = (f1 || f2);   // loc6 = ?

		bool loc7 = !(t1 || t2);  // loc7 = ?	

		return(0);
}
