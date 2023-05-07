## Vinculando seu programa a bibliotecas externas

A internet amplia a disponibilidade de bibliotecas de códigos em qualquer linguagem
de programação pois qualquer programador pode desenvolver sua própria biblioteca e
disponibilizá-la de modo gratuito ou pago. A oferta de bibliotecas de terceiros é
bem ampla, existindo projetos muito similares entre si. Com isso, a escolha pelo
uso de uma ou outra biblioteca depende da sua escolha pessoal. Contudo, alguns
parâmetros podem afetar essa escolha, como:

- Detalhes para aplicação,
- Maturidade do código,
- Continuidade do desenvolvimento,
- Comunidade de usuários.

Existem sites específicos que servem como repositório de bibliotecas de terceiros,
como [Github](www.github.com), [GitLab](www.gitlab.com),
[Atlassian](www.atlassian.com) entre outros, em que o usuário pode realizar o
_download_, compilar e instalar a biblioteca em seu computador. Outra opção é
instalar os pacotes de desenvolvimento disponíveis pelo gerenciador de programas
do seu sistema operacional, ex. `apt-get`, `brew`, `yum` etc. Por fim, recentemente
foram criados aplicativos específicos para gerenciamento e instalação de bibliotecas
C/C++, inclusive com recursos para criação, compilação, testes etc de projetos
completos. Deste último caso, citam-se [vcpkg](https://vcpkg.io/en/),
[Conan](https://conan.io/), [Spack](https://spack.io/), entre outros.

Independente da escolha em como obter as bibliotecas, os pacotes de desenvolvimento
devem ser instalados no computador, disponibilizando os arquivos de código fonte e
o arquivo compilado da biblioteca. Com isso, você pode vincular o seu código ao
disponibilizado pela biblioteca, passando a usar os comandos e recursos já
implementados.

### Formato das bibliotecas de desenvolvimento

Não existe uma padronização em como os desenvolvedores organizam suas pastas e arquivos
em um projeto. Isso parte muito do gosto pessoal de cada um. Contudo, ao disponibilizar
os códigos como uma biblioteca externa, deve-se esperar que alguns arquivos sejam
facilmente encontrados, como os arquivos de cabeçalho (_headers_) e a biblioteca
compilada. Estes arquivos são necessários para usar e acessar os comandos da
biblioteca.

#### Arquivos de cabeçalho

Os arquivos de cabeçalho em C++ possuem a extensão \*.h, \*.hpp ou \*.hxx. Estes arquivos
contém a **declaração** dos comandos implementados na biblioteca. Portanto, para obter
detalhes sobre o tipo de argumentos e o tipo de retorno que um determinado comando exige
e fornece, o programador sempre pode ver o código implementado nos cabeçalhos.

Por padrão, C++ já fornece acesso a alguns cabeçalhos da biblioteca STL (_Standard
Template Library_ - Biblioteca de Modelos Padrão). Nesse caso, o compilador já está
configurado para identificar os diretórios da STL. Para acesso aos comandos, deve-se
incluir o nome do arquivo cabeçalho entre \<\>:

    #include <biblioteca.h>

Para bibliotecas de terceiros, deve-se indicar ao compilador o diretório onde os cabeçalhos
se encontram no computador. Para uso dos comandos, deve-se incluir o cabeçalho de forma
semelhando ao STL, mas usando \"\".

    #include "biblioteca.h"

#### Biblioteca compilada

Em um projeto de desenvolvimento, é possível compilar e construir um arquivo não executável
chamado biblioteca (_library_). Esse arquivo está com todas as instruções do código, em
linguagem de máquina, mas não é possível executá-lo. Contudo, todas as instruções podem
ser acessadas por um arquivo executável, desde que o mesmo seja construído com vínculo
à biblioteca. Por isso que, no desenvolvimento de um aplicativo que pretende usar uma
biblioteca de terceiros, além dos arquivos de cabeçalho, ainda é preciso indicar o arquivo
da biblioteca compilada.

Para isso, existe um padrão de nome e extensão de arquivos de biblioteca compilada. Apesar
disso, isso depende do sistema operacional.

- Windows : arquivos com extensão \*.lib (bilioteca estática) e \*.dll (biblioteca
  dinâmica)
- macOS : arquivos com extensão \*.a (biblioteca estática), \*.so ou \*.dylib (biblioteca
  dinâmica)
- Linux : arquivos com extensão \*.a (biblioteca estática), \*.so (biblioteca dinâmica)

A diferença entre as bibliotecas estáticas e dinâmicas está na forma com que o executável a
ser criado se conecta a elas. Nas bibliotecas estáticas, as instruções são transferidas para
o executável e passam a ser parte dele. Por sua vez, as bibliotecas dinâmicas mantêm as
instruções em seu arquivo e o executável o acessa sempre que precisar. Em termos práticos,
ao usar as bibliotecas estáticas, o executável final se torna independente pois já
incorporou as instruções necessárias. Contudo, caso seja preciso alterar o código original
da biblioteca estática, o executável final deverá ser compilado novamente. Isso não ocorre
com bibliotecas dinâmicas pois o acesso às instruções e comandos é compartilhado para o
executável final. Só a biblioteca dinâmica deverá ser recompilada.

Além disso, para facilitar a identificação dos arquivos, o Linux e macOS seguem uma
padronização para nomes de bibliotecas: `libNOME.ext`, em que `NOME` é o nome da
biblioteca e `ext` é a extensão.

## Como vincular uma biblioteca ao executável

Tudo parte do processo de compilação e construção do executável, incluindo novos
argumentos. Neste caso, é preciso indicar os diretórios (argumento maiúsculo) ou arquivos
específicos (argumento minúsculo), seja de arquivos de cabeçalho ou de biblioteca.

- Arquivos de cabeçalho : `-i` (indicação de arquivo) e `-I` (busca em diretório)
- Arquivos de biblioteca : `-l` (indicação de arquivo) e `-L` (busca em diretório)

#### Processo de compilação

A compilação deve necessariamente incluir os arquivos de cabeçalho. Afinal, o compilador
precisa entender os argumentos e retornos dos comandos que estão na biblioteca. De forma
simplificada:

    g++ -c main.cpp -IDiretorio_Cabeçalho_Biblioteca

Assume-se que o arquivo `main.cpp` contém a chamada do cabeçalho e está usando comandos da
biblioteca.

#### Processo de construção

A construção deve incluir, além dos arquivos de cabeçalho, o arquivo da biblioteca (estática ou
dinâmica). De forma simplificada:

    g++ -o my_app main.o -IDiretorio_Cabeçalho_Biblioteca -LCaminho_Arquivo_Biblioteca
    -lnome_biblioteca

Note que indicamos duas etapas de busca pelo arquivo da biblioteca. Usando `-L`, indicou-se o
diretório completo onde a biblioteca se encontra e com o argumento `-l` indicou-se o nome da
biblioteca desejada. Isso poderia ser feito usando apenas o argumento `-l`, mas já indicando o
diretório e o nome da biblioteca.
