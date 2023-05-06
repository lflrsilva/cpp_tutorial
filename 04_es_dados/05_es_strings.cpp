/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   05_es_strings.cpp
  Author: lflrsilva

Topicos abordados
-----------------
  - Entrada e saída de caracteres e strings em tela
  - Comandos avançados

Referências
-----------
  - https://cplusplus.com/reference/string/string/
  - https://cal-linux.com/tutorials/strings.html
  - https://cplusplus.com/reference/ostream/flush-free/
  - https://cplusplus.com/reference/streambuf/basic_streambuf/
  - https://cplusplus.com/reference/string/string/replace/

*/

#include <iostream>
#include <typeinfo>   // typeid()
#include <string>
#include <sstream>    // stringstream()

using namespace std;

int main(int argc, char** argv) {

    // declaracao de variaveis
    string nome;

    // lendo a string até atingir um separador de texto (espaço, vírgula,
    // tab etc). Comando flush para associar o espaço disponível em página,
    // com algum stream buffer (corrente de dados - no caso, o cin).
    cout << "Entre com o seu nome : " << flush;
    // cin >> nome;

    // OU use uma função para captura da linha toda como um único string
    getline(cin, nome);

    cout << "Obrigado, " << nome << ", por executar este programa."
         << endl;

    // vamos incluir o sobrenome
    string nome_meio = "Racha";
    string nome_familia = "Cuca";

    string nome_completo = nome + " " + nome_meio + " " + nome_familia;
    cout << "Nome completo é "
         << nome_completo << endl;

    // vamos começar a realizar algumas verificações na string
    cout << "Quantas letras tem no nome de família \""
         << nome_familia << "\"? "
         << nome_familia.length() << endl;

    cout << "Em que posição da string está o início do nome \""
         << nome_familia << "\"? "
         << nome_completo.find(nome_familia)<< endl;

    // L u i z . F e r n a n  d  o  .  R  a  c  h  a  .  C  .....
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 .....

    // Vamos substituir o sobrenome por "Chapolin Colorado"
    cout << nome_completo << endl;

    int posicao = nome_completo.find(nome_meio);
    string novo_nome("Chapolin Colorado");

    cout << nome_completo.replace
      (
          posicao,            // posição para iniciar mudança
          novo_nome.length(), // qtos carac vamos alterar
          novo_nome           // nova string
      )
      << endl;

    // Cuidado! A função getline sempre se aplica a strings!
    string str;
    int idade = 0;
    cout << "Entre com sua idade : ";
    getline(cin, str);

    // vamos usar a stream de dados para direcionar a uma variável
    stringstream(str) >> idade;

    cout << idade << typeid(idade).name() << endl;

    return 0;
}
