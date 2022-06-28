#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "sislin.h"
#include "Metodos.h"

int main () {
  // inicializa gerador de numeros aleatorios
  srand(202201);
  
  SistLinear_t *SL;

  // alocacao do tipo pontPont para uma matriz de tamanho 10
  SL = alocaSisLin (10, pontPont);
  
  // inicializando o sistema linear do tipo diagDominante
  iniSisLin (SL, diagDominante, COEF_MAX);

  // imprimindo o sistema linear
  prnSisLin (SL);

  // alocando memoria para o vetor resultado de tamanho 10
  real_t *x;
  x = malloc (sizeof (real_t) * 10);
    if (x == 0) 
      abort (); 
  
  // iniciando o contador
  double tTotal;
  tTotal = timestamp();

  // eliminacao de Gauss
  //eliminacaoGauss (SL, x, tTotal)
}

