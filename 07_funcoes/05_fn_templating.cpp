/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_fn_templating.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Conceitos sobre funções template
  - Tipos genéricos typename e class em funções template

Funções template
----------------

  Considere a situação em que se deseja sobrecarregar uma função de mesmo
  nome para realizar determinada operação de acordo com o tipo de argumento.

  int sum (int a, int b) { return a+b; }

  double sum (double a, double b) { return a+b; }

  Para o exemplo de sobrecarregamento de funções acima, a operação de soma é a
  mesma, alterando apenas o tipo de retorno. Para mais situações como essa,
  basta que o programador sempre inclua a implementação do sobrecarregamento.
  Mas imagine ter muitas situações... Será necessário implementar todas elas?

  Declaração de templates
  -----------------------
  Para esse caso, C++ permite a implementação usando templates com tipos
  genéricos. Para tal, o identificador template deve ser usado e < > para
  inclusão dos argumentos do template.

  template < args_template > decl_funcao( args_funcao )

  Os argumentos com tipos genéricos do template também serão usados nos
  argumentos da função, generalizando, de fato, sua aplicação. Os tipos
  genéricos são especificados com typename ou class (são sinônimos no
  contexto de funções template).

  template <typename tipo_geral>
  tipo_geral sum (tipo_geral a, tipo_geral b) { return a+b; }

  No exemplo acima, tipo_geral pode representar qualquer tipo de variável
  definido no código.

  Instanciação de templates
  -------------------------
  Instanciar um template significa aplicar as regras do template indicando
  os tipos ou valores a serem usados. Na verdade, segue o mesmo princípio
  de chamar uma função, mas usando < > para incluir seus argumentos.

  x = sum<int>(10, 30);

  Os templates podem ser implementados de diferentes formas, aumentando
  muito as possibilidades no tratamento de dados e algoritmos.

  Templates com argumento non-type
  --------------------------------
  São várias as possibilidades de uso dos templates. Em especial, no
  tratamento dados aos argumentos de template, < >. Por exemplo, é
  possível usar os argumentos diretamente na função, sem passar pelos
 argumentos da função em si. São muitas combinações e possibilidades.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/functions2/
  - https://google.github.io/styleguide/cppguide.html

 */

#include <iostream>

// template usando typename
template <typename T>
T soma(T a, T b) {
    T res;
    res = a + b;
    return res;
}

// template usando class
template <class L, class R>
bool sao_iguais(L a, R b) {
    return (a == b);
}

// template com argumento non-type
template <typename T, int N>
T multiplo_fixo (T valor) {
    return valor * N;
}

int main(int argc, char** argv) {

    int xi = 2, yi = 3, resi;
    double xd = 2.5, yd = 3.5, resd;

    // chamada da função soma (int)
    resi = soma<int>(xi, yi);
    std::cout << resi << std::endl;

    // chamada da função soma (double)
    resd = soma<double>(xd, yd);
    std::cout << resd << std::endl;

    // análise de condicional
    if ( sao_iguais<int, double>(resi, resd) ) {
        std::cout << "argumentos iguais" << std::endl;
    } else {
        std::cout << "argumentos diferentes" << std::endl;
    }

    // template non-type
    std::cout << multiplo_fixo<int, 3>(10) << std::endl;
    std::cout << multiplo_fixo<int, 5>(10) << std::endl;

    return 0;
}
