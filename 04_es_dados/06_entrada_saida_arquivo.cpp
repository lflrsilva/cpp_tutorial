/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   06_entrada_saida_arquivo.cpp
  Author: lflrsilva

Tópicos abordados
-----------------
  - Bibliotecas para entrada e saída de dados em arquivos
  - Saída de dados em arquivos
  - Entrada de dados em arquivos

Bibliotecas padrão para E/S de dados em arquivo
-----------------------------------------------

  ofstream : classe stream para escrita em arquivos
  ifstream : classe stream para leitura em arquivos
  fstream  : classe para escrita e leitura em arquivos

  Estas classes são derivadas da iostream, mas redirecionam a stream de dados
  para arquivos no computador. Por padrão, os arquivos são formato texto
  simples (mas podem ser outros formatos) e ficam armazenados no diretório
  de execução do aplicativo (pode-se configurar outros diretórios). As regras
  de formatação de dados são as mesmas que os comandos cout e cin.

  Como primeira etapa, deve-se declarar uma variável de controle das operações
  com associação a um arquivo real.

  ofstream arq;

  A partir dessa variável, é possível abrir o stream de dados para escrita ou
  leitura (ou ambos).

  arq.open(nome_arquivo, mode);

  em que nome_arquivo é uma string com o nome do arquivo (incluindo sua
  extensão) e mode é um parâmetro de definição dos tipos de operação.
  Algumas das opções de mode são:

  - ios::in     : aberto para operações de leitura (entrada de dados)
  - ios::out    : aberto para operações de escrita (saída de dados)
  - ios::binary : arquivo em formato binário
  - ios::app    : operações realizadas ao fim do arquivo (append)
  - ios::trunc  : se o arquivo está aberto para escrita e já existe, seu
                  conteúdo existente é apagado e substituído pelo novo.

  É possível combinar mais de uma opção mode usando operador bitwise OR (|).

  arq.open("meu_arquivo.txt", ios::out | ios::app | ios::binary);

  O retorno da operação de abertura do stream pode ser true ou false, dependendo
  de seu sucesso. Portanto, é possível usar uma lógica condicional atrelada à
  abertura do arquivo.

  São muitas opções para leitura e escrita em arquivos e recomendo a leitura do
  manual. Algumas opções podem checar se o processo de leitura/escrita está aberto
  e o programador tenta realizá-lo mesmo assim. Uma outra opção pode identificar a
  posição interna (linha e coluna) no arquivo para realizar a escrita/leitura.

  Ao finalizar as operações, deve-se fechar o stream de dados.

  arq.close();

  Ao realizar a operação acima, o sistema operacional é notificado e disponibiliza
  os recursos novamente para uso. O comando acima também indica a disponibilidade
  de reabrir o stream em outra condição ou com outro arquivo.

Referências
-----------
  - https://cplusplus.com/doc/tutorial/files/
  - Yang, D. (livro)

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    // declaração de variáveis
    string nome = "Seu Madruga";
    unsigned short int idade = 58;

    // definindo e abrindo stream para saída
    ofstream my_stream("file_out.txt", ios::out);
    if(my_stream.is_open()) {

        // realizando as operações
        my_stream << "Estou escrevendo no arquivo!\n";
        my_stream << "A idade do " << nome << " eh "
                  << idade << "\n";
        my_stream.close();

    } else {
        // caso de erro, aviso o usuário
        cerr << "Erro ao abrir arquivo out!" << endl;
    }

    // declaração de variáveis
    double p, T;
    string dados;

    // definindo e abrindo stream para entrada
    ifstream my_data("file_in.txt", ios::in);
    if(my_data.is_open()) {

        // realizando as operações
        my_data.ignore(80,'\n');        // ignorando a primeira linha
        getline(my_data, dados, '\n');  // capturando a linha até '\n'
        p = atof(dados.c_str());        // string -> float

        my_data.ignore(80,'\n');        // ignorando a terceira linha
        getline(my_data, dados, '\n');  // capturando a linha até '\n'
        T = atof(dados.c_str());        // string -> float

        my_data.close();

        // reportando ao usuário os dados lidos
        cout << "p = " << p << " Pa" << endl;
        cout << "T = " << T << " K"  << endl;

    } else {
        // caso de erro, aviso o usuário
        cerr << "Erro ao abrir arquivo in!" << endl;
    }

    return 0;
}
