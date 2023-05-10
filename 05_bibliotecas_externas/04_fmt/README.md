## Biblioteca fmt

A biblioteca de código aberto [fmt](https://github.com/fmtlib/fmt) fornece uma
alternativa eficiente e segura para as operações de saída de dados formatada em
relação ao disponibilizado por `iostream`. A proposta é aumentar a performance,
diminuindo o esforço na programação. Tanto que os comandos da `fmt` se assemelham
muito ao formato usado por `Python`.

### Instalação com vcpkg

O `vcpkg` possui a biblioteca `fmt`, que pode ser instalada de forma direta.

    vcpkg install fmt

As instruções para incluir a biblioteca no sistema de compilação usando o `CMake`
são:

    The package fmt provides CMake targets:

    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt)

    # Or use the header-only version
    find_package(fmt CONFIG REQUIRED)
    target_link_libraries(main PRIVATE fmt::fmt-header-only)
