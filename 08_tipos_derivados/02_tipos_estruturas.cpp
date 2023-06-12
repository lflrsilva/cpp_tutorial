/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   02_tipos_estruturas.cpp
  Author: lflrsilva

  Tópicos abordados
  -----------------
  - fundamentos de estruturas
  - sintaxe de estruturas

  Definicao de outros tipos de dados:

  Uso de estruturas - eh uma colecao de variaveis referenciadas por
  um unico nome. Desta forma, as informacoes podem ser agrupadas em
  forma estruturada.

  // definicao
  struct nome_estrutura {     // nome_estrutura eh o identificador
      double variavel1;       // as variaveis sao os campos da
      tipo variavel2;         // estrutura
  };

  // declaracao
  nome_estrutura e1;     --> declaracao no programa principal

  // acesso as variaveis
  e1.variavel1 = 3.0;    --> acesso a variavel dentro da estrutura

 */

#include <iostream>
#include <string>

int main(int argc, char** argv) {

    //declaracao da forma da estrutura
    struct tanque {
        std::string nome;   // nome na planta
        int   id ;          // id na planta
        double V;           // volume (m^3)
        double F[2];        // vazao vol. in-out (m^3/s)
    };

    struct ponto3d {
        double x;
        double y;
        double z;
    };

    int i;
    double t, dt;
    struct tanque t1;     // declaracao da estrutura do tipo tanque
    struct tanque t2[2];  // declaracao de array de tanque

    // declaracao com inicializacao
    // struct ponto3d pto = {1.0,2.0,3.0};
    struct ponto3d pto {1.0,2.0,3.0};
    std::cout << "Inicializamos: " << pto.x
                                   << pto.y
                                   << pto.z << "\n";

    // iniciar variaveis
    t1.nome = "tambor_alimentacao";
    t1.id   = 1;
    t1.V    = 10.0; // volume inicial do tanque
    t1.F[0] = 0.0;  // sem vazao de entrada
    t1.F[1] = 0.1;  // vazao de saida

    t2[0]   = t1;   // Inicializa todas as variaveis
                    // de t2[0] como t1
    t2[0].id = 2;   // Id tem que ser outro...

    t2[1].nome = "reator_mistura";
    t2[1].id   = 3;
    t2[1].V    = 0.0;   // volume inicial

    // vazao de saida dos outros tanques
    t2[1].F[0] = t1.F[1] + t2[0].F[1];
    t2[1].F[1] = 0.0;  // vazao de saida

    // Enchimento do reator mistura
    t  = 0.0;
    dt = 0.1;  // passo de tempo
    std::cout << "t \t V\n";
    std::cout << t <<"\t"<< t2[1].V << std::endl;

    for(i = 0; i < 10; i++)
    {
        t2[1].V += t2[1].F[0] - t2[1].F[1];
        t       += dt;
        std::cout << t <<"\t" << t2[1].V << std::endl;
    }

    return 0;
}
