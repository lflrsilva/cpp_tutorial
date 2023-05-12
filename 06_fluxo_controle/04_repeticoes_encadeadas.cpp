/** 

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   repeticoes_encadeadas.cpp
  Author: lflrsilva

  Topicos abordados:
  - Uso de repeticoes encadeadas
  - Aplicacao de comandos encadeados

  Sintaxe basica:
 
  for (i=0; i<=5; i++)
  {
      statement1;
      ...
      for(j=0;j<=3; j++)
      {
          statement2;
          ...
      }
      statement3;
      ...
  }

  Cuidados:
  - Contadores nos lacos interno e externo
  - Uso de break e continue
 
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    int levels, space;

    // construindo uma piramide
    cout <<"Entre com o numero de niveis na piramide: ";
    cin  >> levels;
 
    space = levels;
 
    for (int i = 1 ; i <= levels ; i++ )
    {
        for (int k = 1 ; k < space ; k++ )
        {
            // escrevendo espacos em tela ate coluna = nivel -1
            cout << " ";
        }
        
        space--;
 
        for (int k = 1 ; k <= 2*i - 1 ; k++ )
        {
            // construindo a piramide
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
