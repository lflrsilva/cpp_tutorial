/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   01_entrada_saida_basico.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Entrada e saída de dados em tela
  - Saída de dados
  - Entrada de dados

Entrada e saída de dados
------------------------
  A entrada e saída de dados em C++, seja por tela, teclado ou arquivo, usa uma
  abstração chamada stream. Uma stream é uma entidade em que um programa pode
  inserir ou extrair caracteres. Não há necessidade de conhecer todos os
  detalhes sobre streams, mas entenda como uma fonte ou destino de caracteres
  fornecidos de modo sequencial. Os comandos de entrada e saída estão
  declarados no namespace std.

  Por padrão, existem os objetos básicos para manipular streams:

  - cin  : entrada de stream padrão
  - cout : saída de stream padrão
  - cerr : erro (saída) de stream padrão
  - clog : log (saída) de stream padrão

  Vamos explorar em detalhes cin e cout. Os objetos cerr e clog, na prática,
  tem o mesmo comportamento de cout, mas com propósitos diferentes: mensagem
  de erro e de registro de dados.

Saída de dados em tela
----------------------
  O comando cout é usado com o operador de inserção, <<.

  cout << "saindo com dados em tela";   // imprime sequencia em tela
  cout << 120;                          // imprime 120 em tela
  cout << x;                            // imprime o valor de x em tela

  Entenda o operador << como se inserisse na stream os dados que o precedem.
  Por sua vez, cout leva a stream para tela.

  Vale mencionar que o C++ tem um manipulador de stream endl, que insere o
  caractere '\n' para pular linha.

  cout << "Vamos pular a linha agora" << endl;

  Contudo, existe uma diferença entre usar endl e adicionar manualmente o
  '\n'. O manipulador endl obriga que o buffer da stream seja descarregado,
  ou seja, requer que a saída seja fisicamente concluída na tela. Portanto,
  para códigos em que a interrupção da execução para saída em tela é uma
  feature (característica) requerida, recomenda-se o uso de endl. Senão,
  '\n' é preferido.

Entrada de dados em tela
----------------------
  O comando cin é usado com o operador de extração, >>, cuja operação só é
  concluída após a tecla ENTER (ou RETURN) ser pressionada. O comando extrai
  a informação da tela e a insere na variável desejada.

  int i;
  cin >> i;

  Note que a inserção do dado de acordo com o tipo da variável é importante!
  Caso isso não seja respeitado, a operação falha e o programa continua sem
  definir a variável. Esse é o comportamento padrão de C++ mas que pode levar
  a comportamentos inesperados. Apenas códigos muito simples devem confiar
  em dados extraídos por cin sem checar.

  É possível encadear a entrada de dados.

  cin >> a >> b;

  Qualquer caractere espaço entre os dois valores pode ser usado como
  separação (espaço, TAB ou ENTER).

 Referências
 -----------
   - https://cplusplus.com/doc/tutorial/basic_io/

*/

#include <iostream>

int main(int argc, char** argv) {

    int k;
    std::cout << "Entre com o valor de k : ";
    std::cin  >> k;
    std::cout <<"Olá mundo! \n Esse é o valor de k : "
      << k << std::endl;

    return 0;
}
