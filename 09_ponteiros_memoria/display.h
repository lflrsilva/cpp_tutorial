/**

  Este arquivo faz parte dos tutoriais de C++ github.com/lflrsilva/cpp_tutorial
  (c) Copyright 2023 Luiz Fernando Lopes Rodrigues Silva. All Rights Reserved.

  File:   display.h
  Author: lflrsilva

  Prototypes das funções usadas em 03_args_funcoes.cpp

*/

// Diferentes formas de declaracao do prototype com argumento array
// void display(int num[10]);
// void display(int num[]);
void display(int *num);

// Prototype para somatorio
// ponteiro constante: não pode apontar para outro local
double h(double *const d, int n);

// variável e ponteiro constantes: não pode alterar valor nem onde aponta
// double h(const double* const d, int n);
