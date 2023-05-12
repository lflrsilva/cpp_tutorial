## Biblioteca Matplot++

A biblioteca de código aberto
[Matplot++](https://alandefreitas.github.io/matplotplusplus/) fornece uma
variedade de opções para visualização de dados, com diferentes formatos de plots
com alta qualidade de resolução.

### Instalação com vcpkg

O `vcpkg` possui a biblioteca `matplotplusplus`, que pode ser instalada
de forma direta.

    vcpkg install matplotplusplus

As instruções para incluir a biblioteca no sistema de compilação usando o `CMake`
são:

    find_package(matplot++ CONFIG REQUIRED)
    target_link_libraries(main PRIVATE Matplot++::cimg
                                       Matplot++::matplot
                                       Matplot++::nodesoup)
