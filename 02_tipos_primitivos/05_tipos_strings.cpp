/**
  
  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_tipos_strings.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Cadeia de caracteres: strings

  Referencias:
  - https://cplusplus.com/doc/tutorial/variables/
  - https://cplusplus.com/reference/string/string/

 */

#include <iostream>
#include <string>    // biblioteca para strings

int main(int argc, char** argv) {

    // declaração de string
    std::string my_name;
    my_name = "Luiz Fernando";
    std::cout << my_name << std::endl;

    // declaração e inicialização
    std::string name1 = "Luiz";
    std::string name2 ("Fernando");
    std::string name3 {"Silva"};

    // operação de concatenação
    std::cout << name1 + name2 + name3 << std::endl;

    // concatenação sobre name1
    name1.append(name2);
    name1.append(name3);
    std::cout << name1 << std::endl;

    return (0);
}
