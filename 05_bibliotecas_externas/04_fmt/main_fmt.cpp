/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   main_fmt.cpp
  Author: lflrsilva

  Arquivo teste para uso da biblioteca fmt

Referência
----------
  - https://github.com/fmtlib/fmt

*/

#include <fmt/core.h>
#include <fmt/color.h>   // ativando CORES!!
#include <string>

int main() {

  // saída em tela
  fmt::print("Gostei do fmt!\n");

  // uso do identificador {}
  fmt::print("O valor eh {}!\n", 42);

  // podemos indicar a ordem de saída
  fmt::print("É melhor estar {1} do que {0}.\n", "certo", "feliz");

  // formatando diretamente uma string
  std::string str = fmt::format("Meu numero preferido eh {}!", 42);
  fmt::print("{}\n", str);

  // cores e caracteres especiais!!!
  fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
             "Oie, {}!\n", "pessoal");
  fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
             fmt::emphasis::underline, "Oie, {}!\n", "мир");
  fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
             "Oie, {}!\n", "世界");

  // O que mais tem:
  // - saída em arquivo (muito, muito fácil)
  // - formatação de dados numéricos (inteiros e ponto flutuante)
  // - alinhamento de texto
  // - muito mais coisas...

  return 0;
}
