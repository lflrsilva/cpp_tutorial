## Biblioteca nlohmann json

A biblioteca de código aberto [JSON for Modern C++](https://github.com/nlohmann/json)
é uma entre tantas bibliotecas de manipulação de dados em formato
[JSON](https://www.json.org/json-en.html) (_JavaScript Object Notation_). A escolha em
apresentar justamente essa biblioteca foi motivada por:

- Apresentar sintaxe intuitiva
- Integração trivial ao seu programa
- Muitos testes de execução (eficiência e gerenciamento de memória)

A integração da biblioteca é muito simples pois basta copiar o arquivo de cabeçalho e
compilar junto do seu arquivo principal. Não é preciso realizar o _link_ com um
arquivo de biblioteca (estática ou dinâmica). Portanto, você pode copiar os arquivos
cabeçalho do diretório `json/include/` e usá-los de forma direta no seu
desenvolvimento. Uma outra opção é usar o `vcpkg` para isso.

### Instalação com vcpkg

O `vcpkg` possui a biblioteca `nlohmann-json`, que pode ser instalada
de forma direta.

    vcpkg install nlohmann-json

As instruções para incluir a biblioteca no sistema de compilação usando o `CMake`
são:

    The package nlohmann-json provides CMake targets:

        find_package(nlohmann_json CONFIG REQUIRED)
        target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

    The package nlohmann-json can be configured to not provide implicit conversions via a custom triplet file:

        set(nlohmann-json_IMPLICIT_CONVERSIONS OFF)
