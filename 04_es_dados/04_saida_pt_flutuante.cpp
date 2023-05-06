/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   04_precisao_pt_flutuante.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Saída em tela de ponto flutuante (ios_base::floatfield)
  - Formato e precisão na saída de dados

Formatos em ponto flutuante
---------------------------
  Em todos os formatos, a opção de precisão sempre define o número de casas
  decimais após a casa decimal. Para saída de ponto flutuante, pode-se usar:

  - general    : formato que melhor mantém o espaço disponível na página. Esse
                 é o formato padrão.
  - scientific : formato com um dígito antes da casa decimal e expoente.
  - fixed      : formato com um número (n dígitos) antes da casa decimal e uma
                 parte fracionada depois da casa decimal.

  Em todos os casos, a formatação de precisão NÃO representa a precisão usada
  em cálculos de expressões.

 */

#include <iostream>
#include <cmath>    // leia abaixo

// vc sabia que o namespace já inclui o cmath? Mesmo assim, sempre declare a
// biblioteca que efetivamente quer usar. Isso é fundamental para consciência
// que o bom programador deve ter sobre os recursos que efetivamente quer usar.
using namespace std;

int main(int argc, char** argv) {

    float fpi = atan(1)*4;         // precisão simples    ~ 7  digitos
    double dpi = atan(1)*4;        // precisão dupla      ~ 14 digitos
    long double ldpi = atan(1)*4;  // precisão estendida  ~ 17 digitos

    // formato padrão
    cout << "O valor de dpi eh (padrão): " << dpi << endl;

    // definindo formato scientific
    cout.setf(ios_base::scientific, ios_base::floatfield);
    cout << "O valor de dpi eh (científico): " << dpi << endl;

    // definindo formato fixed
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "O valor de dpi eh (fixo): " << dpi << endl << endl;

    // Formatando a precisão na saída de dados em tela
    cout.setf(ios_base::left, ios_base::adjustfield);
    cout.precision(7);
    cout << "Com 7 casas decimais :" << endl;
    cout << "O valor de fpi eh:  " << fpi  << endl;
    cout << "O valor de dpi eh:  " << dpi  << endl;
    cout << "O valor de ldpi eh: " << ldpi << endl << endl;

    cout.precision(14);
    cout << "Com 14 casas decimais :" << endl;
    cout << "O valor de fpi eh:  " << fpi  << endl;
    cout << "O valor de dpi eh:  " << dpi  << endl;
    cout << "O valor de ldpi eh: " << ldpi << endl << endl;

    cout.precision(30);
    cout << "Com 30 casas decimais :" << endl;
    cout << "O valor de fpi eh:  " << fpi  << endl;
    cout << "O valor de dpi eh:  " << dpi  << endl;
    cout << "O valor de ldpi eh: " << ldpi << endl << endl;

    // bonus round - showpoint para mostrar ou não em tela a separação decimal,
    // quando for possível
    // voltando às opções padrão
    cout.setf(0, ios_base::adjustfield);
    cout.setf(0, ios_base::floatfield);

    double a = 30;
    double b = 10000.0;
    double pi = 3.1416;
    cout.precision(5);
    cout << showpoint   << a << '\t' << b << '\t' << pi << endl;
    cout << noshowpoint << a << '\t' << b << '\t' << pi << endl;

    return 0;
}

