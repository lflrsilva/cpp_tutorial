/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   main_json.cpp
  Author: lflrsilva

  Arquivo teste para uso da biblioteca JSON

Referência
----------
  - https://github.com/nlohmann/json
  - https://json.org/
  - https://medium.com/ml2b/a-guide-to-json-using-c-a48039124f3a

*/

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main() {

    // lendo o arquivo
    std::ifstream f("exemplo.json");
    if (f.is_open()) {

        // passando os dados do arquivo para estrutura de dados json
        json data = json::parse(f);
        std::cout << data << std::endl;

        // acessando itens: [] e .at()
        std::cout << data["nome"] << std::endl;
        std::cout << data.at("feliz") << std::endl;

        std::cout << data["resposta"]["tudo"] << std::endl;
        std::cout << data.at("resposta").at("tudo")
                  << std::endl;

        std::cout << data.at("objeto") << std::endl;

        // alterando valores
        data.at("feliz") = false;

        // ERRO!
//        std::cout << data["resposta"]["tudo"] +
//                data["objeto"]["valor"] << std::endl;

        // Não há suporte para operações aritméticas
        // tudo é tratado como elementos strings do json
        // (não é string padrão). Contudo, é possível a
        // conversão automática entre tipos (pode perder
        // precisão)

        // conversão de tipos: json -> int
        int i = data.at("resposta").at("tudo");
        std::cout << i << std::endl;

        // conversão de tipos: json -> double
        double x = data.at("objeto").at("valor");
        std::cout << x << std::endl;

        // agora eu posso fazer contas
        std::cout << (double)i + x << std::endl;

    } else {
        std::cerr << "Erro ao abrir o arquivo exemplo.json"
                  << std::endl;
    }

    return 0;
}

