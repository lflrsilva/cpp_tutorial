/** 

  Este arquivo faz parte dos tutoriais de C++ {{github.com/lflrsilva/cpp_tutorial}}
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   estrutura_codigo.cpp
  Author: lflrsilva


Ambientação no código
---------------------
  
  Em uma programação imperativa, o código pode ser dividido em algumas regiões
  bem características. De fato, a parte onde os principais comandos são
  colocados está dentro da função main(), delimitado pelas chaves {}.

  Na região antes da função main(), declaram-se as bibliotecas, variáveis
  globais, prototypes de funções etc. Seguindo o paradigma imperativo, dentro
  da função main() deve-se declarar as variáveis usadas, executar as instruções
  e, por fim, finalizar o código.

Ambientação no sistema de compilação
____________________________________

 Siga as etapas no terminal, dentro do diretório em que o arquivo fonte se
 encontra. Para esse exemplo, vamos usar o compilador GNU g++, mas o
 procedimento pode ser feito com o compilador clang++.

 1. Compilação do código (criação do objeto)
 ```console
 $ g++ -c nome_arquivo_fonte.cpp
 ```

 2. Linker para criar executável
 ```console
 $ g++ -o nome_app nome_arquivo.o
 ```

 3. Executar aquivo no terminal
 ```console
 $ ./nome_app
 ```

 */

// DECLARACAO DE BIBLIOTECAS
// iostream é usada para operações de entrada e saída de dados (in-out stream)
// em tela. Veja mais em: https://cplusplus.com/reference/iostream/
#include <iostream>


// Inicio do programa principal
int main(int argc, char* argv[]) {

    // Programação Imperativa
    // REGIÃO DE EXECUCAO
    // 1 - DECLARACAO DAS VARIAVEIS USADAS
    // 2 - ESTRUTURA DO CODIGO
    // 3 - FINALIZACAO
    
    //  DECLARACAO DE VARIAVEIS
    /* Descomentar 1
    int i = 1;        // i está declarado como tipo inteiro
    */

    //  ESTRUTURA DO CODIGO
    std::cout<< "Vamos aprender a programar em C++" << std::endl;
    /* Descomentar 2
    std::cout <<"O valor de i eh: " << i << std::endl;
    */
	
//  FINALIZACAO
    return (0);
}
