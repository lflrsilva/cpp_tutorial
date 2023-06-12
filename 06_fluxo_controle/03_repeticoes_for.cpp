/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_repeticoes_for.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Uso de repeticoes (lacos)
  - Aplicacao do comando for
  - Interrupcao de laco com break
  - Continuacao do laco com continue

Laços e repetições
------------------
  Sintaxe basica, com base em instruções compostas (não linear):

  for (initialize; condition; expression)
  {
      statement1;
      statement2;
      ...
  }

  Etapas:
  - Inicializa o contador
  - Avalia a condicao de execucao do laco. Executa comandos se true
  - Ao fim da execucao de uma repeticao:
     - excuta expressao
     - avalia condicao
     - Caso condicao seja true, realiza uma repeticao
     - Caso false, executa comando logo apos o laco

  Cuidados:
  - Os 3 argumentos são opcionais. Laço infinito!

 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int i, j, nmax = 10;

    // Avaliação da repetição usando for
    cout << "Inicializa variavel i = 0 dentro do laco\n";
    cout << "Avalia se i < imax para execucao do laco\n";
    for(i=0; i < nmax; i++)
    {
        cout << "Iteracao : " << i << " \t ";
        cout << "Executa expressao i++ : " << i+1 << "\t";
        cout << "Checa condicao i<nmax? : " << (i+1) < nmax << endl;
    }
    cout << endl;

    // Mais um teste
    for(i = 3; i < 50; i *= 2)
    {
        cout << "i = " << i << endl;
    }
    cout << endl;

    // Isso eh executado?
    for (i = 3; i > 5; i *= 2) { cout << i << endl; }
    cout << endl;

    // uso de outras expressoes
    for(i = 10; i > 0; i--)
    {
        cout << i << endl;
    }
    cout << "Feliz Ano Novo!\n";

    // Uso de instruções de salto: continue e break
    for (i = 3; i < 50; i *= 2)
    {
        if (i == 6)
            continue;                   // passa a proxima iteracao quando i == 6

        cout << "i = " << i << endl;    // impressao em tela do valor de i

        if (i == 24)
            break;                      // interrompe laco quando i == 24
    }

    // repetições com instruções combinadas
    for (n = 0, i = 10; i != n; n++, i--) {
        cout << "Valor de n = " << n << endl
             << "Valor de i = " << i << endl;
    }

    return 0;
}

