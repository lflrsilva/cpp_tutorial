## Gerenciador de bibliotecas C/C++ vcpkg

O [vcpkg](vcpkg.io/) é um gerenciador gratuito de pacotes C/C++ desenvolvido pela Microsoft e
que tem o objetivo de fornecer e gerenciar bibliotecas. Conta com mais de 1500 bibliotecas
de código aberto disponíveis para _download_ e compilação/construção em um único passo.
O [vcpkg](https://vcpkg.io/en/getting-started.html) é multiplataforma (Windows, Linux e
macOS) e pode ser instalado em poucos passos, tendo dependência em já ter instalado um
compilador C/C++ (`gcc`) e o gerenciador de versões `git`.

### Por quê o vcpkg?

Uma das grandes vantagens do `vcpkg` está na grande quantidade de pacotes disponíveis e sua
simplicidade de uso. Outra vantagem está na centralização do diretório onde todas as bibliotecas
são colocadas, sempre no diretório de instalação do `vcpkg`. Isso simplifica a busca pelos
cabeçalhos e biblioteca compilada. Por fim, o `cmake`, gerenciador de compilação, e o `CLion`
possuem integração com o `vcpkg`, tornando-o a escolha natural para este curso.

### Vamos instalar um pacote!

Ao instalar, adicione o caminho onde o `vcpkg` está instalado ao $PATH para acesso no terminal.
Senão, pelo terminal, vá ao diretório onde o `vcpkg` está instalado para usá-lo. Como ponto de
partida, verifique as opções de comando disponíveis com:

    vcpkg help

Para testar o gerenciador de pacotes, vamos criar um código C++ que usa uma ferramenta externa
para banco de dados, [SQLite](https://sqlite.org/index.html). Vamos buscar o nome do pacote:

    vcpkg search sqlite

Pelos resultados, verifica-se que o nome do `port` (nome dado a uma biblioteca que foi portado
para um gerenciador de pacotes) é `sqlite3`. Vamos instalar!

    vcpkg install sqlite3

Repare nas últimas linhas na saída do comando. São importantes pois contém a informação usada
para uso da biblioteca no `cmake`.

    The package sqlite3:x86-windows provides CMake targets:

    find_package(unofficial-sqlite3 CONFIG REQUIRED)
    target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3))

Podemos ver todos os `ports` das bibliotecas que estão instalados no momento.

    vcpkg list

### Vamos usar a biblioteca!

Neste caso, vamos usar o `cmake` como o gerenciador de compilação e construção do aplicativo.
O `vcpkg` possui um arquivo que passa ao `cmake` todas as informações necessárias para busca e
uso da biblioteca. Basta incluir essa opção no comando de linha do `cmake`, em que `VCPKG_DIR`
é o diretório onde o `vcpkg` está instalado:

    -DCMAKE_TOOLCHAIN_FILE=VCPKG_DIR/scripts/buildsystems/vcpkg.cmake

Considere o código C++ abaixo (nome do arquivo `main.cpp`) em uma estrutura de projeto do
`cmake`:

    // main.cpp
    #include <sqlite3.h>
    #include <iostream>

    int main()
    {
        std::cout << sqlite3_libversion() << std::endl;
        return 0;
    }

e o arquivo `CMakeLists.txt`:

    # CMakeLists.txt
    cmake_minimum_required(VERSION 3.0)
    project(test)

    find_package(unofficial-sqlite3 CONFIG REQUIRED)

    add_executable(main main.cpp)

    target_link_libraries(main PRIVATE unofficial::sqlite3::sqlite3)

Ok, agora vamos criar o executável (lembre-se de alterar o `VCPKG_DIR` para o diretório onde
o `vcpkg` **está instalado** no seu sistema!)

    mkdir build
    cd build
    cmake .. "-DCMAKE_TOOLCHAIN_FILE=VCPKG_DIR/scripts/buildsystems/vcpkg.cmake"
    make

Basta executar o executável e checar a versão usada do `SQLite`!
