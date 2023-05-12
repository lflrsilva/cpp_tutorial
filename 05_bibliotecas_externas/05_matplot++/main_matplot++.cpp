/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   main_matplot++.cpp
  Author: lflrsilva

  Arquivo teste para uso da biblioteca Matplot++

Referência
----------
  - https://alandefreitas.github.io/matplotplusplus/

*/

#include <cmath>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;

    // criando lista de pontos [0, 2*pi]
    std::vector<double> x = linspace(0, 2 * pi);

    // calculando expressões com lista de pontos
    std::vector<double> y1 = transform(x, [](double x) { return 5 * sin(x); });
    std::vector<double> y2 = transform(x, [](double x) { return sin(5 * x); });

    // ajustando layout dos gráficos - 2 linhas, 1 coluna
    tiledlayout(2, 1);

    // instância do primeiro gráfico
    auto ax1 = nexttile();
    stairs(ax1, x, y1);

    // instância do segundo gráfico
    auto ax2 = nexttile();
    stairs(ax2, x, y2);

    show();
    return 0;
}

