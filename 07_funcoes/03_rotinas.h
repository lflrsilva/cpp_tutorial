/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   03_rotinas.h
  Author: lflrsilva

  Rotinas auxiliares para definições em 03_rotinas.cpp.

 */

// Deve-se incluir os cabeçalhos necessários para execução das funções
// repare que o namespace std não foi incluído. Com isso, qualquer
// comando que depende de std deve incluir o namespace como prefixo.
#include <string>

// declaração de prototypes

// Fora do arquivo fonte principal, funções inline só podem ser
// declaradas em arquivos de cabeçalho, junto de sua implementação.
inline std::string concatenate
(
    const std::string& a,
          std::string& b
)
{
    std::string str = a + " " + b;
    //a = "Senhor";     // -- Erro! const!!
    b = "Barriga";
    return str;
}

// função recursiva - o compilador não permite inline
long fatorial(long);

